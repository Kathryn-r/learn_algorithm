//
// Created by 雷雨晴 on 2017/10/1.
//
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n,x,sum=0,s[1001]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(s[x]) continue;
        else{
            s[x]++;
            sum++;
        }
    }
    cout<<sum<<endl;
    for(int i=1;i<1001;i++){
        if(s[i]) cout<<i<<" ";
    }
    return 0;
}
