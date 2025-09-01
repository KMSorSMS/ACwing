/*
一条单向的铁路线上，依次有编号为 1,2,…,n 的 n 个火车站。
每个火车站都有一个级别，最低为 1 级。
现有若干趟车次在这条线路上行驶，每一趟都满足如下要求：如果这趟车次停靠了火车站 x，
则始发站、终点站之间所有级别大于等于火车站 x 的都必须停靠。（注意：起始站和终点站自然也算作事先已知需要停靠的站点） 

现有 m 趟车次的运行情况（全部满足要求），试推算这 n 个火车站至少分为几个不同的级别。

输入格式
第一行包含 2 个正整数 n,m，用一个空格隔开。

第 i+1 行（1≤i≤m）中，首先是一个正整数 si （2≤si≤n），表示第 i 趟车次有 s_i个停靠站；接下来有 s_i
个正整数，表示所有停靠站的编号，从小到大排列。
每两个数之间用一个空格隔开。输入保证所有的车次都满足要求。

输出格式
输出只有一行，包含一个正整数，即 n 个火车站最少划分的级别数。

数据范围
1≤n,m≤1000

输入样例：
9 3 
4 1 3 5 6 
3 3 5 6 
3 1 5 9 
输出样例：
3
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int N=1010;
struct Node{
    int node,grade;
};
int idx=1,n,m;
// int h[N],e[M],ne[M];
bool graph[N][N];
int s[N],node_count[N];
Node node_single[N];
int idx_s;
bool st[N];

// void add_edge(int a,int b){
//     e[idx] = b,ne[idx] = h[a];
//     h[a] = idx++;
// }

int topo(){
    int res;
    for(int i=0;i<idx_s;i++){
        int node = node_single[i].node,grade = node_single[i].grade;
        res = grade;
        // for(int edge=h[node];edge!=0;edge=ne[edge]){
        //     int node_next = e[edge];
        //     if(--node_count[node_next]==0) node_single[idx_s++] = {node_next,grade+1};
        //     // printf("node:%d,node_next:%d,node_next_count:%d\n",node,node_next,node_count[node_next]);
        // }
        for(int i=1;i<=n;i++){
            if(!graph[node][i]) continue;
            int node_next = i;
            // printf("node:%d,node_next:%d,node_next_count:%d\n",node,node_next,node_count[node_next]);
            if(--node_count[node_next]==0) node_single[idx_s++] = {node_next,grade+1};
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int si;
        cin >> si;
        for(int j=1;j<=si;j++){
            cin >> s[j];
            st[s[j]] = true;
        }
        for(int k=s[1];k<=s[si];k++){
            if(!st[k]){
                for(int j=1;j<=si;j++){
                    // add_edge(s[j],k);
                    if(!graph[s[j]][k]){
                        graph[s[j]][k] = true;
                        node_count[k]++;
                    }
                }
            }
        }
        for(int j=1;j<=si;j++){
            st[s[j]] = false;
        }
    }
    for(int i=1;i<=n;i++){
        if(node_count[i]==0) node_single[idx_s++] = {i,1};
    }
    // printf("idx_s:%d,node_single[0]:%d\n",idx_s,node_single[0].node);
    int res = topo();
    if(idx_s < n) cout << "Wrong\n";
    else cout << res << "\n";
    return 0;
}

