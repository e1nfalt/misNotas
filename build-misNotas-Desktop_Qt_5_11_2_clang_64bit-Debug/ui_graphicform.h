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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphicform
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *penWidthSlider;
    QPushButton *saveButton;
    QPushButton *openButton;
    QPushButton *colorButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphicform)
    {
        if (graphicform->objectName().isEmpty())
            graphicform->setObjectName(QStringLiteral("graphicform"));
        graphicform->resize(767, 675);
        centralwidget = new QWidget(graphicform);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 651, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        penWidthSlider = new QSlider(centralwidget);
        penWidthSlider->setObjectName(QStringLiteral("penWidthSlider"));
        penWidthSlider->setGeometry(QRect(470, 530, 160, 16));
        penWidthSlider->setOrientation(Qt::Horizontal);
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(60, 530, 80, 24));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(200, 530, 80, 24));
        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(340, 530, 80, 24));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(190, 490, 80, 24));
        graphicform->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graphicform);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 767, 22));
        graphicform->setMenuBar(menubar);
        statusbar = new QStatusBar(graphicform);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        graphicform->setStatusBar(statusbar);

        retranslateUi(graphicform);

        QMetaObject::connectSlotsByName(graphicform);
    } // setupUi

    void retranslateUi(QMainWindow *graphicform)
    {
        graphicform->setWindowTitle(QApplication::translate("graphicform", "MainWindow", nullptr));
        saveButton->setText(QApplication::translate("graphicform", "Save", nullptr));
        openButton->setText(QApplication::translate("graphicform", "Open", nullptr));
        colorButton->setText(QApplication::translate("graphicform", "Color", nullptr));
        clearButton->setText(QApplication::translate("graphicform", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphicform: public Ui_graphicform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICFORM_H
