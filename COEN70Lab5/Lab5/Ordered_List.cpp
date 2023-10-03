//
//  Ordered_List.cpp
//  Lab5
//
//  Created by Yousef Zoumot on 2/2/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include "Ordered_List.h"
#include <stdlib.h>

using namespace std;

Ordered_List::Ordered_List(){}

/*************************************************/

Ordered_List::Ordered_List(const Ordered_List& source){
    if(this != &source){
        while(size() != 0){
            remove();
        }
        Node* tmp = source.cursor;
        while(tmp->prev()!=NULL)
            tmp=tmp->prev();
        while(tmp != NULL){
            insert(tmp->data());
            tmp = tmp->next();
        }
        
    }
}

/**********************************************************************/

Ordered_List::~Ordered_List(){
}

/**********************************************************************/

Ordered_List& Ordered_List:: operator=(const Ordered_List& other){
    if(this != &other){
        while(size() != 0){
            remove();
        }
        Node* tmp = other.cursor;
        while(tmp->prev()!=NULL)
            tmp=tmp->prev();
        while(tmp != NULL){
            insert(tmp->data());
            tmp = tmp->next();
        }
        
    }
    return *this;
}

/*************************************************************************/

std::ostream& operator<<(std::ostream &out, const Ordered_List &other){
    out<<(List&)other;
    return out;
}

/************************************************************************/

void Ordered_List::insert(int x){
    Node* tmp = cursor;
    Node* tmp_data= new Node(x);
    
    //tmp_data->data() = x;
    
    if(n == 0 && cursor == NULL){
        cursor = tmp_data;
        n++;
        return;
    }
    while(tmp->prev() != NULL){
        tmp = tmp->prev();
    }
    while(x >= tmp->data() && tmp->next()!=NULL){
        tmp = tmp->next();
    }
    if(tmp->prev()!=NULL){
        tmp->prev()->next() = tmp_data;
        tmp_data->next()=tmp;
        tmp->prev()=tmp_data;
    }
    if(tmp->next()==NULL && tmp->data()<=x){
        tmp->next()=tmp_data;
        tmp_data->next()=NULL;
        tmp_data->prev()=tmp;
    }
    else{
        tmp_data->next() = tmp;
        tmp_data->prev() = tmp->prev();
        tmp->prev() = tmp_data;
    }
    n++;
    return;
}



/************************************************************************/

void Ordered_List:: attach(int x){
    Node* tmp = cursor;
    Node* tmp_data;
    tmp_data->data() = x;
    
    while(tmp->prev() != NULL){
        tmp = tmp->prev();
    }
    if(n == 0 && cursor == NULL){
        cursor = tmp_data;
        n++;
        return;
    }
    while(x >= tmp->data()){
        tmp = tmp->next();
    }
    tmp->prev()->next() = tmp_data;
    tmp_data->next() = tmp;
    tmp_data->prev() = tmp->prev();
    tmp->prev() = tmp_data;
    n++;
    return;
}

void Ordered_List::display(){
    start();
    Node* tmp = cursor;
    while(tmp != NULL){
        std::cout << tmp->data() << "\n";
        tmp = tmp->next();
    }
    std::cout << "The size of the list is: " << n << endl;
}



