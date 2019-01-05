#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    get_notes();
    MainWindow::on_refreshButton_clicked();
    ui->comboBox->addItem(">");
    ui->comboBox->addItem("<");
    ui->comboBox->addItem(">=");
    ui->comboBox->addItem("<=");
    ui->comboBox->addItem("==");
    ui->comboBox->addItem("!=");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write_note_list()
{
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::WriteOnly))
    {
        for (auto i : notes)
        {
            QTextStream out(&file);
            out << i->get_type() << "\n" << i->get_title() << "\n" << i->get_created_date()
                << "\n" << i->get_editing_date() << "\n" << i->get_tags() << "\n"
                << i->get_file_path() << "\n";
        }
        file.close();
    }
}

void MainWindow::get_notes()
{
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        QString s = in.readLine();
        while (!s.isEmpty())
        {
            if (s.endsWith("\n"))
                s.remove(s.size() - 1, 1);
            int id = s.toInt();
            QString type = in.readLine();
            QString title = in.readLine();
            QString cr_date = in.readLine();
            QString ed_date = in.readLine();
            QStringList tags_list = in.readLine().split("@");
            QString data_file_path = in.readLine();
            if (type == "Text")
                notes.push_back(new TextNote(id, title, cr_date, ed_date, tags_list, data_file_path));
            else if (type == "Graphic")
                notes.push_back(new GraphicNote(id, title, cr_date, ed_date, tags_list, data_file_path));
            else if (type == "Audio")
                notes.push_back(new AudioNote(id, title, cr_date, ed_date, tags_list, data_file_path));
            else if (type == "Video")
                notes.push_back(new VideoNote(id, title, cr_date, ed_date, tags_list, data_file_path));

            s = in.readLine();
        }

    }
    file.close();
}

void MainWindow::on_refreshButton_clicked()
{
    get_notes();
    ui->listWidget->clear();
    for (auto i : notes)
        ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                "; Title:" + i->get_title());
}

void MainWindow::on_filterButton_clicked()
{
    QString action = ui->comboBox->currentText();
    QString check = ui->lineEdit_2->text();
    Date checked_date(check);
    ui->listWidget->clear();
    if (action == ">")
    {
        for (auto i : notes)
            if (i->get_cr_date() > checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
    else if (action == "<")
    {
        for (auto i : notes)
            if (i->get_cr_date() < checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
    else if (action == ">=")
    {
        for (auto i : notes)
            if (i->get_cr_date() >= checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
    else if (action == "<=")
    {
        for (auto i : notes)
            if (i->get_cr_date() <= checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
    else if (action == "==")
    {
        for (auto i : notes)
            if (i->get_cr_date() == checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
    else
    {
        for (auto i : notes)
            if (i->get_cr_date() != checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
    }
}

void MainWindow::on_findButton_clicked()
{
    QString title = ui->lineEdit->text();
    ui->listWidget->clear();
    for (auto i : notes)
    {
        if (i->get_title() == title)
            ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                    "; Title:" + i->get_title());
    }
}

void MainWindow::on_editButton_clicked()
{
    QStringList item = ui->listWidget->currentItem()->text().split(" ");
    QString id = item[1].remove(item[1].size() - 1, 1);
    QString type = item[3].remove(item[3].size() - 1, 1);
    Note *curr;
    for (auto i : notes)
    {
        if (i->get_id() == id.toInt())
        {
            curr = i;
            break;
        }
    }
    if (!curr) return;

    if (type == "Text")
    {
        TextNoteForm *window = new TextNoteForm();
        window->transfer_note(curr);
        window->show();
    }
    else if (type == "Audio")
    {
        AudioNoteForm *window = new AudioNoteForm();
        window->set_file_path(curr->get_file_path());
        window->show();
    }
    else if (type == "Graphic")
    {
//        GraphicNoteForm *window = new GraphicNoteForm();
//        window->set_file_path(curr->get_file_path());
//        window->show();
    }
    else if (type == "Video")
    {
        VideoNoteForm *window = new VideoNoteForm();
        window->set_file_path(curr->get_file_path());
        window->show();
    }
}

void MainWindow::on_addButton_clicked()
{
    new_note_window *window = new new_note_window();
    window->show();
}
