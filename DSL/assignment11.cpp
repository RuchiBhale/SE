#include <iostream>
using namespace std;
#define max 100
class Queue{
    public:
    int item[max]; 
    int front;
    int rear;
};
class Job{
    public:
    Queue q;
    int isFull(){ //check if queue is full
        if(q.rear==max-1)
            return 1;
        else
            return 0;
    }
    int isEmpty(){ //check if queue is empty
        if(q.front==q.rear)
            return 1;
        else
            return 0;
    }
    void enque(int x){ //to insert an element in the queue
        q.item[++q.rear]=x;

    }
    int deque(){
        return (q.item[++q.front]);
    }
    void display(){
        int i;
        cout<<"\n";
    for(i=q.front+1;i<=q.rear;i++)
	     cout<<q.item[i]<<endl;
    }
};
int main(){
    Job obj;
    int ch;
    int x;
    do{
        cout<<"MENU"<<endl;
        cout<<"1.Insert job\n2.Delete job\n3.Display\n4.EXIT"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            if (!obj.isFull())
		   {   cout<<"\n Enter data:";
			    cin>>x;
			obj.enque(x);
		   }
           else
		      cout<< "Queue is overflow";
            break;
        case 2:
            if(!obj.isEmpty())
                  cout<<"\n Deleted Element="<<obj.deque();
		    else
			{   cout<<"\n Queue is underflow";  }
		    cout<<"\nremaining jobs :";
		    obj.display();
	        break;
        case 3:
            if (!obj.isEmpty())
	        {  cout<<"\n Queue contains:";
		       obj.display();
	        }
	        else
		         cout<<"\n Queue is empty";
	       break;
        case 4:
            cout<<"EXIT";
            break;
        default:
            cout<<"Invalid choice: ";
            break;
        }
}while(ch!=4);
return 0;
    }
    