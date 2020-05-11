#include "UI/include/mainwindow.h"
#include "ui_mainwindow.h"

#include "logic/include/logic.h"
#include "logic/include/exception/JSON_DT/DT_exception_headers.h"

#include <QFileDialog>

const size_t ERROR_DISPLAYING_TIMEOUT = 5000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->actOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    connect(ui->actExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actFindMistakes, SIGNAL(triggered()), this, SLOT(findMistakes()));
    connect(ui->actAutoFormat, SIGNAL(triggered()), this, SLOT(autoFormat()));
    connect(ui->actLineWrap, SIGNAL(changed()), this, SLOT(switchLineWrap()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile() {
    path_ = "";
    ui->plnte_main->clear();
}

void MainWindow::openFile() {
    path_ = QFileDialog::getOpenFileName(this, tr("Open"), "../JSONViewer/resource", tr("JSON (*.json)"));
    Operation op;
    QString raw_json = QString::fromStdString(op.loadFile(path_.toStdString()));
    findMistakes();
    ui->plnte_main->setPlainText(raw_json);
}

void MainWindow::saveFile() {
    if (path_.size()) {
        Operation op;
        op.saveFile(path_.toStdString(), ui->plnte_main->toPlainText().toStdString());
    } else {
        saveFileAs();
    }
}

void MainWindow::saveFileAs() {
    path_ = QFileDialog::getSaveFileName(this, tr("Save As"), "../JSONViewer/resource/", tr("JSON (*.json)"));
    saveFile();
}

void MainWindow::exit() {
   QCoreApplication::quit();
}

void MainWindow::findMistakes() {
    Operation op;
    QString raw_json = ui->plnte_main->toPlainText();
    QString parsed_json = "";
    try {
        parsed_json = QString::fromStdString(op.parseJSON(raw_json.toStdString()));
    } catch (JSONException &err) {
        ui->statusbar->showMessage(err.what(), ERROR_DISPLAYING_TIMEOUT);
        return;
    }
}

void MainWindow::autoFormat() {
    findMistakes();
    Operation op;
    QString raw_json = ui->plnte_main->toPlainText();
    ui->plnte_main->setPlainText(QString::fromStdString(op.parseJSON(raw_json.toStdString())));
}

void MainWindow::switchLineWrap() {
    if (ui->actLineWrap->isChecked()) {
        ui->plnte_main->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    } else {
        ui->plnte_main->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

