/*
FGD小朋友特别喜欢爬山，在爬山的时候他就在研究山峰和山谷。
为了能够对旅程有一个安排，他想知道山峰和山谷的数量。
给定一个地图，为FGD想要旅行的区域，地图被分为 n×n 的网格，每个格子 (i,j) 的高度 w(i,j) 是给定的。
若两个格子有公共顶点，那么它们就是相邻的格子，如与 (i,j) 相邻的格子有(i−1,j−1),(i−1,j),(i−1,j+1),(i,j−1),(i,j+1),(i+1,j−1),(i+1,j),(i+1,j+1)。
我们定义一个格子的集合 S 为山峰（山谷）当且仅当：
S 的所有格子都有相同的高度。S 的所有格子都连通。对于 s 属于 S，与 s 相邻的 s′ 不属于 S，都有 ws>ws′（山峰），或者 ws<ws′（山谷）。
如果周围不存在相邻区域，则同时将其视为山峰和山谷。
你的任务是，对于给定的地图，求出山峰和山谷的数量，如果所有格子都有相同的高度，那么整个地图即是山峰，又是山谷。

输入格式
第一行包含一个正整数 n，表示地图的大小。

接下来一个 n×n 的矩阵，表示地图上每个格子的高度 w。

输出格式
共一行，包含两个整数，表示山峰和山谷的数量。

数据范围
1≤n≤1000,
0≤w≤10^9

输入样例1：
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8
输出样例1：
2 1
输入样例2：
5
5 7 8 3 1
5 5 7 6 6
6 6 6 2 8
5 7 2 5 8
7 1 0 1 7
输出样例2：
3 3

*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=1010;
int graph[N][N];
bool st[N][N];
int dir_x[8] = {1,1,1,0,0,-1,-1,-1};
int dir_y[8] = {1,-1,0,1,-1,1,-1,0};
int n;

int bfs(int start_x, int start_y){
    queue<pair<int,int>> que;
    que.push({start_x,start_y});
    int val = graph[start_x][start_y],other_val = -1;

    while(que.size()){
        int x = que.front().first,y = que.front().second;
        que.pop();
        for(int i=0;i<8;i++){
            int next_x = x+dir_x[i],next_y = y+dir_y[i];
            if(next_x>=1 && next_x<=n && next_y>=1 && next_y<=n){
                if(graph[next_x][next_y] == val){
                    if(!st[next_x][next_y]){
                        que.push({next_x,next_y});
                        st[next_x][next_y] = true;
                    }
                }else{
                    if(val > graph[next_x][next_y]){
                        if(other_val == -1) other_val = 1;
                        else if(other_val != 1) other_val = -2;
                    }else{
                        if(other_val == -1) other_val = 2;
                        else if(other_val != 2) other_val = -2;
                        
                    }
                }
            }
        }
    }
    // 1 代表山峰，2 代表山谷，-1 代表既是又是，-2 代表都不是
    return other_val;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> graph[i][j];
        }
    }
    int count_up=0,count_down=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(st[i][j]) continue;
            int res = bfs(i,j);
            // printf("search:(%d,%d),res:%d\n",i,j,res);
            if(res == 1) count_up++;
            else if(res == 2) count_down++;
            else if(res == -1) count_up++,count_down++;
        }
    }
    cout << count_up << " " << count_down << "\n";
    return 0;
}