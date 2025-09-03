/*
2 5
3 6
4 8 1 5 7
*/

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=610,M=610;
struct Node{
    ll step;
    int w_idx;
};
int n,m;
int worker[N];
Node dis_s[M][N];
int pip[M];
ll res=0,ans=-1;

void dfs(int dep){
    if(ans <= res&&ans!=-1) {return;}   
    if(dep > m) {ans = res;return;}
    Node *dis = dis_s[dep];
    for(int i=1;i<=n;i++){
        ll step =pip[dep] - worker[i];
        step = step<0?-step:step;
        dis[i] = {step,i};
    }
    sort(dis+1,dis+1+n,[](Node& a,Node& b){return a.step < b.step;});
    for(int i=1;i<=n;i++){
        ll step = dis[i].step;
        int w_idx = dis[i].w_idx;
        int prev = worker[w_idx];
        res += step;
        worker[w_idx] = pip[dep];
        dfs(dep+1);
        worker[w_idx] = prev;
        res -= step;
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> worker[i];
    }
    for(int i=1;i<=m;i++){
        cin >> pip[i];
    }
    dfs(1);
    cout << ans << "\n";
}
