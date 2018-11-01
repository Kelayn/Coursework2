#include "emptydict.h"
#include "ui_emptydict.h"

EmptyDict::EmptyDict(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmptyDict)
{
    ui->setupUi(this);
}

EmptyDict::~EmptyDict()
{
    delete ui;
}
