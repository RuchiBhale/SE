/*
 * avl.cpp
 *
 *  Created on: May 16, 2023
 *      Author: exam4
 */
#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

struct Node {
	 int key ;
	 string value ;
	 int height = 1 ;
	 Node* left = nullptr ;
	 Node* right = nullptr ;
};


	class AVLTree {

	 Node* root = nullptr ;

	 int nodeBalanceFactor( Node* node ) {
	 if( node == nullptr ) {
	 return 0 ;
	 }
	 return nodeHeight( node -> left ) - nodeHeight( node -> right ) ;
	 }

	 int nodeHeight( Node *node ) {
	 if( node == nullptr ) {
	 return 0;
	 }
	 return node -> height ;
	 }

	 void updateHeight( Node* node ) {
	 node -> height = 1 + max( nodeHeight( node -> left ) , nodeHeight( node -> right ) ) ;
	 }

	 Node* LLRotation( Node *node ) {
	 Node *newRoot = node->left;
	 newRoot->right = node;
	 node->left = nullptr;

	 updateHeight( node );
	 updateHeight( newRoot );

	 return newRoot;
	 }

	 Node* RRRotation( Node *node ) {
	 Node *newRoot = node->right;
	 newRoot->left = node;
	 node->right = nullptr;

	 updateHeight( node );
	 updateHeight( newRoot );

	 return newRoot;
	 }

	 Node* RLRotation( Node* node ) {
	 node -> right = LLRotation( node -> right ) ;
	 return RRRotation( node ) ;
	 }

	 Node* LRRotation( Node* node ) {
	 node -> left = RRRotation( node -> left ) ;
	 return LLRotation( node ) ;
	 }

	 Node* balance( Node* node ) {
	 if( nodeBalanceFactor( node ) == 2 ) {
	 if( nodeBalanceFactor( node -> left ) < 0 )
	 node = LRRotation( node ) ;
	 else
	 node = LLRotation( node ) ;
	 }
	 else if( nodeBalanceFactor( node ) == -2 ) {
	 if( nodeBalanceFactor( node -> right ) > 0 )
	 node =RLRotation( node ) ;
	 else
	 node = RRRotation( node ) ;
	 }
	 updateHeight( node ) ;
	 return node ;
	 }

	 void iinorder( Node *root ) {
	 if( root == nullptr )
	 return;
	 iinorder( root->left );
	 cout<< root->key <<" ";
	 iinorder( root->right );
	 }

	 Node* insertSubTree( Node* curr , int key , string value ) {
	 if( curr == nullptr ) {
	 Node* newNode = new Node() ;
	 newNode -> key = key ;
	 newNode -> value = value ;
	 return newNode ;
	 }
	 if( curr -> key > key ) {
	 curr -> left = insertSubTree( curr -> left , key , value ) ;
	 }
	 else if( curr -> key < key ) {
	 curr -> right = insertSubTree( curr -> right , key , value ) ;
	 }
	 else {
	 curr -> value = value ;
	 return curr ;
	 }
	 return balance( curr ) ;
	 }

	public:

	 void insert( int key, string value ) {
	 root = insertSubTree( root, key, value);
	 }

	 void inorder() {
	 cout<< "\nInorder: " <<endl;
	 iinorder( root );
	 cout<<endl;
	 }

	 Node* search( int key ) {
	 Node *curr = root;
	 while( curr != nullptr ) {
	 if( key > curr->key )
	 curr = curr->right;
	 else if( key < curr->key )
	 curr = curr->left;
	 else
	 return curr;
	 }
	 return nullptr;
	 }

	 void BFS() {
	 cout<< "\nBFS: " <<endl;
	 queue<Node*> Queue;
	 Queue.push( root ) ;
	 while( !Queue.empty() ) {
	 Node* poppedNode = Queue.front() ;
	 cout << poppedNode -> key << " " ;
	 Queue.pop() ;
	 if( poppedNode -> left != nullptr ) {
	 Queue.push( poppedNode -> left ) ;
	 }
	 if( poppedNode -> right != nullptr ) {
	 Queue.push( poppedNode -> right ) ;
	 }
	 }
	 cout<<endl;
	 }
	};

	int main() {
	 AVLTree tree;

//	 tree.insert(100, "1");
//	 tree.insert(50, "2");
//	 tree.insert(150, "3");
//	 tree.insert(25, "4");
//	 tree.insert(75, "5");
//	 tree.insert(125, "6");
//
//	 tree.BFS();
//	 tree.inorder();
	 int ch;
	 Node *temp;
	 int n;
	 int key; string val;
	 char choice;
	 do{


	 cout<<"\nMENU\n";
	 cout<<"1.Create\n2.BFS\n3.Inorder traversal\n4.Search\n";
	 cin>>ch;
	 switch(ch){
	 case 1:
		 cout<<"Enter the number if nodes to be inserted: ";
		 cin>>n;
		 for(int i=0;i<n;i++){
			 cout<<"Enter the integer key: ";
			 cin>>key;
			 cout<<"Enter the string value: ";
			 cin>>val;
			 tree.insert(key,val);
			 cout<<endl;
		 }
		 break;
	 case 2:
		 cout<<"BFS traversal: "<<endl;
		 tree.BFS();
		 cout<<endl;
		 break;
	 case 3:
		 cout<<"Inorder traversal"<<endl;
		 tree.inorder();
		 cout<<endl;
		 break;
	 case 4:
		 cout<<"Enter the key to be searched: ";
		 cin>>key;
		 temp=tree.search(key);
		 if(temp!=NULL)
			 cout<<"Element found!!";
		 else
			 cout<<"Element not found!";
		 break;

	 }
	 cout<<"Do you want to continue?(y/n): ";
	 cin>>choice;

//	 tree.insert(175, "7");
//	 tree.insert(85, "8");
//	 tree.insert(82, "9");
//
//	 tree.BFS();
//	 tree.inorder();
	 }while(choice=='Y' || choice=='y');
	 return 0;
	}



