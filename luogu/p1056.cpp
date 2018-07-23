//
// Created by 雷雨晴 on 2017/8/19.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct ps{
    int pos,cnt;//坐标，划分数
}H[2005],S[2005];
struct mp{
    int a,b,c,d;
}map[2005];
bool cmp1(ps x,ps y)
{
    return x.cnt>y.cnt;
}
bool cmp2(ps x,ps y)
{
    return x.pos<y.pos;
}
int main()
{
    int M,N,HM,SM,D;
    while(cin>>M>>N>>HM>>SM>>D)//M行，N列，横竖，D组
    {
        for(int i=0;i<D;i++){
            cin>>map[i].a>>map[i].b>>map[i].c>>map[i].d;//(a,b),(c,d)
        }
        //判断后得出划分的性质
        for(int i=0;i<D;i++){
            if(map[i].a==map[i].c) {
                S[min(map[i].b,map[i].d)].cnt++;
                S[min(map[i].b,map[i].d)].pos=min(map[i].b,map[i].d);
            }
            if(map[i].b==map[i].d) {
                H[min(map[i].a,map[i].c)].cnt++;
                H[min(map[i].a,map[i].c)].pos=min(map[i].a,map[i].c);
            }
        }
        //横竖分别排序，cnt大的在前，然后根据数量限制，找到可选划分线，按由小到大输出
        sort(H+1,H+1+M,cmp1);// +1因为0是坐标轴
        sort(S+1,S+1+N,cmp1);
        //坐标小到大
        sort(H+1,H+1+HM,cmp2);
        sort(S+1,S+1+SM,cmp2);
        //输出
        for(int i=1;i<=HM;i++) {
            cout << H[i].pos<<" ";
        }
        cout<<endl;
        for(int i=1;i<=SM;i++)
            cout<<S[i].pos<<" ";
        cout<<endl;
    }
    return 0;
}
