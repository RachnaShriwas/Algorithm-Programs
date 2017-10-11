//bubble sort 

#include<iostream>
using namespace std;

void bubble_sort(int a[], int n) {
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < i; j++) {
			if(a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}

		for(int k = 0; k < n; k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}
}


int main() {

	//worst case
	int arr[] = {10,9,8,7,6,5,4,3,2,1};

	cout<<"\nUnsorted array:\n";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	cout<<"Sorting\n";
	bubble_sort(arr, sizeof(arr)/sizeof(int));
	
	cout<<"\nSorted array:\n";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
		cout<<arr[i]<<" ";


	cout<<"\n\n";
	//average case
	int b[] = {3,1,4,5,2,6,0,8,10};

	cout<<"\nUnsorted array:\n";
	for(int i = 0; i < sizeof(b)/sizeof(int); i++)
		cout<<b[i]<<" ";
	cout<<endl;
	
	cout<<"Sorting\n";
	bubble_sort(b, sizeof(b)/sizeof(int));
	
	cout<<"\nSorted array:\n";
	for(int i = 0; i < sizeof(b)/sizeof(int); i++)
		cout<<b[i]<<" ";



	return 0;
}
