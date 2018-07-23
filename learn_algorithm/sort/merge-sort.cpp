#include <stdio.h>
#include <iostream>
using namespace std;
#define INF 1e6;
int A[1000];

void merge(int *A,int S1,int S2,int E)
{
    int L[1000],R[1000];
    int n1=S2-S1+1;
    int n2=E-S2+1;
    for(int i=1;i<=n1;i++)
        L[i]=A[S1+i-1];
    for(int j=1;j<=n2;j++)
        R[j]=A[S2+j];
    L[n1+1]=INF;R[n1+1]=INF;
    int i=1,j=1;
    for(int k=S1;k<=E;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}

void merge_sort(int *A,int S,int E)
{
    int q;
    if(S<E){
       q=(S+E)/2;
        merge_sort(A,S,q);
        merge_sort(A,q+1,E);
        merge(A,S,q,E);
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        merge_sort(A,0,n-1);
        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
    }
    return 0;
}

