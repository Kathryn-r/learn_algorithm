
#include <stdio.h>
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        long double sum=0;
        int n=0;
        while(sum<=k)
        {
            n++;
            sum=sum+1.0000000000/n;
        }
        printf("%d\n",n);
    }
    return 0;
}
