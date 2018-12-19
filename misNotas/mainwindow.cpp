#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <note.h>
#include <QListWidget>

std::vector<Note> get_notes()
{
    std::vector<Note> notes;
    return notes;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    std::vector<Note> notes;
    notes = get_notes();
    ui->setupUi(this);
    ui->listWidget->addItem("Sparta");
}

MainWindow::~MainWindow()
{
    delete ui;
}
