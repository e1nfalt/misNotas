/********************************************************************************
** Form generated from reading UI file 'graphicform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICFORM_H
#define UI_GRAPHICFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphicform
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphicform)
    {
        if (graphicform->objectName().isEmpty())
            graphicform->setObjectName(QStringLiteral("graphicform"));
        graphicform->resize(800, 600);
        menubar = new QMenuBar(graphicform);
        menubar->setObjectName(QStringLiteral("menubar"));
        graphicform->setMenuBar(menubar);
        centralwidget = new QWidget(graphicform);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicform->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(graphicform);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        graphicform->setStatusBar(statusbar);

        retranslateUi(graphicform);

        QMetaObject::connectSlotsByName(graphicform);
    } // setupUi

    void retranslateUi(QMainWindow *graphicform)
    {
        graphicform->setWindowTitle(QApplication::translate("graphicform", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphicform: public Ui_graphicform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICFORM_H
