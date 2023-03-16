// P1892 [BOI2003]团伙
// Created by DaHuang on 2023/3/16.
// https://www.luogu.com.cn/problem/P1892
#include <iostream>
using namespace std;

int tree[10000];

int find(int a){
    if(tree[a] != a) tree[a] = find(tree[a]);
    return tree[a];
}
void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b) return;
    tree[a] = b;
}

int main(){
    int n , m, l , r; cin >> n >> m;
    char ch;
    for(int i = 1;i <= 2 * n;i++){
        tree[i] = i;
    }
    while(m--){
        cin >> ch >> l >> r;
        if(ch == 'F'){
            merge(l,r);
        }else{
            // 并查集 与 反集 这样就符合了题目敌人的敌人是朋友的规则
            tree[find(l + n)] = find(r);
            tree[find(r + n)] = find(l);
            // 并查集 与 反集 这样就符合了题目敌人的敌人是朋友的规则
        }
    }

    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(tree[i] == i){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}