//
// Created by DaHuang on 2023/3/14.
//
#include <iostream>
using namespace std;
int tree[10000];
int find(int i){
    if(tree[i] != i) tree[i] = find(tree[i]);
    return tree[i];
}
int main(){
    int n , m , p,a,b;cin >> n >> m >> p;
    for(int i = 1;i <= n;i++){
        tree[i] = i ;
    }
    while(m--){
        cin >> a >> b;
        tree[find(a)] = find(b);
    }
    while(p--){
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << "Yes" << endl;
        }else
            cout << "No" << endl;
    }



    return 0;
}