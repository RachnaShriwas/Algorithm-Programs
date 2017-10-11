//binary search using recursion
//returns -1 if element not present in the array

#include<iostream>
using namespace std;

int binary_search(int a[], int l, int r, int x) {
	int m = (l + r) / 2;

	if(l <= r) {
		if(a[m] == x)
			return m;
		else if(a[m] < x)
			return binary_search(a, m+1, r, x);
		else
			return binary_search(a, l, m-1, x);
	}
	else
		return -1;
}


int main() {
	int a[] = {2,4,6,8,10};

	cout<<"Array: "<<endl;
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout<<a[i]<<" ";

	//x present in the array
	int x = 4;
	cout<<"\n"<<x<<" found at index : "<<binary_search(a, 0, sizeof(a)/sizeof(int),x);

	//x not present in the array
	x = 1;
	cout<<"\n"<<x<<" found at index : "<<binary_search(a, 0, sizeof(a)/sizeof(int),x);

	return 0;

}
