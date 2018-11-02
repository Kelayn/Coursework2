#ifndef NEWELEMENT_H
#define NEWELEMENT_H

#include <QDialog>
#include <QString>

namespace Ui {
class NewElement;
}

class NewElement : public QDialog
{
    Q_OBJECT

public:
    explicit NewElement(QWidget *parent = nullptr);
    ~NewElement();

signals:
    void send_data(std::tuple<QString, QString>);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewElement *ui;
};

#endif // NEWELEMENT_H
