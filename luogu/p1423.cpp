//
// Created by 雷雨晴 on 2017/8/17.
//
#include <stdio.h>
int main()
{
    long double x;
    while(~scanf("%Lf",&x))
    {
        long double a=2,sum=0;
        int b=0;
        while(sum<=x)
        {
            sum+=a;
            a=0.98*a;
            b++;
        }
        printf("%d",b);
    }
    return 0;
}
