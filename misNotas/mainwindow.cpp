#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
//#include <string>
#include <fstream>
#include "new_note_window.h"
#include "note.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    notes = get_notes();
    MainWindow::on_pushButton_2_clicked();
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

void MainWindow::on_pushButton_clicked() // add
{
    new_note_window *window = new new_note_window();
    window->show();
}

void MainWindow::on_pushButton_2_clicked() // refresh
{
    notes = get_notes();
    ui->listWidget->clear();
    for (auto i : notes)
    {
        ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                "; Title:" + i->get_title());
    }
}

void MainWindow::on_pushButton_4_clicked() // title_find
{
    QString title = ui->lineEdit->text();
    //std::vector<QString> ar;
    ui->listWidget->clear();
    for (auto i : notes)
    {
        if (i->get_title() == title)
            ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                    "; Title:" + i->get_title());
    }
}

void MainWindow::on_pushButton_5_clicked() // filter_date
{
    QString action = ui->comboBox->currentText();
    QString check = ui->lineEdit_2->text();
    Date checked_date(check);
    ui->listWidget->clear();
    if (action == ">")
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() > checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
    else if (action == "<")
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() < checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
    else if (action == ">=")
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() >= checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
    else if (action == "<=")
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() <= checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
    else if (action == "==")
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() == checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
    else
    {
        for (auto i : notes)
        {
            if (i->get_cr_date() != checked_date)
                ui->listWidget->addItem("ID: " + QString::number(i->get_id()) + "; Type: " + i->get_type() +
                                        "; Title:" + i->get_title());
        }
    }
}

void MainWindow::on_pushButton_3_clicked() // edit
{

}
