//
//  main.cpp
//  Coen70HW3.1 Chapter 5 Problem 2
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
    Node* next;
    Node();
};

class LinkedList{
    int used;
    Node* head;
public:
    LinkedList();
    void add(int x);
    void removeRepitition();
    void printValues();
    
    
};
Node::Node(){
    _data=0;
    next=NULL;
}


LinkedList::LinkedList(){
    head=new Node();
    used=0;
}

void LinkedList::removeRepitition(){
    Node* tmp=head;
    Node* tmp2=head->next;
    Node* tmp3=head;
    Node* tmp5;
   
        while(tmp!=NULL){
            
            tmp2=tmp->next;
            tmp3=tmp;
            while(tmp2!=NULL){
                if(tmp->_data==tmp2->_data){
                    tmp3->next=tmp2->next;
                    tmp5=tmp2;
                    tmp2=tmp2->next;
                    delete tmp5;
                    used--;
                    tmp3=tmp3->next;
                }
                else{
                    tmp2=tmp2->next;
                    tmp3=tmp3->next;
                }
            }
                tmp=tmp->next;
        }
    
}

void LinkedList::add(int x){
    Node* tmp;
    tmp=new Node();
    tmp->next=head->next;
    tmp->_data=x;
    head->next=tmp;
    used++;
    
}

void LinkedList::printValues(){
    int i=0;
    Node* tmp=head->next;
    
    while(tmp!=NULL){
        cout<<"\n"<<tmp->_data;
        tmp=tmp->next;
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
    l1.printValues();
    l1.removeRepitition();
    l1.printValues();
    return 0;
}
