//  Yousef Zoumot
//  main.cpp
//  Coen70HW4.1 *Chapter 6 Problem 2a
//
//  Created by Yousef Zoumot on 2/14/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


template < class T > class set{
public:
    set(T x = 20);
    set(const set& source);
    ~set();
    T erase(const T& target);
    bool erase_one(const T& target);
    void insert(const T& target);
    set operator -(const set& b2);
    set& operator =(const set& source);
    void operator -=(const set& removeIt);
    void operator +=(const set& addend);
    set operator +(const set& b2);
    bool contains(const T& target) const;
    T size() const { return used; }
    T count( const T& target) const;
    void prT();
    
private:
    T* data;
    T capacity;
    void incSize();
    T used;
};



int main(){
    set<int> a;
    set<int> b;
    set<int> c;
    set<int> d;
    a.insert(2);
    a.insert(2);
    a.insert(4);
    a.insert(5);
    a.prT();
    b.insert(4);
    b.insert(2);
    b.insert(6);
    b.prT();
    c = a - b;
    c.prT();
    c = a + b;
    c.prT();
    d.insert(7);
    c += d;
    c.prT();
    c -= d;
    c.prT();
    c.erase_one(3);
    c.prT();
}




template<class T>
T set<T>::erase(const T& target){
    T index = 0;
    T many_removed = 0;
    
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

template<class T>
set<T>:: set(T x){
    assert(x>0);
    used = 0;
    capacity = x;
    data = new T[x];
}

template<class T>
set<T>:: set(const set& source){
    data = NULL;
    *this = source;
}
template<class T>
set<T>:: ~set(){
    if (data)
        delete[] data;
}
template<class T>
void set<T>:: incSize(){
    T* temp = new T[2*capacity];
    for(T i = 0; i < capacity; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}
template<class T>
void set<T>::prT(){
    T i;
    for(i = 0; i < used; i++){
        cout << data[i] << ", ";
    }
    cout << endl;
}
template<class T>
bool set<T>::erase_one(const T& target){
    T index;
    index = 0;
    while((index < used) && (data[index] != target))
        ++index;
    if(index == used)
        return false;
    --used;
    data[index] = data[used];
    return true;
}

template<class T>
void set<T>::insert(const T& entry){
    if(contains(entry))
        return;
    if(size() >= capacity)
        incSize();
    data[used] = entry;
    ++used;
    return;
}
template<class T>
void set<T>::operator +=(const set& addend){
    T i;
    if(size() + addend.size() >= capacity)
        incSize();
    for(i = 0; i < addend.used; i++){
        if(!contains(addend.data[i])){
            data[used] = addend.data[i];
            used++;
        }
    }
}

template<class T>
set<T> set<T>:: operator -(const set& b2){
    set answer = *this;
    for(T i = 0; i < b2.used; i++)
        answer.erase_one(b2.data[i]);
    return answer;
}
template<class T>
void set<T>:: operator -=(const set& removeIt){
    T i;
    for(i = 0; i < removeIt.used; i++)
        erase_one(removeIt.data[i]);
}
template<class T>
T set<T>::count(const T& target) const {
    T answer;
    T i;
    answer = 0;
    for(i = 0; i < used; ++i)
        if (target == data[i])
            ++answer;
    return answer;
}
template<class T>
set<T>& set<T>:: operator =(const set& source){
    if(this == &source)
        return *this;
    if (data)
        delete[] data;
    if(source.used == 0){
        used = 0;
        capacity = 20;
        data = new T[capacity];
        return *this;
    }
    data = new T[source.capacity];
    for(T i = 0; i < source.capacity; i++){
        data[i] = source.data[i];
    }
    used = source.used;
    capacity = source.capacity;
    return  *this;
}
template<class T>
set<T> set<T>::operator +(const set& b2){
    set answer = *this;
    if(answer.size() + b2.size() >= capacity)
        incSize();
    for(T i = 0; i < b2.used; i++){
        if(!answer.contains(b2.data[i])){
            answer.data[used] = b2.data[i];
            answer.used++;
        }
    }
    return answer;
    
    
}
template<class T>
bool set<T>:: contains(const T& target) const{
    T i;
    for(i = 0; i < used; ++i)
        if (target == data[i])
            return true;
    return false;
    
}
