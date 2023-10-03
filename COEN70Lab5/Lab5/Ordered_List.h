//
//  Order.h
//  Lab5
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#pragma once
#include <iostream>
#include "list.h"

class Ordered_List: public List {
public:
    Ordered_List();
    Ordered_List(const Ordered_List& source);
    ~Ordered_List();
    Ordered_List& operator=(const Ordered_List& other);
    friend ostream& operator<<(ostream &out, const Ordered_List &other);
    void insert(int x);
    void attach(int x);
    void display();
};
