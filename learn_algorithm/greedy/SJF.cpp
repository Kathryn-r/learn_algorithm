#include <iostream>
using namespace std;
bool cmp(const int &a, const int &b)
{
    return a<b;
}
int main()
{
    int F[100];
    int N;
    float sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>F[i];
    }
    sort(F,F+N,cmp);
    for(int i=0;i<N;i++){
        sum+=F[i]+sum;
    }
    sum/=N;
    printf("%.2f",sum);
    return 0;
}

