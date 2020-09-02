/********************************************************************************
** Form generated from reading UI file 'popupc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPC_H
#define UI_POPUPC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_popupc
{
public:

    void setupUi(QDialog *popupc)
    {
        if (popupc->objectName().isEmpty())
            popupc->setObjectName(QString::fromUtf8("popupc"));
        popupc->resize(400, 300);

        retranslateUi(popupc);

        QMetaObject::connectSlotsByName(popupc);
    } // setupUi

    void retranslateUi(QDialog *popupc)
    {
        popupc->setWindowTitle(QCoreApplication::translate("popupc", "popupc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class popupc: public Ui_popupc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPC_H
