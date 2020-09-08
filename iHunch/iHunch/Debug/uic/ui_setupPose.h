/********************************************************************************
** Form generated from reading UI file 'setupPose.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPPOSE_H
#define UI_SETUPPOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setupPose
{
public:
    QLabel *label;
    QPushButton *startBtn;
    QComboBox *comboBox;
    QPushButton *stopBtn;
    QPushButton *captureBtn;
    QWidget *camOut;

    void setupUi(QDialog *setupPose)
    {
        if (setupPose->objectName().isEmpty())
            setupPose->setObjectName(QString::fromUtf8("setupPose"));
        setupPose->resize(616, 539);
        setupPose->setMinimumSize(QSize(600, 500));
        label = new QLabel(setupPose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        startBtn = new QPushButton(setupPose);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        startBtn->setGeometry(QRect(240, 60, 75, 23));
        comboBox = new QComboBox(setupPose);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 60, 211, 31));
        stopBtn = new QPushButton(setupPose);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(330, 60, 75, 23));
        captureBtn = new QPushButton(setupPose);
        captureBtn->setObjectName(QString::fromUtf8("captureBtn"));
        captureBtn->setGeometry(QRect(420, 60, 75, 23));
        camOut = new QWidget(setupPose);
        camOut->setObjectName(QString::fromUtf8("camOut"));
        camOut->setGeometry(QRect(20, 110, 481, 371));

        retranslateUi(setupPose);
        QObject::connect(startBtn, SIGNAL(clicked()), setupPose, SLOT(onStartBtn()));
        QObject::connect(stopBtn, SIGNAL(clicked()), setupPose, SLOT(onStopBtn()));
        QObject::connect(captureBtn, SIGNAL(clicked()), setupPose, SLOT(onCaptureBtn()));

        QMetaObject::connectSlotsByName(setupPose);
    } // setupUi

    void retranslateUi(QDialog *setupPose)
    {
        setupPose->setWindowTitle(QCoreApplication::translate("setupPose", "setupPose", nullptr));
        label->setText(QCoreApplication::translate("setupPose", "\354\264\210\352\270\260 \354\236\220\354\204\270 \354\204\244\354\240\225", nullptr));
        startBtn->setText(QCoreApplication::translate("setupPose", "start", nullptr));
        stopBtn->setText(QCoreApplication::translate("setupPose", "stop", nullptr));
        captureBtn->setText(QCoreApplication::translate("setupPose", "capture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setupPose: public Ui_setupPose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPPOSE_H
