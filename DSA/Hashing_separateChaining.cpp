/*
 * assignment5.cpp
 *
 *  Created on: Mar 28, 2023
 *      Author: exam4
 */
#include<iostream>
#include<string>
#define size 10
using namespace std;
class Node{
	string key;
	string value;
	Node *next;
public:
	Node(string k,string v){
		key=k;
		value=v;
		next=NULL;
	}
	friend class Hashing;


};
class Hashing{
	Node *htable[size];
public:
	Hashing(){
		for(int i=0;i<size;i++){
			htable[i]=NULL;
		}
	}

	int hash_function(string);
	void insert(string,string);
	void search(string);
	void del(string);
	void display();


};
int Hashing::hash_function(string k){
	int sum=0;
	for(int i=0;i<k.length();i++){
		sum=sum+k[i];
	}
	return(sum%size);
}
void Hashing::insert(string key,string value){

	int hash_index;
	Node *curr;
	hash_index=hash_function(key);
	Node *temp=htable[hash_index];
	Node *new_node=new Node(key,value);
	if(temp==NULL){
		htable[hash_index]=new_node;
	}
	else{
		curr=temp;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=new_node;

	}
}
void Hashing::search(string key){
	int address=hash_function(key);
	Node *temp=htable[address];
	Node *curr;
	bool flag=false;
	if(temp==NULL){
		cout<<"Not found!!"<<endl;
		return;
	}
	else{
		curr=temp;
		if(curr->key==key){
			flag=true;
			cout<<"Element found!!"<<endl;

		}
		else
			curr=curr->next;

	}
	if(flag==false){
		cout<<"Element not found!!"<<endl;
	}

}
void Hashing::del(string key){
	int loc=hash_function(key);
	Node *temp=htable[loc];
	Node *curr=temp;
	Node *prev=NULL;
	bool flag=false;
	if(temp==NULL){
		cout<<"Element is not present!!"<<endl;
		return;
	}
	if(curr->key==key){
		htable[loc]=curr->next;
		delete curr;
	}
	else{
		while(curr!=NULL){
			if(curr->key==key){
				flag=true;
				break;
			}
			prev=curr;
			curr=curr->next;
		}
		if(flag){
			prev->next=curr->next;
			delete curr;

		}
		else{
			cout<<"Element not found!!"<<endl;
		}

	}


}
void Hashing::display(){
	cout<<"\nNo  Chains\n";
	for(int i=0;i<size;i++){
		cout<<" "<<i<<" ";
		Node *curr= htable[i];
		while(curr!=NULL){
			cout<<curr->key<<"-"<<curr->value<<"-->";
			curr=curr->next;

		}
		cout<<endl;
	}
}
int main(){
	int ch;
	char choice;
	Hashing h;
	string key,value;
	do{
		cout<<"\nMENU!!\n";
		cout<<"1.Insert\n2.Search\n3.Delete\n4.Display\n";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter the key: ";
			cin>>key;
			cout<<"Enter the value: ";
			cin>>value;
			h.insert(key,value);
			break;
		case 2:
			cout<<"Enter the key to be searched: "<<endl;
			cin>>key;
			h.search(key);
			break;
		case 3:
			cout<<"Enter the key to be deleted: "<<endl;
			cin>>key;
			h.del(key);
			break;
		case 4:
			h.display();
			break;


		}
		cout<<"Do you want to continue?(y/n)";
		cin>>choice;

	}while(choice=='y' || choice=='Y');
	return 0;
}

