//calculate ( fib(n-1) + fib(n-2) )mod m  using matrix A
//n is an array of decimal no. of order 10^5
// 10 <= m <= 10^6
//calculate A^n
//A is a 2x2 matrix 
//O(log n)

#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int m;

//copy matrix b into matrix a
void copy(int a[2][2], int b[2][2]) {
	a[0][0] = b[0][0];
	a[0][1] = b[0][1];
	a[1][0] = b[1][0];
	a[1][1] = b[1][1];
}

void printmat(int a[2][2]) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
}


void matmult(int a[2][2], int b[2][2]) {
	int c[2][2];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			c[i][j] = 0;
			for(int k = 0; k < 2; k++)
				c[i][j] = (c[i][j] + ((a[i][k] * b[k][j]) % m)  ) % m;
		}
	}

	copy(a,c);
}

//calculates matrix a to the power n
void powerold(int a[2][2], int n) {
	int y[2][2] = { {1, 0}, {0, 1} };
	
	while(n > 0) {
		if(n&1) 
			matmult(y,a);
		matmult(a,a);
		n = n / 2;
	}
	copy(a,y);
}

//calculates a^n where n is an array of size k
void power(int a[2][2], int k,  int n[]) {		
	
	int y[2][2] = { {1, 0}, {0, 1} };

	int i = k-1;

	//loop from least significant digit to most significant digit
	while(i >= 0) {
	//	cout<<"n[i] = "<<n[i]<<endl;

		//if n[i]>0 calculate y*a^n[i]
		if(n[i] > 0) {
			int temp[2][2];
			copy(temp,a);

	//		cout<<"for i = "<<i<<" a^i :"<<endl;
	//		printmat(temp);

			powerold(temp,n[i]);
			matmult(y,temp);

	//		cout<<endl<<"y*a^i : "<<endl;
	//		printmat(y);

		}
		//a=a^10
		powerold(a, 10);
	//	cout<<endl<<"a^10 = "<<endl;
	//	printmat(a);

		i = i - 1;
	}

	//cout<<"y = "<<endl;
	//printmat(y);
	copy(a,y);
}


int fib(int k, int n[]) {
	int a[2][2] = { {1,1}, {1,0} };

	//cout<<endl<<"n in fib function:";
	//for(int i = 0; i < k; i++)
	//	cout<<n[i]<<" ";
	//cout<<endl;
	
	//calculate a^n and return a[1][0] which is fib(n)
	power(a, k, n);
	return a[1][0];
}


int main() {
	int n[] = {6,2,4,5};

	//m is between 10 and 100000
	//m = rand()%(HIGH - LOW + 1)  +  LOW
	m = rand() % (1000000 - 10 + 1) + 10;
	cout<<"m = "<<m<<" fib = "<<fib(sizeof(n)/sizeof(int), n);
	return 0;
}
