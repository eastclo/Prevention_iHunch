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
    QProgressBar *progressBar;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QComboBox *comboBox;
    QWidget *modeAlarm;
    QLabel *label_10;
    QFrame *frame;
    QCheckBox *soundAlram_checkbox;
    QCheckBox *popup_checkbox;
    QGroupBox *groupBox_2;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *iHunchClass)
    {
        if (iHunchClass->objectName().isEmpty())
            iHunchClass->setObjectName(QString::fromUtf8("iHunchClass"));
        iHunchClass->resize(600, 500);
        iHunchClass->setMinimumSize(QSize(600, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/iHunch/gb.png"), QSize(), QIcon::Normal, QIcon::Off);
        iHunchClass->setWindowIcon(icon);
        centralWidget = new QWidget(iHunchClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 211, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 121, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 60, 111, 41));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 210, 350, 121));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 30, 61, 16));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 68, 16));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 90, 24, 16));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(84, 91, 141, 20));
        progressBar->setValue(30);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(84, 22, 256, 29));
        textBrowser_2 = new QTextBrowser(groupBox);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(84, 57, 256, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 390, 131, 61));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 350, 91, 21));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 370, 151, 41));
        modeAlarm = new QWidget(centralWidget);
        modeAlarm->setObjectName(QString::fromUtf8("modeAlarm"));
        modeAlarm->setGeometry(QRect(170, 350, 162, 91));
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
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 361, 91));
        QFont font1;
        font1.setPointSize(10);
        groupBox_2->setFont(font1);
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 30, 301, 31));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 60, 56, 12));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 60, 56, 12));
        label_5->setAlignment(Qt::AlignCenter);
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
        label_4->setBuddy(horizontalSlider);
        label_5->setBuddy(horizontalSlider);
#endif // QT_CONFIG(shortcut)

        retranslateUi(iHunchClass);
        QObject::connect(pushButton, SIGNAL(clicked()), iHunchClass, SLOT(setPose()));
        QObject::connect(comboBox, SIGNAL(activated(int)), iHunchClass, SLOT(modeChanged(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), iHunchClass, SLOT(mybtn()));

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
        textBrowser->setHtml(QCoreApplication::translate("iHunchClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10\354\213\234\352\260\204 0\353\266\204 0\354\264\210</p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("iHunchClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">7\354\213\234\352\260\204 0\353\266\204 0\354\264\210</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("iHunchClass", "\354\270\241\354\240\225 \354\213\234\354\236\221", nullptr));
        label_9->setText(QCoreApplication::translate("iHunchClass", "\353\252\250\353\223\234 \354\204\244\354\240\225", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("iHunchClass", "\352\264\200\354\260\260 \353\252\250\353\223\234", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("iHunchClass", "\352\265\220\354\240\225 \353\252\250\353\223\234", nullptr));

        label_10->setText(QCoreApplication::translate("iHunchClass", "\354\225\214\353\236\214 \354\204\244\354\240\225", nullptr));
        soundAlram_checkbox->setText(QCoreApplication::translate("iHunchClass", "\352\262\275\352\263\240\354\235\214", nullptr));
        popup_checkbox->setText(QCoreApplication::translate("iHunchClass", "\355\214\235\354\227\205\354\260\275", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("iHunchClass", "\352\265\220\354\240\225 \352\260\220\353\217\204 \354\204\244\354\240\225", nullptr));
        label_4->setText(QCoreApplication::translate("iHunchClass", "\354\225\275\355\225\230\352\262\214", nullptr));
        label_5->setText(QCoreApplication::translate("iHunchClass", "\352\260\225\355\225\230\352\262\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class iHunchClass: public Ui_iHunchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHUNCH_H
