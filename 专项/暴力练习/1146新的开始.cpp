/*
发展采矿业当然首先得有矿井，小 FF 花了上次探险获得的千分之一的财富请人在岛上挖了 n 口矿井，但他似乎忘记了考虑矿井供电问题。
为了保证电力的供应，小 FF 想到了两种办法：
1. 在矿井 i 上建立一个发电站，费用为 vi（发电站的输出功率可以供给任意多个矿井）。
2. 将这口矿井 i 与另外的已经有电力供应的矿井 j 之间建立电网，费用为 p(i,j)。
小 FF 希望你帮他想出一个保证所有矿井电力供应的最小花费方案。

输入格式
第一行包含一个整数 n，表示矿井总数。
接下来 n 行，每行一个整数，第 i 个数 vi 表示在第 i 口矿井上建立发电站的费用。
接下来为一个 n×n 的矩阵 P，其中 p(i,j) 表示在第 i 口矿井和第 j 口矿井之间建立电网的费用。
数据保证 p(i,j)=p(j,i)，且 p(i,i)=0。

输出格式
输出一个整数，表示让所有矿井获得充足电能的最小花费。

数据范围
1≤n≤300,
0≤vi,pi,j≤10^5

输入样例：
4
5
4
4
3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0
输出样例：
9
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
struct Compare{
    bool operator () (const pii& a,const pii& b) const {
        if(a.first != b.first){
            return b.first < a.first;
        }else{
            return b.second < a.second;
        }
    }
};
const int N = 310;
const int M = 2*N*N;
int h[N],e[M],ne[M],w[M];
int dist[N];
bool st[N];
int idx=1,n;

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

int prim(){
    priority_queue<pii,vector<pii>,Compare> heap;
    for(int i=1;i<=n;i++){
        heap.push({dist[i],i});
    }
    int res = 0;
    while(heap.size()){
        int node = heap.top().second, len = heap.top().first;
        heap.pop();
        if(st[node]) continue;
        st[node] = true;
        res += len;
        for(int edge = h[node];edge!=0;edge=ne[edge]){
            int node_next = e[edge];
            if(!st[node_next] && dist[node_next] > w[edge]){
                dist[node_next] = w[edge];
                heap.push({dist[node_next],node_next});
            }
        }
    }
    return res;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> dist[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int weight;
            cin >> weight;
            add_edge(i,j,weight);
        }
    }
    int res = prim();
    cout << res << "\n";
    return 0;
}
/*
完成简单的 prim 的变形,这里有起始的 dist,是因为不一定需要边,我们可以自己假设一个 0 点来
求一个最小生成树问题,0 点到其他点的边都是最开始点的权值,其他的边就是各个点之间自己的边的值了
不过这个假设 0 点的操作实际上在 prim 里面可以优化一下,那就直接把最开始的 dist 设置为点的权值,因为第一次
的 prim 更新一定会更新它们,加入 heap
*/
