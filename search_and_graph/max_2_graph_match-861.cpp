/*
给定一个二分图，其中左半部包含 n_1 个点（编号 1∼n_1），右半部包含 n_2 个点（编号 1∼n_2），二分图共包含 m 条边。
数据保证任意一条边的两个端点都不可能在同一部分中。
请你求出二分图的最大匹配数。
二分图的匹配：给定一个二分图 G，在 G 的一个子图 M 中，M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。
二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。
输入格式
第一行包含三个整数 n_1、 n_2和 m。
接下来 m 行，每行包含两个整数 u 和 v，表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。
输出格式
输出一个整数，表示二分图的最大匹配数。
数据范围
1≤n_1,n_2≤500,
1≤u≤n_1,
1≤v≤n_2,
1≤m≤10^5
输入样例：
2 2 4
1 1
1 2
2 1
2 2
输出样例：
2
*/
#include <cstring>
#include <iostream>
#include <stdio.h>
#define N 510
#define M 100010
int h[N], e[M], ne[M], eidx = 1;
int conn[N];
int n_1, n_2, m;
bool state[N];

inline void add(int n_1_, int n_2_)
{
	e[eidx] = n_2_, ne[eidx] = h[n_1_];
	h[n_1_] = eidx++;
}

bool find_pair(int node)
{
	if(state[node]) return false;
	state[node] = true;
	for(int edge_ = h[node]; edge_ != 0; edge_ = ne[edge_])
	{
		int node_after_ = e[edge_], node_before_ = conn[e[edge_]];
		if(node_before_ == node || (node_before_ != 0 && !find_pair(node_before_))) { continue; }
		else
		{
			conn[node_after_] = node;
			return true;
		}
	}
	return false;
}

int main()
{
	std::cin >> n_1 >> n_2 >> m;
	int u, v;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> u >> v;
		add(u, v);
	}
	int res = 0;
	for(int i = 1; i <= n_1; i++)
	{
		memset(state, 0, sizeof(state));
		if(find_pair(i)) { res++; }
	}
	std::cout << res << "\n";
}
