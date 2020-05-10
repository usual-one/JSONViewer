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

    connect(ui->btn_browse, SIGNAL(clicked()), this, SLOT(setPath()));
    connect(ui->btn_open, SIGNAL(clicked()), this, SLOT(load()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPath()
{
    QString path = QFileDialog::getOpenFileName(this, "../JSONViewer/resource", "../JSONViewer/resource", tr("JSON (*.json)"));
    ui->ln_path->setText(path);
}

void MainWindow::load()
{
    Operation op;
    QString raw_json = QString::fromStdString(op.loadFile(ui->ln_path->text().toStdString()));
    QString parsed_json = "";
    try {
        parsed_json = QString::fromStdString(op.parseJSON(raw_json.toStdString()));
    } catch (JSONException &err) {
        ui->statusbar->showMessage(err.what(), ERROR_DISPLAYING_TIMEOUT);
        return;
    }

    ui->plnte_main->setPlainText(parsed_json);
}



