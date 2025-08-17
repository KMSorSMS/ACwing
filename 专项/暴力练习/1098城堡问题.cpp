/*
    1   2   3   4   5   6   7  
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           (图 1)

   #  = Wall   
   |  = No wall
   -  = No wall

   方向：上北下南左西右东。
图1是一个城堡的地形图。
请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。
城堡被分割成 m∗n
个方格区域，每个方格区域可以有0~4面墙。
注意：墙体厚度忽略不计。

输入格式
第一行包含两个整数 m 和 n，分别表示城堡南北方向的长度和东西方向的长度。
接下来 m 行，每行包含 n 个整数，每个整数都表示平面图对应位置的方块的墙的特征。
每个方块中墙的特征由数字 P 来描述，我们用1表示西墙，2表示北墙，4表示东墙，8表示南墙，P 为该方块包含墙的数字之和。
例如，如果一个方块的 P 为3，则 3 = 1 + 2，该方块包含西墙和北墙。
城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。

输入的数据保证城堡至少有两个房间。

输出格式
共两行，第一行输出房间总数，第二行输出最大房间的面积（方块数）。

数据范围
1≤m,n≤50,
0≤P≤15

输入样例：
4 7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13 
输出样例：
5
9
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int M = 52,N=52;
struct Node{
    int x,y,dep;
};
int graph[M][N];
bool st[M][N];
// 北，南，西，东
int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,-1,1};
int check[4] = {2,8,1,4};
int m,n;

int bfs(int start_x,int start_y){
    queue<Node> que;
    que.push({start_x,start_y,0});
    st[start_x][start_y] = true;
    int count = 0;
    while(que.size()){
        Node node = que.front();
        int x = node.x,y = node.y,dep = node.dep;
        que.pop();
        count++;
        for(int i=0;i<4;i++){
            int next_x = x+dir_x[i],next_y = y+dir_y[i];
            if(next_x >= 1 && next_x <= m && next_y >= 1 && next_y <= n && !st[next_x][next_y] && ((graph[x][y] & check[i]) == 0)){
                st[next_x][next_y] = true;
                que.push({next_x,next_y,dep+1});
            }
        }
    }
    return count;
}

int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> graph[i][j];
        }
    }
    int count=0,max_=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(st[i][j]) continue;
            int res = bfs(i,j);
            // printf("res:%d from: (%d,%d)\n",res,i,j);
            max_ = max(res,max_);
            count++;
        }
    }
    cout << count << "\n" << max_ << "\n";
    return 0;
}
