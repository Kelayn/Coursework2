#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget_Dicts->addItems(_DIRECTORY.entryList(QDir::Files));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isSaved(){
    return _saved;
}

void MainWindow::turnUnsaved(){
    _saved = false;
}

void MainWindow::loadKeys(QString dictName){
    ui->listWidget_Keys->clear();
    Dict *dc = new Dict();
    if(pDict == nullptr)
        dc->load(dictName);
    else
        dc = pDict;
    for(auto key:*dc->get_pDict()){
        ui->listWidget_Keys->addItem(key->get_val());
    }
}

void MainWindow::on_pushButton_Empty_clicked()
{
    QString text = QInputDialog::getText(this,"Создание нового словаря","Введите название словаря");
    ui->dictNameLabel->setText(text);
    pDict = Dict::createEmpty();
    turnUnsaved();
}

void MainWindow::on_pushButton_Load_clicked()
{
    if(ui->listWidget_Dicts->selectedItems().size()==0){
        QMessageBox msBox;
        msBox.setText("Вы не выбрали ни одного словаря.\nВыберите один.");
        msBox.exec();
        return;
    }
    if(!isSaved()){
        int choice = QMessageBox::warning(this, "",
                                       "У Вас есть несохраненный словарь.\n"
                                          "Вы действительно хотите продолжить??",
                                       QMessageBox::Apply | QMessageBox::Discard,
                                       QMessageBox::Discard);
        if(choice == QMessageBox::Discard)
            return;

    }
    auto items = ui->listWidget_Dicts->selectedItems();
    ui->dictNameLabel->setText(items[0]->text());
    Dict *dc = new Dict();
    dc->load(ui->dictNameLabel->text());
    pDict = dc;
    loadKeys(ui->dictNameLabel->text());
}

void MainWindow::on_pushButton_Add_clicked()
{
    if(ui->dictNameLabel->text() == ""){
        QMessageBox msBox;
        msBox.setText("У вас не выбран ни один словарь.\nВыберите один.");
        msBox.exec();
        return;
    }
    auto* newElement = new NewElement();
    connect(newElement, SIGNAL(send_data(std::tuple<QString,QString>)), this, SLOT(get_data(std::tuple<QString,QString>)));
    newElement->show();
}

void MainWindow::get_data(std::tuple<QString,QString> t){
    pDict->addElem(std::get<0>(t),std::get<1>(t));
    ui->listWidget_Keys->addItem(std::get<0>(t));
    loadKeys(ui->dictNameLabel->text());
}

void MainWindow::on_pushButton_KeyF_clicked()
{
    if(ui->listWidget_Keys->selectedItems().size()==0){
        QMessageBox msBox;
        msBox.setText("Вы не выбрали ни одного ключа.\nВыберите один.");
        msBox.exec();
        return;
    }

    auto items = ui->listWidget_Keys->selectedItems();
    DictVal *cur = nullptr;
    ui->listWidget_Values->clear();
    for (auto a: *this->pDict->get_pDict()){
        if(a->get_val()==items[0]->text()){
            cur = a;
            a = nullptr;
            break;
        }
    }

    if(cur!=nullptr){
        cur = cur->get_pNext();
        while(cur!=nullptr){
            ui->listWidget_Values->addItem(cur->get_val());
            cur = cur->get_pNext();
        }
    }
}

void MainWindow::on_pushButton_Save_clicked()
{
    if(pDict->get_pDict()==nullptr){
        QMessageBox msBox;
        msBox.setText("Вы сохраняете пустой словарь. Это невозможно.");
        msBox.exec();
        return;
    }
    pDict->save(ui->dictNameLabel->text());
    QMessageBox msBox;
    msBox.setText("Сохранено.");
    msBox.exec();
}
