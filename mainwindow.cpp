#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget_Dicts->addItems(DIRECTORY.entryList(QDir::Files));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Empty_clicked()
{

    // при нажатии кнопки, вылезает окно "конструктора", в котором предлагается ввести название словаря.
    // потом при помощи смены текста на лейблах в одном и том же окне записывается словарь, записывается, записываеися
    //потом, если сохранить - cериализуется в файл, сохраняется в директории, название вылезает в листвиджете.
    //записывать в файл КАК ОБЪЕКТ, а НЕ как json файл.
}
