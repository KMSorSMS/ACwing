/*
给定一张 N 个点 M 条边的有向无环图，分别统计从每个点出发能够到达的点的数量。
输入格式
第一行两个整数 N,M，接下来 M 行每行两个整数 x,y，表示从 x 到 y 的一条有向边。
输出格式
输出共 N 行，表示每个点能够到达的点的数量。
数据范围
1≤N,M≤30000,
1≤x,y≤N

输入样例：
10 10
3 8
2 3
2 5
5 9
5 9
2 3
3 9
4 8
2 10
4 9
输出样例：
1
6
3
3
2
1
1
1
1
1
*/


#include <iostream>
using namespace std;
const int N = 30010,M = 30010;
int n,m;
int h[N],e[M],ne[M];
int idx=1,idx_s;
int node_single[N],node_count[N],count_res[N];
bool st[N];

void add_edge(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int node){
    int res=count_res[node];
    res++;
    if(st[node]) return res;
    for(int edge=h[node];edge!=0;edge=ne[edge]){
        int node_next = e[edge];
        if(!st[node_next]) dfs(node_next);
        res += count_res[node_next]+1;
    }
    st[node] = true;
    count_res[node] = res;
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        add_edge(x,y);
        node_count[y]++;
    }
    for(int i=1;i<=n;i++){
        if(node_count[i]==0){
            node_single[idx_s++] = i;
        }
    }
    for(int i=0;i<idx_s;i++){

        if(!st[node_single[i]])
            dfs(node_single[i]);
    }
    for(int i=1;i<=n;i++){
        cout << count_res[i] << "\n";
    }
}

