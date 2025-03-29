/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你判断图中是否存在负权回路。
输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。
输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes
*/

#include <cstring>
#include <iostream>
#include <queue>
#define N 2010
#define M 10010

int h[N], e[M], ne[M], weight[M], eidx = 1;
int dist[N], count[N];
int n, m;
bool state[N];
std::queue<int> to_find;

inline void add(int x, int y, int z)
{
	e[eidx] = y, ne[eidx] = h[x], weight[eidx] = z;
	h[x] = eidx++;
}

bool spfa(int start, int end)
{
	// 全部入队
	for(int i = 1; i <= n; i++) { to_find.push(i), state[i] = true; }
	while(!to_find.empty())
	{
		int node_start = to_find.front();
		to_find.pop();
		state[node_start] = false;
		// std::cout << "the node is:" << node_start << "\n";
		for(int edge = h[node_start]; edge != 0; edge = ne[edge])
		{
			int node_ = e[edge], weight_ = weight[edge];
			if(dist[node_start] + weight_ < dist[node_])
			{
				dist[node_] = dist[node_start] + weight_;
				count[node_] = count[node_start] + 1;
				// std::cout << "node: " << node_ << "the cout is: " << count[node_] << "\n";
				if(count[node_] >= n) return true;
				if(!state[node_]) { to_find.push(node_), state[node_] = true; }
			}
		}
	}
	return false;
}

int main()
{
	int x, y, z;
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> x >> y >> z;
		add(x, y, z);
	}
	// memset(dist, 0x3f, sizeof(dist));
	if(spfa(1, n))
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
	return 0;
}
