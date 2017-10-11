//Given a sequence a0,a1,...,an-1, Find
// max(a[j]-a[i]) , j = i+l

#include<iostream>
using namespace std;

//O(n)
int findMaxDiff6(int a[], int n, int l) {
	int i = 0, j = l, m = a[j] - a[i];
	j++;
	while(j < n) {
		i = j-l;
		cout<<a[i]<<" "<<a[j]<<endl;
		if(a[j] - a[i] > m)
			m = a[j] - a[i];
		j++;
	}
	return m;
}

int main() {
	int a[] = {23,45,7,6,600,468,98,34,568};
	int n = sizeof(a)/sizeof(a[0]);
	int l = 3;

	cout<<"Array:\n";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<findMaxDiff6(a, n, l);

	return 0;
}


