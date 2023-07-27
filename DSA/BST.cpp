/*
 * assignment1.cpp
 *
 *  Created on: Feb 17, 2023
 *      Author: exam4
 */
#include<iostream>
using namespace std;
class node
{
	 public:
	 int data;
	 node *left;
	 node *right;
	};
class bst
{

public:
		node *root;
		bst()
		{
		root=NULL;
		}
		void create();
		void insert();
		void postorder(node*);
		void inorder(node *);
		void preorder(node *);
		void search(int key);
		void minimum();
		void maximum();
		int height(node*);
		void swap(node*);
		void del();
	};
	void bst::create()
	{
		node *curr,*temp;
		int ans=1;
		cout<<"enter data:";
		do
		{
		curr=new node;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
		{
			if(curr->data<=temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=curr;
					break;
				}
				else
					temp=temp->right;

			}
			}
			}
			cout<<"Do you want to continue?";
			cin>>ans;
			}while(ans==1);
		}
	void bst::insert()
	{
		node *curr,*temp;
		int ans=1;
		cout<<"enter data:";


		curr=new node;
		cin>>curr->data;
		curr->left=curr->right=NULL;
		if(root==NULL)
		{
		root=curr;
		}
		else
		{
		temp=root;
			while(1)
			{
				if(curr->data<=temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}//end of while
		}
	}

	void bst::minimum()
	{
	 node *temp;
		int min;
	 temp=root;
		while(temp->left!=NULL)
		{
			min=temp->data;
			temp=temp->left;
			if(temp->data<min)
			{
				min=temp->data;
			}
			else
			{
				temp=temp->left;

			}
		}
		cout<<"minimum no. is:"<<min;
	}
	void bst::maximum(){
		node *temp;
				int max;
			 temp=root;
				while(temp->right!=NULL)
				{
					max=temp->data;
					temp=temp->right;
					if(temp->data>max)
					{
						max=temp->data;
					}
					else
					{
						temp=temp->right;

					}
				}
				cout<<"maximum no. is:"<<max;
			}


	int bst::height(node *root)
	{
		if(root==NULL)
		{
		return 0;
		}
		else
		{
			if(height(root->right)>height(root->left))	//right tree is longer
			{
				return (1+height(root->right));
			}
			else
			{
				return (1+height(root->left));
			}
		}
	}


	void bst::inorder(node *root)
	{
		if(root!=NULL)
		{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
		}
	}
	void bst::preorder(node *root)
	{
		if(root!=NULL)
		{
		cout<<" "<<root->data;
		preorder(root->left);
		preorder(root->right);
		}
	}
	void bst::postorder(node *root)
	{
		if(root!=NULL)
		{
		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->data;
		}
	}



	void bst::search(int key)
	{
		node *curr;
		curr=root;
		while(curr!=NULL)
		{
			if(curr->data==key)
			{
				cout<<"found";
				break;
			}
			else
			{
				if(key<curr->data)
				{
					curr=curr->left;
				}
		else
		{
		curr=curr->right;
		}
		}
		}
		if(curr==NULL)	//not found even at the end of the tree.
		{
		cout<<"not found";
		}
	}
	void bst::swap(node *root){
		node *curr;
		curr=root;
		if(curr==NULL)
			return;
		else{
			swap(curr->left);
			swap(curr->right);
			node*temp;
			temp=curr->left;
			curr->left=curr->right;
			curr->right=temp;
		}
	}

	void bst::del(){
		node *curr,*parent,*insuc;
		node *prev=NULL;
		curr=root;
		int val;
		cout<<"Enter the value which is to be deleted: ";
		cin>>val;
		while(curr!=NULL){
			if((curr->data==val) && (curr->left==NULL) && (curr->right==NULL)){
				if(curr==parent->left)
					parent->left=NULL;
				else
					parent->right=NULL;
				delete curr;

				break;
			}


			else if((curr->data==val) && (curr->left!=NULL) && (curr->right==NULL)){
				parent->left=curr->left;
				delete curr;
				break;
			}



			else if((curr->data==val) && (curr->left==NULL) && (curr->right!=NULL)){
				parent->right=curr->right;
				delete curr;
				break;

		}
			else if((curr->data==val) && (curr->left!=NULL) && (curr->right!=NULL)){
				insuc=curr->right;

				while(insuc->left!=NULL){
					prev=insuc;
					insuc=insuc->left;
				}

					parent->right=insuc;
					insuc->left=curr->left;
					insuc->right=prev;
					delete curr;
					break;
				}



			else{
				insuc=curr->right;
				parent=curr;
				if(val<curr->data){
					curr=curr->left;

				}
				else{
					curr=curr->right;
				}
			}
		}
	}





int main()
	{
		bst b;
		int key,ch;
		int value;
		do
		{
		cout<<"\n1.Create\n2.Insert\n3.Inorder\n4.Preorder\n5.Postorder\n6.Search\n7.Minimum\n8.Maximum\n9.Height\n";
		cout<<"10.Swap\n11.Delete\nPress 0 to exit\n";
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.create();
			break;
		case 2:
			b.insert();
			break;
		case 3:
			cout<<"Inorder traversal is\n";
			b.inorder(b.root);
			break;
		case 4:
			cout<<"Preorder traversal is\n";
			b.preorder(b.root);
			break;
		case 5:
			cout<<"Postorder traversal is\n";
			b.postorder(b.root);
			break;
		case 6:
			cout<<"\nEnter key:";
			cin>>key;
			b.search(key);
			break;
		case 7:
			b.minimum();
			break;
		case 8:
			b.maximum();
			break;

		case 9:
			cout<<"Height of tree: "<<b.height(b.root);
			break;

		case 10:
			b.swap(b.root);
			cout<<"After swapping inorder traversal is: \n";
			b.inorder(b.root);
			break;

		case 11:

			b.del();
			cout<<"After deleting the inorder traversal is: \n";
			b.inorder(b.root);
			break;


		}
		}while(ch!=0);
		return 0;
	}




