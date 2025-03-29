/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。
数据保证不存在负权回路。
输入格式第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
输出格式输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 impossible。
数据范围
1≤n,m≤10^5,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2
*/
#include <cstring>
#include <iostream>
#include <queue>
#define N 100010
#define M 100010
int h[N], e[M], ne[M], weight[M], eidx = 1;
int dist[N];
bool state[N];
int n, m;
std::queue<int> to_short;

// 添加x->y权重z的边
inline void add(int x, int y, int z)
{
	e[eidx] = y, weight[eidx] = z, ne[eidx] = h[x];
	h[x] = eidx++;
}

inline void spfa(int start, int end)
{
	dist[start] = 0, to_short.push(start), state[start] = true;
	while(!to_short.empty())
	{
		int node_start = to_short.front();
		to_short.pop(), state[node_start] = false;
		// push all the neighbor node
		for(int edge = h[node_start]; edge != 0; edge = ne[edge])
		{
			int node = e[edge], node_weight = weight[edge];
			if(node_weight + dist[node_start] < dist[node])
			{
				dist[node] = node_weight + dist[node_start];
				if(!state[node]) to_short.push(node), state[node] = true;
			}
		}
	}
	if(dist[end] >= 0x3f3f3f3f / 2)
		std::cout << "impossible\n";
	else
		std::cout << dist[end] << "\n";
}

int main()
{
	int x, y, z;
	memset(dist, 0x3f, sizeof(dist));
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		std::cin >> x >> y >> z;
		add(x, y, z);
	}
	spfa(1, n);
}

/*
Shortest Path Faster Algorithm (SPFA)
就是在bellman-ford的基础上，我们是遍历在待排序队列里面的点，把它们的邻边的节点进行锁边，不断重复直到完成
*/