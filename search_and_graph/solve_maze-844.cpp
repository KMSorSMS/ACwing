/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中
0表示可以走的路，1表示不可通过的墙壁。 最初，有一个人位于左上角
(1,1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角 (n,m)处，至少需要移动多少次。
数据保证 (1,1) 处和 (n,m)处的数字为 0，且一定至少存在一条通路。
输入格式
第一行包含两个整数 n和 m。
接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。
输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。
数据范围
1≤n,m≤100
输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
8
*/
#include <iostream>
#include <utility>
#define N 110
#define M 110
// pair for position x,y
typedef std::pair<int, int> PII;

char maze[N][M];
// the dir is: right, left, down, up
int head, tail, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, result, m, n;
PII queue[N * M];
bool added[N][M];

void bfs(PII start, PII end) {
  queue[head] = start, tail = 1;
  int old_tail = tail;
  while (head != tail) {
    while (head != old_tail) {
      start = queue[head++];
      if (start.first == end.first && start.second == end.second) {
        return;
      }
      // dequeue this point and enqueue all his neighbors
      // search for 4 direction
      int tmp_x, tmp_y;
      for (int i = 0; i < 4; i++) {
        tmp_x = start.first + dir[i][0],      // the x
            tmp_y = start.second + dir[i][1]; // the y
        if (maze[tmp_x][tmp_y] == '0' && tmp_x >= 0 && tmp_x < n &&
            tmp_y >= 0 && tmp_y < m &&
            !added[tmp_x][tmp_y]) { // make sure in maze;
          added[tmp_x][tmp_y] = true, queue[tail++] = {tmp_x, tmp_y};
        }
      }
    }
    old_tail = tail, result++;
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> maze[i][j];
    }
  }
  bfs({0, 0}, {n - 1, m - 1});
  std::cout << result << std::endl;
}