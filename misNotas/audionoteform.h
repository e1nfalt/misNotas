#ifndef AUDIONOTEFORM_H
#define AUDIONOTEFORM_H

#include <audionote.h>
#include <QMediaPlayer>
#include <QWidget>
#include <QFileDialog>

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
    void play();
    void open();
    void save();
    void volume_slider_move(int);
    void positionChanged(qint64);
    void durationChanged(qint64);
    void setPosition(int);
    void mediaStateChanged(QMediaPlayer::State);
private:
    Ui::AudioNoteForm* ui;
    AudioNote* note;
    QMediaPlayer* player;
};

#endif // AUDIONOTEFORM_H
