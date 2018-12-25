#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <note.h>
#include <QListWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
//#include <string>
#include <fstream>
#include "new_note_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    std::vector<Note*> notes;
    notes = get_notes();
    MainWindow::on_pushButton_2_clicked();

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

void MainWindow::on_pushButton_2_clicked()
{
    std::vector<Note*> notes = get_notes();
    ui->listWidget->clear();
    for (auto i : notes)
    {
        ui->listWidget->addItem("Type: " + i->get_type() +
                                "; Title:" + i->get_title() +
                                "; Editind date:" + i->get_editing_date());
    }
}
