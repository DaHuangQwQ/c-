// P5266 【深基17.例6】学籍管理
// Created by DaHuang on 2023/3/15.
// https://www.luogu.com.cn/problem/P5266
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n,m,score; cin >> n;
    string name;
    map<string,int> ans;
    while(n--){
        cin >> m;
        switch (m) {
            case 1:
                cin >> name >> score;
                ans[name] = score;
                cout << "OK" << endl;
                break;
            case 2:
                cin >> name;
                if(ans.count(name)){
                    cout << ans[name] << endl;
                }else{
                    cout << "Not found" << endl;
                }
                break;
            case 3:
                cin >> name;

                if(ans.count(name)){
                    ans.erase(name);
                    cout << "Deleted successfully" << endl;
                }else{
                    cout << "Not found" << endl;
                }

                break;
            case 4:
                cout << ans.size() << endl;
                break;
        }
    }


    return 0;
}
