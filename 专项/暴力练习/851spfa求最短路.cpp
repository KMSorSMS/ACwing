/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。
数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤10^5,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Edge
{
	int x, y, z;
};
const int N = 1e5 + 10, M = 1e5 + 10;
Edge edge[M];
int n, m;
int dist[N], dist_cpy[N];

void spfa(int start)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[start] = 0;
	for(int round = 1; round <= m; round++)
	{
		memcpy(dist_cpy, dist, sizeof(dist));
		for(int i = 1; i <= m; i++)
		{
			Edge edge_loose = edge[i];
			int x = edge_loose.x, y = edge_loose.y, z = edge_loose.z;
			dist[y] = min(dist[y], dist_cpy[x] + z);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge[i] = {x, y, z};
	}
	spfa(1);
	if(dist[n] >= 0x3f3f3f3f / 2) { cout << "impossible\n"; }
	else { cout << dist[n] << "\n"; }
	return 0;
}
