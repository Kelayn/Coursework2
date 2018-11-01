#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Dict.h"
#include <QDir>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     Dict * pDict;

private slots:
    void on_pushButton_Empty_clicked();

private:
    Ui::MainWindow *ui;
    const QDir DIRECTORY = QDir("C:\\Users\\araka\\Documents\\Coursework2\\Dicts\\");
};

#endif // MAINWINDOW_H
