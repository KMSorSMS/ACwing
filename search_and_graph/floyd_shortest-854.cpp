/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。
再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。
数据保证图中不存在负权回路。
输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。
输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。
数据范围
1≤n≤200,
1≤k≤n^2
1≤m≤20000,
图中涉及边长绝对值均不超过 10000 。
输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1
*/

#include <iostream>
#define N 210
#define M 20010
#define INF 1e9
int dis[N][N], n, m, k;

void floyd()
{
	for(int k_ = 1; k_ <= n; k_++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				// printf("\nbefore dis[%d][%d] is :%d\n", i, j, dis[i][j]);
				dis[i][j] = std::min(dis[i][k_] + dis[k_][j], dis[i][j]);
				// printf("dis[%d][%d] is :%d\n", i, j, dis[i][j]);
			}
		}
	}
}

int main()
{
	std::cin >> n >> m >> k;
	int x, y, z;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}
	}

	// printf("\nafter init\n");
	for(int i = 1; i <= m; i++)
	{
		std::cin >> x >> y >> z;
		// printf("\ninput x:%d,y:%d,z:%d\n",x,y,z);
		dis[x][y] = std::min(dis[x][y], z);
	}
	// printf("before floy\n");
	floyd();
	// printf("end floy\n");
	for(int i = 1; i <= k; i++)
	{
		std::cin >> x >> y;
		if(dis[x][y] >= INF / 2) { std::cout << "impossible\n"; }
		else { std::cout << dis[x][y] << "\n"; }
	}
}