/*
5 3
1 5
2 4
3 3
4 2
5 1

5 2
3 5
5 4
8 3
4 2
5 1

5 5
1 5
2 4
3 3
4 2
5 1

*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N=5010,K=5010;
typedef long long ll;
struct Item{
    int val,pri;
};
Item items[N];
int n,k;
priority_queue<int,vector<int>,greater<int>> pqs[N];

ll ans=-0x3f3f3f3f,res=-0x3f3f3f3f;

// void dfs(int dep,int start,int pri_pre){
//     if(dep>k) {
//         if(res > ans) ans=res;
//         return;
//     }
//     for(int i=start;i<=n;i++){
//         ll add = items[i].val;
//         if(pri_pre != -1) add -= (pri_pre-items[i].pri);
//         res += add;
//         dfs(dep+1,i+1,items[i].pri);
//         res -= add;
//     }
// }

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> items[i].val >> items[i].pri;
    }
    sort(items+1,items+n+1,[](Item& a,Item& b){return a.pri > b.pri;});
    // dfs(1,1,-1);
    for(int i=1;i<=n-1;i++){
        ll sum=items[i].val;
        auto pq = pqs[i];
        if(i+k-1>n) break;
        for(int j=1;j<=k-2;j++){
            pq.push(items[i+j].val);
            sum+=items[i+j].val;
        }
        int pre_j = 0;
        for(int j=i+k-1;j<=n;j++){
            sum += items[j].val - pre_j;
            if(pq.size() && pq.top()<pre_j){
                sum += pre_j - pq.top();
                pq.pop();
                pq.push(pre_j);
            }
            pre_j = items[j].val;
            ll tmp_res = sum + (items[j].pri - items[i].pri);
            res = tmp_res > res ? tmp_res : res;
        }
        ans = res > ans ? res : ans;
    }
    cout << ans << "\n";
    return 0;
}
