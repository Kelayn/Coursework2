#include "Dict.h"


Dict::Dict(std::vector<DictVal *> *_pDict) : _pDict(_pDict) {}

Dict::Dict() {
    _pDict= new std::vector<DictVal *>();
}

std::vector<DictVal *> *Dict::get_pDict() const {
    return _pDict;
}

void Dict::set_pDict(std::vector<DictVal *> *_pDict) {
    Dict::_pDict = new std::vector<DictVal*>(*_pDict);
}

Dict* Dict::createEmpty() {
    Dict * dc = new Dict();
    return dc;
}

int Dict::addElem(QString key, QString value) {
    if (!key.isEmpty()) {
        auto *dc = this->get_pDict();
        DictVal *newHead = nullptr;
        for (unsigned int i = 0; i < dc->size(); i++) {
            if ((*dc)[i]->get_val() == key) {
                if (!value.isEmpty()) {
                    newHead = dc->operator[](i);
                    do
                        newHead = newHead->get_pNext();
                    while (newHead->get_pNext() != nullptr);
                    newHead->set_pNext(new DictVal(value));
                    dc = nullptr;
                    newHead = nullptr;
                    return 0;
                }
                else {
                    dc = nullptr;
                    newHead = nullptr;
                    return 1;
                }
            }
        }
        if (newHead == nullptr) {
            newHead = new DictVal(key);
            if (!value.isEmpty())
                newHead->set_pNext(new DictVal(value));
            dc->push_back(newHead);
            dc = nullptr;
            return 0;
        }
    }
    else
        return -1;
    return -1;
}

std::vector<QString> Dict::delByKey(QString key) {
    DictVal *cur = nullptr;
    auto dc = this->get_pDict();
    unsigned int delInd;
    for (unsigned int i = 0; i < dc->size(); i++){
        cur = dc->operator[](i);
        if (cur->get_val() == key){
            delInd = i;
            break;
        }
        cur = nullptr;
    }
    std::vector<QString> vecVals = {};
    if (cur!= nullptr){
        do{
            vecVals.push_back(cur->get_val());
            cur = cur->get_pNext();
        }
        while (cur->get_pNext()!= nullptr);
        dc->erase(dc->begin()+delInd);
        return vecVals;
    }
    cur = nullptr;
    dc = nullptr;
    return vecVals;
}

DictVal* Dict::findByKey(QString key) const {
    auto dc = this->get_pDict();
    DictVal *dv = nullptr;
    for (auto i: *dc){
        if (i->get_val()== key) {
            dv = i;
            break;
        }
    }
    dc = nullptr;
    return dv;
}

QString Dict::changeVal(QString key, QString oldValue, QString newValue) {
    auto cur = Dict::findByKey(key);
    if (cur!=nullptr){
        while(cur->get_val()!=oldValue)
            cur = cur->get_pNext();
        QString oldVal = cur->get_val();
        cur->set_val(newValue);
        return oldVal;
    }
    QString empty;
    cur = nullptr;
    return empty;
}

int partition (std::vector<DictVal*> &vDV, int low, int high) {
    auto pivot = vDV[high]->get_val();
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (vDV[j]->get_val() <= pivot){
            i++;
            std::swap(vDV[i], vDV[j]);
        }
    }
    std::swap(vDV[i + 1], vDV[high]);
    return (i + 1);
}

void quickSort(std::vector<DictVal*> &vDV, int low, int high){
    if (low < high){
        int pi = partition(vDV, low, high);
        quickSort(vDV, low, pi - 1);
        quickSort(vDV, pi + 1, high);
    }
}

void Dict::sort() {
    Dict dc = Dict(*this);
    quickSort(*dc.get_pDict(),0,dc.get_pDict()->size()-1);
    dc = nullptr;
}

Dict::~Dict() {
    if(_pDict)
        delete(_pDict);
}

Dict::Dict(const Dict &obj) {
    if(obj.get_pDict()) {
        this->set_pDict(obj.get_pDict());
    }
}


void Dict::load(QString filename){
    QFile file("C:\\Users\\araka\\Documents\\Coursework2\\Dicts\\" + filename);
    file.open(QIODevice::ReadOnly);
    QTextStream qts(&file);
    auto dc = this->get_pDict();
    while (!qts.atEnd()) {
            QString qs;
            qs = qts.readLine();
            auto valsList = qs.split("\"");
            DictVal *pHead = new DictVal();
            pHead->set_val(valsList[0]);
            dc->push_back(pHead);
                for (int i = 1; i<valsList.size(); i++){
                    DictVal *pDv = new DictVal;
                    while(pHead->get_pNext()!=nullptr)
                        pHead = pHead->get_pNext();
                    pDv->set_val(valsList[i]);
                    pHead->set_pNext(pDv);
                    pDv = nullptr;
                }
                pHead = nullptr;
        }
    dc = nullptr;
}

void Dict::save(QString filename){
    auto dc = this->get_pDict();
    QString elementList = "";
    if(dc!=nullptr && dc->size()>0){
        for(auto key: *dc){
            elementList += key->get_val() + "\"";
            key = key->get_pNext();
            while(key != nullptr){
                elementList += key->get_val() + "\"";
                key = key->get_pNext();
            }
            elementList += "AAA";
        }

        QFile file("C:\\Users\\araka\\Documents\\Coursework2\\Dicts\\" + filename + ".txt");
        file.open(QIODevice::WriteOnly);
        QTextStream qts(&file);
        qts<<elementList;
        file.close();
    }
    else{
        QMessageBox msBox;
        msBox.setText("Не удалось сохранить.");
        msBox.exec();
    }
    dc = nullptr;
}
