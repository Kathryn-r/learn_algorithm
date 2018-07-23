//
// Created by 雷雨晴 on 2017/8/21.
//
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,l;
    char pwd[105];
    while(cin>>n>>pwd)
    {
        l=strlen(pwd);
        for(int i=0;i<l;i++){
            //字母向后移动n格
            pwd[i]=((pwd[i]-'a')+n)%26+('a');
        }
        puts(pwd);
    }
    return 0;
}
/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    int n,i,j;
    cin>>n;
    cin>>s;
    for(i=0;i<s.size();++i)
    {
        for(j=1;j<=n;++j)
        {
            ++s[i];
            if(s[i]>'z')
                s[i]='a';
        }
    }
    cout<<s;
    return 0;
}
 */
