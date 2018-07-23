#include <iostream>
#include <vector>
#include <utility>
#define weight 100
using namespace std;
vector<pair<int,int>>items;
int fraction_bag(vector<pair<int,int>>items)
{
    int value=0;
    int capacity=0;
    for(int i=0;i<items.size();i++){
        //分数背包
        if(items[i].second+capacity>=weight){
            value+=(weight-capacity)*items[i].first/items[i].second;
            return value;
        }
        value+=items[i].first;
        capacity+=items[i].second;
    }
    return value;
}
bool cmp(const pair<int,int>&a, const pair<int,int>&b)
{
    return (a.first/a.second)>(b.first/b.second);
}
int main()
{
    vector<pair<int,int>>items;
    int N;
    cin>>N;
    int w,v;
    for(int i=0;i<N;i++){
        cin>>v>>w;
        items.push_back(pair<int,int>(v,w));
    }
    sort(items.begin(),items.end(),cmp);
    cout<<"max value is "<<fraction_bag(items)<<endl;
    return 0;
}

