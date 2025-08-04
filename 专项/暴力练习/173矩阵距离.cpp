/*
给定一个 N 行 M 列的 01 矩阵 A，A[i][j] 与 A[k][l] 之间的曼哈顿距离定义为：
dist(i,j,k,l) = |i−k|+|j−l|

输出一个 N 行 M 列的整数矩阵 B，其中：

B[i][j]=min 1≤x≤N,1≤y≤M, A[x][y]=1 dist(i,j,x,y)

输入格式
第一行两个整数 N,M。

接下来一个 N 行 M 列的 01 矩阵，数字之间没有空格。

输出格式
一个 N 行 M 列的矩阵 B，相邻两个整数之间用一个空格隔开。

数据范围
1≤N,M≤1000

输入样例：
3 4
0001
0011
0110
输出样例：
3 2 1 0
2 1 0 0
1 0 0 1
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
struct graph_node
{
	int x, y;
};

using namespace std;
const int N = 1010, M = 1010;
int m, n;
char matrix_a[N][M];
bool st[N][M];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool judge_in(int node_x, int node_y)
{
	return node_x >= 1 && node_x <= n && node_y >= 1 && node_y <= m;
}

int bfs(int start_x, int start_y)
{
	memset(st, 0, sizeof(st));
	queue<pair<graph_node, int>> que;
	que.push({{start_x, start_y}, 0});
	while(que.size())
	{
		graph_node node = que.front().first;
		int depth = que.front().second;
		int node_x = node.x, node_y = node.y;
		que.pop();
		if(matrix_a[node_x][node_y] == '1') return depth;
		if(st[node_x][node_y]) continue;
		st[node_x][node_y] = true;
		for(int i = 0; i < 4; i++)
		{
			int next_node_x = node_x + dir[i][0], next_node_y = node_y + dir[i][1];
			if(!st[next_node_x][next_node_y] && judge_in(next_node_x, next_node_y))
			{
				que.push({{next_node_x, next_node_y}, depth + 1});
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> matrix_a[i][j];
			// printf("read:%c\n", matrix_a[i][j]);
		}
	}
	// printf("fin read\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) { cout << bfs(i, j) << " "; }
		cout << "\n";
	}
	return 0;
}
