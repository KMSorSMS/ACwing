/*
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。

接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

输出格式
输出一个整数 m ，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1≤n≤10^5

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
*/

#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M];
int down_count[N];
int idx = 1;
int n;
int max_res = INF;

void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

int dfs_down(int node, int fa)
{
	down_count[node]++;
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int node_next = e[edge];
		if(node_next == fa) continue;
		down_count[node] += dfs_down(node_next, node);
	}
	return down_count[node];
}

void dfs_cal(int node, int fa)
{
	// printf("fa:%d,fa_node:%d,down_count[node]:%d\n", fa, down_count[fa], down_count[node]);
	int max_ = n - down_count[node];
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int node_next = e[edge];
		if(node_next == fa) continue;
		max_ = max(max_, down_count[node_next]);
	}
	// printf("max_res:%d,max_:%d,node:%d\n", max_res, max_, node);
	max_res = min(max_res, max_);
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int node_next = e[edge];
		if(node_next == fa) continue;
		dfs_cal(node_next, node);
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b, 1);
		add_edge(b, a, 1);
	}
	dfs_down(1, 0);
	// for(int i = 1; i <= n; i++) { printf("down_count[%d]:%d\n", i, down_count[i]); }
	dfs_cal(1, 0);
	cout << max_res << "\n";
	return 0;
}
