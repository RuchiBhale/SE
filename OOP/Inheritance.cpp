/*
 * ASSIGNMENT_3.cpp
 *
 *  Created on: Sep 29, 2022
 *      Author: se
 */

#include <iostream>
#include <string>
using namespace std;
class Publication{
public:
string title;
float price;
public:

Publication(){
price=0.0;

}
void accept(){
cout<<"Enter the title of the book: ";
getline(cin>>ws,title);
cout<<endl;
cout<<"Enter the price of the book: ";
cin>>price;
cout<<endl;
}
void display(){
cout<<"The title of the book is: "<<title<<endl;
cout<<"The price of the book is: "<<price<<endl;
}

};
class book:public Publication
{
int pages;
public:
book(){}
void accept();
void display();

};
void book::accept(){
Publication::accept();
cout<<"Enter the number of pages in the book";
cin>>pages;
}

void book::display(){
try{
if(pages<0)
throw pages;
}
catch(int p){
title=" ";
price=0.0;
pages=0.0;

}
Publication::display();
cout<<"Number of pages in the book is: "<<pages<<endl;
}
class tape:public Publication{
float time;
public:
tape(){
time=0.0;
}
void accept();
void display();
};
void tape::accept(){
    Publication::accept();
    cout<<"Enter the time of the audio book";
    cin>>time;

try{


if(time<=0)
throw time;
}

catch(float minutes){
title=" ";
price=0.0;
time=0.0;
}
}
void tape:: display(){
    try{
    if(time<=0.0)
        throw time;
    }

    catch(float minutes){
        title=" ";
        price=0.0;
        time=0.0;
    }
    Publication::display();

    cout<<"The time of the audio book is: "<<time<<endl;
    }

int main(){
book s1;
tape t1;
s1.accept();
s1.display();
t1.accept();
t1.display();

return 0;
}
