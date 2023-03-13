//
// Created by DaHuang on 2023/3/13.
//https://www.luogu.com.cn/problem/solution/P1162
#include <iostream>
using namespace std;
const int N = 60;
int n,used[N][N],board[N][N],dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void dfs(int col, int line){
    if(col < 1 || col > n || line < 1 || line > n || board[col][line] != 0)
        return;
    board[col][line] = 1;
    dfs(col+1,line);
    dfs(col-1,line);
    dfs(col,line+1);
    dfs(col,line-1);

    return;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n; j++){
            cin >> board[i][j];
            if(board[i][j]==1) used[i][j]=-1;
        }
    }
    // 搜索 除了 1 和 2 的地方 然后 方向求解 好思路
    for(int i=1;i<=n;i++)
    {
        if(board[i][1]!=1) dfs(i,1);
        if(board[i][n]!=1) dfs(i,n);//搜第i行的第一列和第n列
    }
    for(int i=1;i<=n;i++)
    {
        if(board[1][i]!=1) dfs(1,i);
        if(board[n][i]!=1) dfs(n,i);//搜第i列的第一行和第n行
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(used[i][j]==-1) printf("1 ");
            else
            if(board[i][j]==0) printf("2 ");
            else printf("0 ");
        }
        printf("\n");
    }

    return 0;
}
