#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "textnoteform.h"
#include "audionoteform.h"
#include "videonoteform.h"
#include "graphicform.h"
#include "new_note_window.h"
#include <note.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //static QString curr_file_name;


private slots:

    void on_refreshButton_clicked();

    void on_filterButton_clicked();

    void on_findButton_clicked();

    void on_editButton_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Note*> notes;
    void get_notes();
    void write_note_list();
};

#endif // MAINWINDOW_H
