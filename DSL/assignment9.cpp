#include <iostream>
using namespace std;
class Expression{
public:
    int top;
	int max=10;
	char s[10];
public:
	Expression(){
		top=-1;
	}
	bool isEmpty(){
		if(top==-1)
			return 1;
		else
			return 0;
	}
	bool isFull(){

		if(top==max-1)
			return 1;
		else
			return 0;
	}
	void push(char ch){
		if(!isFull()){
			top++;
			s[top]=ch;
		}
	}
	char pop(){
		if(!isEmpty()){
			char ch=s[top];
			top--;
			return ch;
		}
		else
			return '\0';
	}
	void checkparenthesis(char s[]){
		int flag=0;
		for(int i=0;s[i]!='\0';i++)
			{   char ch;

				if(s[i]=='(' || s[i]=='[' || s[i]=='{')
					push(s[i]);
				if(s[i]==')'||s[i]==']'||s[i]=='}')
				{
					ch=pop();
					if((s[i]==')'&& ch!='(') ||(s[i]==']'&& ch!='[')||(s[i]=='}'&& ch!='{'))
					{
						flag=1;
						break;
					}
				}
			}
			if(isEmpty()==1 && flag==0)
				cout<<"\nExpresseion is Well Parenthesized.";
			else
				cout<<"\nExpression is not Well Parenthesized.";
	}
};
int main(){
	char s1[10];
	cout<<"Enter the expression: ";
	cin>>s1;
	Expression obj;

	obj.checkparenthesis(s1);

	return 0;
}
