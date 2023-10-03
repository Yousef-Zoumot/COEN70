//
//  main.cpp
//  Lab5
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

//#pragma once
#include <iostream>
#include "Ordered_List.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Ordered_List l1;
    l1.insert(1);
    l1.insert(3);
    l1.insert(2);
    l1.insert(4);
    l1.insert(7);
    l1.insert(6);
    l1.display();
    return 0;
}
