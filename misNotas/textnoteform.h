#ifndef TEXTNOTEFORM_H
#define TEXTNOTEFORM_H

#include <QWidget>

namespace Ui {
class TextNoteForm;
}

class TextNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit TextNoteForm(QWidget *parent = nullptr);
    ~TextNoteForm();

private:
    Ui::TextNoteForm *ui;
};

#endif // TEXTNOTEFORM_H
