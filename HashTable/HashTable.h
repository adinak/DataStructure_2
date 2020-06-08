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
    int operator()(K key) const {
        float junk;
        float mul_key = key * HASH;
        int index = floor(std::modf(mul_key, &junk) * N);
        return index;
    }
};

template<typename T, typename K, typename F = KeyHash<K>>
class HashTable{
private:
    HashTableCell<T, K>** table;
    F hashFunction;
    int size;
    int occupied;
    void expandArray();

public:
    HashTable();
    ~HashTable();

    int getSize() const;
    bool isMember(const K &key) const;
    T insertNewMember(const K &key, const T &data);
    T findMember(K key);
    T deleteMember(K key);

};

//=================== PRIVATE ===================

template<typename T, typename K, typename F>
void HashTable<T, K, F>::expandArray() {
    auto temp_table = new HashTableCell<T, K>*[size * 2];
    int index;
    for (int i = 0; i < size; ++i) {
        HashTableCell<T, K>* current_old = table[i];
        if(current_old != nullptr && !current_old->isCellFree()) {
            index = hashFunction(current_old->getKey());
            HashTableCell<T, K>* current_new = temp_table[index];
            while(current_new != nullptr && !current_new->isCellFree()) {
                index++;
            }
            temp_table[index] = current_old;
            current_old->deleteCell();
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
HashTable<T, K, F>::~HashTable() {
    for (int i = 0; i < size; ++i) {
        if(table[i] != nullptr) {
            table[i]->deleteCell();
        }
    }
    delete[] table;
}

template<typename T, typename K, typename F>
int HashTable<T, K, F>::getSize() const {
    return size;
}

template<typename T, typename K, typename F>
bool HashTable<T, K, F>::isMember(const K &key) const {
    int index = hashFunction(key);
    if (index >= size) {
        return false;
    }
    HashTableCell<T, K>* current = table[index];
    if (current == nullptr) {
        return false;
    }
    while(!current->isCellFree()) {
        if (current->getKey() == key) {
            return true;
        }
        index++;
        current = table[index];
    }
    return false;
}

template<typename T, typename K, typename F>
T HashTable<T, K, F>::insertNewMember(const K &key, const T &data) {
    if(occupied >= size / 2) {
        expandArray();
    }
    int index = hashFunction(key);
    HashTableCell<T, K> *current = table[index];
    if(current != nullptr) {
        while(current != nullptr && !current->isCellFree()) {
            index++;
            current = table[index];
        }
    }
    current = new HashTableCell<T, K>(key, data);
    table[index] = current;
    occupied++;

    return current->getData();
}

template<typename T, typename K, typename F>
T HashTable<T, K, F>::findMember(K key) {
    int index = hashFunction(key);
    HashTableCell<T, K>* current = table[index];
    while (current->getKey() != key) {
        index++;
        current = table[index];
    }
    T data = current->getData();
    return data;
}

template<typename T, typename K, typename F>
T HashTable<T, K, F>::deleteMember(K key) {
    int index = hashFunction(key);
    HashTableCell<T, K>* current = table[index];
    while (current->getKey() != key) {
        index++;
        current = table[index];
    }
    T data = current->getData();
    current->deleteCell();
    return data;
}


#endif //DATASTRUCTURE_2_HASHTABLE_H
