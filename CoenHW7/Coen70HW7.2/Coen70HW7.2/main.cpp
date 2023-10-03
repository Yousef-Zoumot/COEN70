//  Yousef Zoumot
//  main.cpp
//  Coen70HW7.2 Chapter 10 Problem 9
//
//  Created by Yousef Zoumot on 3/13/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//


#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <list>
//#define pow2(n) (1 << (n))

using namespace std;

struct avl_Node
{
    int data;
    struct avl_Node *left;
    struct avl_Node *right;
};

class avlTree
{
public:
    
    avlTree()
    {
        root = NULL;
    }
    avlTree(list<int>);
    int height(){return heightRecursive(root);};
    void insert(int value){root=insertRecursive(root , value);};
    void remove(int value){root=removeRecursive(root, value);};
    void display();
    void inOrder();
    void preOrder();
    void postOrder();
    
private:
    avl_Node *root;
    int heightRecursive(avl_Node *);
    int heightDifferenceRecursive(avl_Node *);
    avl_Node *rightright_rotationRecursive(avl_Node *);
    avl_Node *leftleft_rotationRecursive(avl_Node *);
    avl_Node *leftright_rotationRecursive(avl_Node *);
    avl_Node *rightleft_rotationRecursive(avl_Node *);
    avl_Node* balanceRecursive(avl_Node *);
    avl_Node* insertRecursive(avl_Node *, int );
    avl_Node* removeRecursive(avl_Node *, int );
    void displayRecursive(avl_Node *, int);
    void inOrderRecursive(avl_Node *);
    void preOrderRecursive(avl_Node *);
    void postOrderRecursive(avl_Node *);
    avl_Node* minValueNode(avl_Node* node);
};

avlTree::avlTree(list<int> source){
    root=NULL;
    typename list<int>::iterator it;
    for(it=source.begin(); it!=source.end(); it++){
        insert(*it);
    }
}



void avlTree:: display(){
    if(root ==NULL)
        cout<<"This AVL Tree is empty"<< "\n";
    else{
        displayRecursive(root, 1);
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    
}

void avlTree:: preOrder(){
    preOrderRecursive(root);
}

void avlTree:: inOrder(){
    inOrderRecursive(root);
}

void avlTree:: postOrder(){
    postOrderRecursive(root);
}

avl_Node* avlTree::  minValueNode(avl_Node* node)
{
    avl_Node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    
    return current;
}

//* Height of AVL Tree

int avlTree::heightRecursive(avl_Node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = heightRecursive (temp->left);
        int r_height = heightRecursive (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}


// * Height Difference

int avlTree::heightDifferenceRecursive(avl_Node *temp)
{
    int l_height = heightRecursive (temp->left);
    int r_height = heightRecursive (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


//  Right- Right rotationRecursive

avl_Node *avlTree::rightright_rotationRecursive(avl_Node *parent)
{
    avl_Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left rotationRecursive

avl_Node *avlTree::leftleft_rotationRecursive(avl_Node *parent)
{
    avl_Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


//  Left - Right rotationRecursive

avl_Node *avlTree::leftright_rotationRecursive(avl_Node *parent)
{
    avl_Node *temp;
    temp = parent->left;
    parent->left = rightright_rotationRecursive (temp);
    return leftleft_rotationRecursive (parent);
}


//  Right- Left rotationRecursive

avl_Node *avlTree::rightleft_rotationRecursive(avl_Node *parent)
{
    avl_Node *temp;
    temp = parent->right;
    parent->right = leftleft_rotationRecursive (temp);
    return rightright_rotationRecursive (parent);
}


//  Balancing AVL Tree

avl_Node *avlTree::balanceRecursive(avl_Node *temp)
{
    int bal_factor = heightDifferenceRecursive (temp);
    if (bal_factor > 1)
    {
        if (heightDifferenceRecursive (temp->left) > 0)
            temp = leftleft_rotationRecursive (temp);
        else
            temp = leftright_rotationRecursive (temp);
    }
    else if (bal_factor < -1)
    {
        if (heightDifferenceRecursive (temp->right) > 0)
            temp = rightleft_rotationRecursive (temp);
        else
            temp = rightright_rotationRecursive (temp);
    }
    return temp;
}


//insertRecursive Element into the tree

avl_Node *avlTree::insertRecursive(avl_Node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insertRecursive(root->left, value);
        root = balanceRecursive (root);
    }
    else if (value >= root->data)
    {
        root->right = insertRecursive(root->right, value);
        root = balanceRecursive (root);
    }
    return root;
}

//removes element from tree

avl_Node *avlTree:: removeRecursive(avl_Node *root, int key)
{
    
    
    // PERFORM STANDARD BST DELETE
    
    if (root == NULL)
        return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->data )
        root->left = removeRecursive(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->data )
        root->right = removeRecursive(root->right, key);
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            avl_Node* temp = root->left ? root->left : root->right;
            
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child
            
            delete temp;
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            avl_Node* temp = minValueNode(root->right);
            
            // Copy the inorder successor's data to this node
            root->data = temp->data;
            
            // Delete the inorder successor
            root->right = removeRecursive(root->right, temp->data);
        }
    }
    
    // If the tree had only one node
    if (root == NULL)
        return root;
    
    // GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = heightDifferenceRecursive(root);
    
    // If unbalanced, there are 4 cases
    
    // Left Left Case
    if (balance > 1 && heightDifferenceRecursive(root->left) >= 0)
        return leftleft_rotationRecursive(root);
    
    // Left Right Case
    if (balance > 1 && heightDifferenceRecursive(root->left) < 0)
    {
        return leftright_rotationRecursive(root);
    }
    
    // Right Right Case
    if (balance < -1 && heightDifferenceRecursive(root->right) <= 0)
        return rightright_rotationRecursive(root);
    
    // Right Left Case
    if (balance < -1 && heightDifferenceRecursive(root->right) > 0)
    {
        return rightleft_rotationRecursive(root);
    }
    
    return root;
    
}

//displayRecursive AVL Tree

void avlTree::displayRecursive(avl_Node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        displayRecursive(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        displayRecursive(ptr->left, level + 1);
    }
}


//inOrderRecursive Traversal of AVL Tree

void avlTree::inOrderRecursive(avl_Node *tree)
{
    if (tree == NULL)
        return;
    inOrderRecursive (tree->left);
    cout<<tree->data<<"  ";
    inOrderRecursive (tree->right);
}

//  preOrderRecursive Traversal of AVL Tree

void avlTree::preOrderRecursive(avl_Node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preOrderRecursive (tree->left);
    preOrderRecursive (tree->right);
    
}


// postOrderRecursive Traversal of AVL Tree

void avlTree::postOrderRecursive(avl_Node *tree)
{
    if (tree == NULL)
        return;
    postOrderRecursive ( tree ->left );
    postOrderRecursive ( tree ->right );
    cout<<tree->data<<"  ";
}

int main(int argc, const char * argv[]) {
    avlTree avlt1 = avlTree();
    avlt1.insert(5);
    avlt1.insert(4);
    avlt1.insert(3);
    avlt1.insert(2);
    avlt1.insert(1);
    avlt1.display();
    avlt1.remove(4);
    avlt1.display();
    list<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    myList.push_back(7);
    avlTree avl2=avlTree(myList);
    avl2.display();
    
    
}