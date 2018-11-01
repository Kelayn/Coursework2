#ifndef DICT_H
#define DICT_H

#include "DictVal.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Dict {
private:
    std::vector<DictVal*> *_pDict;
public:
    Dict(std::vector<DictVal *> *_pDict);

    Dict(const Dict& obj);

    virtual ~Dict();

    Dict();

    std::vector<DictVal *> *get_pDict() const;

    void set_pDict(std::vector<DictVal *> *_pDict);

    Dict* createEmpty(); // Returns pt to empty dict

    int addElem(QString key, QString value=""); // Returns 0 if ok, -1 if key is empty and 1 if key is duplicate
                                                    // and val is empty

    std::vector<QString> delByKey(QString ); // returns list of deleted el-s

    DictVal* findByKey(QString) const; // returns pt to selected el-t

    QString changeVal(QString key, QString oldValue, QString newValue); // returns old var

    void sort();

};



#endif // DICT_H
