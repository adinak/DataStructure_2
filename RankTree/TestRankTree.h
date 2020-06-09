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
    RankTree<int, int> * createRandomTree(int num_of_numbers, int random_range, list<int>* in_order_list);
    static RankTree<int,int>* createRankTree(int min, int max);
    Test_result checkRankes();
    Test_result checkSelect();
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
    assert(checkSelect() == SUCCESS);
    cout<<"checkSelect - SUCCESS"<<endl;
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

RankTree<int, int> *TestRankTree::createRandomTree(int num_of_numbers, int random_range, list<int>* in_order_list) {
    auto tree = new RankTree<int, int>();
    list<int> tester;
    for (int i = 0; i < num_of_numbers; i++) {
        int num = (rand() % random_range);
        tester.push_back(num);
        in_order_list->push_back(num);
    }
    in_order_list->sort();
    in_order_list->unique();
    int i = 0;
    while (!tester.empty()) {
        tree->insert(tester.back(), tester.back());
        tester.pop_back();
        i++;
    }
    return tree;
}

Test_result TestRankTree::checkSelect() {
    list<int> lst;
    auto tree = createRandomTree(100, 500, &lst);
    List<int> my_list;
    tree->getTreeToList(IN, &my_list);
    while(!lst.empty()){
        int a = lst.back();
        lst.pop_back();
        int b = my_list.popLast();
        assert(a==b);
    }
    return SUCCESS;
}

#endif //AVLTREE_TESTAVLTREE_H
