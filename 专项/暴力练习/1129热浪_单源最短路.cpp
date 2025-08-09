/*
德克萨斯纯朴的民众们这个夏天正在遭受巨大的热浪！！！
他们的德克萨斯长角牛吃起来不错，可是它们并不是很擅长生产富含奶油的乳制品。
农夫John此时身先士卒地承担起向德克萨斯运送大量的营养冰凉的牛奶的重任，以减轻德克萨斯人忍受酷暑的痛苦。
John已经研究过可以把牛奶从威斯康星运送到德克萨斯州的路线。

这些路线包括起始点和终点一共有 T 个城镇，为了方便标号为 1 到 T。

除了起点和终点外的每个城镇都由 双向道路 连向至少两个其它的城镇。
每条道路有一个通过费用（包括油费，过路费等等）。
给定一个地图，包含 C 条直接连接 2 个城镇的道路。
每条道路由道路的起点 Rs，终点 Re 和花费 Ci 组成。
求从起始的城镇 Ts 到终点的城镇 Te 最小的总费用。

输入格式
第一行: 4 个由空格隔开的整数: T,C,Ts,Te;

第 2 到第 C+1 行: 第 i+1 行描述第 i 条道路，包含 3 个由空格隔开的整数: Rs,Re,Ci。

输出格式
一个单独的整数表示从 Ts 到 Te 的最小总费用。

数据保证至少存在一条道路。

数据范围
1≤T≤2500,
1≤C≤6200,
1≤Ts,Te,Rs,Re≤T,1≤Ci≤1000

输入样例：
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
输出样例：
7
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

const int T = 2600,M=6300*2;

int h[T],e[M],ne[M],w[M];
int idx=1,t,m,start_node,end_node;
bool st[T];
int dist[T];

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

int dij(){
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    dist[start_node] = 0;
    heap.push({0,start_node});
    while(heap.size()){
        int dist_now = heap.top().first,node = heap.top().second;
        heap.pop();
        if(st[node]) continue;
        st[node] = true;
        dist[node] = dist_now;
        if(node==end_node) return dist_now;
        for(int edge = h[node];edge!=0;edge = ne[edge]){
            int node_next = e[edge];
            // printf("node_next:%d\n",node_next);
            if(!st[node_next] && dist[node_next] > dist_now+w[edge]){
                dist[node_next] = dist_now+w[edge];
                heap.push({dist[node_next],node_next});
            }
        }
    }
    // printf("return from end\n");
    return dist[end_node];
}

int main(){
    cin >> t >> m >> start_node >> end_node;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    int res = dij();
    cout << res << "\n";
}

