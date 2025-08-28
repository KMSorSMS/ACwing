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
#include <set>
#include <bitset>
#include <cstdio>
using namespace std;
const int N = 30010,M = 30010;
set<int> sons[N];
bitset<N> visit_set[N];
bitset<N> last;
int n,m,count_fin = 0;
bool st[N];

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        sons[x].insert(y);
    }
    for(int node=1;node<=n;node++) visit_set[node].set(node);
    // for(int node=1;node<=n;node++){
    //     cout << visit_set[node][0] << "\n";
    // }
    for(int step=1;step<=m;step++){
        for(int node=1;node<=n;node++){
            if(st[node]) continue;
            last = visit_set[node];
            for(int son:sons[node]){
                visit_set[node] |= visit_set[son];
            }
            // printf("out fin node:%d,step:%d\n",node,step);
            // cout << visit_set[node][step] << "\n";
            // cout << visit_set[node][step-1] << "\n";
            if(visit_set[node] == last){
                // printf("fin node:%d,step:%d\n",node,step);
                // cout << visit_set[node][step] << "\n";
                count_fin++;
                st[node] = true;
            }
            if(count_fin==n) break;
        }
    }
    for(int node=1;node<=n;node++){
        cout << visit_set[node].count() << "\n";
    }
    return 0;
}
