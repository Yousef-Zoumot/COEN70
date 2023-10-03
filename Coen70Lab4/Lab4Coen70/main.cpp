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

using namespace std;

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