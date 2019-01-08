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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioNoteForm
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *open_button;
    QPushButton *play_button;
    QSlider *volumeControl;
    QPushButton *saveButton;
    QSlider *positionSlider;

    void setupUi(QWidget *AudioNoteForm)
    {
        if (AudioNoteForm->objectName().isEmpty())
            AudioNoteForm->setObjectName(QStringLiteral("AudioNoteForm"));
        AudioNoteForm->resize(640, 480);
        horizontalLayout = new QHBoxLayout(AudioNoteForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        open_button = new QPushButton(AudioNoteForm);
        open_button->setObjectName(QStringLiteral("open_button"));

        gridLayout->addWidget(open_button, 3, 3, 1, 1);

        play_button = new QPushButton(AudioNoteForm);
        play_button->setObjectName(QStringLiteral("play_button"));

        gridLayout->addWidget(play_button, 3, 2, 1, 1);

        volumeControl = new QSlider(AudioNoteForm);
        volumeControl->setObjectName(QStringLiteral("volumeControl"));
        volumeControl->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeControl, 4, 1, 1, 3);

        saveButton = new QPushButton(AudioNoteForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 3, 1, 1, 1);

        positionSlider = new QSlider(AudioNoteForm);
        positionSlider->setObjectName(QStringLiteral("positionSlider"));
        positionSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(positionSlider, 5, 1, 1, 3);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(AudioNoteForm);

        QMetaObject::connectSlotsByName(AudioNoteForm);
    } // setupUi

    void retranslateUi(QWidget *AudioNoteForm)
    {
        AudioNoteForm->setWindowTitle(QApplication::translate("AudioNoteForm", "Form", nullptr));
        open_button->setText(QApplication::translate("AudioNoteForm", "Open", nullptr));
        play_button->setText(QApplication::translate("AudioNoteForm", "Play", nullptr));
        saveButton->setText(QApplication::translate("AudioNoteForm", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioNoteForm: public Ui_AudioNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIONOTEFORM_H
