#include "UI/include/mainwindow.h"
#include "ui_mainwindow.h"

#include "UI/include/colors/settings/setting_palettes.h"
#include "config.h"

#include <QFileDialog>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    highlighter_ = TextHighlighter(ui->plnte_main);

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

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setPalettes() {
    setDefaultPalette(ui->plnte_main);
    setDefaultPalette(this);
    setDefaultPalette(ui->menuFile);
    setDefaultPalette(ui->menuEdit);
    setDefaultPalette(ui->menuView);
}

void MainWindow::newFile() {
    facade_.openNew();

    ui->plnte_main->clear();

    ui->statusbar->showMessage(NEW_FILE_MESSAGE, STATUS_DISPLAYING_TIMEOUT);
}

void MainWindow::openFile() {
    ui->statusbar->showMessage(OPEN_FILE_MESSAGE, STATUS_DISPLAYING_TIMEOUT);

    QString path = QFileDialog::getOpenFileName(this, tr("Open"), "../JSONViewer/resource");
    if (!path.size()) {
        return;
    }

    QString raw_text = QString::fromStdString(facade_.load(path.toStdString()));
    ui->plnte_main->setPlainText(raw_text);
    if (path.endsWith(".json")) {
        findMistakes();
    }
}

void MainWindow::saveFile() {
    if (facade_.pathSet()) {
        facade_.save(ui->plnte_main->toPlainText().toStdString());
        ui->statusbar->showMessage(SAVE_FILE_MESSAGE, STATUS_DISPLAYING_TIMEOUT);
    } else {
        saveFileAs();
    }
}

void MainWindow::saveFileAs() {
    QString path = QFileDialog::getSaveFileName(this, tr("Save As"), "../JSONViewer/resource/");
    if (!path.size()) {
        return;
    }
    facade_.saveTo(path.toStdString(), ui->plnte_main->toPlainText().toStdString());

    ui->statusbar->showMessage(SAVED_AS_MESSAGE + path, STATUS_DISPLAYING_TIMEOUT);
}

void MainWindow::exit() {
   QCoreApplication::quit();
}

void MainWindow::findMistakes() {
    TextMistake mistake = facade_.checkJSONMistakes(ui->plnte_main->toPlainText().toStdString());

    if (facade_.hasMistake()) {
        highlighter_.printMistakeHighlighted(ui->plnte_main->toPlainText(), mistake.getPosition());
    } else {
        QString text = ui->plnte_main->toPlainText();
        highlighter_.clear();
        highlighter_.print(text);
    }

    ui->statusbar->showMessage(QString::fromStdString(mistake.what()), ERROR_DISPLAYING_TIMEOUT);
}

void MainWindow::autoFormat() {
    TextMistake mistake = facade_.checkJSONMistakes(ui->plnte_main->toPlainText().toStdString());
    if (facade_.hasMistake()) {
        ui->statusbar->showMessage(QString::fromStdString(mistake.what()), ERROR_DISPLAYING_TIMEOUT);
        return;
    }

    highlighter_.clear();
    std::vector<TextElement> json_elements = facade_.convertJSONToTextElements();
    highlighter_.printTextElements(QVector<TextElement>(json_elements.begin(), json_elements.end()));
}

void MainWindow::switchLineWrap() {
    if (ui->actLineWrap->isChecked()) {
        ui->plnte_main->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    } else {
        ui->plnte_main->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

