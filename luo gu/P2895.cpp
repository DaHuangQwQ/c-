//
// Created by DaHuang on 2023/3/13.
// https://www.luogu.com.cn/problem/P2895
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int x,y,t;
};
const int N = 400;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool vis[N][N];
int fire[N][N];

int bfs(){
    queue<node> q;
    q.push({0,0,0});
    vis[0][0] = true;
    while(!q.empty()){
        node t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int x = dx[i] + t.x;
            int y = dy[i] + t.y;
            if(x < 0 || y < 0 || vis[x][y]) continue;
            if(fire[x][y] == -1){
                return t.t + 1;
            }
            if(t.t + 1  < fire[x][y]){
                vis[x][y] = true;
                q.push({x,y,t.t+1});
            }
        }
    }
    return -1;
}

int main(){
    int n,x,y,t; cin >> n;
    memset(fire,-1,sizeof fire);
    int tx[]={0,1,-1,0,0};
    int ty[]={0,0,0,1,-1};
    while(n--){
        cin >> x >> y >> t;
        for(int i = 0;i < 5 ;i++){
            int x0 = tx[i] + x;
            int y0 = ty[i] + y;
            if(x0 < 0 || y0 < 0) continue;
            if(fire[x0][y0] == -1 || fire[x0][y0] > t){
                fire[x0][y0] = t;
            }
        }
    }
//    for(int i = 0;i < 20;i++){
//        for(int j = 0;j < 20;j++){
//            cout << fire[i][j] << '\t';
//        }
//        cout << endl;
//    }
    cout << bfs();

    return 0;
}