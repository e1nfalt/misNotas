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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextNoteForm
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *saveButton;
    QPushButton *openButton;
    QLabel *label;

    void setupUi(QWidget *TextNoteForm)
    {
        if (TextNoteForm->objectName().isEmpty())
            TextNoteForm->setObjectName(QStringLiteral("TextNoteForm"));
        TextNoteForm->resize(400, 300);
        plainTextEdit = new QPlainTextEdit(TextNoteForm);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(70, 40, 241, 171));
        saveButton = new QPushButton(TextNoteForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(70, 250, 80, 24));
        openButton = new QPushButton(TextNoteForm);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(220, 250, 80, 24));
        label = new QLabel(TextNoteForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 59, 16));

        retranslateUi(TextNoteForm);

        QMetaObject::connectSlotsByName(TextNoteForm);
    } // setupUi

    void retranslateUi(QWidget *TextNoteForm)
    {
        TextNoteForm->setWindowTitle(QApplication::translate("TextNoteForm", "Form", nullptr));
        saveButton->setText(QApplication::translate("TextNoteForm", "save", nullptr));
        openButton->setText(QApplication::translate("TextNoteForm", "open", nullptr));
        label->setText(QApplication::translate("TextNoteForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextNoteForm: public Ui_TextNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTNOTEFORM_H
