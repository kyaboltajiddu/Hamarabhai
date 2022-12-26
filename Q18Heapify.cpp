#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n, int i)
{
int largest = i;
int l= 2*i+1;
int r= 2*i+2;
if(l<n && arr[l]>arr[largest])
largest = l;
if(r<n && arr[r]>arr[largest])
largest=r;
if(largest!=i)
{
swap(arr[i],arr[largest]);
heapify(arr,n,largest);
}
}
void deleteRoot(int arr[],int& n)
{
int lastNode=arr[n-1];
arr[0]= lastNode;
n=n-1;
//heapify(arr,n,0);
}
void print(int arr[],int n)
{
for(int i=0;i<n;++i)
{
cout<<arr[i]<<" ";
}
}
int main()
{
int arr[] = { 50 , 55 , 52 , 54 , 53};
int n=sizeof(arr)/sizeof(arr[0]);
heapify(arr,n,1);
print(arr,n);
cout<<endl;
deleteRoot(arr,n);
print(arr,n);
cout<<endl;
heapify(arr,n,0);
print(arr,n);
return 0;
}
