//
// Created by 雷雨晴 on 2017/10/2.
//
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
//20位票数，用字符串存储
struct man{
    int h;//号数
    string ticket;

    bool operator<(const man &x)const
    {
        if(ticket.size()!=x.ticket.size())
            return ticket.size()<x.ticket.size();
        else return ticket<x.ticket;
    }
}p[300];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        p[i].h=i;
        cin>>p[i].ticket;
    }
    //这里需要在结构体里运算符重载
    sort(p,p+n);
    cout<<p[n-1].h+1<<endl<<p[n-1].ticket;
    return 0;
}
