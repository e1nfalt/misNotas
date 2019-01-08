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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_note_window
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *new_title;
    QComboBox *comboBox;
    QLineEdit *new_tags_list;
    QPushButton *createButton;

    void setupUi(QWidget *new_note_window)
    {
        if (new_note_window->objectName().isEmpty())
            new_note_window->setObjectName(QStringLiteral("new_note_window"));
        new_note_window->resize(400, 300);
        horizontalLayout = new QHBoxLayout(new_note_window);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        new_title = new QLineEdit(new_note_window);
        new_title->setObjectName(QStringLiteral("new_title"));

        gridLayout->addWidget(new_title, 1, 0, 1, 1);

        comboBox = new QComboBox(new_note_window);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        new_tags_list = new QLineEdit(new_note_window);
        new_tags_list->setObjectName(QStringLiteral("new_tags_list"));

        gridLayout->addWidget(new_tags_list, 2, 0, 1, 1);

        createButton = new QPushButton(new_note_window);
        createButton->setObjectName(QStringLiteral("createButton"));

        gridLayout->addWidget(createButton, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(new_note_window);

        QMetaObject::connectSlotsByName(new_note_window);
    } // setupUi

    void retranslateUi(QWidget *new_note_window)
    {
        new_note_window->setWindowTitle(QApplication::translate("new_note_window", "Form", nullptr));
        createButton->setText(QApplication::translate("new_note_window", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_note_window: public Ui_new_note_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_NOTE_WINDOW_H
