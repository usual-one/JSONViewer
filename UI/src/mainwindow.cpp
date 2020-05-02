#include "UI/include/mainwindow.h"
#include "ui_mainwindow.h"

#include "logics/include/logics.h"

#include <QFileDialog>

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
    QString raw_json = QString::fromStdString(op.load_file(ui->ln_path->text().toStdString()));
    ui->plnte_main->setPlainText(raw_json);
}



