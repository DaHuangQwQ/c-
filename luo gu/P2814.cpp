// P2814 家谱
// Created by DaHuang on 2023/3/15.
// https://www.luogu.com.cn/problem/P2814
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,string> tree;

string find(string a){
    if(tree[a] != a) tree[a] = find(tree[a]);
    return tree[a];
}

int main(){
    char ch = ' ';
    string a,a1;
    cin >> ch >> a;
    while(ch != '$'){
        if(ch == '#'){
            a1 = a;
            if(tree[a] == "") // 用很大的 可能 在 第二种情况下 就 创建了 a
                tree[a] = a;
        }
        if(ch == '+'){
            tree[a] = a1;
        }
        if(ch == '?'){
            cout << a << ' ' << find(a) << endl;
        }
        cin >> ch >> a;
    }


    return 0;
}
