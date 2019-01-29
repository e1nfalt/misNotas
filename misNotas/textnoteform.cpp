#include "textnoteform.h"
#include "ui_textnoteform.h"

TextNoteForm::TextNoteForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TextNoteForm)
{
    ui->setupUi(this);
    QPalette pal;
    pal.setColor(QPalette::Text, Qt::gray);
    ui->plainTextEdit->setPalette(pal);
    connect(ui->openButton, &QPushButton::clicked, this, &TextNoteForm::open);
    connect(ui->saveButton, &QPushButton::clicked, this, &TextNoteForm::save);
}

TextNoteForm::~TextNoteForm()
{
    delete ui;
}

void TextNoteForm::transfer_note(Note* n)
{
    note = dynamic_cast<TextNote*>(n);
    ui->label->setText(note->get_title());
    QFile file(note->get_file_path());
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString line = in.readLine();
        QString text = "";
        while (!line.isEmpty()) {
            text += line + "\n";
            line = in.readLine();
        }
        file.close();
        note->set_text(text);
    }
    ui->plainTextEdit->setPlainText(note->get_text());
}

void TextNoteForm::save()
{
    QString text = ui->plainTextEdit->toPlainText();
    note->set_text(text);
    note->save_into_file();
}

void TextNoteForm::open()
{
    QString text = "";
    QString file_name = QFileDialog::getOpenFileName();
    note->load_data_from_file(file_name);
    text = note->get_text();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(text);
}
