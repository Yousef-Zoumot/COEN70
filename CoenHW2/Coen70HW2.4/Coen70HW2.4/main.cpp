//  Yousef Zoumot
//  main.cpp
//  Coen70HW2.4 *Chapter 4 Problem 1 parts A, D, F, G b/c professor said we only need to choose 4 to do
//
//  Created by Yousef Zoumot on 1/18/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <cstdlib>//Provides size_t

using namespace std;


class String{
    char myString[200];
    size_t length;
public:
    //CONSTRUCTOR FOR THE STRING CLASS
    String(const char str[] = "");
    String(const char c);//part A

    //CONSTANT MEMBER FUNCTIONS FOR THE STRING CLASS
    int searchF(const char c);//Part F returns index of first occurrence or returns -1
    int searchA(const char c);//Part G returns number of occurrences or returns 0
    
    //MODIFICATION MEMBER FUNCTIONS FOR THE STRING CLASS
    void replaceChar(const char c, int index);//part D
    
    //Tester Function
    void printValues();
};

String:: String(const char str[]){
    int i=0;
    if(str[i]=='\0'){
        myString[i]='\0';
        length++;
        return;
    }
    while(str[i]!= '\0'){
        myString[i]=str[i];
        i++;
        length++;
    }
    return;
}

String::String(const char c){
    if(c=='\0'){
        myString[0]=c;
        length++;
        return;
    }
    myString[0]=c;
    length++;
    myString[1]='\0';
    length++;
    return;
    
}


void String:: replaceChar(const char c, int index){
    myString[index]=c;
    return;
}

int String:: searchF(const char c){
    int i=0;
    while(myString[i]!='\0'){
        if(myString[i]==c)
            return i;
        i++;
    }
    cout<<"Not Found ";
    return -1;
}

int String:: searchA(const char c){
    int i=0;
    int answer=0;
    while(myString[i]!='\0'){
        if(myString[i]==c){
            answer++;
        }
        i++;
    }
    return answer;
}

void String:: printValues(){
    int i=0;
    while(myString[i]!='\0'){
        cout<<myString[i];
        i++;
    }
    cout<<"\n";
    
}

int main(int argc, const char * argv[]) {
    String s1("Hello my name is Johnny");
    s1.printValues();
    char c='A';
    String s2(c);
    s2.printValues();
    s2.replaceChar('B', 0);
    s2.printValues();
    c='n';
    cout<<s1.searchF(c)<<"\n";
    cout<<s1.searchA(c)<<"\n";
    
}
