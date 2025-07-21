/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。
现在请你找到树中的一条最长路径。
换句话说，要找到一条路径，使得使得路径两端的点的距离最远。
注意：路径中可以只包含一个点。
输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 ai,bi,ci，表示点 ai 和 bi 之间存在一条权值为 ci 的边。

输出格式
输出一个整数，表示树的最长路径的长度。

数据范围
1≤n≤10000,
1≤a_i,b_i≤n,
−10^5≤ci≤10^5

输入样例：
6
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
输出样例：
22
*/
#include <iostream>
const int N = 10010;
const int W = 20020;
int h[N], e[W], w[W], ne[W];
int idx = 1, max = 0;

inline void add_edge(int a, int b, int weight)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = weight;
	h[a] = idx++;
}

int dfs(int node, int fa)
{
	int max1 = 0, max2 = 0;
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int node_next = e[edge];
		if(node_next == fa) continue;
		int tmp_max = dfs(node_next, node) + w[edge];
		if(tmp_max > max1)
		{
			max2 = max1;
			max1 = tmp_max;
		}
		else if(tmp_max > max2) { max2 = tmp_max; }
	}
	max = max > (max1 + max2) ? max : (max1 + max2);
	return max1;
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
	dfs(1, 0);
	std::cout << max << "\n";
	return 0;
}

/*
分类：从树的一个节点分类路径，有相同最高节点的算作一类，求最大值，这一类的最大值是来自他子节点的第一最深最大值和第二最深最大值和 0 相比的最大值的和。

*/