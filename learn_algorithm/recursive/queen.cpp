#include<cstdio>
#include<iostream>


using namespace std;
const int maxn=105;
int tot,n;
int c[maxn],vis[2][maxn];

void search_queen(int cur){
    if(cur==n) tot++;
    else {
        for(int i=0;i<n;i++){
            if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][cur-i+n]) { //二维数组直接判断，顺序为：列，副对角线，主对角线
                c[cur]=i;
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;//标记
                search_queen(cur+1);
               // vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;//递归完成后一定要修改回来
            }
        }
    }
}

int main () {
    cin>>n;
    search_queen(0);
    cout<<tot<<endl;
    return 0;
}

