//Given a sequence a0,a1,...,an-1, Find
// max(a[j]-a[i]) , j >= i+l

#include<iostream>
using namespace std;

//O(n) method
int findMaxDiff5(int a[], int n, int l) {
	int i = 0;
	int j = l, m = a[j] - a[i];
	j++;

	while(j < n) {
		if(a[i] > a[j-1])
			i = j-l;
		if(a[j] - a[i] > m)
			m = a[j] - a[i];
		j++;
	}
	return m;
}

int main() {
	int a[] = {23,34,45,67,12,78,4,0,12,56};
	int n = sizeof(a)/sizeof(a[0]);
	int l = 3;

	cout<<findMaxDiff5(a, n, l);
	
	return 0;
}
