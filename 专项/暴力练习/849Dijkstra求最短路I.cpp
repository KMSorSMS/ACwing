/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n≤500,
1≤m≤10^5,
图中涉及边长均不超过10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// m 很多，用稠密图
const int N = 510, M = 1e5 + 10;
int graph[N][N];
int dist[N];
bool st[N];
int n, m;

void dij(int start_, int end_)
{
	dist[start_] = 0;
	for(int turn = 1; turn <= n; turn++)
	{
		int min = 0x3f3f3f3f, point = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!st[i] && dist[i] <= min) point = i, min = dist[i];
		}
		// cout << point << "\n====\n";
		st[point] = true;
		// 更新其他
		for(int i = 1; i <= n; i++)
		{
			// printf("point:%d,dist[point]:%d,graph[point][%d]:%d,dist[i]:%d,st:%d,add:%d\n",
			// 	   point,
			// 	   dist[point],
			// 	   i,
			// 	   graph[point][i],
			// 	   dist[i],
			// 	   st[i],
			// 	   dist[point] + graph[point][i]);
			if(!st[i] && dist[i] > dist[point] + graph[point][i])
			{
				// printf("updata:dist[%d]:%d\n", i, dist[i]);
				dist[i] = dist[point] + graph[point][i];
				// printf("updata:dist[%d]:%d\n", i, dist[i]);
			}
		}
	}
	if(dist[end_] != 0x3f3f3f3f) { cout << dist[end_] << "\n"; }
	else { cout << "-1\n"; }
}
inline void init()
{
	memset(dist, 0x3f, (n + 1) * sizeof(int));
	memset(graph, 0x3f, sizeof(graph));
}

int main()
{
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x][y] = z < graph[x][y] ? z : graph[x][y];
	}
	dij(1, n);
}
