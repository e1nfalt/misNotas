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
    void set_title_file_path(QString title, QString path);

private:
    Ui::TextNoteForm *ui;
    QString file_path;
};

#endif // TEXTNOTEFORM_H
