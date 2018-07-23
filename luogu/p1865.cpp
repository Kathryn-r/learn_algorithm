#include <stdio.h>
#include <iostream>
using namespace std;
int ps[1000010];
int n,m;
void inprme()
{
    for(int i=2;i<=m;++i){
        ps[i]=1;
    }
    for(int i=2;i<=m;++i){
        if(ps[i]){
            for(int j=2;i*j<=m;++j){
                ps[i*j]=0;
            }
        }
        ps[i]+=ps[i-1];
    }
}
int main()
{
    int l,r;
    cin>>n>>m;
    inprme();
    while(n--){
        cin>>l>>r;
        if(l<1||r>m){
            cout<<"Crossing the line"<<endl;
            continue;
        }
        else{
            cout<<ps[r]-ps[l]+(ps[l]>ps[l-1]?1:0)<<endl;
        }
    }
    return 0;
}

