/*
在 n 个人中，某些人的银行账号之间可以互相转账。
这些人之间转账的手续费各不相同。
给定这些人之间转账时需要从转账金额里扣除百分之几的手续费，请问 A 最少需要多少钱使得转账后 B 收到 100 元。

输入格式
第一行输入两个正整数 n,m，分别表示总人数和可以互相转账的人的对数。

以下 m 行每行输入三个正整数 x,y,z，表示标号为 x 的人和标号为 y 的人之间互相转账需要扣除 z% 的手续费 ( z<100 )。
最后一行输入两个正整数 A,B。

数据保证 A 与 B 之间可以直接或间接地转账。

输出格式
输出 A 使得 B 到账 100 元最少需要的总费用。
精确到小数点后 8 位。

数据范围
1≤n≤2000,m≤10^5

输入样例：
3 3
1 2 1
2 3 2
1 3 3
1 3
输出样例：
103.07153164
*/

#include <cstdio>
#include <queue>
using namespace std;
int const N = 2010,M = 2e5+10;
int h[N],e[M],ne[M],w[M];
int idx=1;
int n,m,start_,end_;
double dist[N];
bool st[N];

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

double spfa(int start,int end){
    queue<int> que;
    que.push(start);
    dist[start] = 1.0;
    while(que.size()){
        int node = que.front();
        que.pop();
        st[node] = false;
        for(int edge = h[node];edge != 0;edge = ne[edge]){
            int node_next = e[edge];
            if(dist[node_next] < dist[node] * (100-w[edge])/100){
                dist[node_next] = dist[node] * (100-w[edge])/100;
                if(!st[node_next]){
                    st[node_next] = true;
                    que.push(node_next);
                }
            }
        }
    }
    return dist[end];
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add_edge(a,b,c);
        add_edge(b,a,c);
    }
    scanf("%d %d",&start_,&end_);
    double tax = spfa(start_,end_);
    printf("%.8f\n",100/tax);
    return 0;
}

