/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。

请你在树中找到一个点，使得该点到树中其他结点的最远距离最近。

输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 a_i,b_i,c_i，表示点 a_i 和 b_i 之间存在一条权值为 c_i 的边。

输出格式
输出一个整数，表示所求点到树中其他结点的最远距离。

数据范围
1≤n≤10000,
1≤a_i,b_i≤n,
1≤c_i≤10^5

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
// #include <cstdio>
#include <iostream>
#define N 10010
#define M 20010
const int INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M];
int idx = 1;
int fmax1[N], fmax2[N], from_node[N], u_max[N];
int max_centor = -INF;

inline void add(int a, int b, int weight)
{
	e[idx] = b, w[idx] = weight, ne[idx] = h[a];
	h[a] = idx++;
}

int dfs_d(int node, int father)
{
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int child = e[edge];
		if(child == father) continue;
		int tmp_max = dfs_d(child, node) + w[edge];
		if(tmp_max > fmax1[node])
		{
			fmax2[node] = fmax1[node];
			fmax1[node] = tmp_max, from_node[node] = child;
		}
		else if(tmp_max > fmax2[node]) { fmax2[node] = tmp_max; }
	}
	return fmax1[node];
}

void dfs_u(int node, int father)
{
	if(max_centor == -INF)
		max_centor = std::max(u_max[node], fmax1[node]);
	else
		max_centor = std::min(max_centor, std::max(u_max[node], fmax1[node]));
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int child = e[edge];
		if(child == father) continue;
		if(from_node[node] != child)
			u_max[child] = std::max(u_max[node], fmax1[node]) + w[edge];
		else
			u_max[child] = std::max(u_max[node], fmax2[node]) + w[edge];
		dfs_u(child, node);
	}
}

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs_d(1, -1);
	dfs_u(1, -1);
	std::cout << max_centor << "\n";
	return 0;
}
