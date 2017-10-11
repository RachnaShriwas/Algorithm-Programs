//Given a sequence a0,a1,...,an-1, Find
// max(a[j]-a[i]) , j > i

#include<iostream>
using namespace std;

//O(n^2) method
int findMaxDiff3(int a[], int n){
	int m = 0; 
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[j] - a[i] > m)
				m = a[j] - a[i];
		}
	}
	return m;
}

//O(n) method
int findMaxDiff4(int a[], int n) {
	int i = 0, j = 1, max_diff = a[j] - a[i];
	j++;
	while(j < n) {
	//	if(a[i] > a[j-1])
	//		i = j-1;
		if(a[j] - a[i] > max_diff)
			max_diff = a[j] - a[i];
		if(a[i] > a[j])
			i = j;
		j++;
	}
	return max_diff;
}
	

int main() {
	int a[] = {23,45,2,6,4,24,456,78,34,688};
	int n = sizeof(a)/sizeof(a[0]);
	
	//O(n^2) method
	cout<<findMaxDiff3(a, n);
	
	//O(n) method
	cout<<"\nMax difference = "<<findMaxDiff4(a, n);
	return 0;
}
