////
//// Created by DaHuang on 2023/3/16.
////
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//    vector<int> a;
//    int n , t;cin >> n;
//    while(n--){
//        cin >> t;
//        a.push_back(t);
//    }
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<pair<int,int>> init;
//vector<pair<int,int>> path;
//vector<vector<pair<int,int>>> res;
//int sum;
//int n,m,a,b;
//int ans;
//void dfs(int k,vector<bool>& used){
//    if(k >= init.size()){
//        res.push_back(path);
//        return;
//    }
//    for(int i = 0; i <= init.size(); i++){
//        if(used[i])
//            continue;
//        path.push_back(init[i]);
//        dfs(k+1,used);
//        path.pop_back();
////        if(k <= m){
////            used[i] = true;
////            sum += init[i].second;
////            dfs(k+1,used);
////            sum -= init[i].second;
////            used[i] = false;
////        }else{
////            used[i] = true;
////            sum += init[i].first;
////            dfs(k+1,used);
////            sum -= init[i].first;
////            used[i] = false;
////        }
//    }
//}
//
//int main(){
//    cin >> n >> m;
//
//    while(n--){
//        cin >> a >> b;
//        init.push_back({a,b});
//    }
//    vector<bool> used(init.size(),false);
//    dfs(0,used);
//    int sum = 0;
//    for(int i = 0;i < res.size();i++){
//        ans = 0;
//        for(int j = 0;j < res[i].size();j++){
//
//            if(i < m){
//                ans += res[i][j].second;
//            }else{
//                ans += res[i][j].first;
//            }
//        }
//        if(sum < ans){
//            sum = ans;
//        }
//    }
//    cout << sum << endl;
//    return 0;
//}

//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//bool isValid(int row, int col, vector<string>& chessboard, int n) {
//    // 检查列
//    for (int i = 0; i < row; i++) { // 这是一个剪枝
//        if (chessboard[i][col] == 'Q') {
//            return false;
//        }
//    }
//    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
//        if (chessboard[i][j] == 'Q') {
//            return false;
//        }
//    }
//    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//        if (chessboard[i][j] == 'Q') {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main(){
//    int n,m,a,b; cin >> n >> m;
//    vector<string> chessboard(n,string(n,'0'));
//    while(m--){
//        cin >> a >> b;
//        a -= 1;
//        b -= 1;
//        if(isValid(n,n,chessboard,n)){
//            chessboard[a][b] = 'Q';
//            cout << "Yes" << endl;
//        }else{
//            cout << "No" << endl;
//        }
//
//    }
////    for(auto i : chessboard){
////        cout << i << endl;
////    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int q,w,e,r;
//int main(){
//    int n,a1,b1,c1,a2,b2,c2,x,y; cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
//    while(n--){
//        cin >> x >> y;
//    }
//    return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//int tree[1000000000];
//int main(){
//    int n,m;cin >> n >> m;
//    int a,b,c;
//   for(int i = 1;i <= n;i++){
//        cin >> tree[i];
//    }
//    while(m--){
//        cin >> a >> b >> c;
//        if(a == 1){
//            for(int i = b;i <= c;i++){
//                if(tree[i] < 10){
//
//                }else{
//                    tree[i] /= 1.5;
//                }
//            }
//        }
//        if(a == 2){
//            int cnt = 0;
//            for(int i = b;i <= c;i++){
//                if(tree[i] < 100)
//                    cnt++;
//            }
//            cout << cnt << endl;
//        }
//        if(a == 3){
//            int cnt = 0;
//            for(int i = b;i <= c;i++){
//                cnt += tree[i];
//            }
//            cout << cnt << endl;
//        }
//    }
//    return 0;
//}


//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<int> init;
//int main(){
//    int n,a; cin >> n;
//    int sum = 0;
//    for(int i = 0;i < 4*n;i++){
//        cin >> a;
//        init.push_back(a);
//
//    }
//    sort(init.begin(),init.end(),[](int a,int b){
//        return a > b;
//    });
//
//
//    for(int i = 0;i < n;i++){
//        sum += init[i];
//    }
//    cout << sum;
//    return 0;
//}


#include <iostream>
#include <vector>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;





//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 2000000;
//int n,m, m1[N],m2[N],m3[N],ans[15];
//
//
//bool show(int y){
//    for(int x = 1; x <= n;x++){
//
//        if(m1[x] || m2[y+x] || m3[y-x+n]){
//            return false;
//        }
//
//    }
//    return true;
//}
//
//int main(){
//    int x,y;
//    cin >> n >> m;
//    while (m--){
//        cin >> x >> y;
//        if(show(y)){
//            m1[x] = 1;
//            m2[y+x] = 1;
//            m3[y-x+n] = 1;
//            cout << "Yes" << endl;
//        } else{
//            cout << "No" << endl;
//        }
//    }
//
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<pair<int,int>> init;
//vector<pair<int,int>> path;
//int sum;
//int n,m,a,b;
//int ans;
//void dfs(int k,vector<bool>& used){
//    if(ans < sum){
//        ans = sum;
//    }
//    if(k > init.size()){
//        return;
//    }
//    for(int i = 0; i <= init.size(); i++){
//        if(used[i])
//            continue;
//        if(k <= m){
//            used[i] = true;
//            sum += init[i].second;
//            dfs(k+1,used);
//            sum -= init[i].second;
//            used[i] = false;
//        }else{
//            used[i] = true;
//            sum += init[i].first;
//            dfs(k+1,used);
//            sum -= init[i].first;
//            used[i] = false;
//        }
//    }
//}
//
//int main(){
//    cin >> n >> m;
//
//    while(n--){
//        cin >> a >> b;
//        init.push_back({a,b});
//    }
//    vector<bool> used(init.size(),false);
//    dfs(0,used);
//    cout << ans << endl;
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> n;
//vector<int> path;
//vector<vector<int>> res;
//void dfs(vector<bool>& used){ // 无 start 因为 树枝 还可以选择 之前的数字
//    if(path.size() == 2){
//        res.push_back(path);
//        return;
//    }
//    for(int i = 0;i < n.size();i++){
//        if(used[i])
//            continue;
//        used[i] = true;
//        path.push_back(n[i]);
//        dfs(used);
//        path.pop_back();
//        used[i] = false;
//    }
//}
//
//bool isval(vector<int> i){
//    if(i[0] == i[1])
//        return false;
//    for(int p = 31; p>= 0; p--)
//    {
//        if(((i[0]>>p)&1) == ((i[1]>>p)&1)){
//            cout << ((i[0]>>p)&1) << " " << ((i[1]>>p)&1) << endl;
//        }else{
//            return false;
//        }
//    }
//    return true;
//}
//
//int main(){
//    int m,a;cin >>m;
//    vector<bool> used(m);
//    while(m--) {
//        cin >> a;
//        n.push_back(a);
//    }
//    dfs(used);
//    int sum = 0;
//    for(auto i : res){
//        if(isval(i)){
//            sum++;
//        }
//    }
//    cout << sum;
//
//
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//using namespace std;
//long long cnt[200005];
//int main()
//{
//    long long n;long long ans=0;long long maxx=0;
//    cin>>n;
//    memset(cnt,0,sizeof(cnt));
//    while(n--)
//    {
//        long long k;
//        cin>>k;
//        cnt[k]++;
//        if(maxx<k)maxx=k;
//    }
//
//    for(int i=0;i<=maxx;i++)
//    {
//        if(cnt[i])ans+=cnt[i]*cnt[i];
//    }
//    cout<<ans<<endl;
//}


#include <iostream>
#include <vector>
using namespace std;

const int N = 15;
bool col[N], d[N * 2], ud[N * 2];
vector<int> pos;

bool check(int x, int y) {
    if (col[y] || d[x + y] || ud[x - y + N]) {
        return false;
    }
    return true;
}

void dfs(int x, int n) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(x, i)) {
            col[i] = true;
            d[x + i] = true;
            ud[x - i + N] = true;
            dfs(i + 1, n + 1);
            col[i] = false;
            d[x + i] = false;
            ud[x - i + N] = false;
        }
    }
}

int main(){



    return 0;
}
