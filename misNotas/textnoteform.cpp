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
    QString text = ui->plainTextEdit->toPlainText();
    note->set_text(text);
    note->save_into_file();
}

void TextNoteForm::on_openButton_clicked()
{
    QString text = "";
    QString file_name = QFileDialog::getOpenFileName();
    note->load_data_from_file(file_name);
    text = note->get_text();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(text);
}
