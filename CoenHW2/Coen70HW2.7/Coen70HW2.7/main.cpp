//  Yousef Zoumot
//  main.cpp
//  Coen70HW2.7 *Chapter 4 Problem 2e
//
//  Created by Yousef Zoumot on 1/12/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//


#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class bag{
public:
    bag(int x = 20);
    bag(const bag& source);
    ~bag();
    int erase(const int& target);
    bool erase_one(const int& target);
    bool contains(const int& target);
    void insert(const int& entry, int key);
    int size() const { return used; }
    int count( const int& target) const;
    void printValues();
    bag operator +(const bag& b2);
    bag& operator =(const bag& source);
    bag operator -(const bag& b2);
    void operator -=(const bag& removeIt);
    void operator +=(const bag& addend);
private:
    int** data;
    int capacity;
    int used;
    void incSize();
};



int main(){
    bag a;
    bag b;
    bag c;
    bag d;
    a.insert(1, 1);
    a.insert(2, 2);
    a.insert(3, 3);
    a.insert(4, 4);
    b.insert(5, 5);
    b.insert(6, 6);
    b.insert(7, 7);
    a.printValues();
    b.printValues();
    c = a + b;
    c.printValues();
    c = a - b;
    c.printValues();
    d.insert(1,6);
    d.insert(2, 2);
    d.insert(3, 5);
    d.printValues();
    c -= d;
    c.printValues();
    d.erase_one(6);
    d.erase_one(5);
    d.printValues();
}





int bag::erase(const int& target){
    int index = 0;
    int many_removed = 0;
    
    while(index < used){
        if (data[index][0] == target){
            --used;
            data[index][0] = data[used][0];
            data[index][1] = data[used][1];
            ++many_removed;
        }
        else
            ++index;
    }
    
    return many_removed;
    
}

bag:: bag (int x){
    assert(x>0);
    used = 0;
    capacity = x;
    data = new int*[x];
    for(int i = 0; i < x; i++){
        data[i] = new int[2];
    }
}
bag:: bag(const bag& source){
    
    data = NULL;
    *this = source;
}
bag:: ~bag(){
    
    for(int i = 0; i < capacity; i++){
        delete[] data[i];
    }
    delete[] data;
}
void bag::printValues(){
    int i;
    for(i = 0; i < used; i++){
        cout <<data[i][0]<<" " ;
    }
    cout << endl;
    for(i = 0; i < used; i++){
        cout << data[i][1] << " ";
    }
    cout << endl << endl << endl;
}

bool bag::erase_one(const int& target){
    int index;
    index = 0;
    while((index < used) && (data[index][1] != target))
        ++index;
    if(index == used)
        return false;
    --used;
    data[index][1] = data[used][1];
    data[index][0] = data[used][0];
    return true;
}

void bag:: incSize(){
    int** temp = new int* [2*capacity];
    for(int i = 0; i < 2*capacity; i++){
        temp[i][0] = data[i][0];
        temp[i][1] = data[i][1];
    }
    for(int i = 0; i < capacity; i++){
        temp[i][0] = data[i][0];
        temp[i][1] = data[i][1];
    }
    for(int i = 0; i < capacity; i++){
        delete[] data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}


void bag::insert(const int& entry, int key1){
    if(size() == capacity)
        incSize();
    data[used][0] = entry;
    for(int i = 0; i < used; i++){
        if(data[i][1] == key1){
            cout << "That key is already used. Enter another";
            cin >> key1;
            i = 0;
        }
    }
    data[used][1] = key1;
    ++used;
    return;
}

void bag::operator +=(const bag& addend){
    *this = *this + addend;
}

bag bag:: operator -(const bag& source){
    /*bag answer;
     answer.data = NULL;
     answer = *this;*/
    bag answer;
    if(answer.data){
        for(int i = 0; i < answer.capacity; i++){
            delete[] answer.data[i];
        }
        delete[] answer.data;
    }
    answer.data = new int*[capacity];
    for(int i = 0; i < capacity; i++)
        answer.data[i] = new int[2];
    for(int i = 0; i < source.capacity; i++){
        answer.data[i][0] = data[i][0];
        answer.data[i][1] = data[i][1];
    }
    answer.capacity = capacity;
    answer.used = used;
    for(int i = 0; i < source.used; i++){
        answer.erase_one(source.data[i][1]);
        
    }
    return answer;
}

void bag:: operator -=(const bag& removeIt){
    *this = *this - removeIt;
}

int bag::count(const int& target) const {
    int answer;
    int i;
    answer = 0;
    for(i = 0; i < used; ++i)
        if (target == data[i][0])
            ++answer;
    return answer;
}

bag& bag:: operator =(const bag& source){
    if(this == &source)
        return *this;
    if(data){
        for(int i = 0; i < capacity; i++){
            delete[] data[i];
        }
        delete[] data;
    }
    
    if(source.used == 0){
        used = 0;
        capacity = 20;
        data = new int*[20];
        for(int i = 0; i < 20; i++){
            data[i] = new int[2];
        }
        return *this;
    }
    data = new int*[source.capacity];
    for(int i = 0; i < source.capacity; i++)
        data[i] = new int[2];
    for(int i = 0; i < source.used; i++){
        data[i][0] = source.data[i][0];
        data[i][1] = source.data[i][1];
    }
    capacity = source.capacity;
    used =source.used;
    return *this;
}
bag bag::operator +(const bag& source){
    
    bag answer;
    answer = *this;
    if(source.used + used >= capacity)
        answer.incSize();
    for(int i = 0; i < source.used; i++){
        if(!answer.contains(source.data[i][1])){
            answer.insert(source.data[i][0],source.data[i][1]);
        }
    }
    return answer;
}

bool bag:: contains(const int &target){
    for(int i = 0; i < used; i++){
        if(data[i][1] == target)
            return true;
    }
    return false;
    
}
