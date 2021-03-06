
#include <iostream>

using namespace std;

int FindMaxSubarray(int array[], int length)
{
    int start = 0, end = 0;  //记录最大子数组的起始位置（在数组中的下标）
    int MaxSumSub;  //最大子数组的值
    int* dp = new int[length];  //动态规划记录

    dp[0] = array[0];  //初始为第一个数
    MaxSumSub = dp[0];  //最大值初始为第一个数
    int temp = 0;  //

    for(int i = 1; i < length; i++)
    {
        if(dp[i - 1] <= 0)  //前面的<0，直接丢弃
        {
            dp[i] = array[i];
            temp = i; //记录起始为止
        }
        else
            dp[i] = array[i] + dp[i - 1];  //往后求和

        if(dp[i] > MaxSumSub)  //找到到i为止的最大子数组
        {
            MaxSumSub = dp[i];  //最大...
            start = temp;  //标记起始
            end = i;  //标记此时的结束位置
        }
    }

    cout<<"最大子序列的下标:"<<start<<"->"<<end<<endl;
    return MaxSumSub;

}

int main()
{
    int a[] = {-2,-3,-4,-1,-5,-2};
    //int a[] = {23, 4};
    int length = sizeof(a) / sizeof(int);

    cout<<FindMaxSubarray(a, length);
    return 0;
}

