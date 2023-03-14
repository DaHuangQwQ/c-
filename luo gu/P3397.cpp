// P3397 地毯
// Created by DaHuang on 2023/3/14.
// https://www.luogu.com.cn/problem/P3397
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int g[N][N];

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        g[x1][y1] ++ ;
        g[x2 + 1][y1] -- ;
        g[x1][y2 + 1] -- ;
        g[x2 + 1][y2 + 1] ++ ;
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
            cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}
