/*
农夫John发现了做出全威斯康辛州最甜的黄油的方法：糖。
把糖放在一片牧场上，他知道 N 只奶牛会过来舔它，这样就能做出能卖好价钱的超甜黄油。
当然，他将付出额外的费用在奶牛上。
农夫John很狡猾，就像以前的巴甫洛夫，他知道他可以训练这些奶牛，让它们在听到铃声时去一个特定的牧场。
他打算将糖放在那里然后下午发出铃声，以至他可以在晚上挤奶。
农夫John知道每只奶牛都在各自喜欢的牧场（一个牧场不一定只有一头牛）。
给出各头牛在的牧场和牧场间的路线，找出使所有牛到达的路程和最短的牧场（他将把糖放在那）。
数据保证至少存在一个牧场和所有牛所在的牧场连通。
输入格式
第一行: 三个数：奶牛数 N，牧场数 P，牧场间道路数 C。
第二行到第 N+1 行: 1 到 N 头奶牛所在的牧场号。
第 N+2 行到第 N+C+1 行：每行有三个数：相连的牧场A、B，两牧场间距 D，当然，连接是双向的。
输出格式
共一行，输出奶牛必须行走的最小的距离和。
数据范围
1≤N≤500,
2≤P≤800,
1≤C≤1450,
1≤D≤255

输入样例：
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5
输出样例：
8
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
const int N=510,M=3000,P=820;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> pii;
struct Compare{
    bool operator () (const pii &a, const pii &b) const {
        if (a.first != b.first){
            return b.first < a.first;
        }else{
            return b.second < a.second;
        }
    }
};
int h[P],e[M],ne[M],w[M];
int idx=1,n,p,c;
int cow[N];
int dist[P];
bool st[P];

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

int dij(int start){
    memset(dist,0x3f,sizeof(dist));
    memset(st,0,sizeof(st));
    priority_queue<pii,vector<pii>,Compare> heap; 
    dist[start] = 0;
    heap.push({0,start});
    while(heap.size()){
        int node = heap.top().second,len = heap.top().first;
        heap.pop();
        if(st[node]) continue;
        // dist[node] = len;
        st[node] = true;
        for(int edge = h[node];edge != 0;edge = ne[edge]){
            int node_next = e[edge];
            if(!st[node_next] && dist[node_next] > dist[node]+w[edge]){
                dist[node_next] = dist[node] + w[edge];
                heap.push({dist[node_next],node_next});
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(dist[cow[i]] == INF){
            return INF;
        }
        res+=dist[cow[i]];
    }
    return res;
}



int main(){
    cin >> n >> p >> c;
    for(int i=1;i<=n;i++){
        cin >> cow[i];
    }
    for(int i=1;i<=c;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    int min_ = INF;
    for(int i=1;i<=p;i++){
        min_ = min(min_,dij(i));
    }
    cout << min_ << "\n";
}
/*
这里 dij 的实现明显比 spfa 慢，这个是因为额外多加的node，在 spfa 里面，我们只需要更新最短路，
对于已经在 que 里面的元素，并不需要重复加入，但是 dij 里面，每次缩边，只要当前点并非已经是算出最短路，就会
把这部分缩边加入集合，因为集合 (heap) 需要维护一个最小的值，这就导致存在一个动态的更新，我们又不会去掉之前
加入的值，所以导致了额外的时间，但是这样的实现能保证一个相对固定的，稳定性好的结果
*/