/*
一个 m 行 n 列的点阵，相邻两点可以相连。
一条纵向的连线花费一个单位，一条横向的连线花费两个单位。
某些点之间已经有连线了，试问至少还需要花费多少个单位才能使所有的点全部连通。
输入格式
第一行输入两个正整数 m 和 n。

以下若干行每行四个正整数 x1,y1,x2,y2，表示第 x1 行第 y1 列的点和第 x2 行第 y2 列的点已经有连线。
输入保证|x1−x2|+|y1−y2|=1。

输出格式
输出使得连通所有点还需要的最小花费。

数据范围
1≤m,n≤1000

0≤已经存在的连线数≤10000

输入样例：
2 2
1 1 2 1
输出样例：
3
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1010, N = 1010;
const int EDGE=2*M*N, MN = M*N;
struct Edge{
    int x,y,w;
};
Edge edges[EDGE];
int class_set[MN];
int idx_e=0,connect_edge=0;
int m,n;

int find_class(int x){
    if(class_set[x] != x) class_set[x] = find_class(class_set[x]);
    return class_set[x];
}

// int h[MN],e[M],ne[M],w[M];
// int idx=1;
// void add_edge(int a,int b,int c){
//     e[idx] = b,ne[idx] = h[a],w[idx] = c;
//     h[a] = idx++;
// }

int kruscal(){
    int res = 0;
    for(int i=1;i<=idx_e && connect_edge < n*m-1;i++){
        Edge edge = edges[i];
        int x = edge.x,y = edge.y, w = edge.w;
        int x_class = find_class(x),y_class = find_class(y);
        if(x_class == y_class) continue;
        class_set[x_class] = y_class;
        res += w;
        connect_edge++;
    }
    return res;
}

int main(){
    cin >> m >> n;
    // 建图
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         int node = (i-1)*n+j;
    //         if(i-1>=1){
    //             edges[++idx_e] = {node,(i-2)*n+j,1};
    //             // add_edge(node,(i-2)*n+j,1);
    //         }
    //         if(i+1 <= m){
    //             edges[++idx_e] = {node,i*n+j,1};
    //             // add_edge(node,i*n+j,1);
    //         }
    //         if(j-1>=1){
    //             edges[++idx_e] = {node,(i-1)*n+j-1,2};
    //             // add_edge(node,(i-1)*n+j-1,2);
    //         }
    //         if(j+1<=n){
    //             edges[++idx_e] = {node,(i-1)*n+j+1,2};
    //             // add_edge(node,(i-1)*n+j+1,2);
    //         }
    //     }
    // }
    // 先看横向的边
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n-1;j++){
            edges[++idx_e] = {(i-1)*n+j,(i-1)*n+j+1,2};
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m-1;i++){
            edges[++idx_e] = {(i-1)*n+j,(i)*n+j,1};
        }
    }
    for(int i=1;i<=m*n;i++) class_set[i] = i;
    sort(edges+1,edges+1+idx_e,[](Edge a,Edge b){return a.w < b.w;});
    // printf("fin graph build\n");
    int x1,y1,x2,y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        int node1 = (x1-1)*n+y1,node2 = (x2-1)*n+y2;
        int node1_class = find_class(node1),node2_class = find_class(node2);
        if(node1_class != node2_class) connect_edge++;
        class_set[node2_class] = node1_class;
        // printf("read:(%d,%d),(%d,%d)\n",x1,y1,x2,y2);
    }
    // printf("fin read line\n");
    int res = kruscal();
    cout << res << "\n";
    return 0;
}
