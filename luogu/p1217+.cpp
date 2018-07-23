#include <stdio.h>
#include <iostream>

using namespace std;
const int m = 10000000, sqrtm = 3163; //sqrtm = (int)sqrt(m)
bool w[m + 10]; //w[i]记录i是否为质数
bool ispal(int w) { //是否是回文数
    string p = to_string(w);
    string k(p); reverse(k.begin(), k.end());
    return p == k; //k是p倒过来，如果k==p那么p一定是回文
}
int main() {
    memset(w, 1, sizeof(w));
    freopen("/Users/kathryn/Desktop/prim.txt", "w", stdout);
    w[0] = w[1] = false;
    for (int i = 2; i <=sqrtm; ++i) { //筛法主体
        if (!w[i]) continue;
        for (int j = i + i; j < m; j += i)
            w[j] = false;
    }
    cout << "int p[] = {";
    for (int i = 2; i < m; ++i) {
        if (w[i] && ispal(i)) cout << i << ", "; //输出
    }
    cout << "};";
}