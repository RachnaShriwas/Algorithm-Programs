//Given a sequence a0,a1,...,an-1, Find
// max(a[j]-a[i]) , j < i+l

#include<iostream>
using namespace std;

//O(n) method
//for concept refer SlidingWindowMinimum.cpp

int maxDiff(int a[], int n, int k) {
	int l = 0, j = 1, r = 0, s[n-k+1];
	s[l] = 0;
	int max = 0;

	while(j < n) {
		while(r >= l && a[j] < a[s[r]])
			r--;
		s[++r] = j;
		if(j >= k-1) {
			if(s[r] - s[l] >= k)//r-l+1 > k)
				l++;
			if(a[j] - a[s[l]] > max)
				max = a[j] - a[s[l]];
		}
		j++;
	}
	return max;
}

void printarray(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main() {
	int a[] = {3,6,80,7,5,2,9,10,50};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 3;

	cout<<"Initial array:\n";
	printarray(a, n);

	cout<<"Max difference: "<<maxDiff(a, n, k);

	return 0;
}
