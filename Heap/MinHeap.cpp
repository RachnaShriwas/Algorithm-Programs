//All operations of Minheap

#include<bits/stdc++.h>
using namespace std;

class MinHeap {
public:
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

//Bottom Up Heapify
void bottumUpHeapify(int a[], int i) {
	int p = (i-1)/2;
//	cout<<"i = "<<i<<" p = "<<p<<endl;	
	while(i >= 0 && p >= 0 && a[i] < a[p]) {
		swap(&a[i], &a[p]);
//		cout<<"swapped "<<a[i]<<" and "<<a[p]<<endl;
		i = p;
		p = (i-1)/2;
//		cout<<"i = "<<i<<" p = "<<p<<endl;	
	}
}

//Add element to heap
int add(int a[], int i, int x) {
	a[++i] = x;
//	cout<<"a[i] = "<<a[i]<<" i = "<<i<<endl;
	bottumUpHeapify(a, i);
	return i;
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


//delete element from heap
//swap the element with last element and call topDown Heapify
int deleteElement(int a[], int n, int i) {
	swap(&a[i], &a[n]);
	n--;
	topDownHeapify(a, n, i);
	return n;
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

//Change priority of element of heap
void changeKey(int a[], int n, int i, int x) {
	int p = a[i];
	a[i] = x;
	if(p < x) 
		topDownHeapify(a, n, i);
	else
		bottumUpHeapify(a, i);
}

//Delete element from heap by changing its priority
//make element the root and call deleteMin
int deleteE(int a[], int n, int i) {
	changeKey(a, n, i, a[0]-1);
	return deleteMin(a, n);
}

};

