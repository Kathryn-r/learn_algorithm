//
// Created by 雷雨晴 on 2018/7/25.
//
#include <stdio.h>
// 保存预处理年月日
int buf[5001][13][32];
int abs(int x){
    return x<0?-x:x;
}
bool isLeap(int x){
    if(x%4==0&&x%100!=0||x%400==0)
        return true;
}
int dayofmonth[13][2]={
        0,0,
        31,31,
        28,29,
        31,31,
        30,30,
        31,31,
        30,30,
        31,31,
        31,31,
        30,30,
        31,31,
        30,30,
        31,31
};
struct date{
    int day;
    int month;
    int year;
    void nextDay(){
        day++;
        if(day>dayofmonth[month][isLeap(year)]){
            day = 1;
            month ++;
            if(month>12){
                month = 1;
                year ++;
            }
        }
    }
};
int main()
{
    date target;
    int cnt = 0;
    target.day = 1;
    target.month = 1;
    target.year = 0;
    while(target.year!=5001){
        buf[target.year][target.month][target.day] = cnt;
        target.nextDay();
        cnt++;
    }
    int d1,m1,y1,d2,m2,y2;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        printf("%d\n",abs(buf[y2][m2][d2]-buf[y1][m1][d1]));
    }
    return 0;
}
