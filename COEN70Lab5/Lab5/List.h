//
//  List.h
//  Lab5
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//


#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class List{
protected:
    struct Node{
        Node* _prev;
        Node* _next;
        int _data;
        Node(int data, Node* prev = NULL, Node* next = NULL){
            this->_data = data;
            this->_prev = prev;
            this->_next = next;
        }
        int& data(){return _data;};
        Node*& next(){return _next;};
        Node*& prev(){return _prev;};
        
    };

    Node* cursor;
    int n;
public:
        List();
    List(const List& source);
    ~List();
    void start();
    void end();
    void advance();
    void reverse();
    int size();
    void insert(int data);
    void attach(int data);
    int current();
    void remove();
    void display();
    List& operator=(const List& other);
    friend ostream& operator<<(ostream &out, const List &other);
    
};
