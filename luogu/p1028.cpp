/*#include <stdio.h>
int cnt=1;
void dfs(int n)
{
    for(int i=1;i<=n/2;i++){
        cnt++;
        dfs(i);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n)){
        dfs(n);
        printf("%d\n",cnt);
    }
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int f[1005];
    while(~scanf("%d",&n))
    {
        memset(f,0, sizeof(0));
        f[0]=f[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                f[i]=f[i-1]+f[i/2];
            }
            else{
                f[i]=f[i-1];
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int n;
int f[1001]={0};//存每一位数的种类
int main(){
    while(cin>>n)
    {
        for(int i=1;i<=n;i++){ //1-n的递推
            for(int j=1;j<=i/2;j++){
                f[i]+=f[j]; //每一位叠加，递推走起
            }
            f[i]++; //加上本身
        }
        cout<<f[n];//输出n的种类
    }
    return 0;
}


