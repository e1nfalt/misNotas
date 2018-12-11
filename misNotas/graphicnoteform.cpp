#include "graphicnoteform.h"
#include "ui_graphicnoteform.h"

GraphicNoteForm::GraphicNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicNoteForm)
{
    ui->setupUi(this);
}

GraphicNoteForm::~GraphicNoteForm()
{
    delete ui;
}
