//
// Created by DaHuang on 2023/3/13.
// https://www.acwing.com/problem/content/838/
//
#include <iostream>
using namespace std;

int tree[100050];

int find(int x){
    if(tree[x] != x) tree[x] = find(tree[x]); // 使用了 状态 压缩 所有的节点 直接 指向 他们的 祖宗 而不是 父亲
    return tree[x];
}
int main(){
    int n,m,a,b;
    char ch;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        tree[i] = i;
    }
    while(m--){
        cin >> ch >> a >> b;
        if(ch == 'M'){
            tree[find(a)]=find(b);
        }
        else{
            if(find(a) == find(b)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}