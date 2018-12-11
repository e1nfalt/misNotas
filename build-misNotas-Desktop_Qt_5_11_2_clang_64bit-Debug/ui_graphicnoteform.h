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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicNoteForm
{
public:

    void setupUi(QWidget *GraphicNoteForm)
    {
        if (GraphicNoteForm->objectName().isEmpty())
            GraphicNoteForm->setObjectName(QStringLiteral("GraphicNoteForm"));
        GraphicNoteForm->resize(400, 300);

        retranslateUi(GraphicNoteForm);

        QMetaObject::connectSlotsByName(GraphicNoteForm);
    } // setupUi

    void retranslateUi(QWidget *GraphicNoteForm)
    {
        GraphicNoteForm->setWindowTitle(QApplication::translate("GraphicNoteForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicNoteForm: public Ui_GraphicNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICNOTEFORM_H
