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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphicform
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *openButton;
    QPushButton *clearButton;
    QPushButton *colorButton;
    QPushButton *saveButton;
    QSlider *penWidthSlider;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *graphicform)
    {
        if (graphicform->objectName().isEmpty())
            graphicform->setObjectName(QStringLiteral("graphicform"));
        graphicform->resize(434, 387);
        centralwidget = new QWidget(graphicform);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout_2->addWidget(openButton, 2, 1, 1, 1);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout_2->addWidget(clearButton, 1, 0, 1, 1);

        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        gridLayout_2->addWidget(colorButton, 2, 2, 1, 1);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout_2->addWidget(saveButton, 2, 0, 1, 1);

        penWidthSlider = new QSlider(centralwidget);
        penWidthSlider->setObjectName(QStringLiteral("penWidthSlider"));
        penWidthSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(penWidthSlider, 1, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_2);

        graphicform->setCentralWidget(centralwidget);

        retranslateUi(graphicform);

        QMetaObject::connectSlotsByName(graphicform);
    } // setupUi

    void retranslateUi(QMainWindow *graphicform)
    {
        graphicform->setWindowTitle(QApplication::translate("graphicform", "MainWindow", nullptr));
        openButton->setText(QApplication::translate("graphicform", "Open", nullptr));
        clearButton->setText(QApplication::translate("graphicform", "Clear", nullptr));
        colorButton->setText(QApplication::translate("graphicform", "Color", nullptr));
        saveButton->setText(QApplication::translate("graphicform", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphicform: public Ui_graphicform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICFORM_H
