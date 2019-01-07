#ifndef AUDIONOTEFORM_H
#define AUDIONOTEFORM_H

#include <QWidget>
#include <audionote.h>
#include <QAudioInput>
#include <QMediaPlayer>
#include <QAudioRecorder>
#include <QAudioProbe>
#include <QBuffer>

namespace Ui {
class AudioNoteForm;
}

class AudioNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit AudioNoteForm(QWidget *parent = nullptr);
    ~AudioNoteForm();
    void transfer_note(Note*);

private slots:

    void on_play_button_clicked();
    void on_open_button_clicked();

    void on_volumeControl_sliderMoved(int position);

private:
    Ui::AudioNoteForm *ui;
    AudioNote *note;
    QAudioInput audio_input;
    QMediaPlayer *player;
    QAudioRecorder *audioRecorder;
    QAudioProbe *audioProbe;

    QAudioFormat format;
    QBuffer output_buffer;
    QByteArray output_bytes;
    QAudioInput* audio_in;

    QFile *output_file;
};

#endif // AUDIONOTEFORM_H
