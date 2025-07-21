/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。
请你在树中找到一个点，使得该点到树中其他结点的最远距离最近。

输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 ai,bi,ci，表示点 ai 和 bi 之间存在一条权值为 ci 的边。

输出格式
输出一个整数，表示所求点到树中其他结点的最远距离。

数据范围
1≤n≤10000,
1≤ai,bi≤n,
1≤ci≤10^5

输入样例：
5 
2 1 1 
3 2 1 
4 3 1 
5 1 1
输出样例：
2
*/

#include <algorithm>
#include <iostream>
const int N = 10010, M = 20010;
const int INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M];
int max1[N], max2[N], u_max[N], from_node[N];
int idx = 1, min = INF;

inline void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

int dfs_down(int node, int fa)
{
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int next_node = e[edge];
		if(next_node == fa) continue;
		int tmp_max = dfs_down(next_node, node) + w[edge];
		if(tmp_max > max1[node])
		{
			max2[node] = max1[node];
			max1[node] = tmp_max;
			from_node[node] = next_node;
		}
		else if(tmp_max > max2[node]) { max2[node] = tmp_max; }
	}
	return max1[node];
}

void dfs_up(int node, int fa, int weight)
{
	if(from_node[fa] != node) { u_max[node] = std::max(u_max[fa], max1[fa]) + weight; }
	else { u_max[node] = std::max(u_max[fa], max2[fa]) + weight; }
	min = std::min(min, std::max(u_max[node], max1[node]));
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int next_node = e[edge];
		if(next_node == fa) continue;
		dfs_up(next_node, node, w[edge]);
	}
}

int main()
{
	int n;
	std::cin >> n;
	n--;
	while(n--)
	{
		int ai, bi, ci;
		std::cin >> ai >> bi >> ci;
		add_edge(ai, bi, ci);
		add_edge(bi, ai, ci);
	}
	dfs_down(1, 0);
	dfs_up(1, 0, 0);
	std::cout << min << "\n";
}
