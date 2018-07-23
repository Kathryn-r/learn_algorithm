#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long int a[10000000];
int main()
{
    long long int N;
    while(~scanf("%ld",&N))
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++)
            scanf("%lld",&a[i]);
        long long int count=0,Max=0;
        for(int i=1;i<N;i++){
            if(a[i]>a[i-1]){
                count++;
            }
            else{
                Max=max(Max,count);
                count=0;
            }
        }
        printf("%lld\n",Max+1);
    }
    return 0;
}
