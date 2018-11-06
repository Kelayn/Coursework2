#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Dict.h"
#include <QDir>
#include <QDialog>
#include <QMessageBox>
#include <QInputDialog>
#include "newelement.h"
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
     void loadKeys(QString dictName);
     bool isSaved();
     void turnUnsaved();

private slots:
    void on_pushButton_Empty_clicked();

    void on_pushButton_Load_clicked();

    void on_pushButton_Add_clicked();

    void get_data(std::tuple<QString,QString>);

    void on_pushButton_KeyF_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_KeyDel_clicked();

private:
    Ui::MainWindow *ui;
    const QDir _DIRECTORY = QDir("C:\\Users\\araka\\Documents\\Coursework2\\Dicts\\");
    bool _saved = true;
};

#endif // MAINWINDOW_H
