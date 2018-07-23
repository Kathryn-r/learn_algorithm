//
// Created by 雷雨晴 on 2017/10/14.
//



/*
void sort(float *a, int l)
{
    int i, j;
    float v;
    for(i = 0; i < l - 1; i ++)
        for(j = i+1; j < l; j ++) {
            if(a[i] > a[j]){
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i;
    double ans,result;
    float a[101];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        memset(a,0,sizeof(a));
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%f",&a[i]);
            ans+=abs(a[i]-a[i-1]);
        }
        result=ans*5.9;
        printf("%.2f\n",result);
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int i,j,n;
    float t;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            scanf("a[i][j]");
            if(a[i][j]>a[i][j-1])
                t=a[i][j]-a[i][j-1];
            else
                t=a[i][j-1]-a[i][j];
            a[i][j-i]=a[i][j];
        }
        printf("%f\n"t*5.9);
    }
    return 0;
}
*/
#include <stdio.h>
int main()
{
    long int ID;
    while(~scanf("%ld",&ID))
  {
      long long int result=0;
      if(ID%2==0){
          result=ID%10000;
          if(result/1000==0){
              printf("0%lld",result);
          }
    }
      else{
          result = ID%100000;
          printf("%lld",result);
      }
  }
  return 0;
}



