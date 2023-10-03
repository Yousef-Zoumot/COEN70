//
//  main.cpp
//  Lab4
//
//  Created by Yousef Zoumot on 1/26/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>

using namespace std;

class Queue{
    struct Node{
        Node *next;
        int data;
    };
    Node * head;
public:
    Queue();
    ~Queue();
    Queue(const Queue& source);
    void enqueue(int x);
    int dequeue();
    bool isEmpty() const;
};

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





int main(int argc, const char * argv[]) {
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(4);
    Queue q2(q1);
    cout<<q1.dequeue()<<"\n";
    cout<<q1.dequeue()<<"\n";
    cout<<q1.dequeue()<<"\n";
    cout<<q1.dequeue()<<"\n";
    cout<<q2.isEmpty()<<"\n";
    cout<<q2.dequeue()<<"\n";
    cout<<q2.dequeue()<<"\n";
    cout<<q2.dequeue()<<"\n";
    cout<<q2.dequeue()<<"\n";
    return 0;
}
