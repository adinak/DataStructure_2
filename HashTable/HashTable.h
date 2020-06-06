//
// Created by Adina Katz on 04/06/2020.
//

#ifndef DATASTRUCTURE_2_HASHTABLE_H
#define DATASTRUCTURE_2_HASHTABLE_H

#include "HashTableCell.h"
#include <cmath>

#define N 100 //starting size of array
#define HASH 0.61803

template<typename K>
struct KeyHash{
    int operator()(K* key) const {
        int index = N * floor(frac(HASH * key));
        return index;
    }
};

template<typename T, typename K, typename F = KeyHash<K>>
class HashTable{
private:
    HashTableCell<T, K>** table;
    F hashFunction();
    int size;
    int occupied;
    void expandArray();

public:
    HashTable();
    ~HashTable();

    int getSize() const;
    T insertNewMember(const K &key, const T &data);
    T findMember(K key);
    T deleteMember(K key);

};

//=================== PRIVATE ===================

template<typename T, typename K, typename F>
void HashTable<T, K, F>::expandArray() {
    auto temp_table = new HashTableCell<T, K>[size * 2];
    int index;

    for (int i = 0; i < size; ++i) {
        if(!table[i]->isCellFree()) {
            index = hashFunction(table[i]->getKey());
            while(!temp_table[index]->isCellFree()) {
                index++;
            }
            temp_table[index] = table[i];
            table[i]->deleteCell();
        }
    }
    size = size * 2;
    delete [] table;
    table = temp_table;
}

//=================== PUBLIC ===================

template<typename T, typename K,  typename F>
HashTable<T, K, F>::HashTable() : size(N), occupied(0) {
    table = new HashTableCell<T, K> *[N]();
}

template<typename T, typename K, typename F>
HashTable<T, K, F>::~HashTable() { //todo: add loop delete each cell
    delete[] table;
}

template<typename T, typename K, typename F>
int HashTable<T, K, F>::getSize() const {
    return size;
}

template<typename T, typename K, typename F> //todo: go over
T HashTable<T, K, F>::insertNewMember(const K &key, const T &data) {
    if(occupied >= size / 2) {
        expandArray();
    }
    int index = hashFunction(key);
    HashTableCell<T, K> *current = table[index];
    while(!current->isCellFree()) {
        index++;
        current = table[index];
    }
    current = new HashTableCell<T, K>(key, data);
    table[index] = current;

    return current->getData();
}

#endif //DATASTRUCTURE_2_HASHTABLE_H
