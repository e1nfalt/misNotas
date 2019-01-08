#ifndef AUDIONOTEFORM_H
#define AUDIONOTEFORM_H

#include <QAudioInput>
#include <QMediaPlayer>
#include <QWidget>
#include <audionote.h>

namespace Ui {
class AudioNoteForm;
}

class AudioNoteForm : public QWidget {
    Q_OBJECT
public:
    explicit AudioNoteForm(QWidget* parent = nullptr);
    ~AudioNoteForm();
    void transfer_note(Note*);
private slots:
    void on_play_button_clicked();
    void on_open_button_clicked();
    void on_volumeControl_sliderMoved(int position);
    void on_saveButton_clicked();
    void positionChanged(qint64);
    void durationChanged(qint64);
    void setPosition(int);
    void mediaStateChanged(QMediaPlayer::State);

private:
    Ui::AudioNoteForm* ui;
    AudioNote* note;
    QMediaPlayer* player;
    QFile* output_file;
};

#endif // AUDIONOTEFORM_H
