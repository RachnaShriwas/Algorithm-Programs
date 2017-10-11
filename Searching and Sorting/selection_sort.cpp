//takes array and its size as parameter
//time - O(n^2)
//no of swaps = O(n)  ---best---

#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		int min_idx = i;

		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min_idx]) 
				min_idx = j;
		}

		swap(&a[i], &a[min_idx]);

		for(int k = 0; k < n; k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}
}

int main() {
	int arr[] = {3,1,4,5,2,0,7,9,8};
	cout<<"Unsorted array:\n";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"Sorting\n";
	selection_sort(arr, sizeof(arr)/sizeof(int));

	cout<<"\nSorted Array:\n";
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}
