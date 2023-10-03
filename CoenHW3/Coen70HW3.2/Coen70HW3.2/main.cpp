//
//  main.cpp
//  Coen70HW3.2 Chapter 5 Problem 4
//
//  Created by Yousef Zoumot on 2/1/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <cstdlib>

using namespace std;

class Node{
public:
    int _data;
    Node* _next;
    Node* _prev;
    Node();
    Node(int data);
};

class LinkedList{
    int used;
    Node* head;
public:
    LinkedList();
    void add(int x);
    void removeAll();
    void removeRepitition();
    void printValues();
    void reverseOrder(Node*& source);
    Node*& getHead();
    
};
Node::Node(){
    _data=0;
    _next=NULL;
    _prev=NULL;
}

Node::Node(int data){
    this->_data = data;
    this->_next = NULL;
    this->_prev = NULL;
}

void LinkedList::removeAll(){
    Node* tmp=head;
    while(tmp->_next!=NULL)
        tmp=tmp->_next;
    Node* tmp2;
    
    while(used!=0 && tmp!=NULL){
        tmp2=tmp->_prev;
        delete tmp;
        used--;
        tmp=tmp2;
    }
    used=0;
    
}

LinkedList::LinkedList(){
    head=new Node();
    used=0;
}

Node*& LinkedList:: getHead(){
    return head;
}

void LinkedList::reverseOrder(Node*& source){
    //Node* tmpHead=NULL;
    Node* tmp=head;
    LinkedList l1;
    while(tmp!=NULL){
        l1.add(tmp->_data);
        tmp=tmp->_next;
    }
    //Node* tmper=l1.head;
    /*while( tmper->_next!=NULL){
        tmper=tmper->_next;
    }
    delete tmper;*/
    while(used!=0)
        removeAll();
    head=l1.head;
    used=l1.used-1;
}

/*void LinkedList::reverseOrder(Node* &source){
    Node* tmp=head;
    Node* dummy=head;
    Node* sup=head;
    Node* place=head;
    //int x=source._data;
    while(place->_next!=NULL){
        cout<<"1";
        tmp=place;
        dummy=place;
        if(tmp->_next!= NULL){
            cout<<"2";
            tmp=tmp->_next;
        }
        while(tmp->_next!=NULL){
            cout<<"3";
            tmp=tmp->_next;
            dummy=dummy->_next;
        }
        while(dummy->_next!=NULL){
            cout<<"4";
            tmp->_next=place;
            if(&head==&place){
                cout<<"5";
                head=tmp;
                sup=tmp;
            }
            else{
                tmp->_next=sup->_next;
                sup->_next=tmp;
                sup=sup->_next;
                
            }
            
            //place=place->_next;
            dummy->_next=NULL;
        }
    }
    head= source;
}*/

void LinkedList::removeRepitition(){
    Node* tmp=head;
    Node* tmp2=head->_next;
    Node* tmp3=head;
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
                used--;
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

void LinkedList::add(int x){
    Node* tmp=new Node(x);
    head->_prev=tmp;
    tmp->_next=head->_next;
    tmp->_prev=NULL;
    head->_next=tmp;
    used++;
    
}

void LinkedList::printValues(){
    int i=0;
    Node* tmp=head->_next;
    
    while(i!=used){
        cout<<"\n"<<tmp->_data;
        tmp=tmp->_next;
        i++;
    }
    cout<<"\n";
}

int main(int argc, const char * argv[]) {
    LinkedList l1;
    l1.add(5);
    l1.add(4);
    l1.add(3);
    l1.add(2);
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(7);
    l1.add(8);
    l1.add(9);
    l1.add(10);
    l1.printValues();
    l1.removeRepitition();
    l1.printValues();
   // Node tmp=l1.getHead();
    l1.reverseOrder(l1.getHead());
    cout<<"above is opposite order of below";
    l1.printValues();
    return 0;
}