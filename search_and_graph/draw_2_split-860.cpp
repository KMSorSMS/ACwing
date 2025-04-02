/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。
请你判断这个图是否是二分图。
输入格式 第一行包含两个整数 n 和 m。
接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。
输出格式
如果给定图是二分图，则输出 Yes，否则输出 No。
数据范围
1≤n,m≤10^5
输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes
*/

#include <iostream>
#define N 100010
#define M 200010

int h[N], e[M], ne[M], eidx = 1;
int n, m;
int colors[N];

inline void add(int u, int v)
{
	e[eidx] = v, ne[eidx] = h[u];
	h[u] = eidx++;
}

bool dfs_draw(int node, int color)
{
	colors[node] = color;
	for(int edge_ = h[node]; edge_ != 0; edge_ = ne[edge_])
	{
		int node_ = e[edge_];
		// 如果没有上色，就递归进去上色
		if(!colors[node_])
		{
			if(!dfs_draw(node_, 3 - color)) return false;
		}
		else if(colors[node_] == color) //如果上色了，但是颜色和当前冲突就false
			return false;
	}
	return true;
}

int main()
{
	int u, v;
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> u >> v;
		add(u, v), add(v, u);
	}
	bool result = false;
	for(int i = 1; i <= n; i++)
	{
		if(!colors[i] && !dfs_draw(i, 1))
		{
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
}

/*
思路：通过dfs遍历染色，二分染色成功返回true，失败返回false
*/