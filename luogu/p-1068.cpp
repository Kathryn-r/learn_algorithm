//
// Created by 雷雨晴 on 2017/10/1.
//
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct grade{
    int id,score;
}g[5000];
//比较分数和排名序号
bool cmp(grade a,grade b) {
    return(a.id<b.id);//报名号
}
bool cmp2(grade a,grade b) {
    return(a.score>b.score);//分数
}
int main()
{
    int n,m,ans=0,tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>g[i].id>>g[i].score;
    }
    //排序
    sort(g,g+n,cmp2);
    //分数相同排序错序情况，前后分别查找是否有先等的
    for(int j=n-1;j>0;j--)
        for(int i=0;i<n;i++){
            if(g[j].score==g[i].score)
            {
                sort(g+i,g+j+1,cmp);
                break;
            }
        }
    //设定分数线注意1.5的表示
    tmp=g[m*3/2-1].score;
    for(int i=0;i<n;i++){
        if(g[i].score>=tmp) ans++;
    }
    cout<<tmp<<" "<<ans<<endl;
    for(int i=0;i<ans;i++)
        cout<<g[i].id<<" "<<g[i].score<<endl;
    return 0;
}
