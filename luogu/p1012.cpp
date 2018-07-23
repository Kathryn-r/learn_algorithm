#include <iostream>
#include <algorithm>
using namespace std;
string a[30];

bool cmp(const string& a, const string& b){
    return a+b>b+a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}






