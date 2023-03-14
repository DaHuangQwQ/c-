// P1115 最大子段和
// Created by DaHuang on 2023/3/14.
// https://www.luogu.com.cn/problem/P1115
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp = a[0];
    int ans = dp;

    for (int i = 1; i < n; i++) {
//        cout << dp << " * ";
        dp = max(dp + a[i], a[i]);  // 局部 用当前的 数字 和 前几 （包括自己） 相比
//        cout << ans << endl;
        ans = max(ans, dp);         // 全局 找到最大

    }

    cout << ans << endl;

    return 0;
}
