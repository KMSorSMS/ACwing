/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。
现在请你找到树中的一条最长路径。
换句话说，要找到一条路径，使得使得路径两端的点的距离最远。
注意：路径中可以只包含一个点。

输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 a_i,b_i,c_i，表示点 a_i 和 b_i 之间存在一条权值为 c_i 的边。

输出格式
输出一个整数，表示树的最长路径的长度。

数据范围
1≤n≤10000,
1≤a_i,b_i≤n,
−10^5≤c_i≤10^5

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

// #include <cstdio>
#include <iostream>
#define N 10010
#define M 20010
int h[N], e[M], w[M], ne[M];
int idx = 1, max = 0;
// 添加 a->b 这条边
inline void add(int a, int b, int weight)
{
	e[idx] = b, w[idx] = weight, ne[idx] = h[a];
	h[a] = idx++;
}
// father 是为了保证一直往下走，从根
int dfs(int node, int father)
{
	int max1 = 0, max2 = 0;
	for(int edge = h[node]; edge != 0; edge = ne[edge])
	{
		int child = e[edge];
		if(child == father) continue;
		int tmp_max = dfs(child, node) + w[edge];
		if(tmp_max > max1)
		{
			max2 = max1;
			max1 = tmp_max;
		}
		else if(tmp_max > max2) { max2 = tmp_max; }
	}
	max = (max1 + max2) > max ? (max1 + max2) : max;
	return max1;
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
	dfs(1, -1);
	std::cout << max << "\n";
}
