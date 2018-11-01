#include "DictVal.h"

DictVal::DictVal(const QString &_val) : _val(_val){
    _pNext = nullptr;
}

DictVal::DictVal() {
    _pNext = nullptr;
}

const QString &DictVal::get_val() const {
    return _val;
}

void DictVal::set_val(const QString &_val) {
    DictVal::_val = _val;
}

DictVal *DictVal::get_pNext() const {
    return _pNext;
}

void DictVal::set_pNext(DictVal *_pNext) {
    DictVal::_pNext = _pNext;
}

DictVal::~DictVal() {
    if (_pNext)
        delete _pNext;
}
