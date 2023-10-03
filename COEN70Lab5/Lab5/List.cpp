//
//  List.cpp
//  Lab5
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include "List.h"
#include <stdlib.h>
#include <assert.h>

using namespace std;
/*************************************************/

List::List(){
    cursor = NULL;
    n = 0;
} /* end constructor */

List::~List(){}

/*************************************************/

List::List(const List& source){
    operator=(source);
}

/*************************************************/

void List::start(){
    while(cursor->prev() != NULL){
        cursor = cursor->prev();
    }
}

/*************************************************/

void List::end(){
    while(cursor->next() != NULL){
        cursor = cursor->next();
    }
}

/*************************************************/

void List::advance(){
    if(cursor->next() != NULL){
        cursor = cursor->next();
    }
}

/*************************************************/

void List::reverse(){
    if(cursor->prev() != NULL){
        cursor = cursor->prev();
    }
}

/*************************************************/

int List::size(){
    return n;
}

/*************************************************/

int List::current(){
    assert(n != 0);
    return cursor->data();
}

/*************************************************/

std::ostream& operator<<(std::ostream &out, const List& other){
    List::Node* tmp = other.cursor;
    while(tmp != NULL){
        out << tmp->data() << std::endl;
        tmp = tmp->next();
    }
    return out;
}


/*************************************************/

List& List::operator=(const List& other){
    if(this != &other){
        while(size() != 0){
            remove();
        }
        Node* tmp = other.cursor;
        while(tmp->prev()!=NULL)
            tmp=tmp->prev();
        while(tmp != NULL){
            insert(tmp->data());
            tmp = tmp->next();
        }
        
    }
    return *this;
}

/*************************************************/

void List::insert(int data){
    if(n == 0){
        cursor= new Node(data);
        n++;
    }
    else{
        Node* tmp = new Node(data);
        tmp->next() = cursor;
        tmp->prev() = NULL;
        cursor->prev() = tmp;
        cursor = tmp;
        n++;
    }
}

/*************************************************/

void List::attach(int data){
    if(n == 0){
        cursor= new Node(data);
        n++;
    }
    else{
        Node* tmp = new Node(data);
        cursor->next() = tmp;
        tmp->prev() = cursor;
        tmp->next() = NULL;
        cursor = tmp;
        n++;
    }
}

/*************************************************/

void List::remove(){
    Node* tmp = cursor;
    while(tmp != NULL){
        //if(tmp->data() == target){
            if(cursor->next() == NULL){
                cursor = cursor->prev();
                //cursor->next();
                delete tmp;
                n--;
            } else{
                cursor->prev()->next() = cursor->next();
                cursor->next()->prev() = cursor->prev();
                delete tmp;
                n--;
            }
        //}
    }
}

/*************************************************/


void List::display(){
    start();
    Node* tmp = cursor;
    while(tmp != NULL){
        std::cout << tmp->data() << "\n";
        tmp = tmp->next();
    }
    std::cout << "The size of the list is: " << n << endl;
}
