//
// Created by Adina Katz on 04/06/2020.
//

#ifndef DATASTRUCTURE_2_HASHTABLE_H
#define DATASTRUCTURE_2_HASHTABLE_H

#include "HashTableCell.h"
//#include <cmath>

#define N 10 //starting size of array
#define HASH 0.61803
#define DOES_NOT_EXIST -1
#define HALF 0.5
#define QUARTER 0.25


template<typename K>
struct KeyHash{
    int operator()(K key) const {
        float junk;
        float mul_key = key * HASH;
        int index = floor(std::modf(mul_key, &junk) * N);
        return index;
    }
};

template<typename D, typename K, typename F = KeyHash<K>>
class HashTable{
private:
    HashTableCell<D, K>* table;
    F hashFunction;
    int size;
    int occupied;
    void expandTable();
    void reduceTable();

public:
    HashTable();
    ~HashTable();

    int getSize() const;
    bool isMember(const K &key) const;
    int insertNewMember(const K &key, const D &data);
    D& findMember(const K &key);
    D& deleteMember(const K &key);

};

//=================== PRIVATE ===================

template<typename D, typename K, typename F>
void HashTable<D, K, F>::expandTable() {
    auto temp_table = new HashTableCell<D, K>[size * 2];
    int index;
    for (int i = 0; i < size; ++i) {
        HashTableCell<D, K> current_old = table[i];
        if(!current_old.isCellFree()) {
            index = hashFunction(current_old.getKey());
            HashTableCell<D, K> current_new = temp_table[index];
            while(index < size && !current_new.isCellFree()) {
                index++;
                current_new = temp_table[index];
            }
            temp_table[index] = current_old;
        }
    }
    size = size * 2;
    delete [] table;
    table = temp_table;
}

template<typename D, typename K, typename F>
void HashTable<D, K, F>::reduceTable() {
    auto temp_table = new HashTableCell<D, K>[size / 2];
    int index;
    for (int i = 0; i < size; ++i) {
        HashTableCell<D, K> current_old = table[i];
        if(!current_old.isCellFree()) {
            index = hashFunction(current_old.getKey());
            HashTableCell<D, K> current_new = temp_table[index];
            while (index < (size * HALF) && !current_new.isCellFree()) {
                index++;
                current_new = temp_table[index];
            }
            temp_table[index] = current_old;
        }
    }
    size = size * HALF;
    delete [] table;
    table = temp_table;
}

//=================== PUBLIC ===================

template<typename D, typename K,  typename F>
HashTable<D, K, F>::HashTable() : size(N), occupied(0) {
    table = new HashTableCell<D, K> [N]();
}

template<typename D, typename K, typename F>
HashTable<D, K, F>::~HashTable() {
    delete[] table;
}

template<typename D, typename K, typename F>
int HashTable<D, K, F>::getSize() const {
    return size;
}

template<typename D, typename K, typename F>
bool HashTable<D, K, F>::isMember(const K &key) const {
    int index = hashFunction(key);
    if (index >= size) {
        return false;
    }
    HashTableCell<D, K> current = table[index];
    if (current.isCellFree()) {
        return false;
    }
    while(current.wasCellOccupied()) {
        if (current.getKey() == key) {
            return true;
        }
        index++;
        current = table[index % size];
    }
    return false;
}

template<typename D, typename K, typename F>
int HashTable<D, K, F>::insertNewMember(const K &key, const D &data) {
    if (isMember(key)) {
        return DOES_NOT_EXIST;
    }
    if(occupied >= size * HALF) {
        expandTable();
    }
    int index = hashFunction(key);
    HashTableCell<D, K> current = table[index];
    while(!current.isCellFree()) {
        index++;
        current = table[index % size];
    }
    current = HashTableCell<D, K>(key, data);
    table[index % size] = current;
    occupied++;
    return index;
}

template<typename D, typename K, typename F>
D& HashTable<D, K, F>::findMember(const K &key) {
    D data = D();
    if (!isMember(key)) {
        return data;
    }
    int index = hashFunction(key);
    HashTableCell<D, K> current = table[index];
    while (current.wasCellOccupied()) {
        if (current.getKey() == key) {
            return current.getData();
        }
        index++;
        current = table[index % size];
    }
    return data;
}

template<typename D, typename K, typename F>
D& HashTable<D, K, F>::deleteMember(const K &key) {
    D data = D();
    if (!isMember(key)) {
        return data;
    }
    int index = hashFunction(key);
    HashTableCell<D, K> current = table[index];
    while (index < size && current.getKey() != key) {
        index++;
        current = table[index];
    }
    data = current.getData();
    current.deleteCell();
    occupied--;
    if (occupied < size * QUARTER) {
        reduceTable();
    }
    return data;
}

#endif //DATASTRUCTURE_2_HASHTABLE_H
