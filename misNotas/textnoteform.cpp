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
