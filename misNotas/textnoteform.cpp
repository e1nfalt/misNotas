#include "textnoteform.h"
#include "ui_textnoteform.h"
#include <QTextStream>
#include <QFileDialog>

TextNoteForm::TextNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextNoteForm)
{
    ui->setupUi(this);
}

TextNoteForm::~TextNoteForm()
{
    delete ui;
}


void TextNoteForm::set_title_file_path(QString title, QString path)
{
    ui->label->setText(title);
    file_path = path;

    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString line = in.readLine();
        text = "";
        while (!line.isEmpty())
        {
            text += line;
            line = in.readLine();
        }
        file.close();
    }
    ui->plainTextEdit->setPlainText(text);
}

void TextNoteForm::on_pushButton_clicked() // save button
{
    QFile file(file_path);
    text = ui->plainTextEdit->toPlainText();
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out << text;
        file.close();
    }
}

void TextNoteForm::on_pushButton_2_clicked() // open button
{
    QString file_name = QFileDialog::getOpenFileName();
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly))
    {
        text = "";
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isEmpty())
        {
            text += line;
            line = in.readLine();
        }
        file.close();
    }
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(text);

}
