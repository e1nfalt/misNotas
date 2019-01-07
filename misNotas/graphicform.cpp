#include "graphicform.h"
#include "ui_graphicform.h"

graphicform::graphicform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphicform)
{
    ui->setupUi(this);
}

graphicform::~graphicform()
{
    delete ui;
}
