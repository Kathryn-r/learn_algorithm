#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct apple{
    int x;
    int y;
}a;
a apple1[5005];
bool cmp(const a &m,const a &n){
    return m.y<n.y;
}
int main()
{
    int n,a,b,s;
    cin>>n>>s>>a>>b;
    for(int i=0;i<n;i++){
        cin>>apple1[i].x>>apple1[i].y;
    }
    int count=0;
    sort(apple1,apple1+n,cmp);
    for(int i=0;i<n;i++){
        if(a+b>=apple1[i].x&&s>=apple1[i].y){
           count++;
            s-=apple1[i].y;
        }
    }
    printf("%d",count);
    return 0;
}

