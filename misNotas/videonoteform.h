#ifndef VIDEONOTEFORM_H
#define VIDEONOTEFORM_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <videonote.h>

namespace Ui {
class VideoNoteForm;
}

class VideoNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoNoteForm(QWidget *parent = nullptr);
    ~VideoNoteForm();
    void set_file_path(QString);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::VideoNoteForm *ui;
    //QCamera camera;
    QString file_path;
    QMediaPlayer *player;
};

#endif // VIDEONOTEFORM_H
