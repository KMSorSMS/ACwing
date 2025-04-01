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
1≤n≤10^5,
1≤m≤2∗10^5,
图中涉及边的边权的绝对值均不超过 1000。
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
#include <algorithm>
#include <iostream>
#define N 100010
#define M 200010
int n, m;
int set[N];
struct Edge
{
	int u;
	int v;
	int w;
	bool operator<(const Edge& rhs) const
	{
		return this->w < rhs.w;
	}
} edge[M];

// 并查集寻找
int find(int u)
{
	if(set[u] != u) set[u] = find(set[u]);
	return set[u];
}

int kruskal()
{
	int res = 0, count_edge = 0;
	// 取出最小边看能不能加入
	for(int edge_ = 1; edge_ <= m; edge_++)
	{
		int u = edge[edge_].u, v = edge[edge_].v;
		int u_col = find(u), v_col = find(v);
		if(u_col != v_col)
		{
			set[v_col] = u_col; //合并并查集（连通集合）
			res += edge[edge_].w;
			count_edge++;
		}
		// printf("cout_edge: %d\n", count_edge);
		if(count_edge == n - 1) return res;
	}
	return 0x3f3f3f3f;
}

int main()
{
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) { std::cin >> edge[i].u >> edge[i].v >> edge[i].w; }
	for(int i = 1; i <= n; i++) set[i] = i;
	// 把边排序 less，排序结果就是升序排序，第一个是最小的
	std::sort(edge + 1, edge + m + 1);
	int res = kruskal();
	if(res == 0x3f3f3f3f)
		std::cout << "impossible\n";
	else
		std::cout << res << "\n";
	return 0;
}