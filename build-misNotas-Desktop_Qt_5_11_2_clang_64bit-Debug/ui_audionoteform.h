/********************************************************************************
** Form generated from reading UI file 'audionoteform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIONOTEFORM_H
#define UI_AUDIONOTEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioNoteForm
{
public:

    void setupUi(QWidget *AudioNoteForm)
    {
        if (AudioNoteForm->objectName().isEmpty())
            AudioNoteForm->setObjectName(QStringLiteral("AudioNoteForm"));
        AudioNoteForm->resize(400, 300);

        retranslateUi(AudioNoteForm);

        QMetaObject::connectSlotsByName(AudioNoteForm);
    } // setupUi

    void retranslateUi(QWidget *AudioNoteForm)
    {
        AudioNoteForm->setWindowTitle(QApplication::translate("AudioNoteForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioNoteForm: public Ui_AudioNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIONOTEFORM_H
