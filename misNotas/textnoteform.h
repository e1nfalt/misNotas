#ifndef TEXTNOTEFORM_H
#define TEXTNOTEFORM_H

#include <QWidget>
#include <textnote.h>

namespace Ui {
class TextNoteForm;
}

class TextNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit TextNoteForm(QWidget *parent = nullptr);
    ~TextNoteForm();
    void transfer_note(Note*);

private slots:

    void on_saveButton_clicked();
    void on_openButton_clicked();

private:
    Ui::TextNoteForm *ui;
    TextNote *note;
};

#endif // TEXTNOTEFORM_H
