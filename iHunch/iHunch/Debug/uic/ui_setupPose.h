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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setupPose
{
public:
    QLabel *label;
    QPushButton *initBtn;
    QLabel *info_text;
    QLabel *info_text_2;
    QLabel *info_text_3;
    QLabel *infomtxt;

    void setupUi(QDialog *setupPose)
    {
        if (setupPose->objectName().isEmpty())
            setupPose->setObjectName(QString::fromUtf8("setupPose"));
        setupPose->resize(420, 300);
        setupPose->setMinimumSize(QSize(300, 300));
        setupPose->setStyleSheet(QString::fromUtf8("background : rgba(240,248,255,0.99);"));
        label = new QLabel(setupPose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 141, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        initBtn = new QPushButton(setupPose);
        initBtn->setObjectName(QString::fromUtf8("initBtn"));
        initBtn->setGeometry(QRect(110, 180, 181, 51));
        info_text = new QLabel(setupPose);
        info_text->setObjectName(QString::fromUtf8("info_text"));
        info_text->setGeometry(QRect(-40, 140, 501, 31));
        QFont font1;
        font1.setPointSize(11);
        info_text->setFont(font1);
        info_text->setAlignment(Qt::AlignCenter);
        info_text_2 = new QLabel(setupPose);
        info_text_2->setObjectName(QString::fromUtf8("info_text_2"));
        info_text_2->setGeometry(QRect(-30, 80, 501, 31));
        info_text_2->setFont(font1);
        info_text_2->setLineWidth(2);
        info_text_2->setAlignment(Qt::AlignCenter);
        info_text_2->setWordWrap(true);
        info_text_2->setIndent(0);
        info_text_3 = new QLabel(setupPose);
        info_text_3->setObjectName(QString::fromUtf8("info_text_3"));
        info_text_3->setGeometry(QRect(-30, 110, 501, 31));
        info_text_3->setFont(font1);
        info_text_3->setLineWidth(2);
        info_text_3->setAlignment(Qt::AlignCenter);
        info_text_3->setWordWrap(true);
        info_text_3->setIndent(0);
        infomtxt = new QLabel(setupPose);
        infomtxt->setObjectName(QString::fromUtf8("infomtxt"));
        infomtxt->setGeometry(QRect(40, 250, 331, 31));
        infomtxt->setAlignment(Qt::AlignCenter);
        infomtxt->setWordWrap(true);

        retranslateUi(setupPose);
        QObject::connect(initBtn, SIGNAL(clicked()), setupPose, SLOT(initPoseBtn()));

        QMetaObject::connectSlotsByName(setupPose);
    } // setupUi

    void retranslateUi(QDialog *setupPose)
    {
        setupPose->setWindowTitle(QCoreApplication::translate("setupPose", "setupPose", nullptr));
        label->setText(QCoreApplication::translate("setupPose", "\354\264\210\352\270\260 \354\236\220\354\204\270 \354\204\244\354\240\225", nullptr));
        initBtn->setText(QCoreApplication::translate("setupPose", "\354\264\210\352\270\260 \354\236\220\354\204\270 \354\264\254\354\230\201", nullptr));
        info_text->setText(QCoreApplication::translate("setupPose", "\354\264\254\354\230\201 \353\262\204\355\212\274\354\235\204 \353\210\204\353\245\264\353\251\264 5\354\264\210 \353\222\244 \354\264\254\354\230\201\353\220\251\353\213\210\353\213\244.", nullptr));
        info_text_2->setText(QCoreApplication::translate("setupPose", "\354\230\254\353\260\224\353\245\270 \354\236\220\354\204\270\353\245\274 \354\267\250\355\225\234 \353\222\244 \354\264\254\354\230\201 \353\262\204\355\212\274\354\235\204 \353\210\214\353\237\254\354\243\274\354\204\270\354\232\224.", nullptr));
        info_text_3->setText(QCoreApplication::translate("setupPose", "\354\226\274\352\265\264\352\263\274 \354\226\221 \354\252\275 \354\226\264\352\271\250\352\260\200 \354\234\204\354\235\230 \355\231\224\353\251\264\354\227\220 \353\202\230\354\230\244\353\251\264 \353\220\251\353\213\210\353\213\244.", nullptr));
        infomtxt->setText(QCoreApplication::translate("setupPose", "\354\235\264 \354\260\275\354\235\200 \354\264\254\354\230\201\354\235\264 \354\231\204\353\243\214\353\220\234 \353\222\244 \354\236\220\353\217\231\354\234\274\353\241\234 \354\242\205\353\243\214\355\225\251\353\213\210\353\213\244.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setupPose: public Ui_setupPose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPPOSE_H
