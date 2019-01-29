#include "graphicform.h"
#include "ui_graphicform.h"

graphicform::graphicform(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::graphicform)
{
    ui->setupUi(this);
    drawArea = new DrawArea;
    ui->gridLayout->addWidget(drawArea);
    setWindowTitle(tr("This is PAINTER!!!"));
    connect(ui->colorButton, &QPushButton::clicked, this, &graphicform::color);
    connect(ui->saveButton, &QPushButton::clicked, this, &graphicform::save);
    connect(ui->clearButton, &QPushButton::clicked, this, &graphicform::clear);
    connect(ui->openButton, &QPushButton::clicked, this, &graphicform::open);
    resize(600, 600);
}

void graphicform::get_note(Note* n)
{
    note = dynamic_cast<GraphicNote*>(n);
    drawArea->openImage(note->get_file_path());
}

graphicform::~graphicform()
{
    delete ui;
    delete drawArea;
}

DrawArea::DrawArea(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    drawing = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
}

bool DrawArea::openImage(const QString& fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    update();
    return true;
}

void DrawArea::setPenColor(const QColor& newColor) { myPenColor = newColor; }

void DrawArea::setPenWidth(int newWidth) { myPenWidth = newWidth; }

void DrawArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void DrawArea::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        drawing = true;
    }
}

void DrawArea::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
        drawLineTo(event->pos());
}

void DrawArea::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && drawing)
    {
        drawLineTo(event->pos());
        drawing = false;
    }
}

void DrawArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void DrawArea::resizeEvent(QResizeEvent* event)
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void DrawArea::drawLineTo(const QPoint& endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void DrawArea::resizeImage(QImage* image, const QSize& newSize)
{
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void graphicform::save()
{
    QImage image = drawArea->get_image();
    note->update_image(image);
    note->save_into_file();
}

void graphicform::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        note->load_data_from_file(fileName);
        drawArea->openImage(fileName);
    }
}

void graphicform::on_penWidthSlider_valueChanged(int value)
{
    drawArea->setPenWidth(value);
}

void graphicform::color()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid())
        drawArea->setPenColor(color);
    else
    {
        QMessageBox msgBox;
        msgBox.setText("This color is unsupported!");
        msgBox.exec();
    }
}

void graphicform::clear() { drawArea->clearImage(); }
