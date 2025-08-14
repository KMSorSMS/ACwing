/*
给定一个 n×n 的二维数组，如下所示：
int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 0, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。

数据保证至少存在一条从左上角走到右下角的路径。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含 n 个整数 0 或 1，表示迷宫。

输出格式
输出从左上角到右下角的最短路线，如果答案不唯一，输出任意一条路径均可。
按顺序，每行输出一个路径中经过的单元格的坐标，左上角坐标为 (0,0)，右下角坐标为 (n−1,n−1)。
数据范围
0≤n≤1000
输入样例：
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
0 0
1 0
2 0
2 1
2 2
2 3
2 4
3 4
4 4
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;
int graph[N][N];
int n;
bool st[N][N];
pii past[N][N];

struct Item{
    int x,y,depth;
};

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(int start_x,int start_y,int end_x,int end_y){
    queue<Item> que;
    que.push({start_x,start_y,0});
    while(que.size()){
        Item item = que.front();
        que.pop();
        int x = item.x,y = item.y,depth = item.depth;
        if(st[x][y]) continue;
        st[x][y] = true;
        if(x == end_x && y == end_y) return depth;
        for(int i=0;i<4;i++){
            int x_next = x+dir[i][0],y_next = y+dir[i][1];
            if(x_next >= 1 && x_next <= n && y_next >= 1 && y_next <= n && !st[x_next][y_next] && graph[x_next][y_next] == 0){
                que.push({x_next,y_next,depth+1});
                past[x_next][y_next] = {x,y};
            }
        }
    }
    return -1;
}

void print_route(int x,int y){
    if(past[x][y].first != 0 && past[x][y].second!=0){
        print_route(past[x][y].first,past[x][y].second);
    }
    cout << x-1 << ' ' << y-1 << "\n";
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> graph[i][j];
        }
    }
    int res = bfs(1,1,n,n);
    print_route(n,n);
    // cout << res << "\n";
    return 0;
}

