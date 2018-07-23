#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[30010];
int main()
{
    int w,n;
    cin>>w>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt=0;
    int j=n-1,i=0;
    while(i<=j)
    {
        if(a[i]+a[j]<=w){
            cnt++;
            j--;
            i++;
        }
        else{
            cnt++;
            j--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

