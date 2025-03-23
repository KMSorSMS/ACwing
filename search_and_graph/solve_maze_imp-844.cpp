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

// #include <cstdio>
#include <iostream>
#include <ostream>
#include <queue>
#include <utility>

#define N 110
#define M 110
char maze[N][M];
int m, n;
typedef std::pair<int, int> PII;
PII start = {1, 1}, end;
int d[N][M];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs()
{
	std::queue<PII> que;
	que.push(start);
	PII tmp, old_tmp;
	int old_d;
	while(!que.empty())
	{
		old_tmp = tmp = que.front();
		que.pop();
		old_d = d[old_tmp.first][old_tmp.second];
		if(tmp.first == end.first && tmp.second == end.second) { return old_d; }
		for(int i = 0; i < 4; i++)
		{
			tmp.first += dir[i][0], tmp.second += dir[i][1];
			if(maze[tmp.first][tmp.second] == '0' && tmp.first >= 1 && tmp.first <= n &&
			   tmp.second >= 1 && tmp.second <= m)
			{
				maze[tmp.first][tmp.second] = '1';
				d[tmp.first][tmp.second] = old_d + 1;
				que.push(tmp);
				// printf("in finding:{%d,%d}---{%d,%d}\n", old_tmp.first, old_tmp.second,
				//        tmp.first, tmp.second);
			}
			tmp = old_tmp;
		}
	}
	return -1;
}

int main()
{
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) { std::cin >> maze[i][j]; }
	}
	//   std::cout << "\n";
	//   for (int i = 1; i <= n; i++) {
	//     for (int j = 1; j <= m; j++) {
	//       std::cout << maze[i][j] << ' ';
	//     }
	//     std::cout << "\n";
	//   }
	end = {n, m};
	std::cout << bfs() << std::endl;
}