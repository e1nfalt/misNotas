#include "textnoteform.h"
#include "ui_textnoteform.h"


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

}
