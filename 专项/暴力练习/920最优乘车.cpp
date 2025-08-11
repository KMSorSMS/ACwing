/*
H 城是一个旅游胜地，每年都有成千上万的人前来观光。
为方便游客，巴士公司在各个旅游景点及宾馆，饭店等地都设置了巴士站并开通了一些单程巴士线路。
每条单程巴士线路从某个巴士站出发，依次途经若干个巴士站，最终到达终点巴士站。
一名旅客最近到 H 城旅游，他很想去 S 公园游玩，但如果从他所在的饭店没有一路巴士可以直接到达 S 公园，则他可能要先乘某一路巴士坐几站，再下来换乘同一站台的另一路巴士，这样换乘几次后到达 S 公园。

现在用整数 1,2,…N 给 H 城的所有的巴士站编号，约定这名旅客所在饭店的巴士站编号为 1，S 公园巴士站的编号为 N。

写一个程序，帮助这名旅客寻找一个最优乘车方案，使他在从饭店乘车到 S 公园的过程中换乘的次数最少。

输入格式
第一行有两个数字 M 和 N，表示开通了 M 条单程巴士线路，总共有 N 个车站。
从第二行到第 M+1 行依次给出了第 1 条到第 M 条巴士线路的信息，其中第 i+1 行给出的是第 i 条巴士线路的信息，从左至右按运行顺序依次给出了该线路上的所有站号，相邻两个站号之间用一个空格隔开。
输出格式
共一行，如果无法乘巴士从饭店到达 S 公园，则输出 NO，否则输出最少换乘次数，换乘次数为 0 表示不需换车即可到达。
数据范围
1≤M≤100,
2≤N≤500

输入样例：
3 7
6 7
4 7 3 6
2 1 3 5

4 50
9 42 47
48 3 7 14 17 20 42
1 48
6 7 11 12 13 14 15 17 22 23 33 34 37 40 41 47 50

输出样例：
2
*/

#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;
// typedef pair<int,int> pii;
const int N = 510,M = 110, INF = 0x3f3f3f3f;
int g[N][N],stop[N];
// const int MN = M*N*N;
// int h[N],e[MN],ne[MN],w[MN];
// int idx=1;
bool st[N];
int dist[N];
int n,m;

// int class_state[N];
// int class_bus[]

// int find_class(int x){
//     if(class_state[x] != x) class_state[x] = find_class(class_state[x]);
//     return class_state[x];
// }

// void add_edge(int a,int b,int c){
//     e[idx] = b,ne[idx] = h[a],w[idx] = c;
//     h[a] = idx++;
// }

int spfa(int start,int end){
    queue<int> que;
    que.push({start});
    dist[start] = 0;
    while(que.size()){
        int node = que.front();
        que.pop();
        st[node] = false;
        for(int i=1;i<=n;i++){
            if(g[node][i] == 1 && dist[i] > dist[node] + 1){
                dist[i] = dist[node] + 1;
                if(!st[i]){
                    st[i] = true;
                    que.push(i);
                }
            }
        }
    }
    return dist[end];
}

int main(){
    cin >> m >> n;
    memset(dist,0x3f,sizeof(dist));
    string s;
    getline(cin,s);//因为getline回车一次就读一次会造成第一次读入为空
    while(m--){
        string s;
        getline(cin,s);
        stringstream ssin(s);//可以自动分割字符串的字符串流(也是一个容器)，
        int cnt = 0,p;
        while (ssin >> p) stop[cnt ++] = p;//移出字符串流后会自动类型转换
        for (int i = 0;i < cnt - 1;i ++ ) 
            for (int j = i + 1;j < cnt;j ++ ) 
                g[stop[i]][stop[j]] = 1;
    }
    // printf("end input \n");
    int res = spfa(1,n);
    if(res == INF){
        cout << "NO\n";
    }else{
        cout << res-1 << "\n";
    }
}
