#include "videonoteform.h"
#include "ui_videonoteform.h"
#include <QAbstractSlider>
#include <QBoxLayout>
#include <QCamera>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlaylist>
#include <QPushButton>
#include <QStandardPaths>
#include <QToolButton>
#include <QVideoWidget>

VideoNoteForm::VideoNoteForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::VideoNoteForm)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    openButton = new QPushButton("Open");
    connect(openButton, &QPushButton::clicked, this, &VideoNoteForm::openFile);
    playButton = new QPushButton("Play");
    connect(playButton, &QPushButton::clicked, this, &VideoNoteForm::play);
    saveButton = new QPushButton("Save");
    connect(playButton, &QPushButton::clicked, this, &VideoNoteForm::save);
    positionSlider = new QSlider(Qt::Horizontal);
    connect(positionSlider, &QSlider::sliderMoved, this, &VideoNoteForm::setPosition);
    mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    videoWidget = new QVideoWidget;
    mediaPlayer->setVideoOutput(videoWidget);
    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, &VideoNoteForm::mediaStateChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoNoteForm::positionChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoNoteForm::durationChanged);
    QBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);
    QBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(videoWidget);
    layout->addLayout(controlLayout);
    setLayout(layout);
}

VideoNoteForm::~VideoNoteForm()
{
    delete ui;
}

void VideoNoteForm::get_note(Note* n)
{
    note = dynamic_cast<VideoNote*>(n);
    setUrl(QUrl::fromLocalFile(note->get_file_path()));
}

void VideoNoteForm::save()
{
    note->save_into_file();
}

void VideoNoteForm::setUrl(const QUrl& url)
{
    setWindowFilePath(url.isLocalFile() ? url.toLocalFile() : QString());
    mediaPlayer->setMedia(url);
}

void VideoNoteForm::play()
{
    switch (mediaPlayer->state()) {
    case QMediaPlayer::PlayingState:
        mediaPlayer->pause();
        break;
    default:
        mediaPlayer->play();
        break;
    }
}

void VideoNoteForm::openFile()
{
    QString file_name = QFileDialog::getOpenFileName();
    note->load_data_from_file(file_name);
    setUrl(QUrl::fromLocalFile(file_name));
}

void VideoNoteForm::mediaStateChanged(QMediaPlayer::State state)
{
    switch (state) {
    case QMediaPlayer::PlayingState:
        playButton->setText("Pause");
        break;
    default:
        playButton->setText("Play");
        break;
    }
}

void VideoNoteForm::positionChanged(qint64 position)
{
    positionSlider->setValue(position);
}

void VideoNoteForm::durationChanged(qint64 duration)
{
    positionSlider->setRange(0, duration);
}

void VideoNoteForm::setPosition(int position)
{
    mediaPlayer->setPosition(position);
}
