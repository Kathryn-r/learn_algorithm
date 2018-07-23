#include <iostream>
#include <stdio.h>
using namespace std;
int A[100];
void exchange(int &A,int &B)
{
    int temp=0;
    temp=A;
    A=B;
    B=temp;
}
int partition(int *A,int S,int E)
{
    int x,i;
    x=A[E];
    i=S-1;
    for(int j=S;j<E;j++){
        if(A[j]<=x){
            i++;
            exchange(A[i],A[j]);
        }
    }
    exchange(A[i+1],A[E]);
    return i+1;
}
void quick_sort(int *A,int S,int E)
{
    if(S<E) {//递归出口
        int key;
        key = partition(A, S, E);
        quick_sort(A, S, key-1);
        quick_sort(A, key + 1, E);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    quick_sort(A,1,n);
    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
