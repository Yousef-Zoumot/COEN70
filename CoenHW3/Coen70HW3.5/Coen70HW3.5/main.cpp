//
//  main.cpp
//  Coen70HW3.5
//
//  Created by Yousef Zoumot on 2/3/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

class Sequence{
public:
    Sequence();
    //Sequence(const Sequence& source);
    //~Sequence();
    //Modification Member Functions
    void start() {ptr_cursor = ptr_head;};
    void end() {ptr_cursor = ptr_tail;};
    void advance() {ptr_cursor = ptr_cursor->next();};
    void retreat() {ptr_cursor = ptr_cursor->prev();};
    void insert(const int& data);
    void attach(const int& data);
    void remove_current();
    void addToFront(const int& data);
    void addToEnd(const int& data);
    
    //CONSTANT MEMBER FUNCTIONS
    void printValues();
    int size() const {return used;};
    bool is_item() const;
    int current() const {return ptr_cursor->data();};
private:
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
    Node* ptr_head;
    Node* ptr_tail;
    Node* ptr_cursor;
    int used;            //How much of the array is used
};
////********************************************************////
Sequence::Sequence(){
    ptr_head=NULL;
    ptr_tail=NULL;
    ptr_cursor=NULL;
    used=0;
}
////********************************************************////
void Sequence::addToFront(const int& data){//Does not move cursor
    Node* tmp=new Node(data);
    if(used==0 && ptr_head==NULL){
        ptr_head=tmp;
        ptr_tail=tmp;
        ptr_cursor=tmp;
        used++;
        return;
    }
    ptr_head->prev()=tmp;
    tmp->next()=ptr_head;
    ptr_head=tmp;
    tmp->prev()=NULL;
    used++;
}
////********************************************************////
void Sequence::addToEnd(const int& data){//Does not move cursor
    Node* tmp=new Node(data);
    if(used==0 && ptr_tail==NULL){
        ptr_head=tmp;
        ptr_tail=tmp;
        ptr_cursor=tmp;
        used++;
        return;
    }
    ptr_tail->next()=tmp;
    tmp->prev()=ptr_tail;
    ptr_tail=tmp;
    tmp->next()=NULL;
    used++;
}
////********************************************************////
void Sequence::insert(const int& data){//Does move cursor
    Node* tmp=new Node(data);
    if(used==0 && ptr_cursor==NULL){
        ptr_head=tmp;
        ptr_tail=tmp;
        ptr_cursor=tmp;
        used++;
        return;
    }
    if(ptr_cursor->prev()==NULL){
        ptr_cursor->prev()=tmp;
        tmp->next()=ptr_cursor;
        ptr_cursor=tmp;
        tmp->prev()=NULL;
        ptr_head=tmp;
        used++;
    }
    else{
        tmp->prev()=ptr_cursor->prev();
        ptr_cursor->prev()=tmp;
        tmp->next()=ptr_cursor;
        ptr_cursor=tmp;
        used++;
    }
}
////********************************************************////
void Sequence::attach(const int& data){//Does move cursor
    Node* tmp=new Node(data);
    if(used==0 && ptr_cursor==NULL){
        ptr_head=tmp;
        ptr_tail=tmp;
        ptr_cursor=tmp;
        used++;
        return;
    }
    if(ptr_cursor->next()==NULL || ptr_cursor==ptr_tail){
        ptr_cursor->next()=tmp;
        tmp->prev()=ptr_cursor;
        ptr_cursor=tmp;
        tmp->next()=NULL;
        ptr_tail=tmp;
        used++;
    }
    else{
        ptr_cursor->next()->prev()=tmp;
        tmp->next()=ptr_cursor->next();
        ptr_cursor->next()=tmp;
        tmp->prev()=ptr_cursor;
        ptr_cursor=tmp;
        used++;
    }
}
////********************************************************////
void Sequence::remove_current(){//Moves cursor to next unless cursor is at the end
    Node* tmp;
    if(used==0 && ptr_cursor==NULL){
        return;
    }
    if(ptr_cursor->next()==NULL){
        tmp=ptr_cursor;
        ptr_cursor=ptr_cursor->prev();
        ptr_cursor->next()=NULL;
        ptr_tail=ptr_cursor;
        delete tmp;
        used--;
        return;
    }
    if(ptr_cursor->prev()==NULL){
        tmp=ptr_cursor;
        ptr_cursor=ptr_cursor->next();
        ptr_cursor->prev()=NULL;
        ptr_head=ptr_cursor;
        delete tmp;
        used--;
        return;
    }
    else{
        tmp=ptr_cursor;
        ptr_cursor=ptr_cursor->next();
        ptr_cursor->prev()=tmp->prev();
        delete tmp;
        used--;
        return;
    }
}
////********************************************************////
bool Sequence:: is_item() const{
    if(ptr_cursor==NULL)
        return false;
    else{
        return true;
    }
}
////********************************************************////
void Sequence:: printValues(){
    Node* tmp=ptr_head;
    cout<<"The values are:"<<"\n";
    while(tmp!=NULL){
        cout<<tmp->data()<<"\n";
        tmp=tmp->next();
    }
    cout<<"\n";
}

int main(int argc, const char * argv[]) {
    
    ///*
    Sequence s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    Sequence s2(s1);
    s2.start();
    s2.remove_current();
    s1.printValues();
    s2.printValues();
    //*/
    /*
    Sequence s1;
    s1.attach(1);
    s1.attach(2);
    s1.attach(3);
    s1.attach(4);
    s1.attach(5);
    //Sequence s2(s1);
    
    s2.start();
    s1.end();
    
    s2.remove_current();
    s1.remove_current();
    s1.printValues();
    s2.printValues();
     */
    return 0;
}
