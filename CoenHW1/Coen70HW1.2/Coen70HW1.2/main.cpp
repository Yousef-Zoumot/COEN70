//  Yousef Zoumot
//  main.cpp
//  Coen70HW1.2 Chapter 2 Problem 5
//
//  Created by Yousef Zoumot on 1/13/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <math.h>//
#include <iomanip>//
using namespace std;

#define PI 3.14159265

class position{
    
private:
    double x, y, z;
public:
    void setX(double i){x=i;};
    void setY(double j){y=j;};
    void setZ(double k){z=k;};
    void shiftX(double i){x+=i;};
    void shiftY(double j){y+=j;};
    void shiftZ(double k){z+=k;};
    void rotateAroundX(double theta);
    void rotateAroundY(double theta);
    void rotateAroundZ(double theta);
    void printValues();

};

void position:: rotateAroundX(double theta){
    double tempY=y;
    double tempZ=z;
    y= (tempY*cos((theta*PI)/180)) - (tempZ*sin((theta*PI)/180));
    z= (tempY*sin((theta*PI)/180)) + (tempZ*cos((theta*PI)/180));
}

void position:: rotateAroundY(double theta){
    double tempX=x;
    double tempZ=z;
    x=(tempX*cos((theta*PI)/180)) + (tempZ*sin((theta*PI)/180));
    z=(-tempX*sin((theta*PI)/180)) + (tempZ*cos((theta*PI)/180));
}

void position:: rotateAroundZ(double theta){
    double tempX=x;
    double tempY=y;
    x=(tempX*cos((theta*PI)/180)) - (tempY*sin((theta*PI)/180));
    y=(tempX*sin((theta*PI)/180)) + (tempY*cos((theta*PI)/180));
}

void position:: printValues(){
    cout<<"\nThe x value is: "<<std::fixed<<x;
    cout<<"\nThe y value is: "<<std::fixed<<y;
    cout<<"\nThe z value is: "<<std::fixed<<z<<"\n";
    
}





int main(int argc, const char * argv[]) {
    // insert code here...
    position p;
    p.setX(1);
    p.setY(0.0);
    p.setZ(0.0);
    p.rotateAroundZ(90);
    p.printValues();
    p.shiftY(-1);
    p.shiftZ(1);
    p.rotateAroundX(90);
    p.printValues();
    return 0;
}




