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
#include <vector>
#include <cstdio>
#include <bitset>
using namespace std;
const int N = 30050,M = 30010;
vector<int> sons[N];
int node_single[N],node_count[N];
int idx_s,n,m;
bitset<N> visit_set[N];

void topo(){
    for(int node=1;node<=n;node++){
        if(node_count[node]==0) node_single[idx_s++] = node;
    }
    for(int i=0;i<idx_s;i++){
        for(const int &son:sons[node_single[i]]){
            if(--node_count[son]==0) node_single[idx_s++] = son;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        sons[x].push_back(y);
        node_count[y]++;
    }
    topo();
    if(idx_s<n) cout << "Error No Solution\n";
    for(int i=n-1;i>=0;i--){
        int node = node_single[i];
        visit_set[node][node] = 1;
        for(const int &son:sons[node]){
            visit_set[node] |= visit_set[son];
        }
    }
    for(int i=1;i<=n;i++){
        cout << visit_set[i].count() << "\n";
    }
    return 0;
}
/*
通过逆序遍历拓扑排序之后的结果进行可达点列的更新
*/
