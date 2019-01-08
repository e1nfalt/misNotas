/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *addButton;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *findLine;
    QPushButton *findButton;
    QListWidget *listWidget;
    QPushButton *editButton;
    QLineEdit *filterLine;
    QPushButton *filterButton;
    QPushButton *refreshButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(6);
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 12, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 12, 2, 1, 1);

        findLine = new QLineEdit(centralWidget);
        findLine->setObjectName(QStringLiteral("findLine"));

        gridLayout->addWidget(findLine, 1, 2, 1, 1);

        findButton = new QPushButton(centralWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        gridLayout->addWidget(findButton, 2, 2, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setAutoFillBackground(false);
        listWidget->setAlternatingRowColors(false);

        gridLayout->addWidget(listWidget, 4, 0, 1, 3);

        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));

        gridLayout->addWidget(editButton, 12, 1, 1, 1);

        filterLine = new QLineEdit(centralWidget);
        filterLine->setObjectName(QStringLiteral("filterLine"));

        gridLayout->addWidget(filterLine, 13, 2, 1, 1);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        gridLayout->addWidget(filterButton, 14, 2, 1, 1);

        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        gridLayout->addWidget(refreshButton, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "ADD", nullptr));
        label->setText(QApplication::translate("MainWindow", "misNotas", nullptr));
        findButton->setText(QApplication::translate("MainWindow", "TITLE FIND", nullptr));
        editButton->setText(QApplication::translate("MainWindow", "EDIT", nullptr));
        filterButton->setText(QApplication::translate("MainWindow", "FILTER DATE", nullptr));
        refreshButton->setText(QApplication::translate("MainWindow", "REFRESH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
