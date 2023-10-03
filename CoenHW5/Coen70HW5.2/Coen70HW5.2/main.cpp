//  Yousef Zoumot
//  main.cpp
//  Coen70HW5.2  Chapter 11 Problem 5
//
//  Created by Yousef Zoumot on 2/21/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Heap{
    vector<pair<int, int>> data;
    int count;
    int order;
public:
    Heap();
    void push(int);
    int pop();
    int top(){return data[0].first;};
    int size(){return count;};
    bool isEmpty(){return count==0;};
    int lc(int k){return (2*k)+1;};
    int rc(int k){return (2*k)+2;};
    int p(int k){return (k-1)/2;};
    void printValues();
};

Heap:: Heap(){
    vector<pair<int, int>> data(100);
    count=0;
    order=0;
}

void Heap:: push(int input){
    if(count==0){
        data.push_back(pair<int, int> (input, order));
        count++;
        order++;
        return;
    }
    int k=count;
    pair<int, int> tmp;
    data.push_back(pair<int, int> (input, order));
    tmp = data[k];
    while(k>0 && data[ p(k) ].first > input){
        data[k]=data[ p(k) ];
        k= p(k);
    }
    data[k]= tmp;
    count++;
    order++;
    
}

int Heap:: pop(){
    int i, x, child, max, xo;
    max=data[0].first;
    x=data[count-1].first;
    xo=data[count-1].second;
    i=0;
    while(lc(i) < count-1){
        child= lc(i);
        if(rc(i) < count && data[lc(i)] > data[rc(i)])
            child=rc(i);
        if(data[lc(i)].first == data[rc(i)].first){
            if(data[lc(i)].second < data[rc(i)].second)
                child=lc(i);
            else
                child=rc(i);
        }
        if(x > data[child].first ){
            data[i]=data[child];
            i=child;
        }else
            break;
    }
    data[i].first=x;
    data[i].second=xo;
    count--;
    return max;
}

void Heap:: printValues(){
    
    for(int i=0; i<count; i++)
        cout<<data[i].first<<"    "<<data[i].second<< "\n";
    cout<<"\n";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Heap h1;
    h1.push(5);
    h1.push(4);
    h1.push(3);
    h1.push(2);
    h1.push(1);
    //cout<<h1.isEmpty();
    h1.printValues();
    h1.pop();
    h1.printValues();
    h1.pop();
    h1.printValues();
    return 0;
}