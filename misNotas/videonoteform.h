#ifndef VIDEONOTEFORM_H
#define VIDEONOTEFORM_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <videonote.h>
#include <QPushButton>
#include <QSlider>

namespace Ui {
class VideoNoteForm;
}

class VideoNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoNoteForm(QWidget *parent = nullptr);
    ~VideoNoteForm();
    void get_note(Note*);
    void setUrl(const QUrl &url);

private slots:

    void openFile();
    void play();
    void save();

    void mediaStateChanged(QMediaPlayer::State);

    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);

private:
    Ui::VideoNoteForm *ui;
    VideoNote *note;

    QMediaPlayer* mediaPlayer;
    QVideoWidget *videoWidget;
    QPushButton *playButton;
    QPushButton *openButton;
    QPushButton *saveButton;
    QSlider *positionSlider;
};

#endif // VIDEONOTEFORM_H
