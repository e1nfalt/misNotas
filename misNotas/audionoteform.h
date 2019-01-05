#ifndef AUDIONOTEFORM_H
#define AUDIONOTEFORM_H

#include <QWidget>
#include <QAudioInput>
#include <QMediaPlayer>
#include <QAudioRecorder>
#include <QAudioProbe>
#include <QAudioEncoderSettings>
#include <QFileDialog>
#include <audionote.h>

namespace Ui {
class AudioNoteForm;
}

class AudioNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit AudioNoteForm(QWidget *parent = nullptr);
    ~AudioNoteForm();
    void set_file_path(QString path);

private slots:

    void on_rec_button_clicked();
    void on_play_button_clicked();
    void on_save_button_clicked();
    void on_open_button_clicked();

private:
    Ui::AudioNoteForm *ui;
    QAudioInput audio_input;
    QMediaPlayer *player;
    QString file_path;
    QAudioRecorder *audioRecorder;
    QAudioProbe *audioProbe;
};

#endif // AUDIONOTEFORM_H
