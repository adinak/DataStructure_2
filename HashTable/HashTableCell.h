//
// Created by Adina Katz on 06/06/2020.
//

#ifndef DATASTRUCTURE_2_HASHTABLECELL_H
#define DATASTRUCTURE_2_HASHTABLECELL_H

template<typename D, typename K>
class HashTableCell{
private:
    D* data;
    K* key;
    bool isFree;

public:
    HashTableCell(K* key, D* data);
    ~HashTableCell() = default; //todo
    K getKey() const;
    D getData() const;
    HashTableCell<D, K>* getNext() const;
    bool isCellFree() const;
    void deleteCell();
};

//=================== PUBLIC ===================

template<typename D, typename K>
HashTableCell<D, K>::
HashTableCell(K *key, D *data) : key(key), data(data) {
    isFree = false;
}

template<typename D, typename K>
K HashTableCell<D, K>::getKey() const {
    return *key;
}

template<typename D, typename K>
D HashTableCell<D, K>::getData() const {
    return *data;
}

template<typename D, typename K>
void HashTableCell<D, K>::deleteCell() {
    isFree = true;
    delete key;
    key = nullptr;
    delete data;
    data = nullptr;
}

template<typename D, typename K>
bool HashTableCell<D, K>::isCellFree() const {
    return isFree;
}


#endif //DATASTRUCTURE_2_HASHTABLECELL_H
