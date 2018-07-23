#include <stdio.h>
#include <iostream>
using namespace std;
int d[1000001];
bool vis[1000001];
int main()
{
    int n,num;
    cin>>n;
    while (n--)
    {
        cin>>num;
        for(int i=0;i<num;i++){
            cin>>d[i];
        }
        bool Find;
        int i;
        for(i=1;;i++){
            Find=true;
            memset(vis,0, sizeof(vis));
            for(int j=1;j<=num;j++){
                if(vis[d[j]%i]){
                    Find=false;
                    break;
                }
                vis[d[j]%i]=1;
            }
            if(Find) break;
        }
        cout<<i<<endl;
    }
    return 0;
}
