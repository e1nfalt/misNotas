/********************************************************************************
** Form generated from reading UI file 'videonoteform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEONOTEFORM_H
#define UI_VIDEONOTEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoNoteForm
{
public:

    void setupUi(QWidget *VideoNoteForm)
    {
        if (VideoNoteForm->objectName().isEmpty())
            VideoNoteForm->setObjectName(QStringLiteral("VideoNoteForm"));
        VideoNoteForm->resize(400, 300);

        retranslateUi(VideoNoteForm);

        QMetaObject::connectSlotsByName(VideoNoteForm);
    } // setupUi

    void retranslateUi(QWidget *VideoNoteForm)
    {
        VideoNoteForm->setWindowTitle(QApplication::translate("VideoNoteForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoNoteForm: public Ui_VideoNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEONOTEFORM_H
