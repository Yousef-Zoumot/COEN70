//
//  Header.h
//  Lab4Coen70
//
//  Created by Yousef Zoumot on 1/26/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>

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


