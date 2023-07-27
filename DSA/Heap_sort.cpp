/*
 * assignment8.cpp
 *
 *  Created on: May 16, 2023
 *      Author: exam4
 */

#include <iostream>
#define size 25
using namespace std;
class Heap{
	int arr[25];
public:
	int n;
	Heap(){
	        cout<<"enter the value of n: ";
	        cin>>n;
	        for (int i=0;i<n;i++){
	            arr[i]=0;
	        }
	    }
	  void input(){
	    for (int i=0;i<n;i++){
	       int a;
	       cout<<"enter data: "<<endl;
	       cin>>a;
	       arr[i]=a;
	       cout<<endl;

	        }
	    }

  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[min])
      min = left;

    if (right < n && arr[right] < arr[min])
      min = right;

    // Swap and continue heapifying if root is not largest
    if (min != i) {
      int temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
      heapify(arr, n, min);
    }
  }

  // main function to do heap sort
  void heapSort() {
	  for(int i=n;i>=0;i--){
	      heapify(arr, n,i);}
	  	  for(int i=n-1;i>=0;i--){
	        cout<<arr[0]<<" ";
	        int temp=arr[0];
	        arr[0]=arr[i];
	 		arr[i]=temp;
	 		heapify(arr,i,0);
	  	  }
  }

};

  // Driver code
int main() {
	Heap h;
    h.input();

    cout << "Sorted array is \n";
    h.heapSort();
    return 0;
}




