#ifndef NEW_NOTE_WINDOW_H
#define NEW_NOTE_WINDOW_H

#include <QWidget>

namespace Ui {
class new_note_window;
}

class new_note_window : public QWidget
{
    Q_OBJECT

public:
    explicit new_note_window(QWidget *parent = nullptr);
    ~new_note_window();

private slots:

    void on_createButton_clicked();

private:
    Ui::new_note_window *ui;
//    QString text_format = "txt";
//    QString audio_format = "wav";
//    QString graphic_format = "png";
//    QString video_format = "mp4";
};

#endif // NEW_NOTE_WINDOW_H
