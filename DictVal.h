#ifndef DICTVAL_H
#define DICTVAL_H
#include <QString>

//
// Created by Kelayn on 05.10.2018.
//


class DictVal {
private:
   QString _val;
   DictVal *_pNext;
public:
    DictVal(const QString &_val);

    DictVal();

    const QString &get_val() const;

    void set_val(const QString &_val);

    DictVal *get_pNext() const;

    void set_pNext(DictVal *_pNext);

    virtual ~DictVal();

};


#endif // DICTVAL_H
