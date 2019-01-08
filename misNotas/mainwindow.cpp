#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QFile>
#include <QListWidget>
#include <QMessageBox>
#include <QTextStream>
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(640, 480);
    ui->comboBox->addItem(">");
    ui->comboBox->addItem("<");
    ui->comboBox->addItem(">=");
    ui->comboBox->addItem("<=");
    ui->comboBox->addItem("==");
    ui->comboBox->addItem("!=");
    QPalette pal = palette();
    pal.setColor(QPalette::Text, Qt::gray);
    ui->listWidget->setPalette(pal);
    ui->findLine->setPalette(pal);
    ui->filterLine->setPalette(pal);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::edit);
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::refresh);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::filter);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::find);
    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
    notes.clear();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    write_note_list();
}

void MainWindow::write_note_list()
{
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::WriteOnly)) {
        for (auto i : notes) {
            QTextStream out(&file);
            out << i->get_id() << "\n"
                << i->get_type() << "\n"
                << i->get_title() << "\n"
                << i->get_created_date() << "\n"
                << i->get_editing_date() << "\n"
                << i->get_tags() << "\n"
                << i->get_file_path() << "\n";
        }
        file.close();
    }
}

void delete_n(QString& s)
{
    s.remove(s.size() - 1, 1);
}
void MainWindow::get_notes()
{
    notes.clear();
    QFile file("/Users/epidzhx/Staff/misNotas/misNotas/files/notes_list.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString id = in.readLine();
        while (!id.isEmpty()) {
            if (id.endsWith("\n"))
                delete_n(id);
            QString type = in.readLine();
            if (type.endsWith("\n"))
                delete_n(type);
            QString title = in.readLine();
            if (title.endsWith("\n"))
                delete_n(title);
            QString cr_date = in.readLine();
            if (cr_date.endsWith("\n"))
                delete_n(cr_date);
            QString ed_date = in.readLine();
            if (ed_date.endsWith("\n"))
                delete_n(ed_date);
            QStringList tags_list = in.readLine().split("@");
            for (int j = 0; j < tags_list.size(); j++) {
                if (tags_list.at(j).isEmpty())
                    tags_list.removeAt(j);
            }
            QString data_file_path = in.readLine();
            if (data_file_path.endsWith("\n"))
                delete_n(data_file_path);
            if (type == "Text")
                notes.push_back(new TextNote(id, title, Date(cr_date), Date(ed_date), tags_list, data_file_path));
            else if (type == "Graphic")
                notes.push_back(new GraphicNote(id, title, Date(cr_date), Date(ed_date), tags_list, data_file_path));
            else if (type == "Audio")
                notes.push_back(new AudioNote(id, title, Date(cr_date), Date(ed_date), tags_list, data_file_path));
            else if (type == "Video")
                notes.push_back(new VideoNote(id, title, Date(cr_date), Date(ed_date), tags_list, data_file_path));
            id = in.readLine();
        }
    }
    file.close();
}

void MainWindow::refresh()
{
    get_notes();
    ui->listWidget->clear();
    for (auto i : notes)
        ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
}

void MainWindow::filter()
{
    QString action = ui->comboBox->currentText();
    QString check = ui->filterLine->text();
    Date checked_date(check);
    ui->listWidget->clear();
    if (action == ">") {
        for (auto i : notes)
            if (i->get_cr_date() > checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    } else if (action == "<") {
        for (auto i : notes)
            if (i->get_cr_date() < checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    } else if (action == ">=") {
        for (auto i : notes)
            if (i->get_cr_date() >= checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    } else if (action == "<=") {
        for (auto i : notes)
            if (i->get_cr_date() <= checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    } else if (action == "==") {
        for (auto i : notes)
            if (i->get_cr_date() == checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    } else {
        for (auto i : notes)
            if (i->get_cr_date() != checked_date)
                ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    }
}

void MainWindow::find()
{
    QString title = ui->findLine->text();
    ui->listWidget->clear();
    for (auto i : notes) {
        if (i->get_title() == title)
            ui->listWidget->addItem("ID: " + i->get_id() + "; Type: " + i->get_type() + "; Title:" + i->get_title());
    }
}

void MainWindow::edit()
{
    QStringList item = ui->listWidget->currentItem()->text().split(" ");
    QString id = item[1].remove(item[1].size() - 1, 1);
    QString type = item[3].remove(item[3].size() - 1, 1);
    Note* curr;
    for (auto i : notes) {
        if (i->get_id() == id) {
            curr = i;
            break;
        }
    }
    if (!curr)
        return;
    if (type == "Text") {
        TextNoteForm* window = new TextNoteForm();
        window->transfer_note(curr);
        window->show();
    } else if (type == "Audio") {
        AudioNoteForm* window = new AudioNoteForm();
        window->transfer_note(curr);
        window->show();
    } else if (type == "Graphic") {
        graphicform* window = new graphicform();
        window->get_note(curr);
        window->show();
    } else if (type == "Video") {
        VideoNoteForm* window = new VideoNoteForm();
        window->get_note(curr);
        window->show();
    }
}

void MainWindow::add()
{
    new_note_window* window = new new_note_window();
    window->show();
}
