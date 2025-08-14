/*
农民 John 有很多牛，他想交易其中一头被 Don 称为 The Knight 的牛。
这头牛有一个独一无二的超能力，在农场里像 Knight 一样地跳（就是我们熟悉的象棋中马的走法）。
虽然这头神奇的牛不能跳到树上和石头上，但是它可以在牧场上随意跳，我们把牧场用一个 x，y 的坐标图来表示。
这头神奇的牛像其它牛一样喜欢吃草，给你一张地图，上面标注了 The Knight 的开始位置，树、灌木、石头以及其它障碍的位置，除此之外还有一捆草。
现在你的任务是，确定 The Knight 要想吃到草，至少需要跳多少次。
The Knight 的位置用 K 来标记，障碍的位置用 * 来标记，草的位置用 H 来标记。
这里有一个地图的例子：

             11 | . . . . . . . . . .
             10 | . . . . * . . . . . 
              9 | . . . . . . . . . . 
              8 | . . . * . * . . . . 
              7 | . . . . . . . * . . 
              6 | . . * . . * . . . H 
              5 | * . . . . . . . . . 
              4 | . . . * . . . * . . 
              3 | . K . . . . . . . . 
              2 | . . . * . . . . . * 
              1 | . . * . . . . * . . 
              0 ----------------------
                                    1 
                0 1 2 3 4 5 6 7 8 9 0 
The Knight 可以按照下图中的 A,B,C,D… 这条路径用 5 次跳到草的地方（有可能其它路线的长度也是 5）：

             11 | . . . . . . . . . .
             10 | . . . . * . . . . .
              9 | . . . . . . . . . .
              8 | . . . * . * . . . .
              7 | . . . . . . . * . .
              6 | . . * . . * . . . F<
              5 | * . B . . . . . . .
              4 | . . . * C . . * E .
              3 | .>A . . . . D . . .
              2 | . . . * . . . . . *
              1 | . . * . . . . * . .
              0 ----------------------
                                    1
                0 1 2 3 4 5 6 7 8 9 0
注意： 数据保证一定有解。
输入格式
第 1 行： 两个数，表示农场的列数 C 和行数 R。
第 2..R+1 行: 每行一个由 C 个字符组成的字符串，共同描绘出牧场地图。
输出格式
一个整数，表示跳跃的最小次数。
数据范围
1≤R,C≤150
输入样例：
10 11
..........
....*.....
..........
...*.*....
.......*..
..*..*...H
*.........
...*...*..
.K........
...*.....*
..*....*..
输出样例：
5
*/

#include <iostream>
#include <queue>
using namespace std;
const int C = 160,R = 160;
char graph[R][C];
int c,r;
int dir[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
struct Item{
    int x,y,dep;
};
bool st[R][C];

int bfs(int start_x,int start_y,int end_x,int end_y){
    queue<Item> que;
    que.push({start_x,start_y,0});
    while(que.size()){
        Item item = que.front();
        int x = item.x,y = item.y,dep = item.dep;
        que.pop();
        if(x==end_x && y==end_y) return dep;
        for(int i=0;i<8;i++){
            int x_next = x+dir[i][0], y_next = y+dir[i][1];
            if(x_next <= r && x_next >=1 && y_next <= c && y_next >=1 && !st[x_next][y_next] && graph[x_next][y_next] != '*'){
                st[x_next][y_next] = true;
                que.push({x_next,y_next,dep+1});
            }
        }
    }
    return -1;
}

int main(){
    cin >> c >> r;
    int start_x,start_y,end_x,end_y;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'K'){
                start_x = i,start_y = j;
            }else if(graph[i][j] == 'H'){
                end_x = i,end_y = j;
            }
        }
    }
    int res = bfs(start_x,start_y,end_x,end_y);
    cout << res << "\n";
    return 0;   
}
