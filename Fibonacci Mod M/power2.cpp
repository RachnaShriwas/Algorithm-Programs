//calculate x^n using while loop
//x is a decimal no. and n is small
//O(log n)

#include<iostream>
using namespace std;

long long int power(int x, long long int n) {
	int y = 1;
	while(n > 0) {
		if(n % 2 != 0)
			y = y * x;
		x = x * x;
		n = n / 2;
	}
	return y;
}

int main() {
	
	cout<<power(5,100);
	return 0;
}
