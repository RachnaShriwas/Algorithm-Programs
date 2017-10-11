//Heap Sort

#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarray(int a[], int n) {
	for(int i =0; i <= n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

//Top Down Heapify
void topDownHeapify(int a[], int n, int i) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int j;
	while(r <= n) {
		if(a[l] < a[r])
			j = l;
		else
			j = r;
		if(a[i] > a[j]) {
			swap(&a[i], &a[j]);
			i = j;
			l = 2*i +1;
			r = 2*i +2;
		}
		else
			break;
	
	}
	if(l == n && a[l] < a[i])
		swap(&a[l], &a[i]);
}

//DeleteMin from heap
int deleteMin(int a[], int n) {
	swap(&a[0], &a[n]);
	n--;
	topDownHeapify(a, n, 0);
	return n;
}

//Build heap 
//O(n)
void buildHeap(int a[], int n) {
	int i = n/2;
	while(i >= 0) {
		topDownHeapify(a, n, i);
		i--;
	}
}


int main() {
	int a[10] = {2,6,3,4,8,9,7,1,0,5};
	int n = sizeof(a)/sizeof(a[0]) - 1;

	cout<<"Array before sorting:\n";
	printarray(a,n);

	buildHeap(a, n);
	cout<<"Heap is:\n";
	printarray(a,n);

	cout<<"Array after sorting:\n";
	int n1 = n;
	for(int i = 0; i <= n1; i++) {
		cout<<a[0]<<" ";
		n = deleteMin(a,n);
	}


	return 0;

}
