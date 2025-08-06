/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
注意：图中可能存在负权回路。

输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
点的编号为 1∼n。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。
如果不存在满足条件的路径，则输出 impossible。
数据范围
1≤n,k≤500,
1≤m≤10000,
1≤x,y≤n，
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int M = 1e4 + 10, N = 510;
int n, m, k;
struct Edge
{
	int x, y, w;
};
Edge edge[M];
int dist[N], dist_cpy[N];

void bell_ford(int start)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[start] = 0;
	for(int round = 1; round <= k; round++)
	{
		memcpy(dist_cpy, dist, sizeof(dist));
		for(int i = 1; i <= m; i++)
		{
			Edge edge_loose = edge[i];
			int x = edge_loose.x, y = edge_loose.y, w = edge_loose.w;
			dist[y] = min(dist[y], dist_cpy[x] + w);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge[i] = {x, y, z};
	}
	bell_ford(1);
	if(dist[n] >= 0x3f3f3f3f / 2) { cout << "impossible\n"; }
	else { cout << dist[n] << "\n"; }
	return 0;
}
