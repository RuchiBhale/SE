/*
 * assignment1.cpp
 *
 *  Created on: Aug 25, 2022
 *      Author: se
 */
#include <iostream>
using namespace std;
class complex{
    float a,b;
    public:
    complex(){
        a=0.0;
        b=0.0;
    }
    complex(float r,float i){
        a=r;
        b=i;

    }
    void display(){
        cout<<a<<"+i"<<b<<endl;

    }
    complex operator +(complex c2){
        complex c3;
        c3.a=c2.a+a;
        c3.b=c2.b+b;
        return c3;

    }
    complex operator *(complex c2){
        complex c4;
        c4.a=(c2.a*a)-(c2.b*b);
        c4.b=(c2.a*b)+(c2.b*a);
        return c4;
    }
};
int main(){
    complex c3,c4;
    float m,n,p,q;
    int ch;
    cout<<"Enter the value of m and n: ";
    cin>>m>>n;
    cout<<"Enter the value of p and q: ";
    cin>>p>>q;
    complex c1(m,n),c2(p,q);
    c1.display();
    c2.display();
    cout<<"MENU"<<endl;
    cout<<"1.Addition"<<endl;
    cout<<"2.Multiplication"<<endl;
    cout<<"Enter your choice";
    cin>>ch;
    switch(ch){
        case 1:
            c3=c1+c2;
            c3.display();
            break;
        case 2:
            c4=c1*c2;
            c4.display();
            break;

    }


    return 0;


}

