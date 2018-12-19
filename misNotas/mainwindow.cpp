#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <note.h>
#include <QListWidget>
#include <iostream>
#include <string>
#include <fstream>

std::vector<Note*> get_notes()
{
    std::vector<Note*> notes;
    std::ifstream file;
    file.open(":/rec/files/notes_list.txt");
    if (!file)
        std::cout << "ERROR: file not open!" << std::endl;
    else
    {
        std::vector<std::pair<std::string, std::string> > ar;
        int n;
        file >> n;
        notes.assign(n, NULL);
        while (n-- > 0)
        {
            std::string type, way;
            getline(file, type);
            getline(file, way);
            ar.push_back(std::make_pair(type, way));
        }

        file.close();

        int count = 0;
        for (auto i : ar)
        {
            file.open(i.second);
            std::string title_, cr_date, ed_date;
            std::getline(file, title_);
            std::getline(file, cr_date);
            std::getline(file, ed_date);
            if (i.first == "Text")
            {
                std::string text_data, buf;
                while (getline(file, buf))
                    text_data += buf;
                notes[count++] = new TextNote(title_, Date(cr_date), Date(ed_date), text_data);
            }

//            if (i.first == "Text")
//            {
//                std::string text_data, buf;
//                while (getline(file, buf))
//                    text_data += buf;
//                notes[count++] = new TextNote(title_, Date(cr_date), Date(ed_date), text_data);
//            }
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
    ui->listWidget->addItem("Sparta");
}

MainWindow::~MainWindow()
{
    delete ui;
}
