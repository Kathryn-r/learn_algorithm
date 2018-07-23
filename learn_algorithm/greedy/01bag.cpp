#include <iostream>
#include <vector>
using namespace std;
#define weight 100
int F[100],W[100],V[100];
void ZOBag(int F[],int W,int V)
{
    for(int i=weight;i>=W;i--)
        F[i]=max(F[i],F[i-W]+V);
}
int main()
{
    memset(F,0, sizeof(F));
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>V[i]>>W[i];
    }
    for(int i=1;i<=N;i++) {
        ZOBag(F,W[i],V[i]);
    }
    cout<<"max value is "<<F[weight]<<endl;
    return 0;
}

