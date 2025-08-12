/*
农夫约翰被选为他们镇的镇长！
他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。
约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。
约翰的农场的编号是1，其他农场的编号是 2∼n。
为了使花费最少，他希望用于连接所有的农场的光纤总长度尽可能短。
你将得到一份各农场之间连接距离的列表，你必须找出能连接所有农场并使所用光纤最短的方案。

输入格式
第一行包含一个整数 n，表示农场个数。

接下来 n 行，每行包含 n 个整数，输入一个对角线上全是0的对称矩阵。
其中第 x+1 行 y 列的整数表示连接农场 x 和农场 y 所需要的光纤长度。
输出格式
输出一个整数，表示所需的最小光纤长度。
数据范围
3≤n≤100
每两个农场间的距离均是非负整数且不超过100000。

输入样例：
4
0  4  9  21
4  0  8  17
9  8  0  16
21 17 16  0
输出样例：
28
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
struct Compare{
    bool operator () (const pii& a,const pii& b) const{
        if(a.first != b.first){
            return b.first < a.first;
        }else{
            return b.second < a.second;
        }
    }
};
const int N = 110, INF=0x3f3f3f3f;
int graph[N][N],dist[N];
bool st[N];
int n;

int prim(){
    priority_queue<pii,vector<pii>,Compare> heap;
    heap.push({0,1});
    dist[1] = 0;
    int res = 0;
    while(heap.size()){
        int node = heap.top().second,len = heap.top().first;
        heap.pop();
        if(st[node]) continue;
        st[node] = true;
        // printf("added node:%d,dis:%d\n",node,len);
        res += len;
        for(int i=1;i<=n;i++){
            if(!st[i] && graph[node][i] != INF && dist[i] > graph[node][i]){
                // printf("add node_i:%d,node:%d\n",i,node);
                dist[i] = graph[node][i];
                heap.push({dist[i],i});
            }
        }
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> graph[i][j];
        }
    }
    int res = prim();
    cout << res << "\n";
}
