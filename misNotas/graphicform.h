#ifndef GRAPHICFORM_H
#define GRAPHICFORM_H

#include <QMainWindow>
#include <graphicnote.h>

namespace Ui {
class graphicform;
}

class graphicform : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphicform(QWidget *parent = nullptr);
    ~graphicform();

private:
    Ui::graphicform *ui;
};

#endif // GRAPHICFORM_H

//#ifndef GRAPHICNOTEFORM_H
//#define GRAPHICNOTEFORM_H

//#include <QWidget>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <scribblearea.h>
//#include <QTimer>
//#include <QResizeEvent>
//#include <QMenu>

//namespace Ui {
//class GraphicNoteForm;
//}

//class GraphicNoteForm : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit GraphicNoteForm(QWidget *parent = nullptr);
//    ~GraphicNoteForm();
//    void set_file_path(QString);

//private:
//    Ui::GraphicNoteForm *ui;
//    QString file_path;

//    void slotTimer();
//    void on_pushButton_clicked();
//    void on_pushButton_2_clicked();
//    void createActions();
//    void createMenus();
//    bool maybeSave();
//    bool saveFile(const QByteArray &fileFormat);

//    ScribbleArea *scribbleArea;

//    QMenu *saveAsMenu;
//    QMenu *fileMenu;
//    QMenu *optionMenu;
//    QMenu *helpMenu;

//    QAction *openAct;
//    QList<QAction *> saveAsActs;
//    QAction *exitAct;
//    QAction *penColorAct;
//    QAction *penWidthAct;
//    QAction *printAct;
//    QAction *clearScreenAct;
//    QAction *aboutAct;
//    QAction *aboutQtAct;

//private slots:


//    void open();
//    void save();
//    void penColor();
//    void penWidth();
//    void about();
//};

//#endif // GRAPHICNOTEFORM_H
