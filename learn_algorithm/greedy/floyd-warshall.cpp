#include <iostream>
#include <algorithm>
using namespace std;

#define  INF 1000;
int map[6][6],dis[6][6][6];
int n=5;
void init()
{
    int i,j;
    cout<<"please enter the paths matrix"<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>map[i][j];
}
void floy_warshall()
{
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dis[i][j][0]=map[i][j];
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                dis[i][j][k]=min(dis[i][j][k-1],
                                 dis[i][k][k-1]+dis[k][j][k-1]);
            }
}

int main()
{
    init();
    floy_warshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j][5]<900){
                cout<<dis[i][j][5]<<" ";
            }
            else cout<<"INF"<<" ";
        }
        cout<<endl;
    }
    return 0;
}

