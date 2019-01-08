#include "new_note_window.h"
#include "ui_new_note_window.h"
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <iostream>
//#include "mainwindow.h"
#include "date.h"
#include "file_formats.h"

new_note_window::new_note_window(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::new_note_window)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Text");
    ui->comboBox->addItem("Graphic");
    ui->comboBox->addItem("Audio");
    ui->comboBox->addItem("Video");

    ui->new_title->setText("Input title...");
    ui->new_tags_list->setText("Input tags list throught @...");
    QPalette pal;
    pal.setColor(QPalette::Text, Qt::gray);
    ui->new_title->setPalette(pal);
    ui->new_tags_list->setPalette(pal);
}

new_note_window::~new_note_window()
{
    delete ui;
}

void new_note_window::on_createButton_clicked()
{
    QString type = ui->comboBox->currentText();
    QString title = ui->new_title->text();
    QString tags_list = ui->new_tags_list->text();
    if (tags_list.isEmpty())
        tags_list = " ";
    int new_file_name = rand();
    QString fname = "";

    if (type == "Text")
        fname = QString::fromStdString("/Users/epidzhx/Staff/misNotas/misNotas/files/Text" + std::to_string(new_file_name) + "." + text_format.toStdString());
    else if (type == "Graphic")
        fname = QString::fromStdString("/Users/epidzhx/Staff/misNotas/misNotas/files/Graphic" + std::to_string(new_file_name) + "." + graphic_format.toStdString());
    else if (type == "Audio")
        fname = QString::fromStdString("/Users/epidzhx/Staff/misNotas/misNotas/files/Audio" + std::to_string(new_file_name) + "." + audio_format.toStdString());
    else if (type == "Video")
        fname = QString::fromStdString("/Users/epidzhx/Staff/misNotas/misNotas/files/Video" + std::to_string(new_file_name) + "." + video_format.toStdString());

    QFile file(fname);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.close();
        QFile file2("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
        if (file2.open(QIODevice::Append)) {
            QTextStream textStream2(&file2);

            textStream2 << new_file_name << "\n"
                        << type << "\n"
                        << title << "\n"
                        << Date::get_current_date_in_QString() << "\n"
                        << Date::get_current_date_in_QString() << "\n"
                        << tags_list << "\n"
                        << fname << "\n";
            file2.close();
        }
    }

    this->close();
}
