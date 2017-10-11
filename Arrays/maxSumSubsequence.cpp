//Given a sequence a0,a1,...,an-1, Find the maximum sum of all subsequence in the array

#include<iostream>
using namespace std;

//O(n^3) method
int maxSum1(int a[], int n) {
	int m = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int sum = 0;
			for(int k = i; k <= j; k++)
				sum += a[k];
			if(m < sum)
				m = sum;
		}
	}
	return m;
}

//O(n^2)
int maxSum2(int a[], int n) {
	int m = 0;
	for(int i = 0; i < n; i++) {
		int sum = a[i];
		for(int j = i+1; j < n; j++) {
			sum = sum + a[j];
			if(sum > m)
				m = sum;
		}
	}
	return m;
}


//utility function for maxSum3()
int findMaxDiff(int a[], int n) {
	int i = 0, j = 1, m = a[j]-a[i];
	j++;
	while(j < n) {
		if(a[i] > a[j-1]) 
			i = j-1;
		if(a[j]-a[i] > m)
			m = a[j]-a[i];
		j++;
	}
	return m;
}

void printarray(int a[], int n) {
	for(int i = 0; i < n; i++) 
		cout<<a[i]<<" ";
	cout<<endl;
}


//O(n)
//create an array of sum of elements of the array	
//call findMaxDiff(a,n)
int maxSum3(int a[], int n) {
	int p[n] = {0};
	//fill_n(p, n, 0);  include<algorithm>

	p[0] = a[0];
	for(int i = 1; i < n; i++) 
		p[i] = p[i-1] + a[i];

/*	cout<<"Array p\n";
	printarray(p, n);
*/
	return findMaxDiff(p, n);
}

//O(n)
//Kadane's Algorithm
int maxSum4(int a[], int n) {
	int s = a[0], m = 0;
	for(int j = 1; j < n; j++) {
		if(s < 0)
			s = 0;
		//cout<<s<<endl;
		s = s + a[j];
		if(m < s)
			m = s;
	}
	return m;
}

int main() {
	int a[] = {-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);

/*	cout<<"Array:\n";
	printarray(a, n);
*/
	//O(n^3) 
	cout<<"Maximum sum subsequence = "<<maxSum1(a, n)<<endl;

	//O(n^2) 
	cout<<"\nMaximum sum subsequence = "<<maxSum2(a, n)<<endl;

	//O(n) 
	cout<<"\nMaximum sum subsequence = "<<maxSum3(a, n)<<endl;

	//O(n) 
	cout<<"\nMaximum sum subsequence = "<<maxSum4(a, n)<<endl;


	return 0;
}
