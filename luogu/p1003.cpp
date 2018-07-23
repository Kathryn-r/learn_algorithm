//
// Created by 雷雨晴 on 2017/8/17.
//
#include <stdio.h>
#include <iostream>
using namespace std;
struct dt{
    int x,y,dx,dy;
}d[10005];
int main()
{
    long long int n,tempx,tempy,x,y;
    //注意！！！初始化为-1就可以输出没有地毯的情况了
    int ans=-1;
    while(~scanf("%lld",&n))
    {
        for(int i=1;i<=n;i++)
            cin>>d[i].x>>d[i].y>>d[i].dx>>d[i].dy;
        cin>>x>>y;
        //这里用覆盖更新
        for(int i=1;i<=n;i++)
        {
            tempx=d[i].x+d[i].dx;
            tempy=d[i].y+d[i].dy;
            if(x>=d[i].x&&x<=tempx&&y>=d[i].y&&y<=tempy)
                ans=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
