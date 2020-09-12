#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <cstring>
#include <thread>
#include <mutex>
#include <cmath>
#include <ctime>
#include <queue>

#define BAD 0
#define GOOD 1

class RecordTime {
public:
	int status;
	clock_t prev;
	clock_t alarmed;

	RecordTime() {
		status = -1;
		prev = 0;
		alarmed = 0;
	};
};

class Point {
public:
	int x, y;

	Point() {
		x = -1, y = -1;
	};
};

class Points {
public:
	Point Nose, rEye, lEye, lEar, rEar, lShoulder, rShoulder, Neck;

	int length(Point A, Point B) {
		int x = A.x - B.x;
		int y = A.y - B.y;
		return sqrt(x * x + y * y);
	};
};

int startFix(void);
void editChildProccessPath(char* path);
int ConnectClient(HANDLE hNamePipe);
void checkEndSignal(bool sign);
void judgePose();
void operatorQueue(Points *ret, bool how);
bool judge(Points cur);
int setSTDPose(); //초기 자세 설정
int ConnectClient2(HANDLE hNamePipe); //초기 자세 설정