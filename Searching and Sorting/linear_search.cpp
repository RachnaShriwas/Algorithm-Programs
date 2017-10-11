//linear search
//returns -1 if element not present in the array

#include<iostream>
using namespace std;

int linear_search(int a[], int n, int x) {
	for(int i = 0; i < n; i++) {
		if(a[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int a[] = {2,5,3,6,7,1};

	cout<<"Array: \n";
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout<<a[i]<<" ";

	//element present in the array
	int x = 5;
	cout<<"\n"<<x<<" found at index : "<<linear_search(a, sizeof(a)/sizeof(int), x);

	//element not present in the array
	x = 4;
	cout<<"\n"<<x<<" found at index : "<<linear_search(a, sizeof(a)/sizeof(int), x);


	return 0;
}
