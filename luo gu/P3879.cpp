// P3879 [TJOI2010] 阅读理解
// Created by DaHuang on 2023/3/15.
// https://www.luogu.com.cn/problem/P3879
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100001;

map<string,vector<int>> ans;
int cnt[maxn];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    string str;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> m;
        while (m--) {
            cin >> str;
            ans[str].push_back(i);
        }
    }
    cin >> n;
    while(n--){
        cin >> str;
        memset(cnt,0,sizeof cnt);
        for(int i = 0;i < ans[str].size();i++){
            if(cnt[ans[str][i]] == 0){
                if(i == ans[str].size() - 1)
                    cout << ans[str][i];
                else
                    cout << ans[str][i] << ' ';
                cnt[ans[str][i]]++;
            }
        }
        cout << endl;
    }



    return 0;
}
