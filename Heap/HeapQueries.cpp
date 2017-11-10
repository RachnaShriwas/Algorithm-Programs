#include<bits/stdc++.h>
#include"kthSmallest.cpp"
#include"MinHeap.cpp"
#include"MaxHeap.cpp"


bool add(int a[], int n1,int n2, int x,MinHeap min,MaxHeap max) {
//	cout<<n1<<" n1 n2 "<<n2<<endl;
//	min.printarray(a,n1+n2-1);
	n2 = min.add(a+n1,n2-1,x) + 1;
//	min.printarray(a,n1+n2-1);
	min.bottumUpHeapify(a+n1,n2-1);
//	min.printarray(a,n1+n2-1);
//	cout<<n1<<" "<<n2<<endl;
	if(n1 < n2)
	{
		n1++;
//		cout<<"n1= "<<n1<<" n2= "<<n2<<" \n";
		max.bottumUpHeapify(a,n1-1);
//		cout<<"a0: "<<a[n1]<<"\n";
//		cout<<"arr\n";
//		for(int i = n1;i<n1+n2-1;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		min.topDownHeapify(a+n1,n2-2,n1);
		return false;
	}
	else if(n1==n2)
	{
		if(a[n1] < a[0]){
			swap(a[n1],a[0]);
			max.topDownHeapify(a,n1-1,0);
		}
//		cout<<"Inelse: \n";
//		min.printarray(a,n1+n2-1);
		return true;
	}
	return true;
}

bool deleteE(int a[], int n1, int n2, int x, MinHeap min,MaxHeap max) {
    bool b;
    if(x<n1)
    {
        if(n1==n2)
        {
            swap(a[n1],a[x]);
            n2 = min.deleteMin(a+n1,n2-1);
            n1++;
            max.bottumUpHeapify(a,x);
           b=true;
        }
        else
        {
            swap(a[x],a[n1-1]);
            n1--;
            max.bottumUpHeapify(a,x);
            swap(a[n1],a[n1+n2]);
            min.topDownHeapify(a+n1,n2-1,0);
            b = false;
        }
    }
    else
    {
        n2 = min.deleteElement(a+n1,n2-1,x-n1);
        n2++;
        b = true;
//        cout<<n1<<" n1 n2 "<<n2<<endl;
        if(n2<n1-1)
        {
            swap(a[n1-1],a[0]);
            n1--;
            n2++;
//            cout<<n1<<" n1 n2 "<<n2<<endl;
            max.topDownHeapify(a,n1-1,0);
            min.topDownHeapify(a+n1,n2-2,0);
//            cout<<n1<<" n1 n2 "<<n2<<endl;
            b = false;
        }
    }
    return b;
}

int findMedian(int a[], int n) {
	return a[0];
}

int main() {
	MaxHeap max;
	MinHeap min;
	int a[100];
	int brr[] = {2,8,3,10,44,4,11,6,1,14,7};
	for(int i=0;i<(sizeof(brr)/brr[0]);i++) a[i] = brr[i];
	int n = sizeof(brr)/sizeof(brr[0]);
    int k = (n+1)/2;
	max.printarray(a,n-1);
	int median = kthSmallest(a, 0, n-1, k);
	cout<<"Median: "<<a[median]<<endl;
	max.printarray(a,n-1);
	max.buildHeap(a,median);
//	max.printarray(a,n-1);
	min.buildHeap(a+(median+1),n-median-2);
	int n1=median+1,n2=n-median-1;
	bool b = add(a,n1,n2,5,min,max);
	if(!b){
		n1++;
	}
	else
	{
		n2++;
	}
	n++;
	max.printarray(a,n-1);
	 b = add(a,n1,n2,15,min,max);
	if(!b){
		n1++;
	}
	else
	{
		n2++;
	}
	n++;
	max.printarray(a,n-1);
	 b = add(a,n1,n2,20,min,max);
	if(!b){
		n1++;
	}
	else
	{
		n2++;
	}
	n++;
	max.printarray(a,n-1);
	 b = add(a,n1,n2,105,min,max);
	if(!b){
		n1++;
	}
	else
	{
		n2++;
	}
	n++;
	max.printarray(a,n-1);
    b = deleteE(a,n1,n2,9,min,max);
    if(!b)  n1--;
    else    n2--;
    n--;
    min.printarray(a,n-1);
    cout<<"Median is: "<<findMedian(a,n)<<endl;
//    min.printarray(a,n-1);
	return 0;
}
