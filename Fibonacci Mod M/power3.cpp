//calculate fibonacci no. at nth pos using matrix A
//calculate A^n
//A is a 2x2 matrix and n is small
//O(16 x log n)

#include<iostream>
#include<stdio.h>
using namespace std;

void matmult(int a[2][2], int b[2][2]) {

/*	int x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	int y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	int z = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	int w = a[1][0] * b[0][1] + a[1][1] * b[1][1];
*/
	int c[2][2];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			c[i][j] = 0;
			for(int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

/*	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = w;
*/

	a[0][0] = c[0][0]; a[0][1] = c[0][1]; 
	a[1][0] = c[1][0]; a[1][1] = c[1][1];
}

void power(int a[2][2], int n) {
	int y[2][2] = { {1, 0}, {0, 1} };
	
	while(n > 0) {
		if(n&1) 
			matmult(y,a);
		matmult(a,a);
		n = n / 2;
	}

	a[0][0] = y[0][0];
	a[0][1] = y[0][1];
	a[1][0] = y[1][0];
	a[1][1] = y[1][1];
}

int fib(int n) {
	int f[2][2] = { {1,1}, {1,0} };
	
	if(n == 0)
		return 0;
	power(f, n);

	return f[1][0];

}


int main() {
	cout<<fib(100);
	return 0;
}
