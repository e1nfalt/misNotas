#include "graphicform.h"
#include "ui_graphicform.h"

graphicform::graphicform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphicform)
{
    ui->setupUi(this);
}

graphicform::~graphicform()
{
    delete ui;
}

//#include "graphicform.h"
//#include "ui_graphicnoteform.h"
//#include <QSvgGenerator>
//#include <QFileDialog>
//#include <QImage>
//#include <QGraphicsPixmapItem>
//#include <QImageWriter>
//#include <QInputDialog>
//#include <QColorDialog>
//#include <QMessageBox>

//GraphicNoteForm::GraphicNoteForm(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::GraphicNoteForm)
//{
//    ui->setupUi(this);
//    scribbleArea = new ScribbleArea();
//    //ui->setCentralWidget(scribbleArea);
//    //ui->setCentral

//    createActions();
//    createMenus();

//    setWindowTitle(tr("Scribble"));
//    resize(500, 500);
//}

//GraphicNoteForm::~GraphicNoteForm()
//{
//    delete ui;
//}

//void GraphicNoteForm::on_pushButton_clicked() // save
//{

//}

//void GraphicNoteForm::set_file_path(QString file_name)
//{
//    file_path = file_name;
//}

//void GraphicNoteForm::on_pushButton_2_clicked() // open
//{

//}

////void GraphicNoteForm::closeEvent(QCloseEvent *event)
//// {
////     if (maybeSave()) {
////         event->accept();
////     } else {
////         event->ignore();
////     }
//// }

//void GraphicNoteForm::open()
// {
//     if (maybeSave()) {
//         QString fileName = QFileDialog::getOpenFileName(this,
//                                    tr("Open File"), QDir::currentPath());
//         if (!fileName.isEmpty())
//             scribbleArea->openImage(fileName);
//     }
// }

//void GraphicNoteForm::save()
// {
//     QAction *action = qobject_cast<QAction *>(sender());
//     QByteArray fileFormat = action->data().toByteArray();
//     saveFile(fileFormat);
// }

//void GraphicNoteForm::penColor()
// {
//     QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
//     if (newColor.isValid())
//         scribbleArea->setPenColor(newColor);
// }

//void GraphicNoteForm::penWidth()
// {
//     bool ok;
//     int newWidth = QInputDialog::getInt(this, tr("Scribble"),
//                                             tr("Select pen width:"),
//                                             scribbleArea->penWidth(),
//                                             1, 50, 1, &ok);
//     if (ok)
//         scribbleArea->setPenWidth(newWidth);
// }

//void GraphicNoteForm::createActions()
// {
//     openAct = new QAction(tr("&Open..."), this);
//     openAct->setShortcuts(QKeySequence::Open);
//     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

//     foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
//         QString text = tr("%1...").arg(QString(format).toUpper());

//         QAction *action = new QAction(text, this);
//         action->setData(format);
//         connect(action, SIGNAL(triggered()), this, SLOT(save()));
//         saveAsActs.append(action);
//     }

//     printAct = new QAction(tr("&Print..."), this);
//     connect(printAct, SIGNAL(triggered()), scribbleArea, SLOT(print()));

//     exitAct = new QAction(tr("E&xit"), this);
//     exitAct->setShortcuts(QKeySequence::Quit);
//     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

//     penColorAct = new QAction(tr("&Pen Color..."), this);
//     connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

//     penWidthAct = new QAction(tr("Pen &Width..."), this);
//     connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

//     clearScreenAct = new QAction(tr("&Clear Screen"), this);
//     clearScreenAct->setShortcut(tr("Ctrl+L"));
//     connect(clearScreenAct, SIGNAL(triggered()),
//             scribbleArea, SLOT(clearImage()));

//     aboutAct = new QAction(tr("&About"), this);
//     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

//     aboutQtAct = new QAction(tr("About &Qt"), this);
//     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
// }

//void GraphicNoteForm::createMenus()
// {
//     saveAsMenu = new QMenu(tr("&Save As"), this);
//     foreach (QAction *action, saveAsActs)
//         saveAsMenu->addAction(action);

//     fileMenu = new QMenu(tr("&File"), this);
//     fileMenu->addAction(openAct);
//     fileMenu->addMenu(saveAsMenu);
//     fileMenu->addAction(printAct);
//     fileMenu->addSeparator();
//     fileMenu->addAction(exitAct);

//     optionMenu = new QMenu(tr("&Options"), this);
//     optionMenu->addAction(penColorAct);
//     optionMenu->addAction(penWidthAct);
//     optionMenu->addSeparator();
//     optionMenu->addAction(clearScreenAct);

//     helpMenu = new QMenu(tr("&Help"), this);
//     helpMenu->addAction(aboutAct);
//     helpMenu->addAction(aboutQtAct);

////     menuBar()->addMenu(fileMenu);
////     menuBar()->addMenu(optionMenu);
////     menuBar()->addMenu(helpMenu);
// }

//bool GraphicNoteForm::maybeSave()
// {
//     if (scribbleArea->isModified()) {
//        QMessageBox::StandardButton ret;
//        ret = QMessageBox::warning(this, tr("Scribble"),
//                           tr("The image has been modified.\n"
//                              "Do you want to save your changes?"),
//                           QMessageBox::Save | QMessageBox::Discard
//                           | QMessageBox::Cancel);
//         if (ret == QMessageBox::Save) {
//             return saveFile("png");
//         } else if (ret == QMessageBox::Cancel) {
//             return false;
//         }
//     }
//     return true;
// }

//bool GraphicNoteForm::saveFile(const QByteArray &fileFormat)
// {
//     QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

//     QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
//                                initialPath,
//                                tr("%1 Files (*.%2);;All Files (*)")
//                                .arg(QString(fileFormat.toUpper()))
//                                .arg(QString(fileFormat)));
//     if (fileName.isEmpty()) {
//         return false;
//     } else {
//         return scribbleArea->saveImage(fileName, fileFormat);
//     }
// }
