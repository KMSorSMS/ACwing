/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。
输入格式第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
输出格式输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 −1。
数据范围
1≤n,m≤1.5×10^5,图中涉及边长均不小于 0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过 10^9。
输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define N 150010
#define M 150010

typedef std::pair<int, int> PII;
// the first is distance, the second is node index
std::priority_queue<PII, std::vector<PII>, std::greater<PII>> unfind;
int n, m, h[N], e[M], ne[M], weight[M], eidx = 1, dis[N];
bool state[N];
inline void add(int x, int y, int z)
{
	e[eidx] = y, weight[eidx] = z, ne[eidx] = h[x];
	h[x] = eidx++;
}

inline void dijks(int start, int end)
{
	dis[start] = 0;
	unfind.push({0, start});
	// 先根据边加入元素
	for(int edge = h[start]; edge != 0; edge = ne[edge])
	{
		int tmp_node = e[edge];
		if(weight[edge] < dis[tmp_node])
			dis[tmp_node] = weight[edge], unfind.push({weight[edge], tmp_node});
	}
	while(!unfind.empty())
	{
		PII min_pair = unfind.top();
		unfind.pop();
		if(state[min_pair.second]) continue;
		if(min_pair.second == end)
		{
			std::cout << min_pair.first << "\n";
			return;
		}
		dis[min_pair.second] = min_pair.first;
		state[min_pair.second] = true;
		// 缩边
		for(int edge = h[min_pair.second]; edge != 0; edge = ne[edge])
		{
			int tmp_node = e[edge];
			if(min_pair.first + weight[edge] < dis[tmp_node])
			{
				dis[tmp_node] = min_pair.first + weight[edge];
				unfind.push({dis[tmp_node], tmp_node});
			}
		}
	}
	std::cout << "-1\n";
}

int main()
{
	int x, y, z;
	std::cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; i++)
	{
		std::cin >> x >> y >> z;
		add(x, y, z);
	}
	int start = 1, end = n;
	dijks(start, end);
}