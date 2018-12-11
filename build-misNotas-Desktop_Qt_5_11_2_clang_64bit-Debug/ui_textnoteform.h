/********************************************************************************
** Form generated from reading UI file 'textnoteform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTNOTEFORM_H
#define UI_TEXTNOTEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextNoteForm
{
public:

    void setupUi(QWidget *TextNoteForm)
    {
        if (TextNoteForm->objectName().isEmpty())
            TextNoteForm->setObjectName(QStringLiteral("TextNoteForm"));
        TextNoteForm->resize(400, 300);

        retranslateUi(TextNoteForm);

        QMetaObject::connectSlotsByName(TextNoteForm);
    } // setupUi

    void retranslateUi(QWidget *TextNoteForm)
    {
        TextNoteForm->setWindowTitle(QApplication::translate("TextNoteForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextNoteForm: public Ui_TextNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTNOTEFORM_H
