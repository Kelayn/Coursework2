#ifndef CHANGEVAL_H
#define CHANGEVAL_H

#include <QDialog>

namespace Ui {
class ChangeVal;
}

class ChangeVal : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeVal(QWidget *parent = nullptr);
    ~ChangeVal();

private:
    Ui::ChangeVal *ui;
};

#endif // CHANGEVAL_H
