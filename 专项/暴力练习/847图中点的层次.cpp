/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。

所有边的长度都是 1，点的编号为 1∼n。

请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

数据范围
1≤n,m≤10^5

输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10, M = 2e5 + 10;

int h[N], e[M], ne[M];
int st[N];
int n, m;
int idx = 1;

void add_edge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a];
	h[a] = idx++;
}

int bfs(int start, int end)
{
	queue<pii> que;
	que.push({start, 0});
	while(que.size())
	{
		int node = que.front().first, depth = que.front().second;
		que.pop();
		if(node == end) return depth;
		if(st[node]) continue;
		st[node] = true;
		for(int edge = h[node]; edge != 0; edge = ne[edge])
		{
			int node_next = e[edge];
			if(!st[node_next]) { que.push({node_next, depth + 1}); }
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}
	cout << bfs(1, n) << "\n";
	return 0;
}
