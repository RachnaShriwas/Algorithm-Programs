#include<iostream>
using namespace std;

int rec(int n) {
	if(n < 2)
		return n;

	else
		return ( rec(n-1) + rec(n-2) ) % 100;
}

int main() {
	cout<<rec(50);

	return 0;
}

