/*
给定一张 N 个点 M 条边的无向图，求无向图的严格次小生成树。
设最小生成树的边权之和为 sum，严格次小生成树就是指边权之和大于 sum 的生成树中最小的一个。

输入格式
第一行包含两个整数 N 和 M。
接下来 M 行，每行包含三个整数 x，y，z，表示点 x 和点 y 之前存在一条边，边的权值为 z。

输出格式
包含一行，仅一个数，表示严格次小生成树的边权和。(数据保证必定存在严格次小生成树)

数据范围
N≤10^5,M≤3×10^5,
1≤x,y≤N,
0≤z≤10^6

输入样例：
5 6
1 2 1
1 3 2
2 4 3
3 5 4
3 4 3
4 5 6
输出样例：
11
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int M=3e5+10,N=1e5+10,SZ=17,INF=0x3f3f3f3f;
struct Edge{
    int x,y,w;
    bool used;
    bool operator < (const Edge& edge) const {
        return w < edge.w;
    }
};
typedef long long ll;
Edge edges[M];
int class_set[N];
int h[N],e[2*M],ne[2*M],wei[2*M];
int idx=1,n,m;
int depth[N],f[N][SZ],d1[N][SZ],d2[N][SZ];
int max_dis[N];

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],wei[idx] = c;
    h[a] = idx++;
}

int find_class(int x){
    if(class_set[x] != x) class_set[x] = find_class(class_set[x]);
    return class_set[x];
}

ll kruscal(){
    sort(edges+1,edges+1+m,[](const Edge& e1,const Edge& e2){return e1 < e2;});
    for(int i=1;i<=n;i++) class_set[i] = i;
    ll res=0;
    for(int i=1;i<=m;i++){
        int x = edges[i].x, y = edges[i].y;
        int x_class = find_class(x), y_class = find_class(y);
        if(x_class != y_class){
            edges[i].used = true;
            class_set[y_class] = x_class;
            add_edge(x,y,edges[i].w),add_edge(y,x,edges[i].w);
            res += edges[i].w;
        }
    }
    return res;
}

void bfs(){
    queue<int> que;
    que.push(1);
    memset(depth,0x3f,sizeof(depth));
    depth[0] = 0,depth[1] = 1;
    while(que.size()){
        int node = que.front();
        que.pop();
        for(int edge = h[node];edge!=0;edge=ne[edge]){
            int node_next = e[edge];
            if(depth[node_next] > depth[node]+1){
                depth[node_next] = depth[node]+1;
                que.push(node_next);
                f[node_next][0] = node;
                d1[node_next][0] = wei[edge],d2[node_next][0] = -INF;
                for(int i=1;i<SZ;i++){
                    int anc = f[node_next][i-1];
                    f[node_next][i] = f[anc][i-1];
                    int max_[4] = {d1[node_next][i-1],d2[node_next][i-1],d1[anc][i-1],d2[anc][i-1]};
                    // 一定要初始化为负无穷
                    d1[node_next][i] = d2[node_next][i] = -INF;
                    for(int m=0;m<4;m++){
                        int mm = max_[m];
                        if(mm > d1[node_next][i]){
                            d2[node_next][i] = d1[node_next][i];
                            d1[node_next][i] = mm;
                        }else if(mm != d1[node_next][i] && mm >  d2[node_next][i]){
                            d2[node_next][i] = mm;
                        }
                    }
                }
            }
        }
    }
}

int lca(int x,int y,int w_){
    int idx_m = 0;
    if(depth[x] < depth[y]) swap(x,y);
    for(int i=SZ-1;i>=0;i--){
        if(depth[f[x][i]] >= depth[y]){
            max_dis[idx_m++] = d1[x][i];
            max_dis[idx_m++] = d2[x][i];
            x = f[x][i];
        }
    }
    if(x!=y){
        for(int i=SZ-1;i>=0;i--){
            if(f[x][i] != f[y][i]){
                max_dis[idx_m++] = d1[x][i];
                max_dis[idx_m++] = d2[x][i];
                max_dis[idx_m++] = d1[y][i];
                max_dis[idx_m++] = d2[y][i];
                x = f[x][i],y=f[y][i];
            }
        }
        max_dis[idx_m++] = d1[x][0];
        // max_dis[idx_m++] = d2[x][0];
        max_dis[idx_m++] = d1[y][0];
        // max_dis[idx_m++] = d2[y][0];
    }
    int max_1=-INF,max_2=-INF;
    for(int i=0;i<idx_m;i++){
        if(max_dis[i] > max_1){
            max_2 = max_1;
            max_1 = max_dis[i];
        }else if(max_dis[i] != max_1 && max_dis[i] > max_2){
            max_2 = max_dis[i];
        }
    }
    if(w_ > max_1 ) return w_ - max_1;
    if(w_ > max_2) return w_ - max_2;
    return INF;

    // static int distance[N * 2];
    // int cnt = 0;
    // if (depth[a] < depth[b]) swap(a, b);
    // for (int k = 16; k >= 0; k -- )
    //     if (depth[f[a][k]] >= depth[b])
    //     {
    //         distance[cnt ++ ] = d1[a][k];
    //         distance[cnt ++ ] = d2[a][k];
    //         a = f[a][k];
    //     }
    // if (a != b)
    // {
    //     for (int k = 16; k >= 0; k -- )
    //         if (f[a][k] != f[b][k])
    //         {
    //             distance[cnt ++ ] = d1[a][k];
    //             distance[cnt ++ ] = d2[a][k];
    //             distance[cnt ++ ] = d1[b][k];
    //             distance[cnt ++ ] = d2[b][k];
    //             a = f[a][k], b = f[b][k];
    //         }
    //     distance[cnt ++ ] = d1[a][0];
    //     distance[cnt ++ ] = d1[b][0];
    // }

    // int dist1 = -INF, dist2 = -INF;
    // for (int i = 0; i < cnt; i ++ )
    // {
    //     int d = distance[i];
    //     if (d > dist1) dist2 = dist1, dist1 = d;
    //     else if (d != dist1 && d > dist2) dist2 = d;
    // }

    // if (w > dist1) return w - dist1;
    // if (w > dist2) return w - dist2;
    // return INF;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        edges[i] = {x,y,z,false};
    }
    ll sum = kruscal();
    ll res_sum=1e12;
    bfs();
    for(int i=1;i<=m;i++){
        if(!edges[i].used){
            res_sum = min(res_sum,sum+lca(edges[i].x,edges[i].y,edges[i].w));
        }
    }
    cout << res_sum << "\n";
    return 0;
}
