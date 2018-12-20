#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <note.h>
#include <QListWidget>
#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <fstream>
#include "new_note_window.h"

std::vector<Note*> get_notes()
{
    std::vector<Note*> notes;
    //std::ifstream file;
    freopen("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt", "r", stdin);
    std::vector<std::pair<std::string, std::string> > ar;
    std::string type, way;
    while (std::getline(std::cin, type) && std::getline(std::cin, way))
        ar.push_back(std::make_pair(type, way));

    for (auto i : ar)
    {
        freopen(i.second.c_str(), "r", stdin);
        std::string title_, cr_date, ed_date;
        std::cin >> title_;
        std::cin >> cr_date;
        std::cin >> ed_date;
        if (i.first == "Text")
        {
            std::string text_data, buf;
            while (std::getline(std::cin, buf))
                text_data += buf;
            notes.push_back(new TextNote(title_, Date(cr_date), Date(ed_date), text_data));
        }
    }
    return notes;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    std::vector<Note*> notes;
    notes = get_notes();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    new_note_window *window = new new_note_window();
    window->show();
}

//template<class T>
void MainWindow::refresh(Ui::MainWindow *ui)
{
    std::vector<Note*> notes = get_notes();
    ui->listWidget->clear();
    for (auto i : notes)
    {
        QString item = QString::fromStdString(i->get_title() + i->get_editing_date());
        ui->listWidget->addItem(item);
    }

    for (unsigned long i = 0; i < notes.size(); i++)
        ui->listWidget->item(i)->setForeground(Qt::blue);
}
