#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <note.h>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    Note *notes_list;
    //set_tags(ui);


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<Note> get_notes()
{

}
