//
// Created by Aviv9 on 28/04/2020.
//

#ifndef AVLTREE_TESTAVLTREE_H
#define AVLTREE_TESTAVLTREE_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "RankTree.h"
#include "vector"
#include "set"
#include "list"
using namespace std;

typedef enum {SUCCESS, FAIL} Test_result;

void print(list<int> a){
    cout<<"(";
    for(int x : a){
        cout<<x<<", ";
    }
    cout<<")"<<endl;
}

class TestRankTree {
private:
    static RankTree<int,int>* createRankTree(int min, int max);
    Test_result checkRankes();
public:
    TestRankTree(){
        srand (time(nullptr));
    };
    ~TestRankTree() = default;
    Test_result test();

};

Test_result TestRankTree::test() {
    assert(checkRankes() == SUCCESS);
    cout<<"testAdinasList - SUCCESS"<<endl;
    return SUCCESS;
}

RankTree<int, int> *TestRankTree::createRankTree(int min, int max) {
     auto tree = new RankTree<int,int>();
     for (int i=min; i<max; i+=4){
         tree->insert(i,i);
     }
     return tree;
}

Test_result TestRankTree::checkRankes() {
    auto tree = createRankTree(1,450);
    list<int> lst;
    for(int i = 1; i<=tree->getSize(); i++){
        lst.push_back(tree->select(i));
    }
    print(lst);
    delete(tree);
    return SUCCESS;
}


#endif //AVLTREE_TESTAVLTREE_H
