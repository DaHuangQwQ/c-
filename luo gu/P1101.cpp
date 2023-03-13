//
// Created by DaHuang on 2023/3/13.
// https://www.luogu.com.cn/problem/P1101
#include <iostream>
using namespace std;

const int N = 110;
int n,dx[] = {1,-1,0,0,1,1,-1,-1},dy[] = {0,0,1,-1,1,-1,-1,1};
char board[150][150];
char init[] = "yizhong";
int st[N][N];

bool dfs(int row, int line,int k,int i ){
    if(board[row][line] != init[k])
        return false;
    if(board[row][line] == 'g') {
        return true;
    }
    int x = dx[i] + row;
    int y = dy[i] + line;
    if(x < 1 || x > n || y < 1 || y > n)
        return false;
    bool bl = dfs(x,y,k+1,i);
    if(bl){ // 如果 整句话都 成立 才 成立 递归特色
        st[row][line] = 1;
        st[x][y] = 1;
        return true;
    }
    return false;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=n ;j++){
            cin >> board[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=n ;j++){
            if(board[i][j] == init[0]) {
                for(int p = 0; p < 8;p++){ // 不在 dfs 函数 中 使用 八个方向 是 为了 统一方向
                    dfs(i, j, 0,p);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j])
                board[i][j] = '*';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << board[i][j];
        cout << endl;
    }
    return 0;
}