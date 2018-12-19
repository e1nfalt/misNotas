/********************************************************************************
** Form generated from reading UI file 'new_note_window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_NOTE_WINDOW_H
#define UI_NEW_NOTE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_note_window
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *new_note_window)
    {
        if (new_note_window->objectName().isEmpty())
            new_note_window->setObjectName(QStringLiteral("new_note_window"));
        new_note_window->resize(400, 300);
        comboBox = new QComboBox(new_note_window);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 70, 79, 24));
        pushButton = new QPushButton(new_note_window);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 210, 80, 24));
        lineEdit = new QLineEdit(new_note_window);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 130, 113, 24));

        retranslateUi(new_note_window);

        QMetaObject::connectSlotsByName(new_note_window);
    } // setupUi

    void retranslateUi(QWidget *new_note_window)
    {
        new_note_window->setWindowTitle(QApplication::translate("new_note_window", "Form", nullptr));
        pushButton->setText(QApplication::translate("new_note_window", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_note_window: public Ui_new_note_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_NOTE_WINDOW_H
