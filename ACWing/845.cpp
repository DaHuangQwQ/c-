// 845. 八数码
// Created by DaHuang on 2023/3/15.
// https://www.acwing.com/problem/content/847/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> h;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int bfs(string a){
    queue<string> q;
    q.push(a);
    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(t == "12345678x"){
            return  h[t];
        }
        int pos = t.find('x');
        int a = pos/3;
        int b = pos%3;
        int nowt = h[t];
        for(int i = 0;i < 4;i++){
            int x = dx[i] + a;
            int y = dy[i] + b;
            if(x < 0 || x > 2 || y < 0 || y > 2)
                continue;
            swap(t[pos] , t[3*x+y]);
            if(h.find(t) == h.end()){
                h[t] = nowt + 1;
                q.push(t);
            }
            swap(t[pos] , t[3*x+y]);
        }
    }
    return -1;
}

int main(){
    string a;
    for(int i = 0;i < 9;i++){
        char c;
        cin >> c;
        a+=c;
    }
    cout << bfs(a) << endl;
    return 0;
}