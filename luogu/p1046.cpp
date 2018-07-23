//
// Created by 雷雨晴 on 2017/8/17.
//
#include <stdio.h>
int main()
{
    int a[12];
    int k,c=0;
    for(int i=1;i<=10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int j=1;j<=10;j++) {
        if(a[j]<=k+30)
            c++;
    }
    printf("%d\n",c);
    return 0;
}
