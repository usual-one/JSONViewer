#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setPalettes();

    void newFile();

    void openFile();

    void saveFile();

    void saveFileAs();

    void exit();

    void findMistakes();

    void autoFormat();

    void switchLineWrap();

private:
    Ui::MainWindow *ui;

    QString path_;
};
#endif // MAINWINDOW_H
