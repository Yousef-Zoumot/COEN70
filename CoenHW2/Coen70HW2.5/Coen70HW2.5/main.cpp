//  Yousef Zoumot
//  main.cpp
//  Coen70HW2.5 *Chapter 4 Problem 2A
//
//  Created by Yousef Zoumot on 1/18/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include<vector>
#include <cstdlib>//Provides size_t

using namespace std;


class sequence{
public:
    //TYPEDEFS and MEMBER CONSTANTS
    typedef double value_type;
    typedef std::size_t size_type;
    //CONSTRUCTOR
    sequence(const size_t cap);
    //MODIFICATION MEMBER FUNCTIONS
    void start();
    void advance();
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void remove_current();
    
    void addToFront(const value_type& entry);
    void removeFront();
    void addToEnd(const value_type& entry);
    void lastToCurrent();
    
    sequence operator +(const sequence& s2);
    void operator +=(const sequence& s2);
    
    value_type operator[](size_type index);
    
    
    void printValues();
    
    //CONSTANT MEMBER FUNCTIONS
    size_type size() const;
    bool is_item() const;
    value_type current() const;
private:
    value_type* data;
    size_t capacity;
    size_type used;
    size_type current_index;
    void increaseS();
};

int main(int argc, const char * argv[]) {
    // insert code here...
    sequence s1(100), s2(100);
    s1.addToEnd(1);
    s1.addToEnd(2);
    s1.addToEnd(3);
    s1.addToEnd(4);
    s1.addToEnd(5);
    s2.addToEnd(6);
    s2.addToEnd(7);
    s2.addToEnd(8);
    s2.addToEnd(9);
    s1.printValues();
    s2.printValues();
    sequence s3(100);
    s3= s1+s2;
    s3.printValues();
    sequence s4(100);
    s4+=s1;
    s4+=s2;
    s4.printValues();
    cout<<s4[0];
    
    return 0;
}

// MODIFICATION MEMBER FUNCTIONS
sequence::sequence (const size_t cap)
{
    current_index = 0;
    used = 0;
    capacity=cap;
    data= new value_type[capacity];
}

void sequence::start( )
{
    current_index = 0;
}

void sequence::advance( )
{
    current_index++;
}

void sequence::insert(const value_type& entry)
{
    if(current_index==used){
        data[current_index]=entry;
        used++;
        return;
    }
    size_type i;
    for (i = used; i > current_index; i--)
        data[i]= data[i-1];
    
    data[current_index] = entry;
    used++;
}

void sequence::attach(const value_type& entry)
{
    if(!is_item()){
        data[current_index]=entry;
        used++;
        return;
    }
    size_type i;
    for (i = used; i > current_index+1; i--)
        data[i] = data[i+1];
    
    data[current_index+1] = entry;
    current_index++;
    used++;
}

void sequence::remove_current( )
{
    size_type i;
    for (i= current_index; i < used-1; i++)
        data[i] = data[i+1];
    used--;
}

void sequence:: addToFront(const value_type& entry){
    
    if(current_index==used){
        data[current_index]=entry;
        used++;
        return;
    }
    size_type i;
    for (i = used; i > 0; i--)
        data[i]= data[i-1];
    
    data[0] = entry;
    start();
    used++;
}

void sequence:: removeFront(){
    start();
    remove_current();
}

void sequence:: addToEnd(const value_type& entry){
    current_index=used;
    data[current_index]=entry;
    used++;
}

void sequence:: lastToCurrent(){
    data[current_index]=data[used-1];
    used--;
}

double sequence:: operator[](size_type index){
    value_type invalid=100000;
    if(index<size())
        return data[index];
    else{
        cout<<"This is not a valid index";
        return invalid;
    };
}

sequence sequence:: operator +(const sequence& s2){
    sequence temp(100);
    size_type i=0;
    size_type f=0;
    while(temp.size() < size()){
        temp.data[i]=data[i];
        i++;
        temp.used++;
    }
    while (temp.size() < (size()+s2.size())) {
        temp.data[i]=s2.data[f];
        f++;
        i++;
        temp.used++;
    }
    return temp;
}

void sequence:: operator +=(const sequence& s2){
    *this=*this+s2;
    
}

void sequence:: printValues(){
    cout<<"The values in the sequence are as follows: "<<"\n";
    size_type i;
    for(i=0; i<size(); i++)
        cout<<data[i]<<" \n";
}

void sequence:: increaseS(){
    value_type* tmp= new value_type[2*capacity];
    for(int i=0; i<size(); i++){
        tmp[i]=data[i];
    }
    delete[] data;
    data=tmp;
    capacity*=2;
    
}

// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const
{
    return used;
}

bool sequence::is_item( ) const
{
    return current_index != used;
}

sequence::value_type sequence::current( ) const
{
    return data[current_index];
}