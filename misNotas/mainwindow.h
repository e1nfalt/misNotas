#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "audionoteform.h"
#include "graphicform.h"
#include "new_note_window.h"
#include "textnoteform.h"
#include "videonoteform.h"
#include <note.h>
#include <QCloseEvent>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void refresh();
    void add();
    void filter();
    void find();
    void edit();
    void closeEvent(QCloseEvent*);
private:
    Ui::MainWindow* ui;
    std::vector<Note*> notes;
    void get_notes();
    void write_note_list();
};

#endif // MAINWINDOW_H
