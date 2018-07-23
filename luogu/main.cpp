#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

long long int myc(long int n,long int m)
{
    long long int sum=1;
    for(int i=0;i<m;i++)
        sum=(sum*(n-i))%1000000007;
    sum/=m;
    return sum;
}
int main()
{
    long int n,m;
    scanf("%ld%ld",&n,&m);
    printf("%lld",myc(n,m));
    return 0;
}