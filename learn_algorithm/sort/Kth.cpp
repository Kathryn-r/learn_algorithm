//
// Created by 雷雨晴 on 2018/4/17.
//
#include <iostream>
using namespace std;

int getKth( int a[], int alen,
            int b[], int blen,
            int k)
{
    if( NULL == a || alen < 0 || NULL == b || blen < 0 || k <=0 || k > alen + blen )
        return -1;

    if( alen == 0 )
        return b[ k - 1 ];
    if( blen == 0 )
        return a[ k - 1 ];

    if( k == 1 )
        return max( a[0], b[0] );
    int aMid, bMid;
    if( alen & 0x1 ) // 两个数组长度为奇数
    {
        aMid = alen / 2;
        bMid = blen / 2;
    }
    else
    {
        aMid = alen / 2 - 1;
        bMid = blen / 2;
    }

    if( a[aMid] <= b[bMid] )
    {
        if( k <= aMid + bMid + 1 )
            return getKth( a, aMid, b, blen , k  );
        else
            return getKth( a, alen, b+bMid+1, blen-(bMid+1), k - (bMid +1));
    }
    else
    {
        if( k <= aMid + bMid + 1 )
            return getKth( a, alen, b, bMid, k );
        else
            return getKth( a+aMid+1, alen-(aMid+1), b, blen, k - (aMid + 1));
    }
}

int main()
{
    int a[] = {94,66,47,18,9};
    int b[] = {104,98,75,50,36,8};
    int K;
    scanf("%d",&K);
    cout << getKth( a, 5, b,7, K ) << endl;
    return 0;
}
