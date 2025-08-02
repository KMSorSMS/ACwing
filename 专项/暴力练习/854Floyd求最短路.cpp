/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。
数据保证图中不存在负权回路。

输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。
输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200,
1≤k≤n^2,
1≤m≤20000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 210, M = 20010;
int graph[N][N];
int n, m, k;

using namespace std;

inline void init()
{
	memset(graph, 0x3f, sizeof(graph));
	for(int i = 1; i <= n; i++) { graph[i][i] = 0; }
}

void floyd()
{
	for(int k_ = 1; k_ <= n; k_++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k_] + graph[k_][j]);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	init();
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		graph[x][y] = z < graph[x][y] ? z : graph[x][y];
	}
	floyd();
	for(int k_ = 1; k_ <= k; k_++)
	{
		int x, y;
		cin >> x >> y;
		if(graph[x][y] >= 0x3f3f0000)
			cout << "impossible\n";
		else { cout << graph[x][y] << "\n"; }
	}
	return 0;
}
