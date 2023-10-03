//  Yousef Zoumot
//
//  Coen70HW1.1 *Chapter 2 Problems 2 & 3
//
//  Created by Yousef Zoumot on 1/10/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//max, min, mean, last, sum and length

#include <iostream> 
using namespace std;

class statistician{
private:
    double max, min, mean, last;
    double sum =0;
    double length=0;
public:
    double getMax(){return max;};//returns max
    double getMin(){return min;};//returns min
    double getMean(){return mean;};//returns mean
    double getLast(){return last;};//returns last
    double getSum(){return sum;};//returns sum
    double getLength(){return length;};//returns length
        //instead of making variables public, I created functions to change the values
        void changeMax(double n){max=n;};//changes max
        void changeMin(double n){min=n;};//changes min
        void changeMean(double n){mean=n;};//changes mean
        void changeLast(double n){last=n;};//changes last
        void changeSum(double n){sum=n;};//changes sum
        void changeLength(double n){length=n;};//changes length
    void next_number(double n);
    void newSequence();
    void printValues();
    
};

statistician operator +(statistician s1, statistician s2){
    statistician temp;
    temp.changeSum( (s1.getSum() + s2.getSum()) );
    temp.changeLength( (s1.getLength() + s2.getLength()) );
    temp.changeMean( (temp.getSum()/temp.getLength()) );
    temp.changeLast(s2.getLast());
    if(s1.getMax() > s2.getMax())
        temp.changeMax(s1.getMax());
    else
        temp.changeMax(s2.getMax());
    if(s1.getMin() < s2.getMin())
        temp.changeMin(s1.getMin());
    else
        temp.changeMin(s2.getMin());
    return temp;
}

void statistician :: next_number(double n){//this function takes in a double value and checks to see if length is zero.  If so, it sets max and min to the parameter value.  If not it compares the value to the max and min and replaces max and min if applicable.  It then adds the value to the sum, increments length by 1, resets the mean value to the new mean, and places the value as the new last
    if(length==0){
        max=n;
        min= n;
    }
    else{
        
        if(n>max)
            max=n;
        if(n<min)
            min=n;
    }
    
    sum= sum + n;
    length++;
    mean= sum/length;
    last=n;
    
}

void statistician :: newSequence(){//only sets sum and length to zero b/c when the function next_number is called, it checks if length is equal to zero, and if so then it resets the max and min variables as well as mean and last
    sum=0;
    length=0;
    
}

void statistician :: printValues(){//a function that prints all the values in order to clean up the main function
    cout<<"\nThe max value is: " << getMax();
    cout<<"\nThe min value is: " << getMin();
    cout<<"\nThe mean value is: " << getMean();
    cout<<"\nThe last value is : " << getLast();
    cout<<"\nThe sum of all the values is: " << getSum();
    cout<<"\nThe length value is: " << getLength()<<"\n";
}

int main(int argc, const char * argv[]) {
    statistician s1, s2, s3;
    s1.next_number(4);
    s1.next_number(5);
    s1.next_number(6);
    s1.printValues();
    //s1.newSequence();
    s2.next_number(1);
    s2.next_number(2);
    s2.next_number(3);
    s2.printValues();
    
    s3= (s1+ s2);
    s3.printValues();
    return 0;
    
    
}

 
