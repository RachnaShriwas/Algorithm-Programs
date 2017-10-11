//takes array and its size as parameter
//average case = O(n^2)
//best case = O(n)

#include<iostream>
using namespace std;

void insertion_sort(int a[], int n) {
	for(int i = 1; i < n; i++) {
		int k = a[i];
		int j = i-1;
	
		while(j >=0) {
			if(a[j] > k)
				a[j+1] = a[j];
			else
				break;
			j--;
		}
		a[j+1] = k;

		for(int k = 0; k < n; k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}
}


int main() {
	int a[] = {4,2,7,5,0,9,1,8,3};

	cout<<"Unsorted array:\n";
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout<<a[i]<<" ";
	cout<<endl;

	cout<<"Sorting\n";
	insertion_sort(a, sizeof(a)/sizeof(int));

	cout<<"\nSorted array:\n";
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}
