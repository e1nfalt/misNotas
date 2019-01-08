#include "audionoteform.h"
#include "ui_audionoteform.h"
#include <QAudioEncoderSettings>
#include <QFileDialog>
#include <QTimer>

AudioNoteForm::AudioNoteForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AudioNoteForm)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    this->setFixedSize(640, 480);
    ui->play_button->setText("Play");
    audioRecorder = new QAudioRecorder();
    player = new QMediaPlayer;
    ui->volumeControl->setValue(50);

    connect(ui->positionSlider, &QSlider::sliderMoved, this, &AudioNoteForm::setPosition);
    connect(player, &QMediaPlayer::stateChanged, this, &AudioNoteForm::mediaStateChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &AudioNoteForm::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &AudioNoteForm::durationChanged);
}

AudioNoteForm::~AudioNoteForm()
{
    delete ui;
    delete audioRecorder;
    if (player->state() == QMediaPlayer::StoppedState) {
        player->stop();
    }
    delete player;
}

void AudioNoteForm::on_play_button_clicked()
{
    if (player->state() == QMediaPlayer::StoppedState) {
        player->setMedia(QUrl::fromLocalFile(note->get_file_path()));
        player->setVolume(ui->volumeControl->value());
        player->play();
        ui->play_button->setText("Stop");
        //ui->play_button->seti
    } else {
        player->stop();
        ui->play_button->setText("Play");
    }
}

void AudioNoteForm::transfer_note(Note* n)
{
    note = dynamic_cast<AudioNote*>(n);
}

void AudioNoteForm::on_open_button_clicked()
{
    QString file_name = QFileDialog::getOpenFileName();
    note->load_data_from_file(file_name);
}

void AudioNoteForm::on_volumeControl_sliderMoved(int position)
{
    player->setVolume(position);
}

void AudioNoteForm::on_saveButton_clicked()
{
    note->save_into_file();
}

void AudioNoteForm::positionChanged(qint64 position)
{
    ui->positionSlider->setValue(position);
}

void AudioNoteForm::durationChanged(qint64 duration)
{
    ui->positionSlider->setRange(0, duration);
}

void AudioNoteForm::setPosition(int position)
{
    player->setPosition(position);
}

void AudioNoteForm::mediaStateChanged(QMediaPlayer::State state)
{
    switch(state) {
    case QMediaPlayer::PlayingState:
        ui->play_button->setText("Pause");
        break;
    default:
        ui->play_button->setText("Play");
        break;
    }
}
