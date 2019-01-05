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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoNoteForm
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *VideoNoteForm)
    {
        if (VideoNoteForm->objectName().isEmpty())
            VideoNoteForm->setObjectName(QStringLiteral("VideoNoteForm"));
        VideoNoteForm->resize(400, 300);
        graphicsView = new QGraphicsView(VideoNoteForm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(50, 50, 256, 192));
        pushButton = new QPushButton(VideoNoteForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 260, 80, 24));
        pushButton_2 = new QPushButton(VideoNoteForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 260, 80, 24));

        retranslateUi(VideoNoteForm);

        QMetaObject::connectSlotsByName(VideoNoteForm);
    } // setupUi

    void retranslateUi(QWidget *VideoNoteForm)
    {
        VideoNoteForm->setWindowTitle(QApplication::translate("VideoNoteForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("VideoNoteForm", "play", nullptr));
        pushButton_2->setText(QApplication::translate("VideoNoteForm", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoNoteForm: public Ui_VideoNoteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEONOTEFORM_H
