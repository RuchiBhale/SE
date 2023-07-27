/*
 * assignment3.cpp
 *
 *  Created on: 03-Mar-2023
 *      Author: pict
 */
#include <iostream>
using namespace std;
class Node{
	int data;
	Node *left,*right;
	bool rt,lt;
public:
	Node(){
		left=NULL;
		right=NULL;
		rt=false;
		lt=false;
	}
	friend class ThreadBST;

};
class ThreadBST{

	Node *root;
	
public:
	ThreadBST(){
		root=NULL;
		
	}
	
	Node* insert(int key){
		
		Node *ptr=root;
		Node *par=NULL;
		while(ptr!=NULL){
			if(key== ptr->data){
				cout<<"Duplicate key";
				return root;
			}
			par=ptr;
			if(key<ptr->data){
				if(ptr->lt==false)
					ptr=ptr->left;
				else
					break;
			}
			else{
				if(ptr->rt==false)
					ptr=ptr->right;
				else
					break;
			}
		}
		Node *temp=new  Node;
		temp->data=key;
		temp->lt=true;
		temp->rt=true;
		if(par==NULL){
			root=temp;
			temp->left=NULL;
			temp->right=NULL;
		}
		else if(key<par->data){
			
			temp->left=par->left;
			temp->right=par;
			par->lt=false;
			par->left=temp;

		}
		else{
			
			temp->left=par;
			temp->right=par->right;
			par->rt=false;
			par->right=temp;
		}
		return root;
	}
	Node *inorder_suc(Node *ptr){
		if(ptr->rt==true)
			return ptr->right;
		ptr=ptr->right;
		while(ptr->lt==false)
			ptr=ptr->left;
		return ptr;
	}
	void inorder(){
		Node *ptr;
		if(root==NULL)
			cout<<"Tree is empty!";
		ptr=root;
		while(ptr->lt==false)
			ptr=ptr->left;
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr=inorder_suc(ptr);

		}
	}
	void preorder(){
		Node *ptr;
		if(root==NULL){
			cout<<"Tree is empty!";
			return;
		}
		ptr=root;
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			if(ptr->lt==false)
				ptr=ptr->left;
			else if(ptr->rt==false)
				ptr=ptr->right;
			else{
				while(ptr!=NULL && ptr->rt==true)
					ptr=ptr->right;
				if(ptr!=NULL)
					ptr=ptr->right;
			}
		}
	}
	Node *inorder_pre(Node *t){
		if(t->lt==false)
			return t->left;
		t=t->left;
		while(t->rt==false){
			t=t->right;
		}
		return t;
	}

	Node *caseA(Node *par,Node*ptr){
		if(par==NULL)
			root=NULL;
		else if(ptr==par->left){
			par->lt=true;
			par->left=ptr->left;
		}
		else{
			par->rt=true;
			par->right=ptr->right;
		}
		delete ptr;
		return root;
	}
	Node *caseB(Node *par,Node *ptr){
		Node *child;
		if(ptr->lt==false)
			child=ptr->left;
		else
			child=ptr->right;
		if(par==NULL)
			root=child;
		else if(ptr==par->left)
			par->left=child;
		else
			par->right=child;
		Node *s=inorder_suc(ptr);
		Node *p=inorder_pre(ptr);
		if(ptr->lt==false)
			p->right=s;
		else{
			if(ptr->rt==false)
				s->left=p;
		}
		delete ptr;
		return root;
	}
	Node *caseC(Node *par,Node *ptr){
		Node *parsucc=ptr;
		Node *succ=ptr->right;
		while(succ->left!=NULL){
			parsucc==succ;
			succ=succ->left;
		}
		ptr->data=succ->data;
		if(succ->lt==true && succ->rt==true){
			root=caseA(parsucc,succ);
		}
		else
			root=caseB(parsucc,succ);
		return root;
	}
	Node *del(int dkey){
		Node *par;
		Node *ptr=root;
		int found=0;
		while(ptr!=NULL){
			if(dkey==ptr->data){
				found=1;
				break;
			}
			par=ptr;
			if(dkey< ptr->data){
				if(ptr->lt==false)
					ptr=ptr->left;
				else	
					break;
			}
			else{
				if(ptr->rt==false)
					ptr=ptr->right;
				else
					break;

			}
		}
		if(found==0)
			cout<<"Not present in tree!\n";
		else if(ptr->lt==false && ptr->rt==false)
			root=caseC(par,ptr);
		else if(ptr->lt==false)
			root=caseB(par,ptr);
		else if(ptr->rt==false)
			root=caseB(par,ptr);
		else
			root=caseA(par,ptr);
		return root;
		

	}
};
int main(){
	ThreadBST t1;
	//Node *root=NULL;
	int ch;
	char ch1;
	int key;
	int val;
	do{
	cout<<"\nMENU!!\n";
	cout<<"1.Insert\n2.Inorder\n3.Preorder\n4.Delete\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter the data: ";
			cin>>key;
			t1.insert(key);
			break;
		case 2:
			cout<<"The inorder traversal is: ";
			t1.inorder();
			cout<<endl;
			break;
		case 3:
			cout<<"The preorder traversal is: ";
			t1.preorder();
			cout<<endl;
			break;
		case 4:
			cout<<"Enter the data to be deleted: ";
			cin>>val;
			t1.del(val);
			cout<<"\nAfter deletion the inorder traversal of the tree is: \n";
			t1.inorder();
			break;

	}
	cout<<"Do you want to continue? (y/n)";
	cin>>ch1;
	}while(ch1=='y');
	return 0;
}
