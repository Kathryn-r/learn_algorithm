#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int p[100];
void matrixChainOrder(int *p,int **m,int **s,int length)
{
    int n=length-1;
    int j,q=0;
    //M对角线为0
    for(int i=1;i<length;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=0x7fffff;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<m[1][n]<<endl;
}
void print(int **s,int i,int j)
{
    if(i==j){
        cout<<"A"<<i;
    }
    else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    while(~scanf("%d",&N)){
        memset(p,0, sizeof(p));
        for(int i=0;i<N;i++){
            cin>>p[i];
        }
        int **s = new int *[N];
        int **m = new int *[N];
        for(int i=0;i<N;i++) {
            s[i] = new int[N];
            m[i] = new int[N];
        }
        matrixChainOrder(p,m,s,N);
        print(s,1,N-1);
    }
    return 0;
}



