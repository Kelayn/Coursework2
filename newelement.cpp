#include "newelement.h"
#include "ui_newelement.h"
#include <tuple>

NewElement::NewElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewElement)
{
    ui->setupUi(this);
}

NewElement::~NewElement()
{
    delete ui;
}

void NewElement::on_buttonBox_accepted()
{
    QString key = ui->lineEdit->text();
    QString value = ui->lineEdit_2->text();
    auto element = std::make_tuple(key, value);
    emit send_data(element);
    this->close();
}
