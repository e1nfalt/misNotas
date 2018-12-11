#ifndef AUDIONOTEFORM_H
#define AUDIONOTEFORM_H

#include <QWidget>

namespace Ui {
class AudioNoteForm;
}

class AudioNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit AudioNoteForm(QWidget *parent = nullptr);
    ~AudioNoteForm();

private:
    Ui::AudioNoteForm *ui;
};

#endif // AUDIONOTEFORM_H
