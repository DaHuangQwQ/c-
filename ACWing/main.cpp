#include <iostream>
using namespace std;

const int N = 13;

char q[N][N];//存储棋盘
bool dg[N * 2], udg[N * 2], cor[N];//点对应的两个斜线以及列上是否有皇后

int n;
int num = 0;
void dfs(int r)
{
    if(r == n)//放满了棋盘，输出棋盘
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << q[i][j];
            cout << endl;
        }
        num++;
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++)//第 r 行，第 i 列 是否放皇后
    {
        if(!cor[i] && !dg[i + r] && !udg[n - i + r])//不冲突，放皇后
        {
            q[r][i] = 'Q';
            cor[i] = dg[i + r] = udg[n - i + r] = 1;//对应的 列， 斜线 状态改变
            dfs(r + 1);//处理下一行
            cor[i] = dg[i + r] = udg[n - i + r] = 0;//恢复现场
            q[r][i] = '.';
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            q[i][j] = '.';
    dfs(0);
    cout << num << endl;
    return 0;
}