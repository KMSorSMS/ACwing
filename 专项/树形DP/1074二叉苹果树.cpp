/*
有一棵二叉苹果树，如果树枝有分叉，一定是分两叉，即没有只有一个儿子的节点。
这棵树共 N 个节点，编号为 1 至 N，树根编号一定为 1。
我们用一根树枝两端连接的节点编号描述一根树枝的位置。
一棵苹果树的树枝太多了，需要剪枝。但是一些树枝上长有苹果，给定需要保留的树枝数量，求最多能留住多少苹果。
这里的保留是指最终与1号点连通。

输入格式
第一行包含两个整数 N 和 Q，分别表示树的节点数以及要保留的树枝数量。

接下来 N−1 行描述树枝信息，每行三个整数，前两个是它连接的节点的编号，第三个数是这根树枝上苹果数量。

输出格式
输出仅一行，表示最多能留住的苹果的数量。

数据范围
1≤Q<N≤100.
N≠1,
每根树枝上苹果不超过 30000 个。

输入样例：
5 2
1 3 1
1 4 10
2 3 20
3 5 20
输出样例：
21
*/

#include <algorithm>
#include <iostream>
const int N = 110, M = 2 * N;
int h[N], e[M], ne[M], w[M];
// f[i][j] 代表，第 i 个节点为根，边数为 j 的最多苹果的数量
int f[N][M];
int idx = 1;
int n, q;

inline void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

void dfs(int node, int fa)
{
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int node_next = e[edge];
		if(node_next == fa) continue;
		dfs(node_next, node);
		for(int i = q; i >= 1; i--)
		{
			for(int j = 0; j < i; j++)
			{
				f[node][i] = std::max(f[node][i], f[node_next][i - j - 1] + f[node][j] + w[edge]);
			}
		}
	}
}

int main()
{
	std::cin >> n >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	dfs(1, 0);
	std::cout << f[1][q] << "\n";
}