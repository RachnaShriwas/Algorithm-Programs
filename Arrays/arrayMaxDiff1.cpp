//Given a sequence a0,a1,...,an-1, Find
// max|a[i] - a[j]|

#include<iostream>
#include<stdlib.h> //for abs()
using namespace std;

//O(n^2) method
//returns max difference of two no.s
int findmax1(int a[], int n) {
	int m = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(abs(a[i]-a[j]) > m)
				m = abs(a[i] - a[j]);
		}
	}
	return m;
}

//O(n) method
//run a loop and find max and min
//return max-min
int findmax2(int a[], int n) {
	int max = a[0], min = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	return max-min;
}

int main() {
	int a[] = {2,4,7,12,464,678,42,567,34,789,23};
	int n = sizeof(a)/sizeof(a[0]);

	//O(n^2)
	cout<<"Max difference = "<<findmax1(a, n);

	//O(n)
	cout<<"\nMax difference = "<<findmax2(a, n);
	return 0;
}

