#ifndef TEXTNOTEFORM_H
#define TEXTNOTEFORM_H

#include <textnote.h>
#include <QWidget>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class TextNoteForm;
}

class TextNoteForm : public QWidget {
    Q_OBJECT

public:
    explicit TextNoteForm(QWidget* parent = nullptr);
    ~TextNoteForm();
    void transfer_note(Note*);
private slots:
    void save();
    void open();
private:
    Ui::TextNoteForm* ui;
    TextNote* note;
};

#endif // TEXTNOTEFORM_H
