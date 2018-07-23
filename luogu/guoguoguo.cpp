//
// Created by 雷雨晴 on 2017/10/15.
//
#include <stdio.h>

int main()
{
    int N,m,sum,i;
    while(~scanf("%d%d",&N,&m))
    {
        sum=N;
        for(i=1;i<m;i++){
            N=N*2+1;
            sum+=N;
        }
        printf("%d\n",sum);
    }
    return 0;
}
