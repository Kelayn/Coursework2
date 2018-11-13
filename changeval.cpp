#include "changeval.h"
#include "ui_changeval.h"

ChangeVal::ChangeVal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeVal)
{
    ui->setupUi(this);
}

ChangeVal::~ChangeVal()
{
    delete ui;
}

void ChangeVal::on_buttonBox_accepted()
{
    QString newValue = ui->lineEdit->text();
    emit send_data1(newValue);
    this->close();
}
