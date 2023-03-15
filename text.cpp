
#include <iostream>
#include <queue>
using namespace std;
int n = 30,m = 60, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char board[100][100];
bool used[100][100];
int sum;

void bfs(pair<int, int> xy){
    int temp = 0;
    queue<pair<int, int>> q;
    q.push(xy);
    while(!q.empty()){
        pair<int, int> t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || used[x][y] == true || board[x][y] == '0')
                continue;
            q.push({x,y});
            used[x][y] = true;
            temp++;
        }
    }
    if(sum < temp){
        sum = temp;
    }
}

int main(){
    for(int i = 1;i <= n ;i++){
        for(int j = 1;j <=m ;j++){
            cin >> board[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=m ;j++){
            if(board[i][j] == '1' && used[i][j] == false){
                bfs({i,j});
            }
        }
    }
    cout << sum;

}

