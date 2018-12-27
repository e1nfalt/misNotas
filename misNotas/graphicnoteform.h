#ifndef GRAPHICNOTEFORM_H
#define GRAPHICNOTEFORM_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

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
    QGraphicsScene scene;
    QGraphicsView view;
};

#endif // GRAPHICNOTEFORM_H
