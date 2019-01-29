#ifndef GRAPHICFORM_H
#define GRAPHICFORM_H

#include <QMainWindow>
#include <graphicnote.h>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>

namespace Ui {
class graphicform;
}

class DrawArea : public QWidget {
    Q_OBJECT
public:
    DrawArea(QWidget* parent = nullptr);
    bool openImage(const QString& fileName);
    void setPenColor(const QColor& newColor);
    void setPenWidth(int newWidth);
    int penWidth() const { return myPenWidth; }
    QImage get_image() { return image; }
public slots:
    void clearImage();
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    void drawLineTo(const QPoint& endPoint);
    void resizeImage(QImage* image, const QSize& newSize);
    bool drawing;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

class graphicform : public QMainWindow {
    Q_OBJECT
public:
    explicit graphicform(QWidget* parent = nullptr);
    ~graphicform();
    void get_note(Note*);
private slots:
    void save();
    void open();
    void color();
    void clear();
    void on_penWidthSlider_valueChanged(int value);

private:
    Ui::graphicform* ui;
    DrawArea* drawArea;
    GraphicNote* note;
};

#endif // GRAPHICFORM_H
