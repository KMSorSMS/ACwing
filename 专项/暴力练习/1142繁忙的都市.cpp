/*
城市C是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。
城市C的道路是这样分布的：
城市中有 n 个交叉路口，编号是 1∼n，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。
这些道路是 双向 的，且把所有的交叉路口直接或间接的连接起来了。
每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。
但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
1．改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
2．在满足要求1的情况下，改造的道路尽量少。
3．在满足要求1、2的情况下，改造的那些道路中分值最大值尽量小。
作为市规划局的你，应当作出最佳的决策，选择哪些道路应当被修建。

输入格式
第一行有两个整数 n,m 表示城市有 n 个交叉路口，m 条道路。
接下来 m 行是对每条道路的描述，每行包含三个整数u,v,c 表示交叉路口 u 和 v 之间有道路相连，分值为 c。

输出格式
两个整数 s,max，表示你选出了几条道路，分值最大的那条道路的分值是多少。

数据范围
1≤n≤300,
1≤m≤8000,
1≤c≤10000

输入样例：
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8
输出样例：
3 6
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 310,M = 8010;
struct Edge{
    int x,y,w;
};
Edge edges[M];
int idx=0;
int class_set[N];
int n,m;

int find_class(int x){
    if(class_set[x] != x) class_set[x] = find_class(class_set[x]);
    return class_set[x];
}

int kruscal(){
    int add_num = 0,max_edge = 0;
    for(int i=1;i<=idx && add_num < n-1;i++){
        Edge edge = edges[i];
        int x = edge.x,y = edge.y,w = edge.w;
        int x_class = find_class(x),y_class = find_class(y);
        if(x_class == y_class) continue;
        add_num++;
        class_set[y_class] = x_class;
        max_edge = w;
    }
    return max_edge;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        edges[++idx] = {u,v,c};
    }
    for(int i=1;i<=n;i++) class_set[i] = i;
    sort(edges+1,edges+1+idx,[](Edge a,Edge b){return a.w < b.w;});
    int res = kruscal();
    cout << n-1 << " " << res << "\n";
    return 0;
}

