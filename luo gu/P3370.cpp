//
// Created by DaHuang on 2023/3/14.
//
//
// Created by DaHuang on 2023/3/14.
//
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull base=131;
int prime=233317;
ull mod=212370440130137957ll;
ull a[1600];
ull hashe(string a){
    ull ans = 0;
    for(int i = 0;i < a.size();i++){
        ans = (ans * base + (ull)a[i]) % mod + prime;
    }
    return ans;
}

int main(){
    int n ; cin >> n;
    string b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        a[i] = hashe(b);
    }
    sort(a, a+n);
    int ans = 0;
    for(int i = 0 ;i < n ;i++){
        if(a[i] != a[i+1]){
            ans++;
        }
    }
    cout << ans ;


    return 0;
}