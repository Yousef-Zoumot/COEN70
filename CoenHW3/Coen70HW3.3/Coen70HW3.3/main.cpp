//
//  main.cpp
//  Coen70HW3.3 *Chpater 5 Problem 12b
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Set{
protected:
    struct Node{
        Node* _prev;
        Node* _next;
        int _data;
        Node(int data, Node* prev = NULL, Node* next = NULL){
            this->_data = data;
            this->_prev = prev;
            this->_next = next;
        }
        int& data(){return _data;};
        Node*& next(){return _next;};
        Node*& prev(){return _prev;};
        
    };
    
    Node* cursor;
    int n;
public:
    Set();
    Set(const Set& source);
    ~Set();
    void start();
    void end();
    void advance();
    void reverse();
    int size();
    void insert(int data);
    void attach(int data);
    int current();
    void remove();
    void display();
    void removeRepitition();
    bool contains(const int& target);
    Set& operator=(const Set& other);
    friend ostream& operator<<(ostream &out, const Set &other);
    
};

bool Set:: contains(const int& target){//prints 1 if true 0 if false
    Node* tmp=cursor;
    while(tmp->_prev!=NULL){
        tmp=tmp->_prev;
    }
    while(tmp->_next!=NULL){
        if(tmp->_data==target)
            return true;
        tmp=tmp->_next;
    }
    return false;
}

void Set::removeRepitition(){
    Node* tmp=cursor;
    while(tmp->_prev!=NULL)
        tmp=tmp->_prev;
    Node* tmp2=tmp->_next;
    Node* tmp3=tmp;
    Node* tmp5;
    
    while(tmp!=NULL){
        
        tmp2=tmp->_next;
        tmp3=tmp;
        while(tmp2!=NULL){
            if(tmp->_data==tmp2->_data){
                tmp3->_next=tmp2->_next;
                tmp5=tmp2;
                tmp2=tmp2->_next;
                delete tmp5;
                n--;
                tmp3=tmp3->_next;
            }
            else{
                tmp2=tmp2->_next;
                tmp3=tmp3->_next;
            }
        }
        tmp=tmp->_next;
    }
    
}
/*************************************************/

Set::Set(){
    cursor = NULL;
    n = 0;
} /* end constructor */

Set::~Set(){}

/*************************************************/

Set::Set(const Set& source){
    operator=(source);
}

/*************************************************/

void Set::start(){
    while(cursor->prev() != NULL){
        cursor = cursor->prev();
    }
}

/*************************************************/

void Set::end(){
    while(cursor->next() != NULL){
        cursor = cursor->next();
    }
}

/*************************************************/

void Set::advance(){
    if(cursor->next() != NULL){
        cursor = cursor->next();
    }
}

/*************************************************/

void Set::reverse(){
    if(cursor->prev() != NULL){
        cursor = cursor->prev();
    }
}

/*************************************************/

int Set::size(){
    return n;
}

/*************************************************/

int Set::current(){
    assert(n != 0);
    return cursor->data();
}

/*************************************************/

std::ostream& operator<<(std::ostream &out, const Set& other){
    Set::Node* tmp = other.cursor;
    while(tmp != NULL){
        out << tmp->data() << std::endl;
        tmp = tmp->next();
    }
    return out;
}


/*************************************************/

Set& Set::operator=(const Set& other){
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

void Set::insert(int data){
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
    removeRepitition();
}

/*************************************************/

void Set::attach(int data){
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
    removeRepitition();
}

/*************************************************/

void Set::remove(){
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


void Set::display(){
    start();
    Node* tmp = cursor;
    while(tmp != NULL){
        std::cout << tmp->data() << "\n";
        tmp = tmp->next();
    }
    std::cout << "The size of the Set is: " << n << endl;
}

int main(int argc, const char * argv[]) {
    Set s1;
    s1.insert(5);
    s1.insert(4);
    s1.insert(3);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.display();
    cout<<s1.contains(1)<<"\n";//prints 1 if true 0 if false
    cout<<s1.contains(10)<<"\n";//prints 1 if true 0 if false
    return 0;
}
