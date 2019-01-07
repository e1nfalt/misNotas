#include "textnoteform.h"
#include "ui_textnoteform.h"
#include <QFileDialog>
#include <QTextStream>

TextNoteForm::TextNoteForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TextNoteForm)
{
    ui->setupUi(this);
}

TextNoteForm::~TextNoteForm()
{
    delete ui;
}

void TextNoteForm::transfer_note(Note* n)
{
    note = dynamic_cast<TextNote*>(n);
    ui->label->setText(note->get_title());
    QFile file(note->get_file_path());
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line = in.readLine();
        QString text = "";
        while (!line.isEmpty()) {
            text += line + "\n";
            line = in.readLine();
        }
        file.close();
        note->set_text(text);
    }
    ui->plainTextEdit->setPlainText(note->get_text());
}

void TextNoteForm::on_saveButton_clicked()
{
    QFile file(note->get_file_path());
    QString text = ui->plainTextEdit->toPlainText();
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
    note->set_text(text);
}

void TextNoteForm::on_openButton_clicked()
{
    QString text = "";
    QString file_name = QFileDialog::getOpenFileName();
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isEmpty()) {
            text += line;
            line = in.readLine();
        }
        file.close();
    }
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(text);
}
