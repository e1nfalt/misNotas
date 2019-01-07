#ifndef GRAPHICFORM_H
#define GRAPHICFORM_H

#include <QMainWindow>
#include <graphicnote.h>

namespace Ui {
class graphicform;
}


class DrawArea : public QWidget
 {
     Q_OBJECT

 public:
     DrawArea(QWidget *parent = 0);

     bool openImage(const QString &fileName);
     void setPenColor(const QColor &newColor);
     void setPenWidth(int newWidth);

     int penWidth() const { return myPenWidth; }
     QImage get_image() { return image; }

 public slots:
     void clearImage();
     void print();

 protected:
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void paintEvent(QPaintEvent *event);
     void resizeEvent(QResizeEvent *event);

 private:
     void drawLineTo(const QPoint &endPoint);
     void resizeImage(QImage *image, const QSize &newSize);

     bool drawing;
     int myPenWidth;
     QColor myPenColor;
     QImage image;
     QPoint lastPoint;
 };


class graphicform : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphicform(QWidget *parent = nullptr);
    ~graphicform();
    void get_note(Note*);

private slots:

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_colorButton_clicked();

    void on_penWidthSlider_valueChanged(int value);

    void on_clearButton_clicked();

private:
    Ui::graphicform *ui;

    DrawArea *drawArea;
    GraphicNote *note;
};

#endif // GRAPHICFORM_H
