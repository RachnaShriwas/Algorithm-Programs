//Given a sorted sequence a0,a1,...,an-1, Find two no.s such that 
// ai+aj=x
//i and j can be same

#include<iostream>
using namespace std;

//O(n) method
//take two pointers l and r.
//if a[l]+a[r] = x return true
//increment l if sum <x
//decrement r if sum > x
bool findSum(int a[], int n, int x) {
	int l = 0, r = n-1;
	while(l <= r) {
		if(a[l] + a[r] == x) {
			cout<<endl<<a[l]<<" + "<<a[r]<<" = "<<x<<endl;
			return true;
		}
		else if(a[l] + a[r] < x)
			l++;
		else
			r--;
	}
	return false;
}
/*
int main() {
	int a[] = {1,3,5,7,9,11,13,15};
	int x = 20;
	int n = sizeof(a)/sizeof(a[0]);

	cout<<findSum(a, n, x)<<endl;
	
	x = 18;
	cout<<findSum(a, n, x)<<endl;

	x = 40;
	cout<<findSum(a, n, x)<<endl;
return 0;
}*/
