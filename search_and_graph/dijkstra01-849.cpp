/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为
z。 输出格式输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 −1。
数据范围1≤n≤500,1≤m≤10^5,图中涉及边长均不超过10000。
输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

#include <cstring>
#include <iostream>
#define N 510
#define M 100010

int h[N], e[M], ne[M], weight[M], dis[N], state[N], eidx = 1;
int n, m;
// add x->y with weight z to graph
inline void add(int x, int y, int z)
{
	e[eidx] = y, ne[eidx] = h[x], weight[eidx] = z;
	h[x] = eidx++;
}
// find the shortest len from start to end
void dijks(int start, int end)
{
	// first set all the distance
	for(int edge = h[start]; edge != 0; edge = ne[edge])
	{
		if(dis[e[edge]] >= weight[edge]) dis[e[edge]] = weight[edge];
	}
	// go to iteration
	while(true)
	{
		int j = -1;
		for(int i = 1; i <= n; i++)
		{
			if(!state[i])
			{
				if(j == -1 || (dis[i] < dis[j])) { j = i; }
			}
		}
		if(j == end)
		{
			if(dis[j] == 0x3f3f3f3f)
				std::cout << "-1" << "\n";
			else
				std::cout << dis[j] << "\n";
			return;
		}
		state[j] = 1;
		for(int edge = h[j]; edge != 0; edge = ne[edge])
		{
			int node = e[edge];
			if(!state[node] && (dis[j] + weight[edge] < dis[node]))
			{
				dis[node] = dis[j] + weight[edge];
			}
		}
	}
}

int main()
{
	std::cin >> n >> m;
	int x, y, z;
	for(int i = 0; i < m; i++)
	{
		std::cin >> x >> y >> z;
		add(x, y, z);
	}
	int start = 1, end = n;
	// 初始化
	memset(dis, 0x3f, (n + 1) * sizeof(int));
	dijks(start, end);
}

/*
把所有点加入到未被访问的队列里面，将1到它们的边的权重作为当前的距离值，对于本身，距离就是0，对于没有边的，距离就是无穷大（我们设置为-1），然后每次迭代找到一个最短边，这个边就是1到这个节点的最短距离，
迭代方式是：将当前距离里面的最小值选为最短边，这个节点出队，作为已经选好的节点，假如它是m，那么通过d_check[1,k] = d[1,m]+d[m,k] 如果这个值更小，那么就更新记录的d[1,k]的值，把所有k更新
完成之后就走入下一个循环
*/