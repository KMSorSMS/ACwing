/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤10^5,
1≤m≤2∗10^5,
图中涉及边的边权的绝对值均不超过 1000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/

#include <algorithm>
#include <cstdio>
// #include <functional>
#include <iostream>
// #include <queue>
#include <utility>
// #include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int classes[N];
// priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> heap;
pair<int, pii> edges[M];

int find_class(int x)
{
	if(classes[x] != x) { classes[x] = find_class(classes[x]); }
	return classes[x];
}

pii krus()
{
	int res = 0, count_edge = 0;
	for(int i = 1; i <= m; i++)
	{
		int node1 = edges[i].second.first, node2 = edges[i].second.second;
		int dist = edges[i].first;
		int class1 = find_class(node1), class2 = find_class(node2);
		// printf("class1:%d,class2:%d,node1:%d,node2:%d\n", class1, class2, node1, node2);
		if(class1 == class2) continue;
		classes[class2] = class1;
		res += dist;
		count_edge++;
	}
	return {res, count_edge};
}

void init()
{
	for(int i = 1; i <= n; i++) { classes[i] = i; }
}

int main()
{
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = {c, {a, b}};
	}
	sort(edges + 1, edges + m + 1);
	pii res = krus();
	if(res.second != n - 1)
	{
		cout << "impossible\n";
		// printf("the edge:%d,res is %d\n", res.second, res.first);
	}
	else { cout << res.first << "\n"; }
	return 0;
}
