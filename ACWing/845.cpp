//
// Created by DaHuang on 2023/3/15.
//
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int  board[4][4];
bool vis[4][4];
struct node{
    int x,y,k;
};

bool isval(){
    for(int i = 1;i <= 9;i++){
        if(board[i%3][i/3+1] != i){
            return false;
        }
    }
    return true;
}

int bfs(int x, int y){
    queue<node> q;
    q.push({x,y,0});
    while(!q.empty()){
        node t = q.front();
        q.pop();
        if(t.x == 3 && t.y == 3){
            if(isval()){
                return t.k;
            }
        }
        for(int i = 0;i < 4;i++){
            int x = dx[i] + t.x;
            int y = dy[i] + t.y;
            if(x < 1 || x > 3 || y < 1 || y > 3 || vis[x][y] == true)
                continue;
            int temp = board[x][y];
            board[x][y] = board[t.x][t.y];
            board[t.x][t.y] = temp;
            q.push({x,y,t.k+1});
        }
    }
    return -1;
}

int main(){
    int x0,y0;
    char ch;
    for(int i = 1;i <= 3;i++){
        for(int j = 1;j <= 3; j++){
            cin >> ch;
            if(ch == 'x'){
                x0 = i;
                y0 = j;
                board[i][j] = 9;
            }else{
                board[i][j] = ch - '0';
            }
        }
    }

    cout << bfs(x0,y0) << endl;

    return 0;
}