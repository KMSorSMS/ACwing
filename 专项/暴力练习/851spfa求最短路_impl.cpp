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
#include <queue>
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
int h[N], e[M], ne[M], w[M];
int idx = 1, n, m;
int dist[N];
bool st[N];

void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

void spfa(int start)
{
	queue<int> que;
	que.push(start);
	dist[start] = 0;
	while(que.size())
	{
		int node = que.front();
		que.pop();
		for(int edge = h[node]; edge != 0; edge = ne[edge])
		{
			int node_next = e[edge];
			if(dist[node_next] > dist[node] + w[edge])
			{
				dist[node_next] = dist[node] + w[edge];
				que.push(node_next);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);
	}
	spfa(1);
	if(dist[n] == 0x3f3f3f3f) { cout << "impossible\n"; }
	else { cout << dist[n] << '\n'; }
	return 0;
}
