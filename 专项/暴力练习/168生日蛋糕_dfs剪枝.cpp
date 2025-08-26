/*
数据范围
1≤N≤10000,
1≤M≤20
输入样例：
100
2
输出样例：
68
*/
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <cstdio>
#include <iostream>
// #include <algorithm>
using namespace std;
const int N = 1e4+10, M = 25;
int n,m,res_min=0x3f3f3f3f;
int v_min[M],q_min[M];


int get_sqrt(int x){
    int l=1,r=x;
    while(l < r){
        int mid = (l+r) >> 1;
        if(mid * mid >= x) r = mid;
        else l = mid+1;
    }
    return l;
}

void dfs(int depth, int h_i,int r_i,int v,int q){
    if(q >= res_min) return;
    if(depth > m){
        if(v == n && q < res_min){
            res_min = q;
        }
        return;
    }
    int r_u = r_i-1 > get_sqrt(n-v) ? get_sqrt(n-v):r_i-1;
    // 应该从大到小枚举，从底往上搜
    for(int r_i1=r_u;r_i1>=m-depth+1;r_i1--){
        int h_u = (n-v) / r_i1 / r_i1;
        h_u = h_u < h_i - 1? h_u:h_i-1;
        for(int h_i1=h_i-1;h_i1>=m-depth+1;h_i1--){
            int v_new = v + r_i1*r_i1*h_i1;
            int q_new = q + 2*r_i1*h_i1;
            int v_remain = n - v_new;
            if(depth==1) q_new += r_i1 * r_i1;
            if(v_remain > (m-depth)*(r_i1-1)*(r_i1-1)*(h_i1-1) || v_remain < 0) continue;
            if(v_new + v_min[m-depth] > n || q_new + q_min[m-depth] >= res_min) continue;
            if(q_new + 2*v_remain/r_i1 >= res_min) continue;
            // printf("search:r: %d,h: %d\n",r_i1,h_i1);
            dfs(depth+1, h_i1,r_i1,v_new,q_new);
        }
    }
}

void init(){
    for(int i=1;i<=m;i++){
        v_min[i] = v_min[i-1] + i*i;
        q_min[i] = q_min[i-1] + 2*i;
    }
}

int main(){
    cin >> n >> m;
    // printf("fin read\n");
    int n_sq = get_sqrt(n);
    // printf("sqrt n:%d\n",n_sq);
    dfs(1,n,n_sq,0,0);
    if(res_min == 0x3f3f3f3f) cout << "0\n";
    else cout << res_min << "\n";
    return 0;
}

/*
求开根号的方法
*/