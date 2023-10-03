//  Yousef Zoumot
//  main.cpp
//  Coen70HW6.3 * Chapter 10 Problem 4
//
//  Created by Yousef Zoumot on 3/6/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <utility>

#define p(x) (((x)-1)/2)  //returns parent location
#define l(x) ((x)*2+1)  //returns left child location
#define r(x) ((x)*2+2)  //returns right child location


using namespace std;

template <class T>
struct Node {
    T value;
    Node *left;
    Node *right;
    
    Node(T val) {
        this->value = val;
    }
    
    Node(T val, Node<T> left, Node<T> right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
};

/////***************************************************************/////
template <class T>
class BinaryTree {
    
private:
    Node<T> *root;
    int count;
    void addRecursive(Node<T> *root, T val);
    void printRecursive(Node<T> *root);
    int nodesCountRecursive(Node<T> *root);
    int heightRecursive(Node<T> *root);
    bool deleteValueRecursive(Node<T>* parent, Node<T>* current, T value);
    
public:
    vector<bool > is_present;
    void updatePresent1();
    void updatePresent2(Node<T> *tree, int);
    void is_present_user(int i);
    int size(){return count;};
    void add(T val);
    void print();
    int nodesCount();
    int height();
    bool deleteValue(T value);
};

template<class T>
void BinaryTree<T>:: updatePresent1(){
    is_present.resize(pow(2, height())-1);
    updatePresent2(root, 0);
}

template<class T>
void BinaryTree<T>:: updatePresent2(Node<T> *tree, int index){
    if (tree == NULL){
        is_present[index]=false;
            return;
    }
    else{
        is_present[index]=true;
    }
    
        index=l(index);
        updatePresent2(tree->left, index);
        index=r(index);
        updatePresent2(tree->right, index);
}

template <class T>
void BinaryTree<T>:: is_present_user(int i){
    updatePresent1();
    if(is_present[i]){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<"\n";
}

/////***************************************************************/////
template <class T>
void BinaryTree<T>:: addRecursive(Node<T> *root, T val) {
    if (root->value > val) {
        if (!root->left) {
            root->left = new Node<T>(val);
        } else {
            addRecursive(root->left, val);
        }
    } else {
        if (!root->right) {
            root->right = new Node<T>(val);
        } else {
            addRecursive(root->right, val);
        }
    }
}
/////***************************************************************/////
template <class T>
void BinaryTree<T>:: printRecursive(Node<T> *root) {
    if (!root) return;
    printRecursive(root->left);
    cout<<root->value<<' ';
    printRecursive(root->right);
}
/////***************************************************************/////
template <class T>
int BinaryTree<T>:: nodesCountRecursive(Node<T> *root) {
    if (!root) return 0;
    else return 1 + nodesCountRecursive(root->left) + nodesCountRecursive(root->right);
}
/////***************************************************************/////
template <class T>
int BinaryTree<T>:: heightRecursive(Node<T> *root) {
    if (!root) return 0;
    else return 1 + max(heightRecursive(root->left), heightRecursive(root->right));
}
/////***************************************************************/////
template <class T>
bool BinaryTree<T>:: deleteValueRecursive(Node<T>* parent, Node<T>* current, T value) {
    if (!current) return false;
    if (current->value == value) {
        if (current->left == NULL || current->right == NULL) {
            Node<T>* temp = current->left;
            if (current->right) temp = current->right;
            if (parent) {
                if (parent->left == current) {
                    parent->left = temp;
                } else {
                    parent->right = temp;
                }
            } else {
                this->root = temp;
            }
        } else {
            Node<T>* substitute = current->right;
            while (substitute->left) {
                substitute = substitute->left;
            }
            T temp = current->value;
            current->value = substitute->value;
            substitute->value = temp;
            return deleteValueRecursive(current, current->right, temp);
        }
        delete current;
        return true;
    }
    return deleteValueRecursive(current, current->left, value) ||
    deleteValueRecursive(current, current->right, value);
}
/////***************************************************************/////
template <class T>
void BinaryTree<T>:: add(T val) {
    if (root) {
        this->addRecursive(root, val);
    } else {
        root = new Node<T>(val);
    }
}
/////***************************************************************/////
template <class T>
void BinaryTree<T>:: print() {
    printRecursive(this->root);
    cout<<"\n";
}
/////***************************************************************/////
template <class T>
int BinaryTree<T>:: nodesCount() {
    return nodesCountRecursive(root);
}
/////***************************************************************/////
template <class T>
int BinaryTree<T>:: height() {
    return heightRecursive(this->root);
}
/////***************************************************************/////
template <class T>
bool BinaryTree<T>:: deleteValue(T value) {
    return this->deleteValueRecursive(NULL, this->root, value);
}
/////***************************************************************/////


int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree<int> *bst1=new BinaryTree<int>();
    bst1->add(5);
    bst1->add(4);
    bst1->add(7);
    bst1->add(2);
    bst1->add(9);
    bst1->add(8);
    bst1->print();
    bst1->deleteValue(5);
    bst1->print();
    bst1->is_present_user(0);
    bst1->is_present_user(1);
    bst1->is_present_user(7);
    return 0;
}
