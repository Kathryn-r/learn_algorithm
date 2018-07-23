#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int A[1000];
    while(~scanf("%d",&n))
    {
        int key,m;
        for(int i = 1;i <=n;i++)
            cin>>A[i];
        for(int j=2;j<=n;j++){
            key=A[j];
            m=j-1;
            while(A[m]>key&&m>0)
            {
                A[m+1]=A[m];
                m--;
            }
            A[m+1]=key;
        }
        for(int i = 1;i <=n;i++)
            cout<<A[i]<<" ";
    }
    return 0;
}
