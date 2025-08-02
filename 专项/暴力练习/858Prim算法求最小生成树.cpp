/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w ，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500,
1≤m≤10^5,
图中涉及边的边权的绝对值均不超过 10000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/

// 很像 dijkstra

#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 510, M = 2*(1e5 + 10);

int h[N], e[M], ne[M], w[M];
int dist[N];
bool st[N];
int idx = 1, n, m;

void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

int prim(int start)
{
	int res = 0;
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({0, start});
	dist[start] = 0;
	while(heap.size())
	{
		int find_node = heap.top().second, weight = heap.top().first;
		heap.pop();
		if(st[find_node]) continue;
		res += weight;
		st[find_node] = true;
		for(int edge = h[find_node]; edge != 0; edge = ne[edge])
		{
			int node = e[edge];
			if(!st[node] && dist[node] > w[edge])
			{
				dist[node] = w[edge];
				heap.push({dist[node], node});
			}
		}
	}
	return res;
}

void init()
{
	memset(dist, 0x3f, sizeof(dist));
}

int main()
{
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	int res = prim(1);
	for(int i = 1; i <= n; i++)
	{
		if(!st[i])
		{
			cout << "impossible\n";
			return 0;
		}
	}
	cout << res << "\n";
}
/*
完成了 prim 算法的复习,和 dij 相似 的,只不过这里是找到到集合的最小值,而不是到点的最小值.还有,用邻接表的模板存无向图的时候,边的数量是两倍 m!!!
*/