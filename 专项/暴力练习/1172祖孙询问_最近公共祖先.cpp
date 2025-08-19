/*
给定一棵包含 n 个节点的有根无向树，节点编号互不相同，但不一定是 1∼n。
有 m 个询问，每个询问给出了一对节点的编号 x 和 y，询问 x 与 y 的祖孙关系。

输入格式
输入第一行包括一个整数 表示节点个数；
接下来 n 行每行一对整数 a 和 b，表示 a 和 b 之间有一条无向边。如果 b 是 −1，那么 a 就是树的根；
第 n+2 行是一个整数 m 表示询问个数；
接下来 m 行，每行两个不同的正整数 x 和 y，表示一个询问。

输出格式
对于每一个询问，若 x 是 y 的祖先则输出 1，若 y 是 x 的祖先则输出 2，否则输出 0。

数据范围
1≤n,m≤4×10^4,
1≤每个节点的编号≤4×10^4

输入样例：
10
234 -1
12 234
13 234
14 234
15 234
16 234
17 234
18 234
19 234
233 19
5
234 233
233 12
233 13
233 15
233 19
输出样例：
1
0
0
0
2
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40010;
const int M = 2 * N;

int h[N],e[M],ne[M];
int idx=1,n;
int depth[N],f[N][16];

void add_edge(int a,int b){
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx++;
}

void bfs(int root){
    queue<int> que;
    memset(depth,0x3f,sizeof(depth));
    que.push(root);
    depth[0] = 0,depth[root] = 1;
    while(que.size()){
        int node = que.front();
        que.pop();
        for(int edge = h[node];edge!=0;edge=ne[edge]){
            int next_node = e[edge];
            if(depth[next_node] > depth[node] + 1){
                depth[next_node] = depth[node] + 1;
                f[next_node][0] = node;
                for(int i=1;i<16;i++){
                    f[next_node][i] = f[f[next_node][i-1]][i-1];
                }
                que.push(next_node);
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a,b);
    for(int i=15;i>=0;i--){
        if(depth[f[a][i]] >= depth[b]){
            a = f[a][i];
        }
    }
    if(a==b) return a;
    for(int i=15;i>=0;i--){
        if(f[a][i] != f[b][i]){
            a = f[a][i],b = f[b][i];
        }
    }
    return f[a][0];
}

int main(){
    cin >> n;
    int root = 0;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        if(b == -1) root = a;
        else{
            add_edge(a,b);
            add_edge(b,a);
        }
    }
    bfs(root);
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        int res = lca(x,y);
        // printf("Debug:res:%d\n",res);
        if(res == x) cout << "1\n";
        else if(res == y) cout << "2\n";
        else cout << "0\n";
    }
    return 0;
}
