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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioNoteForm
{
public:
    QPushButton *rec_button;
    QPushButton *save_button;
    QPushButton *open_button;
    QPushButton *play_button;

    void setupUi(QWidget *AudioNoteForm)
    {
        if (AudioNoteForm->objectName().isEmpty())
            AudioNoteForm->setObjectName(QStringLiteral("AudioNoteForm"));
        AudioNoteForm->resize(400, 300);
        rec_button = new QPushButton(AudioNoteForm);
        rec_button->setObjectName(QStringLiteral("rec_button"));
        rec_button->setGeometry(QRect(80, 130, 80, 24));
        save_button = new QPushButton(AudioNoteForm);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(80, 170, 80, 24));
        open_button = new QPushButton(AudioNoteForm);
        open_button->setObjectName(QStringLiteral("open_button"));
        open_button->setGeometry(QRect(230, 170, 80, 24));
        play_button = new QPushButton(AudioNoteForm);
        play_button->setObjectName(QStringLiteral("play_button"));
        play_button->setGeometry(QRect(230, 130, 80, 24));

        retranslateUi(AudioNoteForm);

        QMetaObject::connectSlotsByName(AudioNoteForm);
    } // setupUi

    void retranslateUi(QWidget *AudioNoteForm)
    {
        AudioNoteForm->setWindowTitle(QApplication::translate("AudioNoteForm", "Form", nullptr));
        rec_button->setText(QApplication::translate("AudioNoteForm", "rec", nullptr));
        save_button->setText(QApplication::translate("AudioNoteForm", "save", nullptr));
        open_button->setText(QApplication::translate("AudioNoteForm", "open", nullptr));
        play_button->setText(QApplication::translate("AudioNoteForm", "play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioNoteForm: public Ui_AudioNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIONOTEFORM_H
