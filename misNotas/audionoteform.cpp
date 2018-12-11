#include "audionoteform.h"
#include "ui_audionoteform.h"

AudioNoteForm::AudioNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioNoteForm)
{
    ui->setupUi(this);
}

AudioNoteForm::~AudioNoteForm()
{
    delete ui;
}
