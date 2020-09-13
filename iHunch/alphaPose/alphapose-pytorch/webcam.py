import os
import sys
sys.path.append('C:\\Users\\golde\\source\\repos\\Prevention_iHunch\\iHunch\\alphaPose\\alphapose-pytorch')
sys.path.append('C:\\Users\\golde\\source\\repos\\Prevention_iHunch\\iHunch\\alphaPose')
sys.path.append('C:\\Users\\golde\\anaconda3\\envs\\alphapose\\python38.zip')
sys.path.append('C:\\Users\\golde\\anaconda3\\envs\\alphapose\\DLLs')
sys.path.append('C:\\Users\\golde\\anaconda3\\envs\\alphapose\\lib')
sys.path.append('C:\\Users\\golde\\anaconda3\\envs\\alphapose')
sys.path.append('C:\\Users\\golde\\anaconda3\\envs\\alphapose\\lib\\site-packages')
os.chdir('../alphaPose/alphapose-pytorch')
import torch
from torch.autograd import Variable
import torch.nn.functional as F
import torchvision.transforms as transforms
import torch.nn as nn
import torch.utils.data

import numpy as np

from opt import opt

from dataloader_webcam import WebcamLoader, DetectionLoader, DetectionProcessor, DataWriter, crop_from_dets, Mscoco

from yolo.darknet import Darknet
from yolo.util import write_results, dynamic_write_results
from SPPE.src.main_fast_inference import *
from SPPE.src.utils.img import im_to_torch
from fn import getTime


from tqdm import tqdm
import time

import cv2

from pPose_nms import write_json
from pPose_nms import pose_nms
args = opt
args.dataset = 'coco'
args.outputpath = 'examples/res'
args.vis = True

# Load pose model
pose_dataset = Mscoco()
if args.fast_inference:
    pose_model = InferenNet_fast(4 * 1 + 1, pose_dataset)
else:
    pose_model = InferenNet(4 * 1 + 1, pose_dataset)
pose_model.cuda()
pose_model.eval()
webcam = args.webcam
mode = args.mode
if not os.path.exists(args.outputpath):
    os.mkdir(args.outputpath)

# Load input video
data_loader = WebcamLoader(webcam).start()
(fourcc,fps,frameSize) = data_loader.videoinfo()

# Load detection loader
print('Loading YOLO model..')
sys.stdout.flush()
det_loader = DetectionLoader(data_loader, batchSize=args.detbatch).start()
det_processor = DetectionProcessor(det_loader).start()
# Data writer
save_path = os.path.join(args.outputpath, 'AlphaPose_webcam'+webcam+'.avi')
writer = DataWriter(args.save_video, save_path, cv2.VideoWriter_fourcc(*'XVID'), fps, frameSize).start()
runtime_profile = {
    'dt': [],
    'pt': [],
    'pn': []
}
sys.stdout.flush()
batchSize = args.posebatch

def run():
    ret = []
 #   for i in im_names_desc:
     #   try:
    start_time = getTime()
    with torch.no_grad():
        (inps, orig_img, im_name, boxes, scores, pt1, pt2) = det_processor.read()
        if boxes is None or boxes.nelement() == 0:
            writer.save(None, None, None, None, None, orig_img, im_name.split('/')[-1])
  #             continue
        ckpt_time, det_time = getTime(start_time)
        runtime_profile['dt'].append(det_time)
        # Pose Estimation
        if(inps == None):
            writer.save(boxes, scores, [], pt1, pt2, orig_img, im_name.split('/')[-1])
            return []
        datalen = inps.size(0)
        leftover = 0
        if (datalen) % batchSize:
            leftover = 1
        num_batches = datalen // batchSize + leftover
        hm = []
        for j in range(num_batches):
            inps_j = inps[j*batchSize:min((j +  1)*batchSize, datalen)].cuda()
            hm_j = pose_model(inps_j)
            hm.append(hm_j)
        hm = torch.cat(hm)
        ckpt_time, pose_time = getTime(ckpt_time)
        runtime_profile['pt'].append(pose_time)
        hm = hm.cpu().data
                # new code
        preds_hm, preds_img, preds_scores = getPrediction(hm, pt1, pt2, opt.inputResH, opt.inputResW, opt.outputResH, opt.outputResW)
        result = pose_nms(boxes, scores, preds_img, preds_scores)
        print("\n")
        for human in result:
            kp_preds = human['keypoints']
            kp_scores = human['kp_score']
            kp_preds = torch.cat((kp_preds, torch.unsqueeze((kp_preds[5,:]+kp_preds[6,:])/2,0)))
            kp_scores = torch.cat((kp_scores, torch.unsqueeze((kp_scores[5,:]+kp_scores[6,:])/2,0)))
            for n in range(kp_scores.shape[0]):
                if kp_scores[n] <= 0.05:
                     continue
                cor_x, cor_y = int(kp_preds[n, 0]), int(kp_preds[n, 1])
                if(n == 0):
                    print('코' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 1):
                    print('왼눈' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 2):
                    print('오눈' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 3):
                    print('왼귀' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 4):
                    print('오귀' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 5):
                    print('왼어' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 6):
                    print('오어' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
                if(n == 17):
                    print('목' + ': ' + str(cor_x) + ', ' + str(cor_y))
                    ret.append([n, cor_x, cor_y])
        writer.save(boxes, scores, hm, pt1, pt2, orig_img, im_name.split('/')[-1])
        ckpt_time, post_time = getTime(ckpt_time)
        runtime_profile['pn'].append(post_time)
    if args.profile:
        # TQDM
        im_names_desc.set_description(
        'det time: {dt:.3f} | pose time: {pt:.2f} | post processing: {pn:.4f}'.format(
            dt=np.mean(runtime_profile['dt']), pt=np.mean(runtime_profile['pt']), pn=np.mean(runtime_profile['pn']))
        )
    #    except KeyboardInterrupt:
     #       break
    return ret
while(1):
    run()