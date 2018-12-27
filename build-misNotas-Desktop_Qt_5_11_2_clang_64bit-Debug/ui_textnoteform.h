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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *TextNoteForm)
    {
        if (TextNoteForm->objectName().isEmpty())
            TextNoteForm->setObjectName(QStringLiteral("TextNoteForm"));
        TextNoteForm->resize(400, 300);
        plainTextEdit = new QPlainTextEdit(TextNoteForm);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(70, 40, 241, 171));
        pushButton = new QPushButton(TextNoteForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 250, 80, 24));
        pushButton_2 = new QPushButton(TextNoteForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 250, 80, 24));
        label = new QLabel(TextNoteForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 59, 16));

        retranslateUi(TextNoteForm);

        QMetaObject::connectSlotsByName(TextNoteForm);
    } // setupUi

    void retranslateUi(QWidget *TextNoteForm)
    {
        TextNoteForm->setWindowTitle(QApplication::translate("TextNoteForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("TextNoteForm", "save", nullptr));
        pushButton_2->setText(QApplication::translate("TextNoteForm", "open", nullptr));
        label->setText(QApplication::translate("TextNoteForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextNoteForm: public Ui_TextNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTNOTEFORM_H
