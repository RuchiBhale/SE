/*
 * 21367_assignment2.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: exam4
 */
#include <iostream>
using namespace std;


class Node {
    int data;
    Node *left;
    Node *right;

public:
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

    Node(const Node& other){  // parameterized constructor to add left and right node
        if (other.left != NULL ) {
            left = new Node(*other.left);
        }
        if (other.right != NULL) {
            right = new Node(*other.right);
        }
    }

    Node operator=(const Node& other)
    {
        data = other.data;

        Node *left_orig = left;
        left = new Node(*other.left);
        delete left_orig;

        Node *right_orig = right;
        right = new Node(*other.right);
        delete right_orig;

        return *this;
    }

    friend class BTree;
    friend class Stack;
};


// for insertion
class Queue
{
    int r, f;
    Node* qu[20];  // queue will store address of node

    public:
    Queue() {
        r = f = -1;
    }

    Node* front() {
        return qu[f];
    }

    void push(Node* p) {
        if (r==19)
            return;
        if (f==-1)
            f++;
        r++;
        qu[r] = p;

    }

    void pop() {
        if (f==-1)
            return;

        Node *temp = qu[f];
        if (f==r) {
            f = r = -1;
        }
        else {
            f++;
        }

        return;
    }

    int size() {
        return r+f-1;
    }

    bool empty() {
        if (r==-1 || f>r)
            return true;
        else
            return false;
    }
};


// for traversal
class Stack
{
    int top;
    Node* st[20];  // stack will store address of node

    public:
    Stack() {
        top = -1;
    }

    Node* peek() {
        return st[top];
    }

    void push(Node* p) {
        if (top==19)
            return;
        cout<<"pushed "<<p->data<<endl;
        top++;
        st[top] = p;
    }

    void pop() {
        if (top==-1)
            return;

        Node* temp = st[top];
        top++;
        cout<<"popped "<<temp->data<<endl;
        return;
    }

    bool empty() {
        if (top==-1)
            return true;
        else
            return false;
    }
};



class BTree {
    Node *root;
    Queue q;
    Stack s;
    int longest, k;
    static int leaf;
    static int internal;

    public:
    BTree() {
        root = NULL;
        longest = k =  0;
    }


    void create(int d) {
        Node *temp = new Node(d);
        if(root == NULL) {
            root = temp;
        }
        else {
            insert(root, temp);
        }
    }

    void insert(Node *root, Node *var) {
        Node *parent;
        char ch;

        q.push(root);
        while(!q.empty())
        {
            parent = q.front();
            q.pop();

            if(parent->left == NULL) {
                parent->left = var;
                break;
            }

            else
                q.push(parent->left);

            if(parent->right == NULL) {
                parent->right = var;
                break;
            }

            else
                q.push(parent->right);
        }
    }


    void display(){
        int choice = 0;
        cout<<"\nSelect Traversal"<<endl;
        cout<<"1. Inorder\n2. Preorder\n3. Postorder\n4. Exit\n";
        while(true){
            cout<<"\nEnter choice : ";
            cin>>choice;
            if(choice == 1){
                cout<<"Inorder : ";
                inorder(root);
            }
            else if(choice == 2){
                cout<<"Preoder : ";
                preorder(root);
            }
            else if(choice == 3){
                cout<<"Postorder : ";
                postorder(root);
            }
            else
            break;
        }
    }

    void inorder(Node *temp){
        if(temp != NULL){
            inorder(temp->left);
            cout<<temp->data<<" ";
            inorder(temp->right);
        }
    }

    void preorder(Node *temp){
        if(temp != NULL){
            cout<<temp->data<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(Node *temp){
        if(temp != NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data<<" ";
        }
    }


    void swapped(){
        swap(root);
        display();
    }

    void swap(Node *root){
        Node *p = root->left;
        root->left = root->right;
        root->right = p;
        if(root->left != NULL)
        swap(root->left);
        if(root->right != NULL)
        swap(root->right);
    }


    int rheight(){
        return height(root);
    }

    int height(Node *root){
        if(root == NULL){
            return -1;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }


    void count_node(Node *root){
        if(root){
            count_node(root->left);
            if(root->left == NULL && root->right == NULL)
                leaf++;
            if(root->left != NULL || root->right != NULL)
                internal++;
            count_node(root->right);
        }
    }

    static int return_leaf(){
        return leaf;
    }

    static int return_internal(){
        return internal;
    }

    void call_count(){
        count_node(root);
    }


    void delete_tree(){
        erase(root);
    }

    void erase(Node *root){
        if(root){
            erase(root->left);
            erase(root->right);
            cout<<"Deleting node : "<<root->data<<endl;
            delete root;
        }
    }


    void itr_call(){
        cout<<"\nInorder : ";
        itr_inorder(root);
        cout<<"\nPreorder : ";
        itr_preorder(root);
        cout<<"\nPostorder : ";
        itr_postorder(root);
    }

    void itr_inorder(Node *root){
        Node *temp = root;
        while(s.empty() == false || temp != NULL){
            while(temp != NULL){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.peek();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }

    void itr_preorder(Node *root){
        Node *temp = root;
        s.push(root);
        while(!s.empty()){
            temp = s.peek();
            s.pop();
            cout<<temp->data<<" ";
            if(temp->right != NULL){
                s.push(temp->right);
            }
            if(temp->left != NULL){
                s.push(temp->left);
            }
        }
    }

    void itr_postorder(Node *root){
        Node *temp;
        s.push(root);
        if(root == NULL)
            return;
        while(!s.empty()){
            temp = s.peek();
            s.pop();
            s.push(temp);

            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }

        while(!s.empty()){
            temp = s.peek();
            s.pop();
            cout<<temp->data<<" ";
        }
    }


    void itr_height(){
        iheight(root);
    }
    void iheight(Node *root){
        q.push(root);
        int height = 0;
        int count = 0;
        if(root == NULL)
            return;
        while(!q.empty()){
            height++;
            count = q.size();
            while(count--){
                root = q.front();
                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
                q.pop();
            }
        }
        cout<<"\nHeight of binary tree is : "<<height-1<<endl;
    }


    void itr_count(){
        icount(root);
    }

    void icount(Node *root){
        Node *temp = root;
        int internal = 0;
        int leaves = 0;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(temp->left == NULL && temp->right == NULL)
                leaves++;
            if(temp->left != NULL || temp->right != NULL)
                internal++;
        }

        cout<<"\nLeaf nodes are : "<<leaves<<endl;
        cout<<"\nInternal nodes are : "<<internal<<endl;
    }


    void itr_delete(){
        idelete(root);
    }

    void idelete(Node *root){
        if(root == NULL)
            return;
        q.push(root);
        Node *temp;

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            cout<<"Deleting node : "<<temp->data<<endl;
            delete temp;
        }
    }
};


int BTree::leaf = 0;
int BTree::internal = 0;


void func() {
    cout<<"\n1. Insert \n2. Display \n3. Height \n4. Swap \n5. Copy \n6. Leaves \n7. Internal nodes \n8. Erase nodes\n10. Exit\n";
}


int main(){
    BTree tree;
    int n = 0;
    int temp = 0;
    int choice = 0;
    cout<<"***** MENU *****\n";

    func();
    while(true){
        cout<<"\nEnter choice in MENU : ";
        cin>>choice;

        if(choice == 0){
            func();
        }
        else if(choice == 1){
            cout<<"Enter element : ";
            cin>>temp;
            tree.create(temp);
        }
        else if(choice == 2){
            tree.call_count();
            tree.display();
        }
        else if(choice == 3){
            cout<<"\nHeight of tree is : "<<tree.rheight();
        }
        else if(choice == 4){
            tree.swapped();
        }
        else if(choice == 5){
            BTree copy_tree;
            copy_tree = tree;
            cout<<"\nDisplaying elements of copy tree : ";
            copy_tree.display();
        }
        else if(choice == 6){
            cout<<"\nNumber of leaves are : "<<BTree::return_leaf()<<endl;
        }
        else if(choice == 7){
            cout<<"\nNumber of internal nodes : "<<BTree::return_internal()<<endl;
            }
        else if(choice == 8){
            tree.delete_tree();
        }
        else{
            cout<<"\n*** END ***\n";
            break;
        }
    }
    return 0;
}



