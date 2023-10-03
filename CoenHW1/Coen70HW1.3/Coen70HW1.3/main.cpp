//  Yousef Zoumot
//  main.cpp
//  Coen70HW1.3 *Chapter 3 Problem 2
//
//  Created by Yousef Zoumot on 1/12/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib> //provide size_t

using namespace std;


class bag
{
public:
    //TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY=30;
    //CONSTRUCTOR
    bag() {used = 0;}
    //MODIFICATION
    size_type erase (const value_type& target);
    bool erase_one(const value_type& target);
    void insert(const value_type&entry);
    void operator +=(const bag& addend);
    bag operator -(const bag& b);
    void operator -=(const bag& remove);
    //CONSTANT MEMBER FUNCTIONS
    size_type size() const { return used;}
    size_type count(const value_type& target) const;
    void printValues();
private:
    value_type data[CAPACITY]; //the array to store items
    size_type used;            //How much of the array is used
};
//NONMEMBER FUNCTIONS for the bag class
bag operator +(const bag& b1, const bag& b2);


const bag:: size_type bag::CAPACITY;

bag::size_type bag::erase(const value_type& target){
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

bool bag::erase_one(const value_type& target){
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

void bag::insert(const value_type& entry){
    assert(size() < CAPACITY);
    data[used] = entry;
    ++used;
}

void bag::operator +=(const bag& addend){
    assert(size() + addend.size() <= CAPACITY);
    copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}

bag bag:: operator -(const bag& b){
    bag temp = *this;
    for(bag::value_type i=0; i< b.size(); i++)
        temp.erase_one(b.data[i]);
    return temp;
    
}


void bag:: operator -=(const bag& remove){
    for(bag::value_type i=0; i< remove.size(); i++)
        erase_one(remove.data[i]);
    
    
}


bag::size_type bag::count(const value_type& target) const {
    size_type answer;
    size_type i;
    answer = 0;
    for(i = 0; i < used; ++i)
        if (target == data[i])
            ++answer;
    return answer;
}

bag operator +(const bag& b1, const bag& b2){
    bag answer;
    
    assert(b1.size() + b2.size() <= bag::CAPACITY);
    
    answer += b1;
    answer += b2;
    return answer;
}
void bag :: printValues(){//a function that prints all the values in order to clean up the main function
    size_type index=0;
    cout<<"\n";
    while(size() > index){
        cout<<data[index]<<"\n";
        index++;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    bag b, b2;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(3);
    
    b2.insert(3);
    b2.insert(7);
    b2.insert(2);
    b2.insert(3);
    b.printValues();
    b2.printValues();
    
    bag c;
    c=b-b2;
    c.printValues();
    
    b-=b2;
    b.printValues();
    return 0;
}
