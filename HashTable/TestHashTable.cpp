#include <iostream>
#include "HashTable.h"

int main() {

    HashTable<int, int> my_hash;
    int data1 = my_hash.insertNewMember(456, 12);
    int data2 = my_hash.insertNewMember(455, 13);

    if (data1 == 12 && data2 == 13) {
        std::cout << "test1: success!" << std::endl;
    }

    bool contains = my_hash.isMember(456);
    if (contains) {
        std::cout << "test2: success!" << std::endl;
    }
    contains = my_hash.isMember(500);
    if (!contains) {
        std::cout << "test3: success!" << std::endl;
    }

    for (int i = 0; i < 50; ++i) {
        my_hash.insertNewMember(i, i);
        std::cout << my_hash.getSize() << std::endl;
        std::cout << i << std::endl;
    }
    if(my_hash.isMember(456)) {
        std::cout << "test4: success!" << std::endl;
    }
    for (int j = 0; j < 50; ++j) {
        my_hash.deleteMember(j);
        std::cout << my_hash.getSize() << std::endl;
        std::cout << j << std::endl;
    }

    return 0;
}
