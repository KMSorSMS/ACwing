/*
给出 n 个点的一棵树，多次询问两点之间的最短距离。
注意：
边是无向的。所有节点的编号是 1,2,…,n。
输入格式
第一行为两个整数 n 和 m。n 表示点数，m 表示询问次数；
接下来 n−1 行，每行三个整数 x,y,k，表示点 x 和点 y 之间存在一条边长度为 k；
再接下来 m 行，每行两个整数 x,y，表示询问点 x 到点 y 的最短距离。
树中结点编号从 1 到 n。

输出格式
共 m 行，对于每次询问，输出一行询问结果。
数据范围
2≤n≤10^4,1≤m≤2×10^4,0<k≤100,
1≤x,y≤n
输入样例1：
2 2 
1 2 100 
1 2 
2 1
输出样例1：
100
100
输入样例2：
3 2
1 2 10
3 1 15
1 2
3 2
输出样例2：
10
25
*/
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e4+10;
const int M = 2*N,JS=14;
// const int N=10005,M=N*2;

int h[N],e[M],ne[M],w[M];
int idx=1;
int depth[N],f[N][JS],dist[N];
int n,m;

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

void bfs(int root){
    memset(depth,0x3f,sizeof(depth));
    depth[0] = 0,depth[root] = 1;
    queue<int> que;
    que.push(root);
    while(que.size()){
        int node = que.front();
        que.pop();
        for(int edge = h[node];edge!=0;edge=ne[edge]){
            int next_node = e[edge];
            if(depth[next_node] > depth[node]+1){
                depth[next_node] = depth[node]+1;
                que.push(next_node);
                dist[next_node] = dist[node]+w[edge];
                f[next_node][0] = node;
                for(int i=1;i<JS;i++){
                    f[next_node][i] = f[f[next_node][i-1]][i-1];
                }
            }
        }
    }
}

int lca(int x,int y){
    if(depth[x] < depth[y]) swap(x,y);
    for(int i=JS-1;i>=0;i--){
        if(depth[f[x][i]] >= depth[y]){
            x = f[x][i];
        }
    }
    if(x==y) return x;
    for(int i=JS-1;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add_edge(a,b,c),add_edge(b,a,c);
    }
    bfs(1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        int fa = lca(x,y);
        cout << (dist[x]+dist[y]-dist[fa]*2) << "\n";
    }
    return 0;
}
