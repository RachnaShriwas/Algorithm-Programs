//Given an unsorted sequence a0,a1,....an-1, Find two no.s such that 
// ai+aj=x
//i and j can be same.

#include<iostream>
#include "merge_sort.cpp"
#include "binary_search.cpp"
using namespace std;

//O(n^2) method
//run two loops and check if ai+aj == x
bool findSum(int a[], int n, int x) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i] + a[j] == x) {
				cout<<a[i]<<" + "<<a[j]<<" = "<<x<<endl;
				return true;
			}
		}
	}
	return false;
}

//O(nlogn) method
//Sort the array : O(nlogn)
//run a loop and binary search for (x-ai) : O(n) * O(logn) = O(nlogn)
bool findSum1(int a[], int n, int x){
	merge_sort(a, 0, n-1);
	for(int i = 0; i < n; i++) { 
		int k =  binary_search(a, 0, n, x-a[i]);
		if(k != -1) {
			cout<<a[i]<<" + "<<a[k]<<" = "<<x<<endl;
			return true;
		}
	}
	return false;
}


int main() {
	int a[] = {2,5,1,8,7,3,6};
	int x = 7;
	int n = sizeof(a)/sizeof(a[0]);

	//O(n^2) method
	cout<<findSum(a, n, x)<<endl;

	//O(nlogn) method
	cout<<findSum1(a, n, x);
	return 0;
}
