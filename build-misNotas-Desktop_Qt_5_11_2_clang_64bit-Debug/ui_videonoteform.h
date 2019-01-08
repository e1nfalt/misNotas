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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoNoteForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *saveButton;
    QSlider *timeSlider;
    QGridLayout *videoLayout;

    void setupUi(QWidget *VideoNoteForm)
    {
        if (VideoNoteForm->objectName().isEmpty())
            VideoNoteForm->setObjectName(QStringLiteral("VideoNoteForm"));
        VideoNoteForm->resize(566, 449);
        verticalLayout = new QVBoxLayout(VideoNoteForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        openButton = new QPushButton(VideoNoteForm);
        openButton->setObjectName(QStringLiteral("openButton"));

        gridLayout->addWidget(openButton, 2, 1, 1, 1);

        playButton = new QPushButton(VideoNoteForm);
        playButton->setObjectName(QStringLiteral("playButton"));

        gridLayout->addWidget(playButton, 2, 2, 1, 1);

        saveButton = new QPushButton(VideoNoteForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 2, 0, 1, 1);

        timeSlider = new QSlider(VideoNoteForm);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(timeSlider, 1, 0, 1, 3);

        videoLayout = new QGridLayout();
        videoLayout->setObjectName(QStringLiteral("videoLayout"));

        gridLayout->addLayout(videoLayout, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(VideoNoteForm);

        QMetaObject::connectSlotsByName(VideoNoteForm);
    } // setupUi

    void retranslateUi(QWidget *VideoNoteForm)
    {
        VideoNoteForm->setWindowTitle(QApplication::translate("VideoNoteForm", "Form", nullptr));
        openButton->setText(QApplication::translate("VideoNoteForm", "Open", nullptr));
        playButton->setText(QApplication::translate("VideoNoteForm", "Play", nullptr));
        saveButton->setText(QApplication::translate("VideoNoteForm", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoNoteForm: public Ui_VideoNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEONOTEFORM_H
