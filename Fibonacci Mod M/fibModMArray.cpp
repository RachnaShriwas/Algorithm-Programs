//algo to find fibonacci using array

#include<iostream>
using namespace std;

int dp(int n) {
	int f[100000];

	f[0] = 0;
	f[1] = 1;

	int i;
	for(i = 2; i < n; i++) 
		f[i] = ( f[i-1] + f[i-2] ) % 100;
	return f[i-1];
}

int main() {
	cout<<dp(100000);
	return 0;
}
