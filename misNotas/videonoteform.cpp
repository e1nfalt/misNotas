#include "videonoteform.h"
#include "ui_videonoteform.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVideoWidget>
#include <QCamera>
#include <QMediaPlaylist>

VideoNoteForm::VideoNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoNoteForm)
{
    ui->setupUi(this);
//    QGraphicsView *view = new QGraphicsView();
//    QGraphicsScene *scene = new QGraphicsScene();
//    QVideoWidget *widget = new QVideoWidget();
//    view->setScene(scene);
//    scene->addWidget(widget);
//    view->show();

//    QCamera *camera;
//    if(QCamera::availableDevices().count() > 0) {
//        camera = new QCamera();
//        camera->setViewfinder(widget);
//        camera->start();
//    }
    player = new QMediaPlayer();

}

VideoNoteForm::~VideoNoteForm()
{
    delete ui;
}


void VideoNoteForm::set_file_path(QString path)
{
    file_path = path;
}

void VideoNoteForm::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName();
    QFile file(file_name);
    QByteArray arr;
    if (file.open(QIODevice::ReadOnly))
    {
        arr = file.readAll();
        file.close();
    }
    QFile file2(file_path);
    if (file2.open(QIODevice::WriteOnly))
    {
        file2.write(arr);
        file2.close();
    }
}

void VideoNoteForm::on_pushButton_clicked()
{
//    player->setMedia(QUrl::fromLocalFile(file_path));
//    //player->setMedia(QUrl::fromLocalFile("/Users/epidzhx/Downloads/1530917387_05_-gods-plan.mp3"));
//    player->setVolume(50);
//    player->play();
    QMediaPlaylist* playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl::fromLocalFile((file_path)));
    //playlist->addMedia(QUrl::fromLocalFile(file_path));

    QVideoWidget *videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();
}
