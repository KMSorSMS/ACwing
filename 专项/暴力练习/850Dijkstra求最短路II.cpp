/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×10^5,
图中涉及边长均不小于 0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过 10^9。

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
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int M = 2e5 + 10, N = 2e5 + 10;
int h[N], e[M], ne[M], w[M];
int dist[N];
bool st[N];
int idx = 1;
int m, n;
typedef pair<int, int> PII;

void dij(int start_, int end_)
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, start_});
	while(!heap.empty())
	{
		PII point = heap.top();
		heap.pop();
		int node_finded = point.second, distance = point.first;
		if(st[node_finded]) continue;
		st[node_finded] = true;
		// printf("node_finded:%d,dist:%d,heap_size:%ld\n", node_finded, distance, heap.size());
		dist[node_finded] = distance < dist[node_finded] ? distance : dist[node_finded];
		for(int edge = h[node_finded]; edge != 0; edge = ne[edge])
		{
			int node = e[edge];
			if(dist[node] > dist[node_finded] + w[edge])
			{
				dist[node] = dist[node_finded] + w[edge];
				heap.push({dist[node], node});
			}
		}
	}
	if(dist[end_] != 0x3f3f3f3f) { cout << dist[end_] << "\n"; }
	else { cout << "-1\n"; }
}

inline void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}
inline void init()
{
	memset(dist, 0x3f, (n + 1) * sizeof(int));
}

int main()
{
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add_edge(x, y, z);
	}
	dij(1, n);
}
