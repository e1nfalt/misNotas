#include "videonoteform.h"
#include "ui_videonoteform.h"

VideoNoteForm::VideoNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoNoteForm)
{
    ui->setupUi(this);
}

VideoNoteForm::~VideoNoteForm()
{
    delete ui;
}
