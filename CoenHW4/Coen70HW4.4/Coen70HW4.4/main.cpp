//
//  main.cpp
//  Coen70HW4.4
//
//  Created by Yousef Zoumot on 2/14/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//



#include <iostream>
#include <cassert>
#include <cstdlib> //provide size_t
#include <utility>

using namespace std;

template<class T, class K>
class Keyed_Bag
{
public:
    //CONSTRUCTOR
    Keyed_Bag();
    //MODIFICATION
    bool erase_one(const T& target);
    void insert(const T& entry, T key);
    void operator +=(const Keyed_Bag& addend);
    Keyed_Bag operator -(const Keyed_Bag& b);
    void operator -=(const Keyed_Bag& remove);
    //CONSTANT MEMBER FUNCTIONS
    T size() const { return used;}
    T count(const T& target) const;
    void prTValues();
private:
    struct Node{
        Node* _prev;
        Node* _next;
        T _data;
        K _key;
        Node(T data, K key, Node* prev = NULL, Node* next = NULL){
            this->_data = data;
            this->_key=key;
            this->_prev = prev;
            this->_next = next;
        }
        T& first(){return _data;};
        K& second(){return _key;};
        Node*& next(){return _next;};
        Node*& prev(){return _prev;};
        
    };
    Node* head;
    T used;            //How much of the array is used
};

template<class T, class K>
Keyed_Bag<T,K>::Keyed_Bag(){
    head=NULL;
    used=0;
}

//NONMEMBER FUNCTIONS for the Keyed_Bag class
//Keyed_Bag operator +(const Keyed_Bag& b1, const Keyed_Bag& b2);



template<class T, class K>
bool Keyed_Bag<T,K>::erase_one(const T& key1){
    Node* tmp=head;
    while(tmp->_next!=NULL && tmp->_key != key1)
        tmp=tmp->_next;
    if(tmp->_next==NULL)
        return false;
    --used;
    if(tmp->_prev!=NULL)
        tmp->_prev->_next=tmp->_next;
    if(tmp->_prev==NULL)
        head=tmp->_next;
    delete tmp;
    return true;
}

template<class T, class K>
void Keyed_Bag<T,K>::insert(const T& entry, T key){
    Node* tmp=new Node(entry, key);
    Node* dummy=head;
    Node* mummy=head;
    if(head==NULL){
        head=tmp;
        return;
    }
    while(mummy!=NULL){
        
        if(mummy->_key==tmp->_key)
            return;
        mummy=mummy->_next;
    }
    while(dummy->_next!=NULL){
        dummy=dummy->_next;
    }
    dummy->_next=tmp;
    tmp->_prev=dummy;
    tmp->_next=NULL;
    ++used;
    return;
}

template<class T, class K>
void Keyed_Bag<T,K>:: prTValues(){//a function that prTs all the values in order to clean up the main function
    Node* tmp=head;
    cout<<"\n";
    while(tmp->_next!=NULL){
        cout<<"data: "<<tmp->_data<<"  with key: "<<tmp->_key<<"\n";
        tmp=tmp->_next;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    Keyed_Bag<int, double> b, b2;
    b.insert(1,1);
    b.insert(2,2);
    b.insert(3,3);
    b.insert(4,4);
    b.insert(3,5);
    b.insert(7,4);
    b.insert(8,5);
    b.insert(9,6);
    
    b2.insert(3,6);
    b2.insert(7,7);
    b2.insert(2,2);
    b2.insert(3,3);
    b2.insert(3,7);
    b.prTValues();
    b2.prTValues();
    
    return 0;
}
