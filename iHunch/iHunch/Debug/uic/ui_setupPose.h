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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_setupPose
{
public:
    QLabel *label;
    QGraphicsView *graphicsView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *setupPose)
    {
        if (setupPose->objectName().isEmpty())
            setupPose->setObjectName(QString::fromUtf8("setupPose"));
        setupPose->resize(600, 500);
        setupPose->setMinimumSize(QSize(600, 500));
        label = new QLabel(setupPose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        graphicsView = new QGraphicsView(setupPose);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 50, 461, 361));
        buttonBox = new QDialogButtonBox(setupPose);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(420, 460, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(setupPose);

        QMetaObject::connectSlotsByName(setupPose);
    } // setupUi

    void retranslateUi(QDialog *setupPose)
    {
        setupPose->setWindowTitle(QCoreApplication::translate("setupPose", "setupPose", nullptr));
        label->setText(QCoreApplication::translate("setupPose", "\354\264\210\352\270\260 \354\236\220\354\204\270 \354\204\244\354\240\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setupPose: public Ui_setupPose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPPOSE_H
