//
//  Lab2coen70.cpp
//  Lab1
//
//  Created by Yousef Zoumot on 1/5/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

/* Lab1B.cpp */
#include <iostream>
using namespace std;
int main() {
    int score[10];
    for (int i=1; i <= 10; ++i) {
        score[i]=3*i;
        cout << score[i];
    }
    return 0;
}