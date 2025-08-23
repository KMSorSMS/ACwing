/*
传说中的暗之连锁被人们称为 Dark。
Dark 是人类内心的黑暗的产物，古今中外的勇者们都试图打倒它。
经过研究，你发现 Dark 呈现无向图的结构，图中有 N 个节点和两类边，一类边被称为主要边，而另一类被称为附加边。
Dark 有 N–1 条主要边，并且 Dark 的任意两个节点之间都存在一条只由主要边构成的路径。
另外，Dark 还有 M 条附加边。
你的任务是把 Dark 斩为不连通的两部分。
一开始 Dark 的附加边都处于无敌状态，你只能选择一条主要边切断。
一旦你切断了一条主要边，Dark 就会进入防御模式，主要边会变为无敌的而附加边可以被切断。
但是你的能力只能再切断 Dark 的一条附加边。
现在你想要知道，一共有多少种方案可以击败 Dark。
注意，就算你第一步切断主要边之后就已经把 Dark 斩为两截，你也需要切断一条附加边才算击败了 Dark。

输入格式
第一行包含两个整数 N 和 M。
之后 N–1 行，每行包括两个整数 A 和 B，表示 A 和 B 之间有一条主要边。
之后 M 行以同样的格式给出附加边。

输出格式
输出一个整数表示答案。

数据范围
N≤100000,M≤200000，数据保证答案不超过2^31−1

输入样例：
4 1
1 2
2 3
1 4
3 4
输出样例：
3
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring> 
using namespace std;

const int N = 1e5+10,M=2e5+10,SZ=17;
int h[N],e[M],ne[M];
int idx=1,n,m,ans;
int depth[N],f[N][SZ],d[N];

void add_edge(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

void bfs(){
    queue<int> que;
    que.push(1);
    memset(depth,0x3f,sizeof(depth));
    depth[0] = 0,depth[1] = 1;
    while(que.size()){
        int node=que.front();
        que.pop();
        for(int edge=h[node];edge!=0;edge=ne[edge]){
            int node_next = e[edge];
            if(depth[node_next] > depth[node]+1){
                depth[node_next] = depth[node]+1;
                que.push(node_next);
                f[node_next][0] = node;
                for(int i=1;i<SZ;i++){
                    f[node_next][i] = f[f[node_next][i-1]][i-1];
                }
            }
        }
    }
}

int lca(int x,int y){
    if(depth[x] < depth[y]) swap(x,y);
    for(int i=SZ-1;i>=0;i--){
        if(depth[f[x][i]] >= depth[y]){
            x = f[x][i];
        }
    }
    if(x==y) return x;
    for(int i=SZ-1;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}

int dfs(int node,int fa){
    int res = 0;
    for(int edge=h[node];edge!=0;edge=ne[edge]){
        int node_next = e[edge];
        if(node_next==fa) continue;
        int w_ = dfs(node_next,node);
        if(w_ == 0){
            ans += m;
        }else if(w_ == 1){
            ans += 1;
        }
        res += w_;
    }
    res += d[node];
    return res;
}

int main(){
    cin >> n >>m;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin >> x >> y;
        add_edge(x,y),add_edge(y,x);
    }
    bfs();
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        int anc = lca(x,y);
        d[x]++,d[y]++;
        d[anc] -=2;
    }
    dfs(1,0);
    cout << ans << "\n";
    return 0;
}
