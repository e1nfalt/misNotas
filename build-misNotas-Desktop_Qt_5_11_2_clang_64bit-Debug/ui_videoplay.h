/********************************************************************************
** Form generated from reading UI file 'videoplay.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAY_H
#define UI_VIDEOPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoplay
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *videoplay)
    {
        if (videoplay->objectName().isEmpty())
            videoplay->setObjectName(QStringLiteral("videoplay"));
        videoplay->resize(435, 365);
        verticalLayout_2 = new QVBoxLayout(videoplay);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(videoplay);

        QMetaObject::connectSlotsByName(videoplay);
    } // setupUi

    void retranslateUi(QWidget *videoplay)
    {
        videoplay->setWindowTitle(QApplication::translate("videoplay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videoplay: public Ui_videoplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAY_H
