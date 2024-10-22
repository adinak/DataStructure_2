//
// Created by Adina Katz on 06/06/2020.
//

#ifndef DATASTRUCTURE_2_HASHTABLECELL_H
#define DATASTRUCTURE_2_HASHTABLECELL_H

template<typename D, typename K>
class HashTableCell{
private:
    D data;
    K key;
    bool isFree;
    bool wasOccupied;

public:
    HashTableCell();
    HashTableCell(const K &key, const D &data);
    ~HashTableCell() = default;
    K& getKey() ;
    D& getData() ;
    void setKey(const K &new_key) ;
    void setData(const D &new_data);
    void set(const K &new_key, const D &new_data);
    bool isCellFree() const;
    bool wasCellOccupied() const;
    void deleteCell();
};

//=================== PUBLIC ===================

template<typename D, typename K>
HashTableCell<D, K>::HashTableCell() {
    data = D();
    key = K();
    isFree = true;
    wasOccupied = false;
}

template<typename D, typename K>
HashTableCell<D, K>::
HashTableCell(const K &key, const D &data) : key(key), data(data) {
    isFree = false;
    wasOccupied = true;
}

template<typename D, typename K>
K& HashTableCell<D, K>::getKey()  {
    return key;
}

template<typename D, typename K>
D& HashTableCell<D, K>::getData()  {
    return data;
}

template<typename D, typename K>
void HashTableCell<D, K>::deleteCell() {
    isFree = true;
}

template<typename D, typename K>
bool HashTableCell<D, K>::isCellFree() const {
    return isFree;
}

template<typename D, typename K>
bool HashTableCell<D, K>::wasCellOccupied() const {
    return wasOccupied;
}

template<typename D, typename K>
void HashTableCell<D, K>::setData(const D &new_data) {
    data = new_data;
}

template<typename D, typename K>
void HashTableCell<D, K>::setKey(const K &new_key) {
    key = new_key;
}

template<typename D, typename K>
void HashTableCell<D, K>::set(const K &new_key, const D &new_data) {
    setKey(new_key);
    setData(new_data);
    isFree = false;
    wasOccupied = true;
}


#endif //DATASTRUCTURE_2_HASHTABLECELL_H
