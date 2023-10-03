//  Yousef Zoumot
//  main.cpp
//  Coen70HW2.2 *Chapter 3 Problem 5
//
//  Created by Yousef Zoumot on 1/12/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib> //provide size_t

using namespace std;


class set
{
public:
    //TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY=30;
    //CONSTRUCTOR
    set() {used = 0;}
    //MODIFICATION
    size_type erase (const value_type& target);
    bool erase_one(const value_type& target);
    void insert(const value_type&entry);
    void operator +=(const set& addend);
    set operator -(const set& b);
    void operator -=(const set& remove);
    //CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used;}
    size_type count(const value_type& target) const;
    void printValues();
    bool contains(const value_type& target);
    set operator +(const set& b2);
private:
    value_type data[CAPACITY]; //the array to store items
    size_type used;            // much of the array is used
};
//NONMEMBER FUNCTIONS for the set class
set operator +(const set& b1, const set& b2);


const set:: size_type set::CAPACITY;


bool set:: contains(const value_type& target){
    for(size_type i=0; i<size(); i++){
        if(data[i]== target)
            return true;
    }
    return false;
}

set::size_type set::erase(const value_type& target){
    size_type index = 0;
    size_type many_removed = 0;
    
    while(index < used){
        if (data[index] == target){
            --used;
            data[index] = data [used];
            ++many_removed;
        }
        else
            ++index;
    }
    
    return many_removed;
    
}

bool set::erase_one(const value_type& target){
    size_type index;
    index = 0;
    while((index < used) && (data[index] != target))
        ++index;
    if(index == used)
        return false;
    --used;
    data[index] = data[used];
    return true;
}

void set::insert(const value_type& entry){
    assert(size() < CAPACITY);
    if(contains(entry)){
        return;
    }
    data[used] = entry;
    ++used;
    return;
}


set set:: operator -(const set& b){
    set temp = *this;
    for(set::value_type i=0; i< b.size(); i++)
        temp.erase_one(b.data[i]);
    return temp;
    
}


void set:: operator -=(const set& remove){
    for(set::value_type i=0; i< remove.size(); i++)
        erase_one(remove.data[i]);
    
    
}


set::size_type set::count(const value_type& target) const {
    size_type answer;
    size_type i;
    answer = 0;
    for(i = 0; i < used; ++i)
        if (target == data[i])
            ++answer;
    return answer;
}

void set::operator +=(const set& addend){
    assert(size() + addend.size() <= CAPACITY);
    for(int i=0; i<addend.size(); i++){
        if(!contains(addend.data[i])){
            data[used]=addend.data[i];
            used++;
        }
    }
    
}


set set:: operator +(const set& b2){
    set answer;
    
    assert(size() + b2.size() <= CAPACITY);
    answer=*this;
    answer+=b2;
    return answer;
}
void set :: printValues(){//a function that prints all the values in order to clean up the main function
    size_type index=0;
    cout<<"\n";
    while(size() > index){
        cout<<data[index]<<"\n";
        index++;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    set b, b2;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(3);
    
    b2.insert(4);
    b2.insert(5);
    b2.insert(6);
    b2.insert(2);
    b.printValues();
    b2.printValues();
    
    set c;
    c=b+b2;
    c.printValues();
    
    b+=b2;
    b.printValues();
    return 0;
}