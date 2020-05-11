#include "UI/include/mainwindow.h"
#include "ui_mainwindow.h"

#include "logic/include/logic.h"
#include "logic/include/exception/JSON_DT/DT_exception_headers.h"

#include "UI/include/setting_palettes.h"

#include <QFileDialog>
#include <QShortcut>
#include <QDebug>

const size_t ERROR_DISPLAYING_TIMEOUT = 7000;

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

    setPalettes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPalettes()
{
    setDefaultPalette(ui->plnte_main);
    setDefaultPalette(this);
    setDefaultPalette(ui->menuFile);
    setDefaultPalette(ui->menuEdit);
    setDefaultPalette(ui->menuView);
}

void MainWindow::newFile() {
    path_ = "";
    ui->plnte_main->clear();
}

void MainWindow::openFile() {
    path_ = QFileDialog::getOpenFileName(this, tr("Open"), "../JSONViewer/resource", tr("JSON (*.json)"));
    if (!path_.size()) {
        return;
    }
    Operation op;
    QString raw_json = QString::fromStdString(op.loadFile(path_.toStdString()));
    ui->plnte_main->setPlainText(raw_json);
    findMistakes();
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
    if (!path_.size()) {
        return;
    }
    saveFile();
}

void MainWindow::exit() {
   QCoreApplication::quit();
}

void MainWindow::findMistakes() {
    QString raw_json = ui->plnte_main->toPlainText();
    Operation op;
    QString mistake_msg = "No mistakes found!";
    try {
        QString parsed_json = QString::fromStdString(op.parseJSON(raw_json.toStdString()));
    } catch (ArrayException &err) {
        mistake_msg = "Found Array mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (ObjectException &err) {
        mistake_msg = "Found Object mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (KeyValuePairException &err) {
        mistake_msg = "Found Object mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (BooleanException &err) {
        mistake_msg = "Found Boolean mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (NullException &err) {
        mistake_msg = "Found Null mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (NumberException &err) {
        mistake_msg = "Found Number mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (StringException &err) {
        mistake_msg = "Found String mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (JSONException &err) {
        mistake_msg = "Found JSON mistake at line " + QString::number(err.getPosition().getRow()) +
                " at character " + QString::number(err.getPosition().getColumn()) +
                ": " + err.what();
    } catch (std::exception &err) {
        mistake_msg = "Found some mistake: " + QString(err.what());
    }
    ui->statusbar->showMessage(mistake_msg, ERROR_DISPLAYING_TIMEOUT);
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

