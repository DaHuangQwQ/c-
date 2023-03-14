//
// Created by DaHuang on 2023/3/14.
//
#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull base=131;
int prime=233317;
ull mod=212370440130137957ll;
ull a[300000];
ull tree[300000];
int hashe(string a){
    ull ans = 0;
    for(int i = 0;i < a.size();i++){
        ans = (ans * base + (ull)a[i]) % mod + prime;
    }
}
ull find(ull a){
    for(tree[a] != a) tree[a] = find(tree[a]);
    return tree[a];
}
int main(){
    int n ; cin >> n;
    string a,b;
    for(int i = 0;i < n;i++){
        tree[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
//        a[2*i+1] = hashe(a);
//        a[2*i+2] = hashe(b);
        tree[hashe(a)] = find(hashe(b));
    }



    return 0;
}