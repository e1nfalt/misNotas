#ifndef GRAPHICNOTEFORM_H
#define GRAPHICNOTEFORM_H

#include <QWidget>

namespace Ui {
class GraphicNoteForm;
}

class GraphicNoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicNoteForm(QWidget *parent = nullptr);
    ~GraphicNoteForm();

private:
    Ui::GraphicNoteForm *ui;
};

#endif // GRAPHICNOTEFORM_H
