//calculate x^n recursively
//x is a decimal no. and n is small
//O(log n)

#include<iostream>
using namespace std;

int power(int x, int n) {
	if(n < 0)
		return power(x, -n);
	else if(n == 0)
		return 1;
	else if(n % 2 == 0)
		return power(x * x, n / 2);
	else if(n % 2 != 0)
		return (x * power(x * x, n / 2));
}

int main() {
	
	cout<<power(5,3);
	return 0;
}

