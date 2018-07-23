#include <iostream>
using namespace std;
bool F[10];
void y(int n)
{
    F[n%10]=true;
    F[n/10%10]=true;
    F[n/100%10]=true;
}
int main()
{
    double A,B,C;
    cin>>A>>B>>C;
    double temp,ans=0;
    for(int i=100;i<333;i++){
        int m,n;
        temp=i;
        m=temp*B/A;
        n=temp*C/A;
        bool flag=true;
        for(int w=1;w<=9;w++){
            F[w]=false;
        }
        y(i);
        y(m);
        y(n);
        for(int j=1;j<=9;j++){
            if(!F[j]){
                flag=false;
            }
        }
        if(flag){
            printf("%d %d %d\n",i,m,n);
            ans++;
        }
    }
    if(ans==0){
        printf("No!!!\n");
    }
    return 0;
}
/*
#include<iostream>
using namespace std;
bool f[11];                             //创建数组
void doit(int i){                    //一个函数，用来判断三位数各个位置上的数字
f[i%10]=true;
f[i/10%10]=true;
f[i/100%10]=true;                //如果该数字出现就把数组里的那个位置赋为true
}
int main()                                      //主函数
{
    double a,b,c,temp,ans=0;
    cin>>a>>b>>c;                            //输入
    for(int i=100;i<=333;i++)             //开始寻找
    {
        temp=i;
        int m=temp/a*b,n=temp/a*c;          //创建出三个数
        bool flag=true;                                //定义一个标志
        for(int i=1;i<=9;i++)
            f[i]=false;                                     //初始化数组
        doit(i);
        doit(m);
        doit(n);                                            //运用函数进行判断
        for(int i=1;i<=9;i++)
        {
            if(f[i]==false)                                //判断是否所有数都出现了，如果没有则flag=false
                flag=false;
        }
        if(flag)                                             //如果全部出现
        {
            cout<<i<<" "<<m<<" "<<n<<endl;           //输出三个数
            ans++;                                                        //ans++，说明有答案
        }
    }
    if(ans==0)                                            //如果没有答案
        cout<<"No!!!";                                  //输出“No！！！”
    return 0;
}
*/