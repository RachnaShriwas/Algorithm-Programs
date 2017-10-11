//merge_sort(int array, int first_idx, int last_idx)
//running time = O(nlogn)
//additional space = O(n)

#include<iostream>
using namespace std;

void merge(int a[], int i, int k, int j) {
	int l = i, r = k+1, x = 0;
	int b[j-i+1];
	while(l <= k && r <= j) {
		if(a[l] < a[r])
			b[x++] = a[l++];
		else
			b[x++] = a[r++];	

	}
	while(l <= k)
		b[x++] = a[l++];
	while(r <= j)
		b[x++] = a[r++];

	//copy vaules of temp array b to original array
	l = i, x = 0;
	while(l <= j)
		a[l++] = b[x++]; 

}

void merge_sort(int a[], int i, int j) {
	if(i < j) {
		int k = (i + j) / 2;
		merge_sort(a, i , k);
		merge_sort(a, k+1, j);
		merge(a, i, k, j);
	}
}

int main() {
	int a[] = {3,1,5,9,2,7,6,8,0,2,5,6};
	int n = sizeof(a)/sizeof(int);

	cout<<"Unsorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	cout<<"Sorting\n";
	merge_sort(a, 0, n-1);

	cout<<"\nSorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
