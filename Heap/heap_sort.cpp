//All operations of heap

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

int main() {
	int a[10] = {2,6,3,4,8,9,7,1,0,5};
	int n = sizeof(a)/sizeof(a[0]) - 1;

/*	n = add(a,n,2);
//	cout<<"added 2 at i = "<<n<<endl;
	n = add(a,n,3);
//	cout<<"added 3 at i = "<<n<<endl;
	n = add(a,n,5);
//	cout<<"added 5 at i = "<<n<<endl;
	n = add(a,n,1);
//	cout<<"added 1 at i = "<<n<<endl;

	cout<<"Array after adding all elements:\n";
	printarray(a,n);

	int b[] = {4,3,1,6,8,5};
	int n1 = sizeof(b)/sizeof(b[0]) - 1;

	cout<<"\n\nTest Array:\n";
	printarray(b, n1);

	cout<<"Building heap from test array:\n";
	buildHeap(b, n1);
	cout<<"Array after build heap\n";
	printarray(b,n1);
	cout<<"\n\n";

	
	cout<<"Array before deleteElement 5 at index 2\n";
	printarray(a, n);
	n = deleteElement(a,n,2);
	cout<<"Array after deleting 5:\n";
	printarray(a, n);

	cout<<"\nDeleting min from heap:\n";
	n = deleteMin(a, n);
	printarray(a, n);

	
	cout<<"Changing key of 3(at index 1) to 1;\n";
	changeKey(a, n, 1, 1);
	printarray(a,n);
	

	cout<<"Adding 4,5,6 to heap\n";
	n = add(a,n,4);
	n = add(a,n,5);
	n = add(a,n,6);
	cout<<"Array now is\n";
	printarray(a,n);

	cout<<"Deleting 5(at index 3) from the heap\n";
	n = deleteE(a,n,3);
	printarray(a,n);
*/

	buildHeap(a, n);
	cout<<"Heap is\n";
	printarray(a,n);

	cout<<"Array after sorting\n";
	int n1 = n;
	for(int i = 0; i <= n1; i++) {
		cout<<a[0]<<" ";
		n = deleteMin(a,n);
	}


	return 0;

}
