#ifndef EMPTYDICT_H
#define EMPTYDICT_H

#include <QDialog>

namespace Ui {
class EmptyDict;
}

class EmptyDict : public QDialog
{
    Q_OBJECT

public:
    explicit EmptyDict(QWidget *parent = nullptr);
    ~EmptyDict();

private:
    Ui::EmptyDict *ui;

};

#endif // EMPTYDICT_H
