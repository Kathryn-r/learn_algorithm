#include <iostream>
using namespace std;
int ans,a[15000][11],b[11];
int n;
void dfs(int m,int k)//m表示第几种调料(1-10)，k表示已有的美味度
{
    if(m>10){
        if(k==n){
            ans++;//(1-n)
            for(int i=1;i<=10;i++){
                a[ans][i]=b[i];
            }
        }
        return;
    }
    for(int i=1;i<=3;i++){
        if(k+i>n) break;
        b[m]=i;
        dfs(m+1,k+i);
        b[m]=0;
    }
}
int main()
{
    cin>>n;
    dfs(1,0);
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        for(int j=1;j<=10;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}