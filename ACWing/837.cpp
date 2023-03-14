//
// Created by DaHuang on 2023/3/14.
// https://www.acwing.com/problem/content/839/
//
// Created by DaHuang on 2023/3/14.
// https://www.acwing.com/problem/content/839/
#include <iostream>
using namespace std;
int tree[3000500];
int size1[3000500];
int find(int x){
    if(tree[x] == x) return x;
    else return tree[x] = find(tree[x]); // 无状态压缩
}
void merge(int a,int b){
    int x = find(a);
    int y = find(b);
    if (x != y) { // 很重要 这句话
        tree[x] = y;
        size1[y] += size1[x];
    }
    return;
}
int main(){
    int n , m , a , b;
    string ch;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        tree[i] = i;
        size1[i] = 1;
    }
    while(m--){
        cin >> ch;
        if(ch == "C"){
            cin  >> a >> b;
            merge(a,b);
        }
        if(ch == "Q1"){
            cin >> a >> b;
            if(find(a) == find(b)){
                cout << "Yes" << endl;
            }else{
                cout << "No" <<endl;
            }
        }
        if(ch == "Q2"){
            cin >> a;
            cout << size1[find(a)] << endl;
        }
    }

    return 0;
}