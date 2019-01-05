/********************************************************************************
** Form generated from reading UI file 'graphicnoteform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICNOTEFORM_H
#define UI_GRAPHICNOTEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicNoteForm
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *GraphicNoteForm)
    {
        if (GraphicNoteForm->objectName().isEmpty())
            GraphicNoteForm->setObjectName(QStringLiteral("GraphicNoteForm"));
        GraphicNoteForm->resize(400, 300);
        graphicsView = new QGraphicsView(GraphicNoteForm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        pushButton = new QPushButton(GraphicNoteForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 250, 80, 24));
        pushButton_2 = new QPushButton(GraphicNoteForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 250, 80, 24));

        retranslateUi(GraphicNoteForm);

        QMetaObject::connectSlotsByName(GraphicNoteForm);
    } // setupUi

    void retranslateUi(QWidget *GraphicNoteForm)
    {
        GraphicNoteForm->setWindowTitle(QApplication::translate("GraphicNoteForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("GraphicNoteForm", "save", nullptr));
        pushButton_2->setText(QApplication::translate("GraphicNoteForm", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicNoteForm: public Ui_GraphicNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICNOTEFORM_H
