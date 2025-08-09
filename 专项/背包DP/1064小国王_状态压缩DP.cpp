/*
在 n×n 的棋盘上放 k 个国王，国王可攻击相邻的 8 个格子，求使它们无法互相攻击的方案总数。

输入格式
共一行，包含两个整数 n 和 k。

输出格式
共一行，表示方案总数，若不能够放置则输出0。

数据范围
1≤n≤10,
0≤k≤n^2

输入样例：
3 2
输出样例：
16
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll; 
const int N = 12,K = 144, S = 1024;
ll f[N][K][S];
int n,k;
vector<int> head[S];
vector<int> state;
int count_ones[S];

bool check_legal(int a){
    for(int i=0;i<n-1;i++){
        //就一个条件，不能相邻有 1
        if(((a >> i)&1) && ((a >> (i+1))&1)){
            return false;
        }
    }
    return true;
}

void cal_count_ones(int a){
    int tmp = a;
    while(tmp!=0){
        if(tmp & 1) count_ones[a]++;
        tmp >>= 1;
    }
}

void init_head(){
    // 先排查哪些是合格的 state
    for(int i=0;i<(1<<n);i++){
        if(check_legal(i)){
            state.push_back(i);
            cal_count_ones(i);
            // printf("legal:%x,ones:%d\n",i,count_ones[i]);
        }
    }
    for(int a: state){
        for(int b : state){
            if(((a&b)==0) && check_legal(a|b)){
                head[a].push_back(b);
            }
        }
    }
}

int main(){
    cin >> n >> k;
    init_head();
    f[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int a:state){
            int ones = count_ones[a];
            for(int j=k; j>= ones;j--){
                for(int b:head[a]){
                    f[i][j][a] +=  f[i-1][j-ones][b];
                }
            }
        }
    }
    ll res = 0;
    for(int a: state){
        res += f[n][k][a];
    }
    cout << res << "\n";
    return 0;
}
