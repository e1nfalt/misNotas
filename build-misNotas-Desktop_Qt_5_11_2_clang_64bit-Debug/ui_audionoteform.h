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
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioNoteForm
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *play_button;
    QPushButton *open_button;
    QSlider *volumeControl;

    void setupUi(QWidget *AudioNoteForm)
    {
        if (AudioNoteForm->objectName().isEmpty())
            AudioNoteForm->setObjectName(QStringLiteral("AudioNoteForm"));
        AudioNoteForm->resize(352, 303);
        verticalLayout = new QVBoxLayout(AudioNoteForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        play_button = new QPushButton(AudioNoteForm);
        play_button->setObjectName(QStringLiteral("play_button"));

        verticalLayout->addWidget(play_button);

        open_button = new QPushButton(AudioNoteForm);
        open_button->setObjectName(QStringLiteral("open_button"));

        verticalLayout->addWidget(open_button);

        volumeControl = new QSlider(AudioNoteForm);
        volumeControl->setObjectName(QStringLiteral("volumeControl"));
        volumeControl->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(volumeControl);


        retranslateUi(AudioNoteForm);

        QMetaObject::connectSlotsByName(AudioNoteForm);
    } // setupUi

    void retranslateUi(QWidget *AudioNoteForm)
    {
        AudioNoteForm->setWindowTitle(QApplication::translate("AudioNoteForm", "Form", nullptr));
        play_button->setText(QApplication::translate("AudioNoteForm", "play", nullptr));
        open_button->setText(QApplication::translate("AudioNoteForm", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioNoteForm: public Ui_AudioNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIONOTEFORM_H
