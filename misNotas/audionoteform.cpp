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
    ui->play_button->setText("Play");
    audioRecorder = new QAudioRecorder();
    player = new QMediaPlayer;
    ui->volumeControl->setValue(50);
    QStringList codecList = this->audioRecorder->supportedAudioCodecs();
    for (auto i : codecList)
        std::cout << i.toStdString() << std::endl;
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
