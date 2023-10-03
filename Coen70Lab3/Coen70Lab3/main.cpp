//  Gabrielle Tordillos & Yousef Zoumot
//  main.cpp
//  Coen70Lab3
//  Paul Thurston
//  Created by Yousef Zoumot on 1/19/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cassert>
#include <stdlib.h>//

using namespace std;

class Stack{
public:
    double express[100];
    void push(double x);
    double pop();
    double top();
    bool empty();
    void printValues();
private:
    int used;
    int last;
    
};

void Stack:: push(double x){
    assert(last!=used-1);
    express[last++]=x;
    used++;
    return;
}
bool Stack:: empty(){
    if(used==0)
        return true;
    else{
        return false;
    }
}
double Stack:: pop(){
    assert(!empty());
    double temp= express[--used];
    last--;
    return temp;
}

double Stack:: top(){
    return express[last];
}

void Stack:: printValues(){
    cout<<"The values in the stack are: ";
    for(int i=0; i<used; i++){
        cout<<express[i]<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    
    string expr, token;
    Stack s1;
    double temp1, temp2;
    getline(cin, expr);
    istringstream stream(expr);
    while(stream >> token){
        if(token=="+"){
            temp1=s1.pop();
            temp2=s1.pop();
            s1.push(temp1+temp2);
        }
        if(token=="-"){
            temp1=s1.pop();
            temp2=s1.pop();
            s1.push(temp2-temp1);
        }
        if(token=="/"){
            temp1=s1.pop();
            temp2=s1.pop();
            s1.push(temp2/temp1);
        }
        if(token=="*"){
            temp1=s1.pop();
            temp2=s1.pop();
            s1.push(temp1*temp2);
        }
        if(token!="+" && token!="-" && token!="/" && token!="*"){
            double temp=atof(token.c_str());
            s1.push(temp);
        }
        
    }
    s1.printValues();
}
