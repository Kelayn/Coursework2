#include "newelement.h"
#include "ui_newelement.h"

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
