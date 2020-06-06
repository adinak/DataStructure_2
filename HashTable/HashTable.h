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
    HashTableCell<T, K>** dynamic_array;
    F hashFunction();
    int size;
    int occupied;
    void expandArray();

public:
    HashTable();
    ~HashTable();

    int getSize() const;
    T insertNewMember(K key);
    T findMember(K key);
    T deleteMember(K key);

};

//=================== PRIVATE ===================

template<typename T, typename K, typename F>
void HashTable<T, K, F>::expandArray() {
    auto temp_array = new HashTableCell<T, K>[size * 2];
    int index;

    for (int i = 0; i < size; ++i) {
        if(!dynamic_array[i]->isCellFree()) {
            index = hashFunction(dynamic_array[i]->getKey());
            while(temp_array[index] != nullptr) {
                index++;
            }
            temp_array[index] = dynamic_array[i];
            dynamic_array[i]->deleteCell();
        }
    }
    size = size * 2;
    delete [] dynamic_array;
    dynamic_array = temp_array;
}

//=================== PUBLIC ===================

template<typename T, typename K,  typename F>
HashTable<T, K, F>::HashTable() : size(N), occupied(0) {
    dynamic_array = new HashTableCell<T, K>[N];
}

template<typename T, typename K, typename F>
HashTable<T, K, F>::~HashTable() { //todo
    delete[] dynamic_array;
}

template<typename T, typename K, typename F>
int HashTable<T, K, F>::getSize() const {
    return size;
}

template<typename T, typename K, typename F>
T HashTable<T, K, F>::insertNewMember(K key) {
    if(occupied >= size / 2) {
        expandArray();
    }
    int index = hashFunction(key);
    HashTableCell<T, K> *current = dynamic_array[index];
    if(!current->isCellFree()) {
        while(current->getNext() != nullptr) {
            current = current->getNext();
        }
    }

    return nullptr;
}

#endif //DATASTRUCTURE_2_HASHTABLE_H
