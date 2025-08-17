/*
农夫约翰有一片 N∗M 的矩形土地。
最近，由于降雨的原因，部分土地被水淹没了。
现在用一个字符矩阵来表示他的土地。
每个单元格内，如果包含雨水，则用”W”表示，如果不含雨水，则用”.”表示。
现在，约翰想知道他的土地中形成了多少片池塘。
每组相连的积水单元格集合可以看作是一片池塘。
每个单元格视为与其上、下、左、右、左上、右上、左下、右下八个邻近单元格相连。
请你输出共有多少片池塘，即矩阵中共有多少片相连的”W”块。

输入格式
第一行包含两个整数 N 和 M。
接下来 N 行，每行包含 M 个字符，字符为”W”或”.”，用以表示矩形土地的积水状况，字符之间没有空格。
输出格式
输出一个整数，表示池塘数目。

数据范围
1≤N,M≤1000

输入样例：
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
输出样例：
3
*/
#include <iostream>
#include <queue>
using namespace std;
const int N=1010,M=1010;
char graph[N][M];
int m,n;
bool st[N][M];

int dir_x[8] = { 1, 1, 1,-1,-1,-1, 0, 0};
int dir_y[8] = { 1,-1, 0, 1,-1, 0, 1,-1};


void bfs(int start_x,int start_y){
    queue<pair<int,int>> que;
    que.push({start_x,start_y});
    st[start_x][start_y] = true;
    while(que.size()){
        int x = que.front().first, y = que.front().second;
        que.pop();
        for(int i=0;i<8;i++){
            int next_x = x+dir_x[i],next_y = y+dir_y[i];
            if(next_x >=1 && next_x <= n && next_y >= 1 && next_y <= m && !st[next_x][next_y] && graph[next_x][next_y] == 'W'){
                que.push({next_x,next_y});
                st[next_x][next_y] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> graph[i][j];
        }
    }
    int res= 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(graph[i][j] == 'W' && !st[i][j]){
                bfs(i,j);
                res++;
            }
        }
    }
    cout << res << "\n";
}
