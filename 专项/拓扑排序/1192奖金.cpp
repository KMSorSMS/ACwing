/*
由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali Company总经理Mr.Z心情好，决定给每位员工发奖金。
公司决定 以每个人本年在公司的贡献为标准来计算他们得到奖金的多少。
于是Mr.Z下令召开 m 方会谈。
每位参加会谈的代表提出了自己的意见：“我认为员工 a 的奖金应该比 b 高！”
Mr.Z 决定要找出一种奖金方案， 满足各位代表的意见， 且同时使得总奖金数最少。
每位员工奖金最少为 100元 ，且必须是整数。

输入格式
第一行包含整数 n,m，分别表示公司内员工数以及参会代表数。
接下来 m 行，每行 2 个整数 a,b，表示某个代表认为第 a 号员工奖金应该比第 b 号员工高。
输出格式
若无法找到合理方案，则输出“Poor Xed”；
否则输出一个数表示最少总奖金。
数据范围
1≤n≤10000,
1≤m≤20000,
1≤a,b≤n
输入样例：
2 1
1 2
输出样例：
201
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10010,M = 20010;
struct Node{
    int node,sal;
};
int n,m;
int h[N],e[M],ne[M];
int idx=1;
int node_count[N];
Node node_single[N];
int idx_s,res;

void add_edge(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        add_edge(b,a);
        node_count[a]++;
    }
    for(int i=1;i<=n;i++){
        if(node_count[i]==0){
            node_single[idx_s++] = {i,100};
        }
    }
    for(int i=0;i<idx_s;i++){
        Node node_ = node_single[i];
        int node =  node_.node;
        // printf("node:%d,sal:%d\n",node,node_.sal);
        res += node_.sal;
        for(int edge=h[node];edge!=0;edge=ne[edge]){
            int node_next = e[edge];
            if(--node_count[node_next]==0) {
                node_single[idx_s++] = {node_next,node_.sal+1};
            }
        }
    }
    if(idx_s < n) cout << "Poor Xed\n";
    else cout << res << "\n";

}
// 完成拓扑排序的奖金问题,这里对于每一层 salary 的更新有点类似 bfs