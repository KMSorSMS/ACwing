/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
数据范围
1≤n≤500,
1≤m≤10^5,
图中涉及边的边权的绝对值均不超过 10000 。
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

#include <cstring>
#include <iostream>
#define N 510
#define M 200010

int n, m, h[N], e[M], ne[M], weight[M], eidx = 1;
int dist[N];
bool stat[N];

void add(int u, int v, int w)
{
	e[eidx] = v, ne[eidx] = h[u], weight[eidx] = w;
	h[u] = eidx++;
}

int prime(int start)
{
	int res = 0;
	dist[start] = 0;
	int times = n;
	while(times--)
	{
		// 从dist里面找到到集合的最小值
		int finded = -1;
		for(int i = 1; i <= n; i++)
		{
			if(!stat[i] && (finded == -1 || dist[i] < dist[finded])) finded = i;
		}
		stat[finded] = true;
		// printf("the finded is %d\n", finded);
		// 判定孤立点
		if(dist[finded] == 0x3f3f3f3f) return 0x3f3f3f3f;
		// 通过finded去更新
		for(int edge = h[finded]; edge != 0; edge = ne[edge])
		{
			int node_ = e[edge], weight_ = weight[edge];
			// printf("dist[%d] is %d, weight is %d\n", node_, dist[node_], weight_);
			if(!stat[node_] && dist[node_] > weight_) dist[node_] = weight_;
		}
		// printf("the dist[%d] is %d\n", finded, dist[finded]);
		res += dist[finded];
	}
	return res;
}

int main()
{
	int u, v, w;
	memset(dist, 0x3f, sizeof(dist));
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
	int res = prime(1);
	if(res == 0x3f3f3f3f)
		std::cout << "impossible\n";
	else
		std::cout << res << "\n";
	return 0;
}