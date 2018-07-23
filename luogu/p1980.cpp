//
// Created by 雷雨晴 on 2017/8/17.
//
#include <stdio.h>
int main()
{
    long long int n;
    int x,c=0;
    while(~scanf("%lld%d",&n,&x))
    {
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j!=0)
            {
                if(j%10==x)
                    c++;
                j/=10;
            }
        }
        printf("%d\n",c);
    }
}
