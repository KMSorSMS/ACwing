/*
定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1。

数据范围
1≤n,m≤10^5

输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;
int h[N], e[M], ne[M];
int in_count[N];
int idx = 1;
int m, n;
int no_in_node[N];
int idx_node = 1;

void add_edge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a];
	h[a] = idx++;
}

void find_topo()
{
	for(int i = 1; i < idx_node; i++)
	{
		int node = no_in_node[i];
		for(int edge = h[node]; edge != 0; edge = ne[edge])
		{
			int next_node = e[edge];
			if((--in_count[next_node]) == 0) { no_in_node[idx_node++] = next_node; }
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a == b)
		{
			cout << "-1\n";
			return 0;
		}
		in_count[b]++;
		add_edge(a, b);
	}
	for(int i = 1; i <= n; i++)
	{
		if(in_count[i] == 0) { no_in_node[idx_node++] = i; }
	}
	find_topo();
	if(idx_node <= n) { cout << "-1\n"; }
	else
	{
		for(int i = 1; i <= n; i++) { cout << no_in_node[i] << " "; }
		cout << "\n";
	}
}
/*
注意，有自环是不可能满足拓扑的。很类似于 bfs,只需要将入度为 0 的点加入队列,然后遍历即可,这里可以看到因为要打印结果,所以我用的数组而不是 queue 来保存队列
*/
