//Given a sequence a0,a1,...an-1 find
// min|a[i]-a[j]|

#include<iostream>
#include<stdlib.h> //for abs()
#include"merge_sort.cpp"
using namespace std;

//O(nlogn) method
//sort the array : O(nlogn)
//run lopp from 0 to n and update min :O(n)
int findMinDiff(int a[], int n) {
	merge_sort(a, 0, n-1);
	int min = a[0];
	for(int i = 0; i < n-1; i++) {
		if(abs(a[i] - a[i+1]) < min)
			min = abs(a[i] - a[i+1]);
	}
	return min;
}

int main() {
	int a[] = {34,6,4,456,67,324,35,674,234,45,56,3};
	int n = sizeof(a)/sizeof(a[0]);

	cout<<"Min difference = "<<findMinDiff(a, n);

	return 0;
}
	
