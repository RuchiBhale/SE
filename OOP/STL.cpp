/*
 * assignment6.cpp
 *
 *  Created on: Dec 1, 2022
 *      Author: se
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Information{
public:
	string name,tel,dob;
	int roll_no;
	Information(){};
	Information(string n,string t,string d,int r){
		name=n;
		tel=t;
		dob=d;
		roll_no=r;

	}
	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Telephone number: "<<tel<<endl;
		cout<<"Date of birth: "<<dob<<endl;
		cout<<"Roll No: "<<roll_no;

	}
	friend bool operator == (const Information &key,const Information &S1){
	return(key.name == S1.name);
	}

};
bool compare(Information S1,Information S2)
{
	return(S1.roll_no<S2.roll_no);
}
void Search(vector<Information>&X,Information key){
	vector<Information>::iterator K;
	K = find(X.begin(),X.end(),key);
	if(K!= X.end()){
		cout<<"Element found"<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}
}
int main(){
	string name,telno,dob,key;
	int roll_no;
	vector<Information>S;
	vector<Information>::iterator k;
	int n;
	cout<<"Enter the number of records to be entered: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter Name: ";
		cin>>name;
		cout<<"Enter telephone number: ";
		cin>>telno;
		cout<<"Enter the date of birth: ";
		cin>>dob;
		cout<<"Enter roll no: ";
		cin>>roll_no;
		Information s(name,telno,dob,roll_no);
		S.push_back(s);

	}
	int ch;
	cout<<"MENU"<<endl;
	cout<<"1.Sorting\n2.Searching"<<endl;
	cin>>ch;
	switch(ch){
	case 1:
		 sort(S.begin(),S.end(),compare);
		 for(int i=0;i<n;i++){
		 S[i].display();
		 cout<<endl;
		}
		 break;
	case 2:
	   Information key1;
	   cout<<"Enter name to be searched:";
	   cin>>key1.name;
	   Search(S,key1);
	   break;

}
	   return 0;
}
