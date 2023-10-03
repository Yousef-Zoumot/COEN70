//  Yousef Zoumot
//  main.cpp
//  Coen70HW2.6 *Chapter 4 Problem 2b
//
//  Created by Yousef Zoumot on 1/23/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//


#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

class set{
    int* data;
    int capacity;
    void incSize();
    int used;
public:
    set(int x = 20);
    set(const set& source);
    ~set();
    int erase(const int& target);
    bool erase_one(const int& target);
    void insert(const int& target);
    set operator -(const set& b2);
    set& operator =(const set& source);
    void operator -=(const set& removeIt);
    void operator +=(const set& addend);
    set operator +(const set& b2);
    bool contains(const int& target) const;
    int size() const { return used; }
    int count( const int& target) const;
    void printValues();
};

int main(){
    set a;
    set b;
    set c;
    set d;
    a.insert(1);
    a.insert(2);
    a.insert(2);
    a.insert(3);
    a.printValues();
    b.insert(3);
    b.insert(2);
    b.insert(5);
    b.printValues();
    c = a - b;
    c.printValues();
    c = a + b;
    c.printValues();
    d.insert(3);
    c += d;
    c.printValues();
    c -= d;
    c.printValues();
    c.erase_one(1);
    c.printValues();
}


    
    
    
    int set::erase(const int& target){
        int index = 0;
        int many_removed = 0;
        
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
    set:: set (int x){
        assert(x>0);
        used = 0;
        capacity = x;
        data = new int[x];
    }
    set:: ~set(){
        if (data)
            delete[] data;
    }
    set:: set(const set& source){
        data = NULL;
        *this = source;
    }
    
    void set:: incSize(){
        int* temp = new int[2*capacity];
        for(int i = 0; i < capacity; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }
    void set::printValues(){
        int i;
        for(i = 0; i < used; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    bool set::erase_one(const int& target){
        int index;
        index = 0;
        while((index < used) && (data[index] != target))
            ++index;
        if(index == used)
            return false;
        --used;
        data[index] = data[used];
        return true;
    }
    
    void set::operator +=(const set& addend){
        int i;
        if(size() + addend.size() >= capacity)
            incSize();
        for(i = 0; i < addend.used; i++){
            if(!contains(addend.data[i])){
                data[used] = addend.data[i];
                used++;
            }
        }
    }


    
        
    set set:: operator -(const set& b2){
        set answer = *this;
        for(int i = 0; i < b2.used; i++)
            answer.erase_one(b2.data[i]);
        return answer;
    }

    int set::count(const int& target) const {
        int answer;
        int i;
        answer = 0;
        for(i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    void set:: operator -=(const set& removeIt){
        int i;
        for(i = 0; i < removeIt.used; i++)
            erase_one(removeIt.data[i]);
    }
    void set::insert(const int& entry){
        if(contains(entry))
            return;
        if(size() >= capacity)
            incSize();
        data[used] = entry;
        ++used;
        return;
    }
    set& set:: operator =(const set& source){
        if(this == &source)
            return *this;
        if (data)
            delete[] data;
        if(source.used == 0){
            used = 0;
            capacity = 20;
            data = new int[capacity];
            return *this;
        }
        data = new int[source.capacity];
        for(int i = 0; i < source.capacity; i++){
            data[i] = source.data[i];
        }
        used = source.used;
        capacity = source.capacity;
        return  *this;
    }

    bool set:: contains(const int& target) const{
        int i;
        for(i = 0; i < used; ++i)
            if (target == data[i])
                return true;
        return false;
        
    }

    set set::operator +(const set& b2){
        
        set answer = *this;
        if(answer.size() + b2.size() >= capacity)
            incSize();
        for(int i = 0; i < b2.used; i++){
            if(!answer.contains(b2.data[i])){
                answer.data[used] = b2.data[i];
                answer.used++;
            }
        }
        return answer;
        
        
    }
    
