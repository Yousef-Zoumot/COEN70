//
//  main.cpp
//  Lab4Coen70
//
//  Created by Yousef Zoumot on 1/26/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "Queue.h"

Queue::Queue(){
    head=NULL;
}

Queue::~Queue(){
    while(!isEmpty())
        dequeue();
}

Queue::Queue(const Queue& source){
    if(this==&source)
        return;
    while(!isEmpty())
        dequeue();
    if(source.isEmpty()){
        return;
    }
    Node* temp=source.head;
    while(temp!=NULL){
        enqueue(temp->data);
        temp=temp->next;
    }
}

void Queue:: enqueue(int x){
    Node* tmp= new Node;
    tmp->data=x;
    if(head==NULL){
        head=tmp;
        head->next=NULL;
        return;
    }
    if(x>=head->data){
        tmp->next=head;
        head=tmp;
        return;
    }
    Node* cursor=head;
    while(cursor->next!=NULL && cursor->next->data>x){
        cursor=cursor->next;
    }
    tmp->next=cursor->next;
    cursor->next=tmp;
    return;
}

int Queue:: dequeue(){
    assert(!isEmpty());
    Node * tmp= head;
    head=tmp->next;
    int _data=tmp->data;
    delete tmp;
    return _data;
}

bool Queue:: isEmpty()const{
    return head==NULL;
}


