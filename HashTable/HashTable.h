//
// Created by Adina Katz on 04/06/2020.
//

#ifndef DATASTRUCTURE_2_HASHTABLE_H
#define DATASTRUCTURE_2_HASHTABLE_H

#include "HashTableCell.h"
#include "list.h"
#include <cmath>

#define N 10 //starting size of array
#define HASH 0.61803 //Hashing const used in the default Hash Function
#define DOES_NOT_EXIST -1

/***
 * default universal Hash Function
 * @tparam K - the type of the keys
 */
template<typename K>
struct KeyHash{
    int operator()(K key) const {
        float junk;
        float mul_key = key * HASH;
        int index = floor(std::modf(mul_key, &junk) * N);
        return index;
    }
};
/***
 * Hash Table with custom Hash Function
 * @tparam D - Type of data
 * @tparam K - Type of keys
 * @tparam F - optional: custom Hash Function
 */
template<typename D, typename K, typename F = KeyHash<K>>
class HashTable{
private:
    //array of HashTableCells to store the data
    HashTableCell<D, K>* table;
    //Hash Function variable
    F hashFunction;
    //the size of the data array
    int size;
    //number of cells in use in the data array
    int occupied;

    /**
     * increase the data array size by 2 when the array is 0.8 full.
     * the function can occur only when adding new element.
     */
    void expandTable();

    /**
     * decrease the data array size by 2 when the array is 0.25 full.
     * the function can occur only when deleting an element.
     */
    void reduceTable();

public:
    /**
     * default constructor, initialize new HashTable with the starting size
     */
    HashTable();

    /**
     * default destructor, free the data array allocated memory.
     */
    ~HashTable();

    /**
     * @return the size of the data array
     */
    int getSize() const;

    /**
     * @return the number of cells in use in the array
     */
    int getOccupied() const;

    /**
     * @param key
     * @return true if an element with the given key exists in the data array
     *         false otherwise
     */
    bool isMember(const K &key) const;

    /**
     * Add new element with the given parameters to the data array
     * @param key
     * @param data
     * @return the index location of the new element.
     *         -1 if an element with the same key exists in the data array
     */
    int insertNewMember(const K &key, const D &data);

    /**
     * find the element with the given key
     * @param key - key to search
     * @return the data corresponding to the key given
     */
    D findMember(const K &key);

    /**
     * delete an element from the data array
     * @param key - key to delete
     * @return the data of the element to delete (in case the user need to
     *         deallocate the data from the memory.
     *         default data element in case the key is not found
     */
    D deleteMember(const K &key);

    /**
     * Allocate new list that contain the element from the data array
     * @return pointer to the new list
     */
    List<D>* toList();


};

//=================== PRIVATE ===================

template<typename D, typename K, typename F>
void HashTable<D, K, F>::expandTable() {
    auto temp_table = new HashTableCell<D, K>[size * 2];
    int index;
    for (int i = 0; i < size; ++i) {
        HashTableCell<D, K>* current_old = &table[i];
        if(!current_old->isCellFree()) {
            index = hashFunction(current_old->getKey());
            HashTableCell<D, K>* current_new = &temp_table[index % (size * 2)];
            while(!current_new->isCellFree()) {
                index++;
                current_new = &temp_table[index % (size * 2)];
            }
            current_new->set(current_old->getKey(), current_old->getData());
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
        HashTableCell<D, K>* current_old = &table[i];
        if(!current_old->isCellFree()) {
            index = hashFunction(current_old->getKey());
            HashTableCell<D, K>* current_new = &temp_table[index % (size / 2)];
            while (!current_new->isCellFree()) {
                index++;
                current_new = &temp_table[index % (size / 2)];
            }
            current_new->set(current_old->getKey(), current_old->getData());
        }
    }
    size = size / 2;
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
int HashTable<D, K, F>::getOccupied() const {
    return occupied;
}

template<typename D, typename K, typename F>
bool HashTable<D, K, F>::isMember(const K &key) const {
    int index = hashFunction(key);
    HashTableCell<D, K>* current = &table[index % size];
    if (!current->wasCellOccupied()) {
        return false;
    }
    while(current->wasCellOccupied()) {
        if ((!current->isCellFree()) && (current->getKey() == key)) {
            return true;
        }
        index++;
        current = &table[index % size];
    }
    return false;
}

template<typename D, typename K, typename F>
int HashTable<D, K, F>::insertNewMember(const K &key, const D &data) {
    if (isMember(key)) {
        return DOES_NOT_EXIST;
    }
    if(occupied >= (size*0.8)) {
        expandTable();
    }
    int index = hashFunction(key);
    HashTableCell<D, K>* current = &table[index % size];
    while(!current->isCellFree()) {
        index++;
        current = &table[index % size];
    }
    current->set(key, data);
    occupied++;
    return index;
}

template<typename D, typename K, typename F>
D HashTable<D, K, F>::findMember(const K &key) {
    D data = D();
    if (!isMember(key)) {
        return data;
    }
    int index = hashFunction(key);
    HashTableCell<D, K>* current = &table[index % size];
    while (current->wasCellOccupied()) {
        if (current->getKey() == key) {
            return current->getData();
        }
        index++;
        current = &table[index % size];
    }
    return data;
}

template<typename D, typename K, typename F>
D HashTable<D, K, F>::deleteMember(const K &key) {
    D data = D();
    if (!isMember(key)) {
        return data;
    }
    int index = hashFunction(key);
    HashTableCell<D, K>* current = &table[index % size];
    while (current->getKey() != key) {
        index++;
        current = &table[index % size];
    }
    data = current->getData();
    current->deleteCell();
    occupied--;
    if (occupied < (size / 4)) {
        reduceTable();
    }
    return data;
}

template<typename D, typename K, typename F>
List<D> *HashTable<D, K, F>::toList() {
     auto lst = new List<D>();
    HashTableCell<D,K>* cur;
    for(int i=0; i<size; i++ ){
        cur = &table[i];
        if(!cur->isCellFree()){
            lst->pushLast(cur->getData());
        }
    }
    return lst;
}

#endif //DATASTRUCTURE_2_HASHTABLE_H
