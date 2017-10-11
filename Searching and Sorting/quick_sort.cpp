//quick_sort(int array, int first_idx, int last_idx)
//using random pivot
//average running time = O(nlogn)
//worst case = O(n^2)

#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarray(int a[], int i, int j) {
	for(int k = i; k <= j; k++)
		cout<<a[k]<<" ";
	cout<<endl;
}


//returns index of pivot element
int random_pivot(int a[], int i, int j){
	return i + ( rand() % (j-i+1) );
}

int partition(int a[], int i, int j, int p) {
	int l = i, r = j-1;

	while(l <= r) {
		while(l <= r && a[l] <= p) l++;
		while(l <= r && a[r] > p) r--;

		if(l < r) {
			swap(&a[l], &a[r]);
			l++; r--;
		}
	}

//	cout<<"before swap with pivot:\n";
//	printarray(a,i,j);
//	cout<<"l= "<<l<<" j= "<<j<<endl;
	swap(&a[j], &a[l]);
//	cout<<"after swap with pivot:\n";
//	printarray(a,i,j);
	return l;
}

void quick_sort(int a[], int i, int j) {
	if(i < j) {
//		cout<<"array:\n";
//		printarray(a,i,j);

		int p = random_pivot(a, i, j);
//		cout<<"\npivot index and element: "<<p<<" "<<a[p]<<endl;	

		//move pivot to last index
		swap(&a[j], &a[p]);
//		cout<<"first swap with pivot\n";
//		printarray(a,i,j);

		int k = partition(a, i, j, a[j]);
//		cout<<"Partitioned at: "<<k<<endl;

		quick_sort(a, i, k-1);
		quick_sort(a, k+1, j);
	}

}

int main() {
	int a[] = {3,2,6,9,6,1,0,8,7};
	int n = sizeof(a)/sizeof(int);

	cout<<"Unsorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	quick_sort(a, 0, n-1);

	cout<<"Sorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	int b[] = {10,9,8,7,6,5,4,3,2,1,0};
	n = sizeof(b)/sizeof(int);

	cout<<"Unsorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<b[i]<<" ";
	cout<<endl;

	quick_sort(b, 0, n-1);

	cout<<"Sorted array:\n";
	for(int i = 0; i < n; i++)
		cout<<b[i]<<" ";
	cout<<endl;


	return 0;
}
