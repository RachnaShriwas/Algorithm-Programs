//Given a sequence a0,a1,...an-1, Find 3 no.s such that a[i]+a[j]=a[k]
//i and j can be same

#include<iostream>
#include"merge_sort.cpp"
#include"arrayque2.cpp" //for findSum(a[],n,x)  with complexity O(n)
using namespace std;

//O(n^3) method
bool findSum2(int a[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(a[i] + a[j] == a[k]) {
					cout<<a[i]<<" + "<<a[j]<<" = "<<a[k]<<endl;
					return true;
				}
			}
		}
	}
	return false;
}

//O(n^2) method
//sort the array : O(nlogn)
//run a loop k -> 0 to n  : O(n) * O(n) = O(n^2)
	//call findSum(a,n, a[k]) with complexity O(n)

//Open problem...no solution till now with < O(n^2)
bool findSum3(int a[], int n) {
	merge_sort(a, 0, n-1);
	for(int k = 0; k < n; k++) {
		if(findSum(a, n, a[k])) 
			return true;
	}
	return false;
}

int main() {
	int a[] = {11,5,3,7,13,9,15,26};
	int n = sizeof(a)/sizeof(a[0]);

	//O(n^3) method
	cout<<findSum2(a, n)<<endl;

	//O(n^2) method
	cout<<findSum3(a, n)<<endl;
	return 0;
}
