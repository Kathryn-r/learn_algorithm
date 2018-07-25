//
// Created by 雷雨晴 on 2018/7/25.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct student {
    int age;
    int score;
    char name[105];
}stu[1000];

bool cmp(student a,student b)
{
    if(a.score!=b.score){
        return  a.score<b.score;
    }
    else{
        int tmp = strcmp(a.name,b.name);
        if(tmp!=0) {return tmp<0;}
        else{
            return a.age<b.age;
        }
    }
}

// 也可以在结构体中定义
struct E{
    char name[101];
    int age;
    int score;
    bool operator < (const E &b) const{
        if(score!=b.score){
            return  score<b.score;
        }
        else{
            int tmp = strcmp(name,b.name);
            if(tmp!=0) {return tmp<0;}
            else{
                return age<b.age;
            }
        }
    }
};
int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s%d%d",stu[i].name,&stu[i].age,&stu[i].score);
        }
        sort(stu,stu+n,cmp);
        for(int i=0;i<n;i++){
            printf("%s %s %d\n",stu[i].name,stu[i].age,stu[i].score);
        }
    }
    return 0;
}

