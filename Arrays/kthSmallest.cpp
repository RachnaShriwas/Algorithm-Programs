#include<bits/stdc++.h>
using namespace std;

int rPivot(int p,int q)
{
    return ((rand()%(q-p+1)) + p);
}

int partition(int a[],int p,int q)
{
    int l=p, r=q-1;
    while(l<=r)
    {
        while(l<=r && a[l]<a[q])
            l++;
        while(l<=r && a[r]>a[q])
            r--;
        if(l<=r)
        {
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }
    swap(a[q],a[l]);
    return l;
}

int kthSmallest(int a[],int l, int r, int rank)
{
    if(l<=r)
    {
        //cout<<"l: "<<l<<" r: "<<r<<" rank: "<<rank<<endl;
        int k = rPivot(l,r);
        swap(a[r],a[k]);
        int pos = partition(a,l,r);
        //cout<<"pos: "<<pos<<endl;
        if(pos - l == rank-1)
        {
            return pos;
        }
        else if(pos - l > rank-1)
        {
            return kthSmallest(a,l,pos-1,rank);
        }
        else
        {
            return kthSmallest(a,pos+1,r,rank-(pos-l+1));
        }
    }
}
/*
int main()
{
    int a[] = {2,8,7,9,1,600,121,123,11,130,700,20,12,54,234,3,565,5,33};
    int n = sizeof(a)/sizeof(a[0]);
    int k = (n+1)/2;
    kthSmallest(a,0,n-1,k);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<n<<" "<<k<<" "<<a[k-1]<<endl;
    return 0;
}*/
