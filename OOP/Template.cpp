/*
 * assignment5.cpp
 *
 *  Created on: Nov 17, 2022
 *      Author: se
 */
#include <iostream>
using namespace std;
template <class T>
void selection_sort(T arr[],int n){
	int min;
	T temp;
	for(int i=0;i<n-1;i++)
	 {
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	 }
	cout<<"\nSorted array is\n";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<"  ";

	}



int main(){
	int ch;
	char d;
	do
	{
		   cout<<"-------MENU---------"<<endl;
			cout<<"1.Integer values\n2.FLoat values\n";
			cout<<"Enter your choice: \n";
			cin>>ch;
			int n1,n2;

			switch(ch){
			case 1:
			{	cout<<"Enter the size of the array: ";
				cin>>n1;
				int arr1[n1];
				cout<<"enter the elements: ";
				for(int i=0;i<n1;i++)
					cin>>arr1[i];
				selection_sort<int>(arr1,n1);
				break;
			}

			case 2:
			{   cout<<"Enter the size of the array: ";
				cin>>n2;
				float arr2[n2];
				cout<<"Enter the elements: ";
				for(int i=0;i<n2;i++)
					cin>>arr2[i];
				selection_sort<float>(arr2,n2);
				break;
			}
			default:
				cout<<"INVALID CHOICE";
			}

			cout<<"\nEnter y to continue and n to exit";
			cin>>d;

	}while(d=='y');

	return 0;
}

