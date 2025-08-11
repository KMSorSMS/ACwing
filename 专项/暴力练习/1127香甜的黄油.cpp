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
#include <algorithm>
using namespace std;
const int N=510,M=3000,P=820;

int h[P],e[M],ne[M],w[M];
int idx=1;
int n,c,p;
int cow[N];
int dist[P][P];

void add_edge(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

// void floyd(){
//     for(int k=1;k<=p;k++){
//         for(int i=1;i<=p;i++){
//             for(int edge = h[k];edge!=0;edge = ne[edge]){
//                 int next_node = e[edge];
//                 if(dist[i][next_node] > dist[i][k] + w[edge]){
//                     dist[i][next_node] = dist[i][k] + w[edge];
//                 }
//             }
//         }
//     }
// }

void floyd(){
    for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    cin >> n >> p >> c;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=p;i++){
        dist[i][i] = 0;
    }
    for(int i=1;i<=n;i++){
        cin >> cow[i];
    }
    for(int i=1;i<=c;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
        add_edge(b,a,c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    floyd();
    int min_ = 0x3f3f3f3f;
    for(int i=1;i<=p;i++){
        int res = 0;
        for(int j=1;j<=n;j++){
            int cow_p = cow[j];
            res += dist[i][cow_p];
        }
        min_ = min(res,min_);
    }
    cout << min_ << "\n";
    return 0;
}
