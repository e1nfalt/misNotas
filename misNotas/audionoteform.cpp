#include "audionoteform.h"
#include "ui_audionoteform.h"

AudioNoteForm::AudioNoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioNoteForm)
{
    ui->setupUi(this);
    ui->rec_button->setText("rec");
    ui->play_button->setText("play");
    audioRecorder = new QAudioRecorder();
    player = new QMediaPlayer;
}

AudioNoteForm::~AudioNoteForm()
{
    delete ui;
    delete audioRecorder;
    delete player;
}

void AudioNoteForm::on_rec_button_clicked()
{


    QAudioEncoderSettings settings;
    settings.setCodec("mp3");
    settings.setSampleRate(16000);
    settings.setBitRate(32);
    settings.setQuality(QMultimedia::HighQuality);
    settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);

    audioRecorder->setEncodingSettings(settings);
    audioRecorder->setAudioInput(audioRecorder->defaultAudioInput());
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(file_path));
    audioRecorder->setContainerFormat("mp3");

    audioRecorder->record();
}

void AudioNoteForm::on_play_button_clicked()
{
    player->setMedia(QUrl::fromLocalFile(file_path));
    //player->setMedia(QUrl::fromLocalFile("/Users/epidzhx/Downloads/1530917387_05_-gods-plan.mp3"));
    player->setVolume(50);
    player->play();
}

void AudioNoteForm::set_file_path(QString path)
{
    file_path = path;
}

void AudioNoteForm::on_save_button_clicked()
{
    audioRecorder->stop();
}

void AudioNoteForm::on_open_button_clicked()
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
