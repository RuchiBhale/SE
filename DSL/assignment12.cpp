#include<iostream>
using namespace std;
#define MAX 10
//const int MAX=5;

class Job
{
	int id;
	int priority;
	friend class Queue;		//Queue can access private members of class Job
public:
	void getdata()
	{
		cout<<"\nEnter Job ID: ";
		cin>>id;
		cout<<"Enter Job Priority: ";
		cin>>priority;
	}

	void putdata()
	{  
		cout<<"\n"<<id;
		cout<<"\t\t"<<priority;
	}

	bool operator<=(Job j) {
		if (priority<=j.priority)
			return true;
		return false;
	}
	
};

class Queue
{
	int front,rear;
	Job queue[MAX]; 
public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	bool isEmpty();
	bool isFull();
	void enqueue();
	void dequeue();
	void display();

};

bool Queue::isEmpty()
{
	if(front==(rear+1)||rear==-1)
	//if (front == rear)
		return 1;
	else 
		return 0;
}

bool Queue::isFull()
{
	if(rear==MAX-1)
	{
		return 1;
	}
	else
		return 0;
}

void Queue::enqueue()
{
	Job j;

	if(isFull())
	{
		cout<<"\nQueue is Full.";
	}
	else
	{
		j.getdata();
		if(rear==-1)//empty
		{
			front++;
			rear++;

			queue[rear]=j;
		}
		else
		{

			int i=rear;
			while((i>=0) && (queue[i]<=j)) 	//overloaded operator used
			{
				queue[i+1]=queue[i];
				i--;
			}
			queue[i+1]=j;
			rear++;
		}
		cout<<"\nJob Added To Queue."<<endl;
	}
}

void Queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.";
	}
	else
	{
		front++;
		cout<<"\nJob Processed From Queue."<<endl;
	}
}

void Queue::display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			queue[i].putdata();
		}
	}
}

int main()
{

	int ch;
	Queue q;

	do
	{

		cout<<"\nMENU\n";
		cout<<"1.Insert job\n";
		cout<<"2.Remove jobs\n";
		cout<<"3.Display\n";
		cout<<"4.Exit\n";

		cout<<"Enter choice: ";
		cin>>ch;

		switch(ch)
		{

			case 1: 
				q.enqueue();
				break;

			case 2: 
				q.dequeue();
				break;

			case 3:
				cout<<"Job ID ";
				cout<<"\t  Job Priority ";
				q.display();
				break;

			case 4:
				cout<<"Exiting Program...\n";
				break;

			default:
				cout<<"Invalid input!\n";
				break;
		}
	} while(ch!=4);

	return 0;
}