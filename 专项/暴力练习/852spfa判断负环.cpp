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

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 2e3 + 10, M = 1e4 + 10;
int h[N], e[M], ne[M], w[M];
int idx = 1, n, m;
int dist[N],count_edge[N];
bool st[N];
bool connect[N];

void add_edge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c;
	h[a] = idx++;
}

bool spfa(int start)
{
	dist[start] = 0;
	queue<int> que;
	que.push(start);
	while(que.size())
	{
		int node = que.front();
		que.pop();
		st[node] = false;
		connect[node] = true;
		if(count_edge[node] >= n) return false;
		for(int edge = h[node]; edge != 0; edge = ne[edge])
		{
			int node_next = e[edge];
			if(dist[node_next] > dist[node] + w[edge])
			{
				dist[node_next] = dist[node] + w[edge];
                count_edge[node_next] = count_edge[node] + 1;
				if(!st[node_next])
				{
					que.push(node_next);
					st[node_next] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add_edge(x, y, z);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!connect[i] && !spfa(i))
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}
