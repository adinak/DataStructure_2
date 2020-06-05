//
// Created by Aviv9 on 27/04/2020.
//


#ifndef RANKTREE_RANKTREENODE_H
#define RANKTREE_RANKTREENODE_H

#include <iostream>
using std::ostream;

template<class K, class D>
class RankTreeNode{
private:
    //private variables for internal use
    D data;
    K key;
    RankTreeNode* left;
    RankTreeNode* right;
    //bidirectional tree
    RankTreeNode* father;
    //left subtree height
    int hl;
    //right subtree height
    int hr;
    //number of children's
    int w;

    //return reference to data attribute
    D& getData();
    //return reference to key attribute
    K& getKey();
    //compute the height of the node according to hl and hr
    int getHeight();
    //Balance factor for Avl tree, Bf = hl-hr
    int getBf();
    RankTreeNode* getRight();
    RankTreeNode* getLeft();
    RankTreeNode* getFather();
    void setRight(RankTreeNode<K,D>* next);
    void setLeft(RankTreeNode<K,D>* next);
    //set next as left/right son according to next key value
    void setSon(RankTreeNode<K,D>* next);

    template <class KEY,class DATA>
    friend class AVLTree;

public:
    /**
     * default RankTreeNode constructor, uses D and K default constructors
     */
    RankTreeNode() : data(), key(), left(nullptr), right(nullptr),
                     father(nullptr), hl(0), hr(0){};
    /**
     * creating new Node with the given data and key parameters
     * @param key
     * @param data
     */
    RankTreeNode(K key, D data) : data(data), key(key), left(nullptr),
                                  right(nullptr), father(nullptr), hl(0), hr(0){};
    /**
     * no new memory is allocated so default destructor is fine
     */
    ~RankTreeNode() = default;

    /**
     * print node attributes, for debugging purposes
     */
    void printNode();

};

/** Getters **/

template<class K, class D>
K& RankTreeNode<K,D>::getKey() {
    return this->key;
}

template<class K, class D>
D& RankTreeNode<K,D>::getData() {
    return this->data;
}
template<class K, class D>
int RankTreeNode<K,D>::getHeight() {
    return ((this->hl>this->hr) ? this->hl:this->hr)+1;
}

template<class K, class D>
int RankTreeNode<K, D>::getBf() {
    return (this->hl-this->hr);
}

template<class K, class D>
RankTreeNode<K,D>* RankTreeNode<K,D>::getLeft() {
    return this->left;
}

template<class K, class D>
RankTreeNode<K,D>* RankTreeNode<K,D>::getRight() {
    return this->right;
}

template<class K, class D>
RankTreeNode<K,D>* RankTreeNode<K,D>::getFather() {
    return this->father;
}

/** Setters **/

template<class K, class D>
void RankTreeNode<K,D>::setLeft(RankTreeNode<K,D>* next){
    this->left = next;
    if(next == nullptr){
        this->hl = 0;
    }
    else {
        this->hl = next->getHeight();
        next->father = this;
    }
}

template<class K, class D>
void RankTreeNode<K,D>::setRight(RankTreeNode<K,D>* next){
    this->right = next;
    if(next == nullptr){
        this->hr = 0;
    }
    else {
        this->hr = next->getHeight();
        next->father = this;
    }
}

template<class K, class D>
void RankTreeNode<K, D>::setSon(RankTreeNode<K, D> *next) {
    if(next->key > this->key) {
        this->setRight(next);
    }
    else {
        this->setLeft(next);
    }
}


/** Printnig Function **/

template<class K, class D>
void RankTreeNode<K,D>::printNode(){
    std::cout<<"("<<this->getKey()<<", "<<this->getData()<<")";
}



#endif //RANKTREE_RANKTREENODE_H
