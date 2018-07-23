#include <stdio.h>
#include <iostream>
using namespace std;
int c[10]={6,2,5,5,4,5,6,3,7,6};

int fun(int n)
{
    int num=0;
    if(n==0){
        num=c[0];
    }
    while(n>0)
    {
        num += c[n % 10];
        n /= 10;
    }
    return num;
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        int count=0;
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                if(fun(i)+fun(j)+fun(i+j)==n-4)
                    count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

