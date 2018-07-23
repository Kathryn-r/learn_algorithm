#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int A[100];
int n;
void exchange(int &A,int &B)
{
    int temp=0;
    temp=A;
    A=B;
    B=temp;
}
void max_heapify(int A[],int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if(l<=n&&A[l]>A[i]){
        largest=l;
    } else{
        largest=i;
    }
    if(r<=n&&A[r]>A[i]){
        largest=r;
    } else{
        largest=i;
    }
    if(largest!=i){
        exchange(A[i],A[largest]);
        max_heapify(A,largest);
    }
}

void build_max_heap(int A[])
{
    for(int i=n/2;i>=1;i--){
        max_heapify(A,i);
    }
}
void heap_sort(int A[])
{
    build_max_heap(A);
    for(int i=n;i>=2;i--){
        exchange(A[1],A[i]);
        n--;
        max_heapify(A,1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    heap_sort(A);
    for(int i=1;i<=n;i++){
        cout<<A[i];
    }
    return 0;
}
