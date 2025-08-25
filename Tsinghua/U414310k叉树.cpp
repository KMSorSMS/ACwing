/*
5 2
0 1
0 2
0 3
1 4
1 5
*/

#include <iostream>
using namespace std;
const int N=1e5+10,M = 2e5+10,INF = 0x3f3f3f3f;
int h[N],e[M],ne[M];
int count_node;
int idx=1,m,k,count_over, node_low = INF;
int count_edge[N];
bool st[N];

void add_edge(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int node,int fa){
    st[node] = true;
    for(int edge=h[node];edge!=0;edge=ne[edge]){
        int node_next = e[edge];
        if(node_next==fa || st[node_next]) continue;
        count_edge[node]++;
        count_node++;
        dfs(node_next,node);
    }
    if(fa != -1 && count_edge[node] > k) count_over++;
    if(count_edge[node] < k ) node_low = node < node_low ? node : node_low;
}

int main(){
    cin >> m >> k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        add_edge(a,b),add_edge(b,a);
    }
    dfs(0,-1);
    if(count_node != m) cout << "It's not a tree!\n";
    else if(count_over != 0 || count_edge[0] > k+1) cout << "No such a node!";
    else {
        cout << node_low << "\n";
    }
    return 0;
}
