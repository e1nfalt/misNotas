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
    : QWidget(parent), ui(new Ui::VideoNoteForm)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    openButton = ui->openButton;
    connect(openButton, &QPushButton::clicked, this, &VideoNoteForm::openFile);
    playButton = ui->playButton;
    connect(playButton, &QPushButton::clicked, this, &VideoNoteForm::play);
    saveButton = ui->saveButton;
    connect(playButton, &QPushButton::clicked, this, &VideoNoteForm::save);
    positionSlider = ui->timeSlider;
    connect(positionSlider, &QSlider::sliderMoved, this, &VideoNoteForm::setPosition);
    mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    videoWidget = new QVideoWidget;
    ui->videoLayout->addWidget(videoWidget);
    mediaPlayer->setVideoOutput(videoWidget);
    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, &VideoNoteForm::mediaStateChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoNoteForm::positionChanged);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoNoteForm::durationChanged);
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
    switch (mediaPlayer->state())
    {
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
