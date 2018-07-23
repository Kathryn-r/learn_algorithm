//
// Created by 雷雨晴 on 2017/8/17.
//
#include <stdio.h>
long long int a[102];
long long int z;
int i=0;
int main()
{
    while(~scanf("%lld",&z)&&z)
    {
        i++;
        a[i] = z;
    }
    for(int j=i;j>=1;j--)
    {
        printf("%lld ",a[j]);
    }
    return 0;
}
