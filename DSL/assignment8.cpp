/*
 * assignment8.cpp
 *
 *  Created on: 22-Nov-2022
 *      Author: pict
 */
#include <iostream>
#include <iomanip>
using namespace std;

class node{
public:
	int start;
	int max;
	int min;
	int end;
	int flag;
	node* next;

};
class sll{
public:
	int size;
	node* temp;
	node *head,*last;
	sll(){
		head=NULL;
		last=NULL;
	}
	void schedule(){
		cout<<"Enter the no of slots you want in the schedule";
		cin>>size;

		for(int i=0;i<size;i++){
			temp=new node();
			cout<<"Enter the start time: ";
			cin>>temp->start;
			cout<<"Enter minimum duration: ";
			cin>>temp->min;
			cout<<"Enter the maximum duration: ";
			cin>>temp->max;
			cout<<"Enter the end time: ";
			cin>>temp->end;
			temp->flag=0;
			temp->next=NULL;
			if(head==NULL){
				head=temp;
				last=head;

			}
			else{
				last->next=temp;
				last=temp;

			}
	}
	}
	void display(){
		int count=1;
		node* temp;
		cout<<"-------------APPOINTMENT SCHEDULE---------------\n";
		cout<<"SR NO\tStart\tEND\tMin_duration\tMax_duration\tStatus"<<endl;
        temp=head;
        while(temp!=NULL){
        	cout<<count;
        	cout<<"\t";
        	cout<<temp->start<<"\t";
        	cout<<temp->end<<"\t";
        	cout<<temp->min<<"\t\t";
        	cout<<temp->max<<"\t\t";
        	if(temp->flag){
        	    cout<<"Booked"<<endl;
        	    }
        	    else{cout<<"free"<<endl;}

        	temp=temp->next;
        	count++;
        }
	}
	void book(){
		int t;
		cout<<"\nEnter Appointment Time:";
		cin>>t;
	    node* temp=head;
	    while(temp!=NULL){
	    	if(t==temp->start){
	    		if(temp->flag==0){
	    			cout<<"Appointment booked"<<endl;
	    			temp->flag=1;
	    		    break;
	    		}
	    	}

	    	temp=temp->next;

	    }
	    display();
	}
	void cancel(){
	cout<<"\nEnter Appointment Time To Cancel:";
	int c;
	cin>>c;
	node* temp=head;
	while(temp != NULL){
	if(c == temp->start){
	if(temp->flag == 1){
	cout<<"Appointment Canceled!"<<endl;
	temp->flag = 0;
	}

	else
		cout<<"Appointment was not booked"<<endl;}
	temp = temp->next;
	}
	display();
	}
	void sort(){
	     node *sort;
	    for(int i=0;i<size;i++){
	        sort = head;
	        while(sort->next != NULL){

	        if (sort->start > sort->next->start){
	            int t;
	            t=sort->start;
	            sort->start = sort->next->start;
	            sort->next->start = t;

	            t=sort->end;
	            sort->end = sort->next->end;
	            sort->next->end = t;

	            t=sort->min;
	            sort->min = sort->next->min;
	            sort->next->min = t;

	            t=sort->max;
	            sort->max = sort->next->max;
	            sort->next->max = t;

	            t=sort->flag;
	            sort->flag = sort->next->flag;
	            sort->next->flag = t;

	        }
	    sort = sort->next;
	    }


	    }
	    cout<<"Sorting Done!!"<<endl;
	    display();
	}


};
int main(){
	sll s1;
	int ch;
	char d;
	s1.schedule();
	cout<<"Enter y to continue and n to exit";
	cin>>d;

	while(d=='y'){

		cout<<"MENU"<<endl;
		cout<<"1.Display\n2.BOOK\n3.Cancel an appointment\n4.Sort the schedule\n";
		cout<<"Enter your choice";
		cin>>ch;
		switch(ch){
		case 1:
			s1.display();
			break;
		case 2:
			s1.book();
			break;
		case 3:
			s1.cancel();
			break;
		case 4:
			s1.sort();
			break;
		default:
			cout<<"Invalid choice";

		}
		cout<<"Enter y to continue and n to exit";
		cin>>d;

	}
return 0;
}




