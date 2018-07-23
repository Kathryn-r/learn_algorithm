//
// Created by 雷雨晴 on 2017/8/17.
//
#include<iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    for(int i=n;i>=0;i--)
    {
        cin>>m;
        //符号，分类第一项和其他项
        if(i==n) {
            if(m<0) printf("-");
        }
        else {
            if(m>0) printf("+");
            if(m<0) printf("-");
        }
        //数值
        //系数不是1才输出系数，0的话不输出任何，倒数第一第二项没有^，
        if(abs(m)!=1&&abs(m)!=0&&i!=0) printf("%d",abs(m));//系数
        if(i==0&&abs(m)!=0) printf("%d",abs(m));
        //^
        if(i!=0&&i!=1&&abs(m)!=0) printf("x^%d",i);
        //倒数第二项
        if(i==1&&m!=0) printf("x");
    }
    return 0;
}
