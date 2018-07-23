/*#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
const int N=100;
enum decreaseDir {Init = 0, Left, Up, LeftUp};
void LCSPrint(int** LCS_dir,char* s1,char* s2,size_t row,size_t col)
{
    if(s1==NULL||s2==NULL){
        return;
    }
    size_t n,m;
    n=strlen(s1);
    m=strlen(s2);
    if(n==0||m==0||row>n||col>m)
        return;
    if(LCS_dir[row][col]==LeftUp){
        if(row>0&&col>0)
            LCSPrint(LCS_dir,s1,s2,row-1,col-1);
        printf("%c",s1[row]);
    }
    else if(LCS_dir[row][col]==Left){
        if(col>0){
            LCSPrint(LCS_dir,s1,s2,row,col-1);
        }
    }
    else if(LCS_dir[row][col]==Up){
        if(row>0){
            LCSPrint(LCS_dir,s1,s2,row-1,col);
        }
    }
}
int LCS(char s1[N],char s2[N])
{
    size_t n,m;
    n=strlen(s1);
    m=strlen(s2);
    if(!m||!n){ return 0; }
    //初始化LCS_len矩阵
    int **LCS_len;
    LCS_len=(int **)(new int[n]);
    for(int i=0;i<n;i++)
        LCS_len[i]=new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            LCS_len[i][j]=0;
    //初始化标记矩阵
    int** LCS_dir;
    LCS_dir=(int **)(new int[n]);
    for(int i=0;i<n;i++)
        LCS_dir[i]=new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            LCS_dir[i][j]=Init;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0){
                if(s1[i]==s2[j]) {
                    LCS_len[i][j] = 1;
                    LCS_dir[i][j] =LeftUp;
                }
                else{
                    if(i==0){
                        LCS_len[i][j]=LCS_len[i][j-1]+1;
                        LCS_dir[i][j]=Left;
                    }
                    else{LCS_len[i][j]=LCS_len[i-1][j]+1;
                        LCS_dir[i][j]=Up;
                    }
                }
            }
            else{
                if(s1[i]==s2[j]){
                    LCS_len[i][j]=LCS_len[i-1][j-1]+1;
                    LCS_dir[i][j]=LeftUp;
                }
                else{
                    if(LCS_len[i-1][j]>LCS_len[i][j-1]){
                        LCS_len[i][j]=LCS_len[i-1][j];
                        LCS_dir[i][j]=Up;
                    }
                    else{
                        LCS_len[i][j]=LCS_len[i][j-1];
                        LCS_dir[i][j]=Left;
                    }
                }
            }
        }
    }
    LCSPrint(LCS_dir,s1,s2,n-1,m-1);
    return LCS_len[n-1][m-1];
}
int main()
{
    char s1[N],s2[N];
    while(~scanf("%s%s",s1,s2)){
        LCS(s1,s2);
        printf("\n");
    }
    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b)? a : b;
}
int lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    for (i=0; i<=m; i++) {
        for (j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}
/*测试上面的函数 */
/*
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    getchar();
    return 0;
}
*/


// 动态规划求解并输出所有LCS
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

string X;
string Y;
vector<vector<int>> table; // 动态规划表
set<string> setOfLCS;      // set保存所有的LCS

int max(int a, int b)
{
    return (a>b)? a:b;
}

/**
 * 字符串逆序
 */
string Reverse(string str)
{
    int low = 0;
    int high = str.length() - 1;
    while (low < high)
    {
        char temp = str[low];
        str[low] = str[high];
        str[high] = temp;
        ++low;
        --high;
    }
    return str;
}

/**
 * 构造表，并返回X和Y的LCS的长度
 */
int lcs(int m, int n)
{
    // 表的大小为(m+1)*(n+1)
    table = vector<vector<int>>(m+1,vector<int>(n+1));

    for(int i=0; i<m+1; ++i)
    {
        for(int j=0; j<n+1; ++j)
        {
            // 第一行和第一列置0
            if (i == 0 || j == 0)
                table[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                table[i][j] = table[i-1][j-1] + 1;

            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }

    return table[m][n];
}

/**
 * 求出所有的最长公共子序列，并放入set中
 */
void traceBack(int i, int j, string lcs_str)
{
    while (i>0 && j>0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs_str.push_back(X[i-1]);
            --i;
            --j;
        }
        else
        {
            if (table[i-1][j] > table[i][j-1])
                --i;
            else if (table[i-1][j] < table[i][j-1])
                --j;
            else   // 相等的情况
            {
                traceBack(i-1, j, lcs_str);
                traceBack(i, j-1, lcs_str);
                return;
            }
        }
    }

    setOfLCS.insert(Reverse(lcs_str));
}


int main()
{

    cin>>X>>Y;
    int m = X.length();
    int n = Y.length();
    int length = lcs(m, n);
    cout << "The length of LCS is " << length << endl;
    string str;
    traceBack(m, n, str);
    // 倒序输出
    set<string>::iterator beg = setOfLCS.begin();
    for( ; beg!=setOfLCS.end(); ++beg)
        cout << *beg << endl;
    getchar();
    return 0;
}


