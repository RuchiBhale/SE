/*
 * assignment4.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: exam4
 */
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;
#define size 10
int hashIndex=0;
class Data{
    long int phno;
    string name;
    public:
    Data(){
        phno=-1;
        name=" ";

    }
    friend class Hash;
};
int hashcode(long int key){
    return key%size;
}
class Hash
{
    public:
    Data hash_table[size];
    void insert_without(string n,long int ph){
        Data d;
    int pos;
    d.name=n;
    d.phno=ph;
    pos=hashcode(ph); //calculating the address of the key

    if(hash_table[pos].phno==-1){
        hash_table[pos]=d;
//        cout<<"Added data successfully!!"<<endl;

    }
    else{
        while(hash_table[pos].phno!=-1){
            pos=(pos+1)%size; //to make it circular
        }
        hash_table[pos]=d;
    }

    }
    void insert_with(string n,long int ph){
        Data d,temp;
        int pos;
        d.phno=ph;
        d.name=n;
        pos=hashcode(d.phno);
        if(hash_table[pos].phno==-1){
            hash_table[pos]=d;
            cout<<"Added Data successfully!!";

        }
        else{
            temp=hash_table[pos];
            if(hashcode(temp.phno)==pos){
                while(hash_table[pos].phno!=-1){
                    pos=(pos+1)%size;
                }
                hash_table[pos]=d;

                }


            else{
                hash_table[pos]=d;
                while(hash_table[pos].phno!=-1){
                    pos=(pos+1)%size;
                }
                hash_table[pos]=temp;

            }
        }

    }

    void search(long int ph){
    int count=0;

    int index=hashcode(ph);
    int a=0;
    bool found=false;
    while(a!=9){
        if(hash_table[index].phno==ph){
            cout<<"Found at "<<index<<endl;
            found=true;
            break;

        }
        else{
            ++index;
            index=index%size;
        }
        a++;
        count++;

    }
    if(found==false){
        cout<<"Not found in the hash table!"<<endl;
    }
    cout<<"No of comparisons are: ";
    cout<<count+1<<endl;

    }
    void del(long int ph){
    bool found=false;

    for(int i=0;i<size;i++){
        if(hash_table[i].phno==ph){
            cout<<"Deletion succesful!!"<<endl;
            found=true;
            hash_table[i].phno=-1;
            hash_table[i].name=" ";
        }
    }
    if(found==false)
        cout<<"Element not found"<<endl;
    }
    void display(){
        cout<<"**************************************";
        cout<<"\nPosition"<<setw(15)<<"Name"<<setw(20)<<"Phone Number"<<endl;
        cout<<"***************************************";
        for(int i=0;i<size;i++){
            cout<<"\n"<<i<<setw(20)<<hash_table[i].name<<setw(20)<<hash_table[i].phno<<endl;
        }
    }

};


int main(){
    Hash h;
    Hash h1;
    string name;
    int ch;
    long int phno;
    long int phone;
    char choice;
    do{
    cout<<"\nMENU!!\n";
    cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display\n";
    cout<<"Enter your choice: "<<endl;
    cin>>ch;

    switch(ch){
        case 1:
        	cout<<"Enter the phone number: "<<endl;
        	cin>>phno;
        	cout<<"Enter the name: "<<endl;
        	cin>>name;
            h.insert_without(name,phno);
            h1.insert_with(name,phno);
            break;
        // case 2:
        //     h.insert_with();
        //     break;
        case 2:

        	cout<<"Enter the phone number to be searched: "<<endl;
        	cin>>phone;
            h.search(phone);
            h1.search(phone);
            break;
        case 3:

        	cout<<"Enter the phone number to be deleted: "<<endl;
        	cin>>phone;
            h.del(phone);
            break;
        case 4:
            h.display();
            h1.display();
            break;
    }
    cout<<"Do you want to continue?(y/n): ";
    cin>>choice;

    }while(choice=='y');

   return 0;
}



