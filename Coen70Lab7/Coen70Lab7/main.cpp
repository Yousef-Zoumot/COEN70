//  Yousef Zoumot Rey-David Palomares
//  main.cpp
//  Coen70Lab7
//
//  Created by Yousef Zoumot on 2/16/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include "Map.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Map<int, int> map1;
    map1.insert(1,2);
    map1.insert(2,3);
    map1.insert(3,4);
    map1.insert(3,4);
    map1.insert(3,3);
    map1.insert(4,4);
    map1.printVales();
    map1.remove_key(2);
    map1.printVales();
    map1.value_of(1);
    return 0;
}
