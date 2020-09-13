/********************************************************************************
** Form generated from reading UI file 'iHunch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHUNCH_H
#define UI_IHUNCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iHunchClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QProgressBar *poseRatio;
    QTextBrowser *fullTimeTextBar;
    QTextBrowser *badTimeTextBar;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QComboBox *comboBox;
    QWidget *modeAlarm;
    QLabel *label_10;
    QFrame *frame;
    QCheckBox *soundAlram_checkbox;
    QCheckBox *popup_checkbox;
    QComboBox *alarmIntervalComboBox;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QSlider *poseFixDegreeSlider;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *myTitleBar;
    QPushButton *closeBtn;
    QPushButton *minBtn;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QComboBox *unHealthComboBox;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *iHunchClass)
    {
        if (iHunchClass->objectName().isEmpty())
            iHunchClass->setObjectName(QString::fromUtf8("iHunchClass"));
        iHunchClass->resize(600, 520);
        iHunchClass->setMinimumSize(QSize(600, 520));
        iHunchClass->setMaximumSize(QSize(600, 520));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iHunch/gb.png"), QSize(), QIcon::Normal, QIcon::Off);
        iHunchClass->setWindowIcon(icon);
        centralWidget = new QWidget(iHunchClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 211, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 90, 121, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 80, 111, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 230, 401, 121));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 30, 61, 16));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 60, 68, 16));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 90, 24, 16));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        poseRatio = new QProgressBar(groupBox);
        poseRatio->setObjectName(QString::fromUtf8("poseRatio"));
        poseRatio->setGeometry(QRect(110, 91, 141, 20));
        poseRatio->setValue(0);
        poseRatio->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fullTimeTextBar = new QTextBrowser(groupBox);
        fullTimeTextBar->setObjectName(QString::fromUtf8("fullTimeTextBar"));
        fullTimeTextBar->setGeometry(QRect(110, 22, 256, 29));
        badTimeTextBar = new QTextBrowser(groupBox);
        badTimeTextBar->setObjectName(QString::fromUtf8("badTimeTextBar"));
        badTimeTextBar->setGeometry(QRect(110, 57, 256, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 380, 131, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/iHunch/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(32, 32));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 370, 91, 21));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 390, 151, 41));
        modeAlarm = new QWidget(centralWidget);
        modeAlarm->setObjectName(QString::fromUtf8("modeAlarm"));
        modeAlarm->setGeometry(QRect(170, 370, 261, 91));
        label_10 = new QLabel(modeAlarm);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(9, 9, 52, 16));
        frame = new QFrame(modeAlarm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 41, 144, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        soundAlram_checkbox = new QCheckBox(frame);
        soundAlram_checkbox->setObjectName(QString::fromUtf8("soundAlram_checkbox"));
        soundAlram_checkbox->setGeometry(QRect(10, 10, 59, 16));
        popup_checkbox = new QCheckBox(frame);
        popup_checkbox->setObjectName(QString::fromUtf8("popup_checkbox"));
        popup_checkbox->setGeometry(QRect(75, 10, 59, 16));
        alarmIntervalComboBox = new QComboBox(modeAlarm);
        alarmIntervalComboBox->addItem(QString());
        alarmIntervalComboBox->addItem(QString());
        alarmIntervalComboBox->addItem(QString());
        alarmIntervalComboBox->setObjectName(QString::fromUtf8("alarmIntervalComboBox"));
        alarmIntervalComboBox->setGeometry(QRect(160, 60, 51, 22));
        label_11 = new QLabel(modeAlarm);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(160, 30, 101, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 401, 91));
        QFont font1;
        font1.setPointSize(10);
        groupBox_2->setFont(font1);
        poseFixDegreeSlider = new QSlider(groupBox_2);
        poseFixDegreeSlider->setObjectName(QString::fromUtf8("poseFixDegreeSlider"));
        poseFixDegreeSlider->setGeometry(QRect(50, 30, 301, 31));
        poseFixDegreeSlider->setMinimum(0);
        poseFixDegreeSlider->setMaximum(100);
        poseFixDegreeSlider->setOrientation(Qt::Horizontal);
        poseFixDegreeSlider->setTickPosition(QSlider::TicksBelow);
        poseFixDegreeSlider->setTickInterval(10);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 60, 56, 12));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(320, 60, 56, 12));
        label_5->setAlignment(Qt::AlignCenter);
        myTitleBar = new QWidget(centralWidget);
        myTitleBar->setObjectName(QString::fromUtf8("myTitleBar"));
        myTitleBar->setGeometry(QRect(0, 0, 600, 31));
        closeBtn = new QPushButton(myTitleBar);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(570, 10, 20, 20));
        closeBtn->setFocusPolicy(Qt::TabFocus);
        closeBtn->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/iHunch/close_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon2);
        minBtn = new QPushButton(myTitleBar);
        minBtn->setObjectName(QString::fromUtf8("minBtn"));
        minBtn->setGeometry(QRect(540, 10, 20, 20));
        minBtn->setFocusPolicy(Qt::TabFocus);
        minBtn->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/iHunch/minimum_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        minBtn->setIcon(icon3);
        label_3 = new QLabel(myTitleBar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 10, 101, 16));
        pushButton_3 = new QPushButton(myTitleBar);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 41, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("border: none;"));
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(32, 32));
        unHealthComboBox = new QComboBox(centralWidget);
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->addItem(QString());
        unHealthComboBox->setObjectName(QString::fromUtf8("unHealthComboBox"));
        unHealthComboBox->setGeometry(QRect(490, 181, 91, 22));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(420, 180, 111, 21));
        iHunchClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(iHunchClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        iHunchClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(iHunchClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        iHunchClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(iHunchClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        iHunchClass->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
        label_4->setBuddy(poseFixDegreeSlider);
        label_5->setBuddy(poseFixDegreeSlider);
#endif // QT_CONFIG(shortcut)

        retranslateUi(iHunchClass);
        QObject::connect(pushButton, SIGNAL(clicked()), iHunchClass, SLOT(setPose()));
        QObject::connect(comboBox, SIGNAL(activated(int)), iHunchClass, SLOT(modeChanged(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), iHunchClass, SLOT(mybtn()));
        QObject::connect(minBtn, SIGNAL(clicked()), iHunchClass, SLOT(minimum_Btn()));
        QObject::connect(closeBtn, SIGNAL(clicked()), iHunchClass, SLOT(close_Btn()));

        QMetaObject::connectSlotsByName(iHunchClass);
    } // setupUi

    void retranslateUi(QMainWindow *iHunchClass)
    {
        iHunchClass->setWindowTitle(QCoreApplication::translate("iHunchClass", "iHunch", nullptr));
        label->setText(QCoreApplication::translate("iHunchClass", "\352\261\260\353\266\201\353\252\251\354\235\204 \355\206\240\353\201\274\353\252\251\354\234\274\353\241\234", nullptr));
        label_2->setText(QCoreApplication::translate("iHunchClass", "\354\264\210\352\270\260 \354\236\220\354\204\270 \354\204\244\354\240\225", nullptr));
        pushButton->setText(QCoreApplication::translate("iHunchClass", "\354\236\220\354\204\270 \354\204\244\354\240\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("iHunchClass", "\355\206\265\352\263\204", nullptr));
        label_6->setText(QCoreApplication::translate("iHunchClass", "\354\240\204\354\262\264 \354\213\234\352\260\204", nullptr));
        label_7->setText(QCoreApplication::translate("iHunchClass", "\354\225\210 \354\242\213\354\235\200 \354\236\220\354\204\270", nullptr));
        label_8->setText(QCoreApplication::translate("iHunchClass", "\353\271\204\354\234\250", nullptr));
        fullTimeTextBar->setHtml(QCoreApplication::translate("iHunchClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0\354\213\234\352\260\204 0\353\266\204 0\354\264\210</p></body></html>", nullptr));
        badTimeTextBar->setHtml(QCoreApplication::translate("iHunchClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0\354\213\234\352\260\204 0\353\266\204 0\354\264\210</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("iHunchClass", "  \354\270\241\354\240\225 \354\213\234\354\236\221", nullptr));
        label_9->setText(QCoreApplication::translate("iHunchClass", "\353\252\250\353\223\234 \354\204\244\354\240\225", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("iHunchClass", "\352\264\200\354\260\260 \353\252\250\353\223\234", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("iHunchClass", "\352\265\220\354\240\225 \353\252\250\353\223\234", nullptr));

        label_10->setText(QCoreApplication::translate("iHunchClass", "\354\225\214\353\236\214 \354\204\244\354\240\225", nullptr));
        soundAlram_checkbox->setText(QCoreApplication::translate("iHunchClass", "\352\262\275\352\263\240\354\235\214", nullptr));
        popup_checkbox->setText(QCoreApplication::translate("iHunchClass", "\355\214\235\354\227\205\354\260\275", nullptr));
        alarmIntervalComboBox->setItemText(0, QCoreApplication::translate("iHunchClass", "5", nullptr));
        alarmIntervalComboBox->setItemText(1, QCoreApplication::translate("iHunchClass", "7", nullptr));
        alarmIntervalComboBox->setItemText(2, QCoreApplication::translate("iHunchClass", "10", nullptr));

        alarmIntervalComboBox->setCurrentText(QCoreApplication::translate("iHunchClass", "5", nullptr));
        label_11->setText(QCoreApplication::translate("iHunchClass", "\354\236\254 \354\225\214\353\236\214 \354\213\234\352\260\204(\354\264\210)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("iHunchClass", "\352\265\220\354\240\225 \352\260\220\353\217\204 \354\204\244\354\240\225", nullptr));
        label_4->setText(QCoreApplication::translate("iHunchClass", "\354\225\275\355\225\230\352\262\214", nullptr));
        label_5->setText(QCoreApplication::translate("iHunchClass", "\352\260\225\355\225\230\352\262\214", nullptr));
#if QT_CONFIG(tooltip)
        closeBtn->setToolTip(QCoreApplication::translate("iHunchClass", "\353\213\253\352\270\260", nullptr));
#endif // QT_CONFIG(tooltip)
        closeBtn->setText(QString());
#if QT_CONFIG(tooltip)
        minBtn->setToolTip(QCoreApplication::translate("iHunchClass", "\354\265\234\354\206\214\355\231\224", nullptr));
#endif // QT_CONFIG(tooltip)
        minBtn->setText(QString());
        label_3->setText(QCoreApplication::translate("iHunchClass", "Turtle Neck Slice", nullptr));
        pushButton_3->setText(QString());
        unHealthComboBox->setItemText(0, QCoreApplication::translate("iHunchClass", " 3\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(1, QCoreApplication::translate("iHunchClass", " 4\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(2, QCoreApplication::translate("iHunchClass", " 5\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(3, QCoreApplication::translate("iHunchClass", " 6\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(4, QCoreApplication::translate("iHunchClass", " 7\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(5, QCoreApplication::translate("iHunchClass", " 8\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(6, QCoreApplication::translate("iHunchClass", " 9\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        unHealthComboBox->setItemText(7, QCoreApplication::translate("iHunchClass", "10\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));

        unHealthComboBox->setCurrentText(QCoreApplication::translate("iHunchClass", " 3\354\264\210 \354\247\200\354\206\215\354\213\234", nullptr));
        label_12->setText(QCoreApplication::translate("iHunchClass", "\354\225\210 \354\242\213\354\235\200 \354\236\220\354\204\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class iHunchClass: public Ui_iHunchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHUNCH_H
