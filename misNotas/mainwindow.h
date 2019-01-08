#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "textnoteform.h"
#include "audionoteform.h"
#include "videonoteform.h"
#include "graphicform.h"
#include "new_note_window.h"
#include <note.h>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void refresh();
    void add();
    void filter();
    void find();
    void edit();
    void closeEvent(QCloseEvent*);

private:
    Ui::MainWindow *ui;
    std::vector<Note*> notes;
    void get_notes();
    void write_note_list();
};

#endif // MAINWINDOW_H
