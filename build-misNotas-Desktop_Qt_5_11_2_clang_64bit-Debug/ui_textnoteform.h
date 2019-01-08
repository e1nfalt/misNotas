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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextNoteForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *saveButton;
    QPushButton *openButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *TextNoteForm)
    {
        if (TextNoteForm->objectName().isEmpty())
            TextNoteForm->setObjectName(QStringLiteral("TextNoteForm"));
        TextNoteForm->resize(640, 480);
        verticalLayout = new QVBoxLayout(TextNoteForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(TextNoteForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        saveButton = new QPushButton(TextNoteForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 2, 0, 1, 1);

        openButton = new QPushButton(TextNoteForm);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 2, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(TextNoteForm);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(TextNoteForm);

        QMetaObject::connectSlotsByName(TextNoteForm);
    } // setupUi

    void retranslateUi(QWidget *TextNoteForm)
    {
        TextNoteForm->setWindowTitle(QApplication::translate("TextNoteForm", "Form", nullptr));
        label->setText(QApplication::translate("TextNoteForm", "TextLabel", nullptr));
        saveButton->setText(QApplication::translate("TextNoteForm", "save", nullptr));
        openButton->setText(QApplication::translate("TextNoteForm", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextNoteForm: public Ui_TextNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTNOTEFORM_H
