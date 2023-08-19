#include <iostream>
using namespace std;
struct node{
	int col,row;
	int status;
	struct node *next ,*prev;
}*head[10],*tail[10]; //global array of nodes
class cinema{
public:
	cinema(){
		for(int i=0;i<10;i++){
			head[i]=tail[i]=NULL;
			struct node* temp;
			for(int j=1;j<=7;j++){
				temp= create_node(j,i+1);
				if(head[i]==tail[i] && head[i]==NULL){
					head[i]=tail[i]=temp;
					head[i]->next=tail[i]->next=NULL;
					head[i]->prev=tail[i]->prev=NULL;
				}
				else{
					temp->next=head[i];
					head[i]->prev=temp;
					head[i]=temp;
					head[i]->prev=tail[i];
					tail[i]->next=head[i];
				}

			}

		}
	}
   int getCount() {
    struct node* temp;
    int count=0;
	for(int j=0 ; j<10 ; j++){
	temp=head[j];
	for(int i=0 ; i<7 ; i++){
        if(temp->status==1)
            count++;
	temp=temp->next;
	}
	
	}
    return count;
	}

	node* create_node(int x,int y){
		struct node* temp=new(struct node);
		if(temp==NULL){
			cout<<"NO MEMORY ALLOCATED YET";
			return 0;
		}
		else{
			temp->row=x;
			temp->col=y;
			temp->status=0;//0 indicates that the seat is not booked yet
			temp->next=NULL;
			temp->prev=NULL;
			return temp;

		}


	}
	void book_seat(){
		int x,y;
		cout<<"Enter the row and the column of the seat which is to be booked: ";
		cin>>x>>y;
		struct node* temp;
		temp=head[x-1];//as we have started the row index from 0
		for(int count=0;count<7;count++){
			if(temp->row==y){
				if(temp->status==0){ //check if seat is vacant
					temp->status=1;//change the status of the seat to be 1 i.e booked
				}
				else{
					cout<<"Seat unavailable";
				}

			}temp=temp->next;

		}
		display();

	}
	void cancel(){
		int x,y;
		cout<<"Enter the row and column of the seat which is to be canceled: ";
		cin>>x>>y;
		struct node*temp;
		temp=head[x-1];
		for(int count=0;count<7;count++){
			if(temp->row==y){
				if(temp->status==1){
					temp->status=0;
				}
				else{
					cout<<"Seat is not booked yet!";
				}
			}
			temp=temp->next;
		}
		display();


	}
	void display(){
	struct node* temp;
	for(int j=0 ; j<10 ; j++){
	temp=head[j];
	for(int i=0 ; i<7 ; i++){
	cout<<temp->col<<","<<temp->row;
	cout<<"-"<<temp->status<<"\t";
	temp=temp->next;
	}
	cout<<"\n";
	}
	}
};
int main(){
	cinema c;
	cout<<"The layout of seats is as follows:\n";
	c.display();
	int ch;
	cout<<"MENU: ";
	do{
		cout<<"\n1.Book your seat\n2.Cancel your booking\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:{
            c.book_seat();
            int result=c.getCount();
            cout<<"No of seats booked: "<<result<<endl;
            cout<<"No of seats vacant: "<<70-result<<endl;
			break;
        }
			
		case 2:{
            c.cancel();
            int result=c.getCount();
            cout<<"No of seats booked: "<<result<<endl;
            cout<<"No of seats vacant: "<<70-result<<endl;

			break;
        }
			
        
		default:
			cout<<"INVALID CHOICE: ";
		}
	}while(ch!=3);

}

