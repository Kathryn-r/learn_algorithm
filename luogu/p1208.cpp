#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct coF{
    int p;//单价
    int a;//数量
};
bool cmp(const coF& a,const coF& b)
{
    return a.p<b.p;
}
int main()
{
    int N,M;
    cin>>N>>M;
    coF cow[5005];
    for(int i=0;i<M;i++){
        cin>>cow[i].p>>cow[i].a;
    }
    sort(cow,cow+M,cmp);
    int cost=0;
    for(int i=0;i<M;i++){
        if(cow[i].a<N){
            cost+=cow[i].p*cow[i].a;
            N-=cow[i].a;
            continue;
        }
        else{
            cost+=cow[i].p*N;
            break;
        }
    }
    printf("%d\n",cost);
    return 0;
}

