//
// Created by 雷雨晴 on 2017/8/21.
//
#include <iostream>
using namespace std;
//char->int
int char_to_int(char ch)
{
    //ox40是16进制的@
    return ch-0x40;
}
//name->number
int work(string name)
{
    int sum=1;
    for(int i=0;i<name.length();i++)
    {
        sum*=char_to_int(name[i]);
    }
    return sum%47;
}
int main()
{
    string name_UFO,name_team;
    while(cin>>name_UFO>>name_team)
    {
        if(work(name_UFO)==work(name_team))
            cout<<"GO"<<endl;
        else cout<<"STAY"<<endl;
    }
    return 0;
}
