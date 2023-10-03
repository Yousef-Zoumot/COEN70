//  Yousef Zoumot
//  main.cpp
//  Coen70HW4.5 Chapter 6 Problem 8
//
//  Created by Yousef Zoumot on 2/14/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//



#include <iostream>
#include <cassert>
#include <cstdlib> //provide size_t
#include <utility>

using namespace std;

class Gift{
    char _gift[40];
public:
    void typeGift();
    void printGift();
};

class Person{
private:
    char name[40];
public:
    Person(){used_g = 0;};
    Gift gifts[100];
    void addGift(Gift& g);
    void typeName();
    void printName();
    int used_g;
};

class Gift_List{
    Person people[100];
    int used_p;
public:
    Gift_List(){used_p=0;};
    void addPerson(Person& p);
    void removeLast();
    void printList();
};

void Gift_List:: printList(){
    cout<<"The list is as follows: "<<"\n";
    for(int i=0; i<used_p; i++){
        people[i].printName();
        cout<< " has a gift list that consists of: "<<"\n";
        for(int k=0; k<people[i].used_g; k++ ){
            people[i].gifts[k].printGift();
            cout<<"\n";
        }
    }
    
}

void Gift_List:: removeLast(){
    used_p--;
}

void Gift_List:: addPerson(Person& p){
    people[used_p]=p;
    used_p++;
}
void Person:: addGift(Gift& g){
    gifts[used_g]=g;
    used_g++;
}

void Gift:: typeGift(){
    cout<<"Please type a gift less that 40 characters long: "<< "\n";
    cin>>_gift;
}

void Gift:: printGift(){
    cout<<_gift;
}

void Person:: printName(){
    cout<<name;
    
}

void Person:: typeName(){
    cout<<"Please type a name less that 40 characters long: "<< "\n";
    cin>>name;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Person p1, p2, p3;
    p1.typeName();
    p2.typeName();
    p3.typeName();
    Gift g1, g2, g3, g4, g5, g6;
    g1.typeGift();
    g2.typeGift();
    g3.typeGift();
    g4.typeGift();
    g5.typeGift();
    g6.typeGift();
    p1.addGift(g1);
    p1.addGift(g4);
    p2.addGift(g2);
    p2.addGift(g5);
    p3.addGift(g3);
    p3.addGift(g6);
    
    Gift_List gl;
    gl.addPerson(p1);
    gl.addPerson(p2);
    gl.addPerson(p3);
    gl.printList();
    gl.removeLast();
    gl.printList();
    return 0;
}