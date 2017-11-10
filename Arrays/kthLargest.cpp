//algo to find kth smallest element in an array
//same as finding element with a given rank
//running time = O(n)
//Randomized Algorithm
/****Also known as RANDOMISED QUICKSELECT****/

#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Standard partition process of Quick Sort. considers the last element
//as pivot and moves all smaller element to left of it and greater elements to right.
int partition(int a[], int l, int r) {
	int x = a[r], i = l;
	for(int j = l; j <= r-1; j++) {
		if(a[j] <=x) {
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[r]);
	return i;
}

//Picks a random pivot element between l and r and partitions array around the randomly picked element using partition()
int randomPartition(int a[], int l, int r) {
	int n = r-l+1;
	int pivot = rand() % n;
	swap(&a[l + pivot], &a[r]);
	return partition(a, l, r);
}

//this function returns k'th smallest element in a[l..r] using
//Quicksort based method.
//Assumption: elements are distinct in the array
int kthsmallest(int a[], int l, int r, int k) {
	if(k > 0 && k <= r - l + 1) {
		//partition the array around a random element and
		//get position of pivot element in sorted array
		int pos = randomPartition(a, l, r);

		//if position is same as k
		if(pos-l == k-1)
			return a[pos];
		//if position is more, recur for the left subarray
		if(pos-l > k-1)
			return kthsmallest(a, l, pos-l, k);
		//else recur for right subarray
		return kthsmallest(a, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

int main() {
	int a[] = {12,3,5,7,4,19,26};
	int n = sizeof(a)/sizeof(a[0]), k = 3;

	//search (n-k+1)th smallest
	cout<<kthsmallest(a, 0, n-1, n-k+1);
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	return 0;
}

