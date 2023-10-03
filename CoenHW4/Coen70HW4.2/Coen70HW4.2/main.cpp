// Yousef Zoumot
//  main.cpp
//  Coen70HW4.2 Chapter 6 Problem 2b
//
//  Created by Yousef Zoumot on 2/14/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <cstdlib>//Provides size_t

using namespace std;

template <class T>
class sequence{
public:
    //TYPEDEFS and MEMBER CONSTANTS
    typedef std::size_t size_type;
    static const size_type CAPACITY=30;
    //CONSTRUCTOR
    sequence();
    //MODIFICATION MEMBER FUNCTIONS
    void start();
    void advance();
    void insert(const T& entry);
    void attach(const T& entry);
    void remove_current();
    
    void addToFront(const T& entry);
    void removeFront();
    void addToEnd(const T& entry);
    void lastToCurrent();
    
    sequence operator +(const sequence& s2);
    void operator +=(const sequence& s2);
    
    T operator[](size_type index);
    
    void printValues();
    
    //CONSTANT MEMBER FUNCTIONS
    size_type size() const;
    bool is_item() const;
    T current() const;
private:
    T data[CAPACITY];
    size_type used;
    size_type current_index;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    sequence<int> s1;
    sequence<int> s2;
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
    sequence<int> s3;
    s3= s1+s2;
    s3.printValues();
    sequence<int> s4;
    s4+=s1;
    s4+=s2;
    s4.printValues();
    cout<<s4[0];
    
    return 0;
}

// MODIFICATION MEMBER FUNCTIONS
template <class T>
sequence<T>::sequence ()
{
    current_index = 0;
    used = 0;
}
template <class T>
void sequence<T>::start( )
{
    current_index = 0;
}
template <class T>
void sequence<T>::advance( )
{
    current_index++;
}
template <class T>
void sequence<T>::insert(const T& entry)
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
template <class T>
void sequence<T>::attach(const T& entry)
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
template <class T>
void sequence<T>::remove_current( )
{
    size_type i;
    for (i= current_index; i < used-1; i++)
        data[i] = data[i+1];
    used--;
}
template <class T>
void sequence<T>:: addToFront(const T& entry){
    
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
template <class T>
void sequence<T>:: removeFront(){
    start();
    remove_current();
}
template <class T>
void sequence<T>:: addToEnd(const T& entry){
    current_index=used;
    data[current_index]=entry;
    used++;
}
template <class T>
void sequence<T>:: lastToCurrent(){
    data[current_index]=data[used-1];
    used--;
}
template <class T>
T sequence<T>:: operator[](size_type index){
    T invalid=100000;
    if(index<size())
        return data[index];
    else{
        cout<<"This is not a valid index";
        return invalid;
    };
}
template <class T>
sequence<T> sequence<T>:: operator +(const sequence& s2){
    sequence temp;
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
template <class T>
void sequence<T>:: operator +=(const sequence& s2){
    *this=*this+s2;
    
}
template <class T>
void sequence<T>:: printValues(){
    cout<<"The values in the sequence are as follows: "<<"\n";
    size_type i;
    for(i=0; i<size(); i++)
        cout<<data[i]<<" \n";
}

// CONSTANT MEMBER FUNCTIONS
template <class T>
size_t sequence<T>::size( ) const
{
    return used;
}
template <class T>
bool sequence<T>::is_item( ) const
{
    return current_index != used;
}
template <class T>
T sequence<T>::current( ) const
{
    return data[current_index];
}
