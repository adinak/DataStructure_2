#include <iostream>
#include "HashTable.h"
#include "Artist.h"

void test1();
void test2();

int main() {
    test1();
    test2();

    return 0;
}


void test1() {
    std::cout << "@@@@@@@@@@@@@@@@   TEST 1  @@@@@@@@@@@@@@@@@@@" << std::endl;
    HashTable<int, int> my_hash;
    std::cout << "size: " << my_hash.getSize() << std::endl;
    int data1 = my_hash.insertNewMember(456, 12);
    int data2 = my_hash.insertNewMember(455, 13);

    /*if (data1 == 12 && data2 == 13) {
        std::cout << "test1: success!" << std::endl;
    }*/

    bool contains = my_hash.isMember(456);
    if (contains) {
        std::cout << "test2: success!" << std::endl;
    } else {
        std::cout << "test2: FAIL" << std::endl;
    }
    contains = my_hash.isMember(500);
    if (!contains) {
        std::cout << "test3: success!" << std::endl;
    } else {
        std::cout << "test3: FAIL" << std::endl;
    }

    if (my_hash.deleteMember(456) == 12) {
        std::cout << "test4: success!" << std::endl;
        std::cout << "size:" << my_hash.getSize() << std::endl;
    } else {
        std::cout << "test4: FAIL" << std::endl;
    }

    if (my_hash.deleteMember(455) == 13) {
        std::cout << "test5: success!" << std::endl;
        std::cout << "size:" << my_hash.getSize() << std::endl;
    } else {
        std::cout << "test5: FAIL" << std::endl;
    }

    std::cout << "============== INSERT ============ " << std::endl;
    for (int i = 0; i < 50; ++i) {
        my_hash.insertNewMember(i, i);
        std::cout << "size: " << my_hash.getSize() << std::endl;
        std::cout << i << std::endl;
    }
    if(!my_hash.isMember(456)) {
        std::cout << "test6: success!" << std::endl;
    } else {
        std::cout << "test6: FAIL" << std::endl;
    }

    std::cout << "============== FIND ============ " << std::endl;
    for (int k = 0; k < 50; ++k) {
        if (my_hash.isMember(k)) {
            std::cout << k << ": found" << std::endl;
        } else {
            std::cout << k << ": NOT found" << std::endl;
        }
    }

    std::cout << "============== DELETE ============ " << std::endl;
    for (int j = 0; j < 50; ++j) {
        my_hash.deleteMember(j);
        std::cout << "size: " << my_hash.getSize() << std::endl;
        std::cout << "occupied: " << my_hash.getOccupied() << std::endl;
        std::cout << j << std::endl;
    }
}

void test2() {
    std::cout << "@@@@@@@@@@@@@@@@   TEST 2  @@@@@@@@@@@@@@@@@@@" << std::endl;
    int index;
    HashTable<Artist, int> hash;
    for (int i = 0; i < 10; ++i) {
        Artist artist(i);
        index = hash.insertNewMember(i, artist);
        std::cout << i << " in: " << index << std::endl;
        std::cout << "size: " << hash.getSize() << std::endl;
        std::cout << "occupied: " << hash.getOccupied() << std::endl;

    }


}