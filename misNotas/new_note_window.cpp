#include "new_note_window.h"
#include "ui_new_note_window.h"
#include <QComboBox>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>

new_note_window::new_note_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_note_window)
{


    ui->setupUi(this);
    ui->comboBox->addItem("Text");
    ui->comboBox->addItem("Graphic");
    ui->comboBox->addItem("Audio");
    ui->comboBox->addItem("Video");
}

new_note_window::~new_note_window()
{
    delete ui;
}

std::string get_current_date_str()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    return std::to_string(timeinfo->tm_year+1900) + "." + std::to_string(timeinfo->tm_mon)
            + "." +  std::to_string( timeinfo->tm_mday);
}

void new_note_window::on_pushButton_clicked()
{
    QString title = ui->lineEdit->text();
    QString type = ui->comboBox->currentText();

    if (type == "Text")
    {
        unsigned long u = rand();

        QString fname = QString::fromStdString("/Users/epidzhx/Staff/misNotas/misNotas/files/" + std::to_string(u) + ".txt");
        QFile file(fname);
        if (!file.exists())
            std::cout << "Shit" << std::endl;
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

            QTextStream textStream(&file);

            textStream << title.toStdString().c_str() << "\n" << get_current_date_str().c_str();
            file.close();

            freopen("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt", "a", stdout);
            std::cout << "Text" << std::endl << fname.toStdString() << std::endl;
        }
        else std::cout << "ERROR! FILE IS NOT OPEN!" << std::endl;

        this->close();

    }
    else if (type == "Graphic")
    {

    }

    else if (type == "Audio")
    {

    }
    else if (type == "Video")
    {

    }
}
