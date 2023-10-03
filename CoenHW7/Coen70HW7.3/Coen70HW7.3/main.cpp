//  Yousef Zoumot
//  main.cpp
//  Coen70HW7.2 Chapter 10 Problem 12
//
//  Created by Yousef Zoumot on 3/13/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//


#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include "string.h"


using namespace std;


class Book
{
public:
    struct BookNode
    {
        BookNode(string nam, string auth, int isbn, string dat);
        string name;
        string author;
        int iSBN;
        string date;
        struct BookNode *left;
        struct BookNode *right;
    };
    
    Book()
    {
        root = NULL;
    }
    Book(list<int>);
    int height(){return heightRecursive(root);};
    void insert(BookNode source){root=insertRecursive(root ,source);};
    void remove(int value){root=removeRecursive(root, value);};
    void display();
    void inOrder();
    void preOrder();
    void postOrder();
    
private:
    BookNode *root;
    int heightRecursive(BookNode *);
    int heightDifferenceRecursive(BookNode *);
    BookNode *rightright_rotationRecursive(BookNode *);
    BookNode *leftleft_rotationRecursive(BookNode *);
    BookNode *leftright_rotationRecursive(BookNode *);
    BookNode *rightleft_rotationRecursive(BookNode *);
    BookNode* balanceRecursive(BookNode *);
    BookNode* insertRecursive(BookNode *, BookNode source);
    BookNode* removeRecursive(BookNode *, int );
    void displayRecursive(BookNode *, int);
    void inOrderRecursive(BookNode *);
    void preOrderRecursive(BookNode *);
    void postOrderRecursive(BookNode *);
    BookNode* minValueNode(BookNode* node);
};

bool lowercase(char c1, char c2){
    return tolower(c1) < tolower(c2);
}

Book::BookNode::BookNode(string nam, string auth, int isbn, string dat){
    name=nam;
    author=auth;
    iSBN=isbn;
    date=dat;
}

void Book:: display(){
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

void Book:: preOrder(){
    preOrderRecursive(root);
}

void Book:: inOrder(){
    inOrderRecursive(root);
}

void Book:: postOrder(){
    postOrderRecursive(root);
}

Book::BookNode* Book::  minValueNode(BookNode* node)
{
    BookNode* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    
    return current;
}

//* Height of AVL Tree

int Book::heightRecursive(BookNode *temp)
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

int Book::heightDifferenceRecursive(BookNode *temp)
{
    int l_height = heightRecursive (temp->left);
    int r_height = heightRecursive (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


//  Right- Right rotationRecursive

Book::BookNode *Book::rightright_rotationRecursive(BookNode *parent)
{
    BookNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left rotationRecursive

Book::BookNode *Book::leftleft_rotationRecursive(BookNode *parent)
{
    BookNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


//  Left - Right rotationRecursive

Book::BookNode *Book::leftright_rotationRecursive(BookNode *parent)
{
    BookNode *temp;
    temp = parent->left;
    parent->left = rightright_rotationRecursive (temp);
    return leftleft_rotationRecursive (parent);
}


//  Right- Left rotationRecursive

Book::BookNode *Book::rightleft_rotationRecursive(BookNode *parent)
{
    BookNode *temp;
    temp = parent->right;
    parent->right = leftleft_rotationRecursive (temp);
    return rightright_rotationRecursive (parent);
}


//  Balancing AVL Tree

Book::BookNode *Book::balanceRecursive(BookNode *temp)
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

Book::BookNode *Book::insertRecursive(BookNode *root, BookNode source)
{
    if (root == NULL)
    {
        root = new BookNode(source.name, source.author, source.iSBN, source.date);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
        string temp1=source.author;
        string temp2=root->author;
        for(int i=0; i<temp1.size(); i++){
            temp1[i]=tolower(temp1[i]);
        }
        for(int i=0; i<temp2.size(); i++){
            temp2[i]=tolower(temp2[i]);
        }
    if( temp1 < temp2)
    {
        root->left = insertRecursive(root->left, source);
        root = balanceRecursive (root);
    }
    else if (temp1 >= temp2)
    {
        root->right = insertRecursive(root->right, source);
        root = balanceRecursive (root);
    }
    return root;
}

//removes element from tree
/*
Book::BookNode *Book:: removeRecursive(BookNode *root, int key)
{
    
    
    // PERFORM STANDARD BST DELETE
    
    if (root == NULL)
        return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->author )
        root->left = removeRecursive(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->author )
        root->right = removeRecursive(root->right, key);
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            BookNode* temp = root->left ? root->left : root->right;
            
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
            BookNode* temp = minValueNode(root->right);
            
            // Copy the inorder successor's data to this node
            root->author = temp->author;
            
            // Delete the inorder successor
            root->right = removeRecursive(root->right, temp->author);
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
*/
//displayRecursive AVL Tree

void Book::displayRecursive(BookNode *ptr, int level)
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
        cout<<ptr->author;
        displayRecursive(ptr->left, level + 1);
    }
}


//inOrderRecursive Traversal of AVL Tree

void Book::inOrderRecursive(BookNode *tree)
{
    if (tree == NULL)
        return;
    inOrderRecursive (tree->left);
    cout<<tree->author<<"  ";
    inOrderRecursive (tree->right);
}

//  preOrderRecursive Traversal of AVL Tree

void Book::preOrderRecursive(BookNode *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->author<<"  ";
    preOrderRecursive (tree->left);
    preOrderRecursive (tree->right);
    
}


// postOrderRecursive Traversal of AVL Tree

void Book::postOrderRecursive(BookNode *tree)
{
    if (tree == NULL)
        return;
    postOrderRecursive ( tree ->left );
    postOrderRecursive ( tree ->right );
    cout<<tree->author<<"  ";
}

int main(int argc, const char * argv[]) {
    Book::BookNode *b1= new Book::BookNode("name", "author1", 1234, "3/6/2001");
    Book::BookNode *b2= new Book::BookNode("name", "author2", 123456, "3/6/2001");
    Book::BookNode *b3= new Book::BookNode("name", "author3", 12345, "3/6/2001");
    Book::BookNode *b4= new Book::BookNode("name", "author4", 12346, "3/6/2001");
    Book::BookNode *b5= new Book::BookNode("name", "author5", 12356, "3/6/2001");
    Book::BookNode *b6= new Book::BookNode("name", "author6", 12456, "3/6/2001");
    Book::BookNode *b7= new Book::BookNode("name", "author7", 13456, "3/6/2001");
    Book::BookNode *b8= new Book::BookNode("name", "author4", 23456, "3/6/2001");
    Book avlt1 = Book();
    avlt1.insert(*b1);
    avlt1.insert(*b2);
    avlt1.insert(*b3);
    avlt1.insert(*b4);
    avlt1.insert(*b5);
    avlt1.insert(*b6);
    avlt1.insert(*b7);
    avlt1.insert(*b8);
    avlt1.display();
}