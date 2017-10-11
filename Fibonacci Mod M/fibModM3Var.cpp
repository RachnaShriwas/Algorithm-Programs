//algo to implement fibonacci using 2 variables

#include<iostream>
using namespace std;

int linear(int n) {
	int a = 0, b = 1, c = n, i;

	for(i = 2; i < n; i++) {
		c = ( a + b ) % 100;
		a = b;
		b = c;
	}

	return c;
}

int main() {
	cout<<linear(100000);
	return 0;
}
