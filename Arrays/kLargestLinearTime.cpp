#include<bits/stdc++.h>
using namespace std;

void printArr(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
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
        while(l<=r && a[r]>=a[q])
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

int kthSmallest(int a[],int b[],int n,int m,int ptr,int l, int r, int rank)
{
    if(l<=r)
    {
      //  cout<<"n"<<n<<" m "<<m<<" ptr "<<ptr<<" l "<<l<<" r "<<r<<" rank "<<rank<<endl;
        //printArr(b,m);
        int k = rPivot(l,r);
        swap(b[r],b[k]);
        int pos = partition(b,l,r);
      //  cout<<"pos: "<<pos<<endl;
        if(pos == rank && ptr == n)
        {
            return pos;
        }
        else if(pos > rank)
        {

            return kthSmallest(a,b,n,m,ptr,l,pos-1,rank);
        }
        else
        {
            if(ptr<n){
                for(int j=0; j<pos && ptr<n; j++)
                {
                    b[j] = a[ptr++];
                }
        //        cout<<"pre: "<<ptr<<" ";
                return kthSmallest(a,b,n,m,ptr,0,m-1,rank);
            }
            else
            {
                return kthSmallest(a,b,n,m,ptr,pos+1,m-1,rank-pos);
            }
        }
    }
}

int main()
{
    int a[] = {1,2,22,43,65,1235,4321,12,50,5,33,700,67,32,44,76};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 6;
    int b[2*k];
    int j=0;
    for(int i=0;i<2*k;i++){
        if(i>=n)
            break;
        b[j++]= a[i];
    }
    //cout<<j<<endl;
    kthSmallest(a,b,n,j,min(n,j),0,j-1,j/2);
    //cout<<n<<" \n";

    for(int i=j-1;i>=j-k;i--)
    {
        cout<<b[i]<<" ";
    }
//    cout<<n<<" "<<k<<" "<<a[k-1]<<endl;
    return 0;
}
