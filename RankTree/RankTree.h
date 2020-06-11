//
// Created by Aviv9 on 27/04/2020.
//



#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include "RankTreeNode.h"
#include "list.h"


typedef enum {RANK_TREE_SUCCESS, RANK_TREE_KEY_ALREADY_EXISTS, RANK_TREE_KEY_NOT_EXISTS,
                                        BALANCED, NOT_BALANCED} RankTreeResult;
typedef enum {PRE, IN, POST} RankTreeOrderType;

/**
 * Creating and operating AVL Tree, as learnt at the lectures.
 * Storing, accessing at removing data at binary-search tree, while O(h)=log(n)
 * when "h" stands for tree's depth and "n" stands for nodes stored at the tree.
 * @tparam K Datatype of node KEY
 * @tparam D Datatype of node DATA
 */

template<class K, class D>
class RankTree{
private:
    //Number of nodes in the tree
    int num_of_nodes;
    RankTreeNode<K,D>* root;
    //Pointer to the node with the biggest_node Key
    RankTreeNode<K,D>* biggest_node;

    //Rotating function for inserting or deleting nodes
    RankTreeResult rotateLL(RankTreeNode<K,D>* B);
    RankTreeResult rotateLR(RankTreeNode<K,D>* C);
    RankTreeResult rotateRR(RankTreeNode<K,D>* B);
    RankTreeResult rotateRL(RankTreeNode<K,D>* C);

    //Add new_node to the tree
    RankTreeResult addNewNode(RankTreeNode<K,D>* new_node);
    //Balance single tree node
    RankTreeResult balanceNode(RankTreeNode<K,D>* curr);

    //Transferring the tree nodes data to lists according to specific order
    RankTreeResult getPreOrder(RankTreeNode<K,D>* root_node, List<D> *ordered_list);
    RankTreeResult getPreOrder(RankTreeNode<K,D>* root_node, List<D> *ordered_list,
                               int& n);

    RankTreeResult getInOrder(RankTreeNode<K, D> *root_node, List<D> *ordered_list);
    RankTreeResult getInOrder(RankTreeNode<K, D> *root_node, List<D> *ordered_list,
                              int& n);

    RankTreeResult getPostOrder(RankTreeNode<K, D> *root_node,
                                List<D> *ordered_list);
    RankTreeResult getPostOrder(RankTreeNode<K, D> *root_node,
                                List<D> *ordered_list, int& n);

    //Swap two nodes position, used for deleting nodes
    RankTreeResult swapNodes(RankTreeNode<K,D>* a, RankTreeNode<K,D>* b);
    //Deleting node from the tree
    RankTreeNode<K, D> * deleteNode(RankTreeNode<K, D> *node_to_delete);
    //Deleting node with two children required special handling therefore
    // it has special function
    RankTreeNode<K, D> * deleteNodeWithTwoChildren(RankTreeNode<K,D>* node_to_delete);

    //Find node in the tree with a specific key
    RankTreeNode<K,D>* findNode(const K& key);

    //Delete all the nodes from the tree
    void clearTree(RankTreeNode<K, D> *root_node);

    /*Iterate over the tree nodes in in-order and using doSomthing function on
     *the nodes data, doSomthing need to have exactly 3 parameters:
     *
     */
    template<typename Function, typename S>
    RankTreeResult iterateAndDoInOrder(RankTreeNode<K, D> *node, Function
        doSomething, List<S>* lst , int &n);

    //TODO: delete when done testing
    template <class KEY,class DATA>
    friend class RankTree;
public:
    // C'tors and D'tors
    RankTree();
    ~RankTree();

    //return the num of nodes in the tree
    int getSize();

    //Insert & Remove
    /**
     * Adds new item to the tree, while keeping it balanced
     * @param key Identifier of new item
     * @param data Data of new item
     * @return RANK_TREE_SUCCESS / RANK_TREE_KEY_ALREADY_EXISTS
     */
    RankTreeResult insert(K& key, D& data);

    /**
     * Removes an item from the tree, while keeping it balanced
     * @param key Identifier of removed item
     * @return RANK_TREE_SUCCESS / RANK_TREE_KEY_NOT_EXISTS
     */
    RankTreeResult remove(const K& key);

    /**
     * Searches after a specific item, identifies by key, and returns a pointer
     * to its data
     * @param key Identifier for desired item
     * @return pointer to the data associated with the specific key / nullptr if
     * the specific key do not exists
     */
    D* find(const K& key);

    /**
     * Prints (to std::cout) the content of the tree, by using selected search
     * method
     * @param type Search method (PRE, IN, POST)
     */
    void printAVLTree(RankTreeOrderType type);

    // Data Accessing
    /**
     * Puts data stored at the tree to a given List<D>, using given search order
     * @param Order type for the search (PRE, IN, POST)
     * @param data_list List<D> to store search results at
     * @param optional param that indicate the number of nodes to store in the
     *        list
     */
    RankTreeResult getTreeToList(RankTreeOrderType type, List<D> *ordered_list);
    RankTreeResult getTreeToList(RankTreeOrderType type, List<D> *ordered_list,
                                 int& n);

    /**
     * Iterate over n of the tree nodes in in-order and use doSomething function
     * on each nodes data.
     * to use the function the user need to create a class with () operator
     * overloaded with spesific params
     * @param doSomething(D data, int &n, List<S>* lst)
     *        @param data is the nodes data to operate on
     *        @param n uses to count the number of action (the user can increase
     *               decrease n in order to count actions)
     *        @param lst - list to store inner structs, can be nullptr if not
     *                     used
     * @param number of nodes/ actions to made
     * @return RANK_TREE_SUCCESS
     */
    template<typename Function, typename S>
    RankTreeResult doSomethingInOrder(Function doSomething, int &n, List<S>*lst);

    /**
     * Given a key of an element in the tree the function return its position
     * in the ordered series of all the tree elements when the smallest element
     * is in position 1 and the biggest element is in position tree.size()
     * @param key - the key of the element to search
     * @return the position of the element in the ordered series
     * @return -1 if an element with the given key doesnt exists in the tree
     */
    int rank(K key);
    /**
     * finds the i element in the ordered series of all the tree elements and
     * return its key, the user can get the element data by using find(K key)
     * function on the returned key.
     * @param i - the rank of the element to find (1 is the smallest, tree.size()
     * is the biggest.
     * @return the element found in the i' position in the ordered series
     * @return default K value if i<=0 or i>tree.size
     */
    K select(int i);


    /**
     * Delete all the nodes from the tree and set Private variable to nullptr
     */
    void clear();
};

/* ###################################################
 *          Implementation - Public Functions
 * ###################################################
 */

/* ----------------------------------
 *         C'tors and D'tors
 * ----------------------------------
 */

template<class K, class D>
RankTree<K, D>::RankTree():num_of_nodes(0), root(nullptr), biggest_node(nullptr){}

template<class K, class D>
RankTree<K, D>::~RankTree() {
    clearTree(this->root);
    num_of_nodes = 0;
    this->root = nullptr;
    this->biggest_node = nullptr;
}

/* ----------------------------------
 *         Get Size
 * ----------------------------------
 */

template<class K, class D>
int RankTree<K, D>::getSize() {
    return this->num_of_nodes;
}

/* ----------------------------------
 *         Insert & Remove
 * ----------------------------------
 */

template<class K, class D>
RankTreeResult RankTree<K,D>::insert(K& key, D& data){
    RankTreeNode<K,D>* new_node = new RankTreeNode<K,D>(key, data);
    RankTreeResult add_result = addNewNode(new_node);//Adds the node to the tree
    if(add_result != RANK_TREE_SUCCESS){//Something went wrong
        delete new_node;
        return add_result;
    }
    this->num_of_nodes++;
    RankTreeResult balance_result = NOT_BALANCED;
    RankTreeNode<K,D>* curr = new_node;
    K son_key = curr->getKey();
    //Checking the BF of each node in the route to the root, updating heights
    for(curr = new_node->getFather(); curr != nullptr ;curr=curr->getFather()){
        //checking in which direction we went up
        if(son_key>curr->getKey()){
            curr->hr = curr->getRight()->getHeight();
        }
        else if(son_key<curr->getKey()){
            curr->hl = curr->getLeft()->getHeight();
        }
        //after one rotation the tree is balanced
        if(balance_result == NOT_BALANCED) {
            balance_result = balanceNode(curr);
        }
        son_key = curr->getKey();
    }
    return RANK_TREE_SUCCESS;
}

/**Rotation Functios**/

template<class K, class D>
RankTreeResult RankTree<K,D>::rotateLL(RankTreeNode<K, D>* B) {
    //B is the unbalanced node with BF>1
    RankTreeNode<K,D>* A = B->getLeft();
    RankTreeNode<K,D>* father = B->getFather();

    B->setLeft(A->getRight());
    A->setRight(B);

    //fix number of sons
    int new_w = 1;
    if(B->getRight()!= nullptr){
        new_w+= B->getRight()->getNumberOfSons();
    }
    if(B->getLeft() != nullptr){
        new_w+= B->getLeft()->getNumberOfSons();
    }
    B->setNumberOfSons(new_w);
    A->setNumberOfSons(new_w + A->getLeft()->getNumberOfSons()+1);
    if(father == nullptr){//that means B is the root
        A->father = nullptr;
        this->root = A;
    }
    else {
        father->setSon(A);
    }
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K,D>::rotateLR(RankTreeNode<K, D>* C) {
    //C is the unbalanced node with BF>1
    RankTreeNode<K,D>* B = C->getLeft();
    //B has BF=1 therefore he has a right son
    RankTreeNode<K,D>* A = B->getRight();
    RankTreeNode<K,D>* father = C->getFather();

    B->setRight(A->getLeft());
    A->setLeft(B);
    C->setLeft(A->getRight());
    A->setRight(C);

    //fix number of sons
    int new_w = 1;
    if(B->getRight()!= nullptr){
        new_w+= B->getRight()->getNumberOfSons();
    }
    if(B->getLeft() != nullptr){
        new_w+= B->getLeft()->getNumberOfSons();
    }
    B->setNumberOfSons(new_w);

    new_w = 1;
    if(C->getRight()!= nullptr){
        new_w+= C->getRight()->getNumberOfSons();
    }
    if(C->getLeft() != nullptr){
        new_w+= C->getLeft()->getNumberOfSons();
    }
    C->setNumberOfSons(new_w);
    A->setNumberOfSons(B->getNumberOfSons() + C->getNumberOfSons()+1);
    if(father == nullptr){//that means C is the root
        A->father = nullptr;
        this->root = A;
    }
    else {
        father->setSon(A);
    }
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::rotateRR(RankTreeNode<K, D> *B) {
    //B is the unbalanced node with BF<-1
    RankTreeNode<K,D>* A = B->getRight();
    RankTreeNode<K,D>* father = B->getFather();

    B->setRight(A->getLeft());
    A->setLeft(B);

    //fix number of sons
    int new_w = 1;
    if(B->getRight()!= nullptr){
        new_w+= B->getRight()->getNumberOfSons();
    }
    if(B->getLeft() != nullptr){
        new_w+= B->getLeft()->getNumberOfSons();
    }
    B->setNumberOfSons(new_w);
    A->setNumberOfSons(new_w + A->getRight()->getNumberOfSons()+1);

    if(father == nullptr){//that means B is the root
        A->father = nullptr;
        this->root = A;
    }
    else {
        father->setSon(A);
    }
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K,D>::rotateRL(RankTreeNode<K, D>* C) {
    //C is the unbalanced node with BF<-1
    RankTreeNode<K,D>* B = C->getRight();
    //B has BF=1 therefore he has a right son
    RankTreeNode<K,D>* A = B->getLeft();
    RankTreeNode<K,D>* father = C->getFather();

    B->setLeft(A->getRight());
    A->setRight(B);
    C->setRight(A->getLeft());
    A->setLeft(C);
    //fix number of sons
    int new_w = 1;
    if(B->getRight()!= nullptr){
        new_w+= B->getRight()->getNumberOfSons();
    }
    if(B->getLeft() != nullptr){
        new_w+= B->getLeft()->getNumberOfSons();
    }
    B->setNumberOfSons(new_w);

    new_w = 1;
    if(C->getRight()!= nullptr){
        new_w+= C->getRight()->getNumberOfSons();
    }
    if(C->getLeft() != nullptr){
        new_w+= C->getLeft()->getNumberOfSons();
    }
    C->setNumberOfSons(new_w);
    A->setNumberOfSons(B->getNumberOfSons() + C->getNumberOfSons()+1);

    if(father == nullptr){//that means C is the root
        A->father = nullptr;
        this->root = A;
    }
    else {
        father->setSon(A);
    }
    return RANK_TREE_SUCCESS;
}

/**Adding Node Function**/

template<class K, class D>
RankTreeResult RankTree<K, D>::addNewNode(RankTreeNode<K,D>* new_node) {
    K key = new_node->getKey();
    RankTreeNode<K,D>* curr = this->root;
    bool new_biggest_node = true;
    if(curr == nullptr){
        this->root = new_node;
        this->biggest_node = new_node;
        return RANK_TREE_SUCCESS;
    }
    while(curr!= nullptr){
        K curr_key = curr->getKey();
        if(curr_key==key) {
            return RANK_TREE_KEY_ALREADY_EXISTS;
        }
        else if(key>curr_key){
            curr->incNumberOfSons();
            if(curr->getRight() == nullptr){
                curr->setRight(new_node);
                if(new_biggest_node){
                    this->biggest_node = new_node;
                }
                break;
            }
            curr = curr->getRight();
        }
        else if(key<curr_key){
            curr->incNumberOfSons();
            new_biggest_node = false;
            if(curr->getLeft() == nullptr){
                curr->setLeft(new_node);
                break;
            }
            curr = curr->getLeft();
        }
    }
    return RANK_TREE_SUCCESS;
}

/** Balance Node Function **/

template<class K, class D>
RankTreeResult RankTree<K, D>::balanceNode(RankTreeNode<K, D> *curr) {
    if(curr->getBf()==2){
        if(curr->getLeft()->getBf() >= 0){
            if(rotateLL(curr) == RANK_TREE_SUCCESS) return BALANCED;
        }
        if(curr->getLeft()->getBf() == -1){
            if(rotateLR(curr) == RANK_TREE_SUCCESS) return BALANCED;
        }
    }
    if(curr->getBf()==-2){
        if(curr->getRight()->getBf() <= 0){
            if(rotateRR(curr) == RANK_TREE_SUCCESS) return BALANCED;
        }
        if(curr->getRight()->getBf() == 1){
            if(rotateRL(curr) == RANK_TREE_SUCCESS) return BALANCED;
        }
    }
    return NOT_BALANCED;
}

/** Remove main Function **/

template<class K, class D>
RankTreeResult RankTree<K, D>::remove(const K &key) {
    RankTreeNode<K,D>* node_to_delete = findNode(key);
    if(node_to_delete== nullptr){
        return RANK_TREE_KEY_NOT_EXISTS;
    }
    RankTreeNode<K,D>* curr = deleteNode(node_to_delete);
    this->num_of_nodes--;
    K son_key;
    if(curr != nullptr){
        son_key = curr->getKey();
    }
    for(; curr != nullptr ;curr=curr->getFather()){
        curr->decNumberOfSons();
        if(son_key>curr->getKey()){
            curr->hr = curr->getRight()->getHeight();
        }
        else if(son_key<curr->getKey()){
            curr->hl = curr->getLeft()->getHeight();
        }
        if(balanceNode(curr) == BALANCED){
            curr = curr->getFather();
        }
        son_key = curr->getKey();
    }
    return RANK_TREE_SUCCESS;
}

/** Swap Two Nodes **/
template<class K, class D>
RankTreeResult RankTree<K, D>::swapNodes(RankTreeNode<K, D>* a, RankTreeNode<K, D>* b) {
    if(b->getHeight()>a->getHeight()){
        RankTreeNode<K,D>* tmp = a;
        a=b;
        b=tmp;
    }
    RankTreeNode<K,D>* a_father = a->getFather();
    RankTreeNode<K,D>* b_father = b->getFather();

    if (b_father == a) {   // In case a is parent of b
        if (a->getLeft()->key == b->key) {
            b->setLeft(a);
            a->setLeft(nullptr);
            b->setRight(a->getRight());
            a->setRight(nullptr);
        } else { // Right son
            b->setLeft(a->getLeft());
            a->setLeft(nullptr);
            RankTreeNode<K,D>* tn_new_right = b->getRight();
            b->setRight(a);
            a->setRight(tn_new_right);
        }

        // Deal with fathers
        if (a == this->root) {
            this->root = b;
            b->father = nullptr;
        }
        else {
            if (a_father->getLeft() != nullptr &&
                                        a_father->getLeft()->key == a->key) {
                a_father->setLeft(b);
            }
            else{
                a_father->setRight(b);
            }
        }
    }
    else { // At least 1 node between a, b
        b->setLeft(a->getLeft());
        a->setLeft(nullptr);
        RankTreeNode<K,D>* tn_new_right = b->getRight();
        b->setRight(a->getRight());
        a->setRight(tn_new_right);

        if (a == this->root) {
            this->root = b;
            b->father = nullptr;
        }
        else {
            if (a_father->getLeft() != nullptr &&
                                        a_father->getLeft()->key == a->key) {
                a_father->setLeft(b);
            }
            else {
                a_father->setRight(b);
            }
        }
        if (b_father->getLeft() != nullptr &&
                                        b_father->getLeft()->key == b->key) {
            b_father->setLeft(a);
        }
        else {
            b_father->setRight(a);
        }
    }
    int tmp = a->getNumberOfSons();
    a->setNumberOfSons(b->getNumberOfSons());
    b->setNumberOfSons(tmp);
    return RANK_TREE_SUCCESS;
}

/** Delete Node **/
template<class K, class D>
RankTreeNode<K, D> * RankTree<K, D>::deleteNode(RankTreeNode<K, D> *node_to_delete) {
    RankTreeNode<K,D>* dead;
    RankTreeNode<K,D>* father = node_to_delete->getFather();
    bool biggest = (this->biggest_node->getKey() == node_to_delete->getKey());
    if (node_to_delete->getLeft() != nullptr &&
                                        node_to_delete->getRight() == nullptr) {
        dead = node_to_delete;
        if(father == nullptr){
            this->root = node_to_delete->getLeft();
            this->root->father = nullptr;
        }
        else{
            father->setSon(node_to_delete->getLeft());
        }
        if(biggest){
            this->biggest_node = this->biggest_node->getLeft();
            while(this->biggest_node->getRight() != nullptr) {
                this->biggest_node = this->biggest_node->getRight();
            }
        }
        delete dead;
        return father;
    }
    else if (node_to_delete->getLeft() == nullptr &&
                                        node_to_delete->getRight() != nullptr) {
        dead = node_to_delete;
        if(father == nullptr){
            this->root = node_to_delete->getRight();
            this->root->father = nullptr;
        }
        else{
            father->setSon(node_to_delete->getRight());
        }
        delete dead;
        return father;
    }
    else if (node_to_delete->getLeft() == nullptr &&
                                        node_to_delete->getRight() == nullptr) {
        dead = node_to_delete;
        if(father == nullptr){
            this->root = nullptr;
        }
        else if(father->getRight() &&
                        (node_to_delete->key == father->getRight()->getKey())){
            father->setRight(nullptr);
        }
        else{
            father->setLeft(nullptr);
        }
        if(biggest){
            this->biggest_node = father;
        }
        delete dead;
        return father;
    }
    else {
        return deleteNodeWithTwoChildren(node_to_delete);
    }
}

/** Delete Node With Two Children **/
template<class K, class D>
RankTreeNode<K, D> * RankTree<K, D>::deleteNodeWithTwoChildren(
        RankTreeNode<K, D> *node_to_delete) {
    RankTreeNode<K,D>* curr = node_to_delete;
    curr = curr->getRight();
    while(curr->getLeft()!=nullptr){
        curr = curr->getLeft();
    }
    swapNodes(curr, node_to_delete);
    return deleteNode(node_to_delete);
}





/** Print Function **/
template<class K, class D>
void RankTree<K, D>::printAVLTree(RankTreeOrderType type) {
    List<D> ordered_list;
    getTreeToList(type, &ordered_list);
    std::cout<<ordered_list<<std::endl;
}

/* ----------------------------------
 *        Getters To List
 * ----------------------------------
 */
template<class K, class D>
RankTreeResult RankTree<K, D>::getTreeToList(RankTreeOrderType type, List<D> *ordered_list) {
    switch(type){
        case PRE:
            getPreOrder(this->root, ordered_list);
            break;
        case IN:
            getInOrder(this->root, ordered_list);
            break;
        case POST:
            getPostOrder(this->root, ordered_list);
            break;
    }
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::getTreeToList(RankTreeOrderType type, List<D> *ordered_list, int &n) {
    switch(type){
        case PRE:
            getPreOrder(this->root, ordered_list, n);
            break;
        case IN:
            getInOrder(this->root, ordered_list, n);
            break;
        case POST:
            getPostOrder(this->root, ordered_list, n);
            break;
    }
    return RANK_TREE_SUCCESS;
}

/** Recursive Order Functions **/

template<class K, class D>
RankTreeResult RankTree<K, D>::getPreOrder(RankTreeNode<K, D> *root_node,
                                           List <D> *ordered_list) {
    if(root_node == nullptr) return RANK_TREE_SUCCESS;
    ordered_list->pushLast(root_node->getData());
    getPreOrder(root_node->getLeft(),ordered_list);
    getPreOrder(root_node->getRight(),ordered_list);
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::getInOrder(RankTreeNode<K, D> *root_node,
                                          List<D> *ordered_list) {
    if(root_node == nullptr) return RANK_TREE_SUCCESS;
    getInOrder(root_node->getLeft(),ordered_list);
    ordered_list->pushLast(root_node->getData());
    getInOrder(root_node->getRight(),ordered_list);
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::getPostOrder(RankTreeNode<K, D> *root_node,
                                            List<D> *ordered_list) {
    if(root_node == nullptr) return RANK_TREE_SUCCESS;
    getPostOrder(root_node->getLeft(),ordered_list);
    getPostOrder(root_node->getRight(),ordered_list);
    ordered_list->pushLast(root_node->getData());
    return RANK_TREE_SUCCESS;
}


template<class K, class D>
RankTreeResult RankTree<K, D>::getPreOrder(RankTreeNode<K, D> *root_node, List<D> *ordered_list, int &n) {
    if(root_node == nullptr || n == 0) return RANK_TREE_SUCCESS;
    ordered_list->pushLast(root_node->getData());
    n--;
    getPreOrder(root_node->getLeft(), ordered_list, n);
    getPreOrder(root_node->getRight(), ordered_list, n);
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::getInOrder(RankTreeNode<K, D> *root_node, List<D> *ordered_list, int &n) {
    if(root_node == nullptr || n == 0) return RANK_TREE_SUCCESS;
    getInOrder(root_node->getLeft(), ordered_list, n);
    if(n == 0) return RANK_TREE_SUCCESS;
    ordered_list->pushLast(root_node->getData());
    n--;
    getInOrder(root_node->getRight(), ordered_list, n);
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
RankTreeResult RankTree<K, D>::getPostOrder(RankTreeNode<K, D> *root_node, List<D> *ordered_list, int &n) {
    if(root_node == nullptr || n == 0) return RANK_TREE_SUCCESS;
    getPostOrder(root_node->getLeft(), ordered_list, n);
    getPostOrder(root_node->getRight(), ordered_list, n);
    if(n == 0) return RANK_TREE_SUCCESS;
    ordered_list->pushLast(root_node->getData());
    n--;
    return RANK_TREE_SUCCESS;
}

/* ----------------------------------
 *               Find
 * ----------------------------------
 */

template<class K, class D>
D* RankTree<K, D>::find(const K &key) {
    RankTreeNode<K,D>* node_to_find = findNode(key);
    if(node_to_find == nullptr){
        return nullptr;
    }
    return &node_to_find->getData();
}

template<class K, class D>
RankTreeNode<K, D>* RankTree<K, D>::findNode(const K &key) {
    RankTreeNode<K,D>* curr = root;
    while(curr != nullptr){
        K curr_key = curr->getKey();
        if(curr_key == key){
            return curr;
        }
        else if(key<curr_key){
            curr = curr->getLeft();
        }
        else if(key>curr_key){
            curr = curr->getRight();
        }
    }
    return nullptr;
}

/* ----------------------------------
 *              Clear
 * ----------------------------------
 */

template<class K, class D>
void RankTree<K, D>::clear() {
    clearTree(this->root);
    num_of_nodes = 0;
    this->root = nullptr;
    this->biggest_node = nullptr;
    return;
}

template<class K, class D>
void RankTree<K, D>::clearTree(RankTreeNode<K, D> *root_node) {
    if(root_node == nullptr) return;
    clearTree(root_node->getLeft());
    clearTree(root_node->getRight());
    delete root_node;
}

/* ----------------------------------
 *  User-Custom  Iterate Functions
 * ----------------------------------
 */

template<class K, class D>
template<typename Function, typename S>
RankTreeResult RankTree<K, D>::doSomethingInOrder(Function doSomething, int &n,
                                                  List<S>* lst ) {
    return iterateAndDoInOrder(this->root, doSomething, lst, n);
}

template<class K, class D>
template<typename Function, typename S>
RankTreeResult RankTree<K, D>::iterateAndDoInOrder(RankTreeNode<K, D> *node,
                                                   Function doSomething, List<S>* lst, int &n) {
    if(node == nullptr || n == 0) return RANK_TREE_SUCCESS;
    iterateAndDoInOrder(node->getLeft(), doSomething, lst, n);
    if(n == 0) return RANK_TREE_SUCCESS;
    doSomething(node->getData(), n, lst);
    iterateAndDoInOrder(node->getRight(), doSomething, lst, n);
    return RANK_TREE_SUCCESS;
}

template<class K, class D>
int RankTree<K, D>::rank(K key) {
    if(this->find(key) == nullptr){
        return -1;
    }
    RankTreeNode<K,D>* curr = root;
    int rank = 0;
    int left_w;
    while(curr != nullptr){
        left_w = 0;
        K curr_key = curr->getKey();
        if(curr->getLeft()) {
            left_w = curr->getLeft()->getNumberOfSons();
        }
        if(curr_key == key){
            return rank+left_w+1;
        }
        else if(key<curr_key){
            curr = curr->getLeft();
        }
        else if(key>curr_key){
            rank += left_w+1;
            curr = curr->getRight();
        }
    }
    return rank;
}

template<class K, class D>
K RankTree<K, D>::select(int i) {
    if(i<=0 || i>this->num_of_nodes){
        K tmp;
        return tmp;
    }
    RankTreeNode<K,D>* curr = root;
    int index = i;
    int left_w;
    while(curr != nullptr){
        left_w = 0;
        if(curr->getLeft()) {
            left_w = curr->getLeft()->getNumberOfSons();
        }
        if(left_w == index-1){
            return curr->getKey();
        }
        else if(left_w > index-1){
            curr = curr->getLeft();
        }
        else if(left_w < index-1){
            index-= left_w+1;
            curr = curr->getRight();
        }
    }
    return curr->getKey();
}


#endif //AVLTREE_AVLTREE_H
