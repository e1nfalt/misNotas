#ifndef VIDEONOTEFORM_H
#define VIDEONOTEFORM_H

#include <QWidget>

namespace Ui {
class VideoNoteForm;
}

class VideoNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoNoteForm(QWidget *parent = nullptr);
    ~VideoNoteForm();

private:
    Ui::VideoNoteForm *ui;
};

#endif // VIDEONOTEFORM_H
