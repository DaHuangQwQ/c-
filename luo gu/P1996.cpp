// P1996 约瑟夫问题
// Created by DaHuang on 2023/3/14.
// https://www.luogu.com.cn/problem/P1996
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n , m,c = 1; cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while(!q.empty()){
        if(c == m){
            cout << q.front() << " ";
            q.pop();
            c = 1;
        } else{
            c++;
            q.push(q.front());
            q.pop();
        }
    }

    return 0;
}