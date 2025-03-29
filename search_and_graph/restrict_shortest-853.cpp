/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
注意：图中可能 存在负权回路 。
输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
点的编号为 1∼n。输出格式输出一个整数，表示从 1号点到 n 号点的最多经过 k 条边的最短距离。
如果不存在满足条件的路径，则输出 impossible。
数据范围
1≤n,k≤500,
1≤m≤10000,
1≤x,y≤n，
任意边长的绝对值不超过 10000。
输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/
#include <cstring>
#include <iostream>
#define N 510
#define M 10010
int n, m, k, dis[N], back[N];
struct Edge
{
	int x, y, z;
} edge[M];

inline void bellman_ford(int start, int end)
{
	// 初始化长度
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int i = 1; i <= k; i++)
	{
		// 每一轮迭代之前需要拷贝
		memcpy(back, dis, sizeof(dis));
		for(int j = 1; j <= m; j++)
		{
			if(back[edge[j].x] + edge[j].z < dis[edge[j].y])
			{
				dis[edge[j].y] = back[edge[j].x] + edge[j].z;
			}
		}
	}
	if(dis[end] >= 0x3f3f3f3f / 2)
		std::cout << "impossible\n";
	else
		std::cout << dis[end] << "\n";
}

int main()
{
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) { std::cin >> edge[i].x >> edge[i].y >> edge[i].z; }
	bellman_ford(1, n);
	return 0;
}

/*
bellman-ford算法的外层迭代指的是，迭代k次的时候，结果是从源点，经过不超过k条边的最短距离
*/