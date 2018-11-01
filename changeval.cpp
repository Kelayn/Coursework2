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
