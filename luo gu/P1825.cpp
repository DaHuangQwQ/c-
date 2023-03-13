//
// Created by DaHuang on 2023/3/13.
//https://www.luogu.com.cn/problem/P1825

#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct node{
    int x;
    int y;
    int n;
};
int x0,y0,dx[]={0,0,1,-1},dy[]={1,-1,0,0},n,m;
char board[350][350];
bool used[350][350];

void tp(int & x,int &y){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(board[i][j] == board[x][y] && (i != x || j != y)){
                x = i;
                y = j;
                return;
            }
        }
    }
}

void bfs(){
    queue<node> q;
    q.push((node){x0,y0,0});
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if(board[t.x][t.y] == '='){
            cout << t.n << endl;
            return;
        }
        if(board[t.x][t.y] >= 'A' && board[t.x][t.y] <= 'Z'){
            tp(t.x, t.y);
        }
        for(int i = 0;i < 4;i++){
            int x = dx[i] + t.x;
            int y = dy[i] + t.y;
            if(x < 1 || x > n || y < 1 || y > m || board[x][y] == '#' || used[x][y] == true)
                continue;
            q.push((node){x,y,t.n+1});
            used[x][y] = true;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> str;
        for(int j = 1;j <= m;j++){
            board[i][j] = str[j-1];
            if(board[i][j] == '@'){
                x0 = i;
                y0 = j;
            }
        }
    }
    bfs();
    return 0;
}

