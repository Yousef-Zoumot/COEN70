//  Yousef Zoumot Ken Wakaba
//  main.cpp
//  Coen70Lab2
//
//  Created by Yousef Zoumot & Ken Wakaba on 1/12/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
using namespace std;

class Complex{
private:
    double a;
    double b;
    char imaginary='i';
public:
    double real(){return a;};
    double imagine(){return b;};
    void setReal(double x){a=x;};
    void setImaginary(double y){b=y;};
    Complex(double n1, double n2);
    Complex();
    friend istream& operator >>(istream& ins, Complex& og1);
    friend ostream& operator <<(ostream& ins, Complex og1);
    
};

Complex::Complex(double n1, double n2){
    a=n1;
    b=n2;
}

Complex::Complex(){
    a=0;
    b=0;
}

Complex operator +(Complex og1, Complex og2){
    Complex temp;
    temp.setReal( (og1.real()+og2.real()) );
    temp.setImaginary( (og1.imagine()+og2.imagine()) );
    return temp;
}

Complex operator *(Complex og1, Complex og2){
    Complex temp;
    temp.setReal( (og1.real()*og2.real()) - (og1.imagine()*og2.imagine()) );
    temp.setImaginary( (og1.real()*og2.imagine())+ (og1.imagine()*og2.real()) );
    return temp;
}

ostream& operator <<(ostream& ins, Complex og1){
    ins<<og1.real()<<" + "<<og1.imagine()<<"i\n";
    return ins;
}

istream& operator >>(istream& ins, Complex& og1){
    double real, imagine;
    cout<<"Please enter real number \n";
    ins>>real;
    og1.setReal(real);
    cout<<"Please enter imaginary number \n";
    ins>>imagine;
    og1.setImaginary(imagine);
    return ins;
    
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    Complex c1;
    Complex c2(1.0, 2.0);
    c1.setReal((3.0));
    cout<<c1;
    //cin>>c2;
    cout<<c2;
    Complex c3= c1+c2;
    cout<<c3;
    Complex c4= c1*c2;
    cout<<c4;
    std::cout << "Hello, World!\n";
    return 0;
}
