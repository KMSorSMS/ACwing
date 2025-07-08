/*
Joe觉得云朵很美，决定去山上的商店买一些云朵。
商店里有 n 朵云，云朵被编号为 1,2,…,n，并且每朵云都有一个价值。
但是商店老板跟他说，一些云朵要搭配来买才好，所以买一朵云则与这朵云有搭配的云都要买。
但是Joe的钱有限，所以他希望买的价值越多越好。
输入格式
第 1 行包含三个整数 n，m，w，表示有 n 朵云，m 个搭配，Joe有 w 的钱。

第 2∼n+1 行，每行两个整数 c_i，d_i 表示 i 朵云的价钱和价值。

第 n+2∼n+1+m 行，每行两个整数 u_i，v_i，表示买 u_i 就必须买 v_i，同理，如果买 v_i 就必须买 u_i。

输出格式
一行，表示可以获得的最大价值。
数据范围
1≤n≤10000,
0≤m≤5000,
1≤w≤10000,
1≤c_i≤5000,
1≤d_i≤100,
1≤u_i,v_i≤n
输入样例：
5 3 10
3 10
3 10
3 10
5 100
10 1
1 3
3 2
4 2
输出样例：
1
*/
// #include <algorithm>
// #include <cstdio>
#include <iostream>
#define N 10010
#define W 10010
int a[N], value[N], cost[N];
int values_[N], costs_[N];
bool added[N];
// f[i][j] 是前 i 个商品里面，体积不超过 j 的最大价值
int f[W];
// int class_set[N],nums;

int find(int node)
{
	int finded = node;
	if(a[node] != node) finded = find(a[node]);
	a[node] = finded;
	return finded;
}

int main()
{
	int n, m, w;
	std::cin >> n >> m >> w;
	for(int i = 1; i <= n; i++) { a[i] = i; }
	for(int i = 1; i <= n; i++) { std::cin >> cost[i] >> value[i]; }
	while(m--)
	{
		int u_i, v_i;
		std::cin >> u_i >> v_i;
		int u_class = find(u_i);
		int v_class = find(v_i);
		if(u_class != v_class)
		{
			a[u_class] = v_class;
			value[v_class] += value[u_class], cost[v_class] += cost[u_class];
		}
	}
	int idx = 1;
	for(int i = 1; i <= n; i++)
	{
		int class_a = find(i);
		if(!added[class_a])
		{
			values_[idx] = value[class_a], costs_[idx] = cost[class_a];
			idx++;
			added[class_a] = true;
		}
	}
	// printf("idx:%d\n", idx);
	for(int i = 1; i <= idx; i++)
	{
		for(int j = w; j >= costs_[i]; j--)
		{
			f[j] = f[j - costs_[i]] + values_[i] > f[j] ? f[j - costs_[i]] + values_[i] : f[j];

			// f[i][j] = f[i - 1][j];
			// if(costs_[i] <= j)
			// {
			// 	f[i][j] = f[i][j] > (f[i - 1][j - costs_[i]] + values_[i])
			// 				  ? f[i][j]
			// 				  : (f[i - 1][j - costs_[i]] + values_[i]);
			// }
		}
	}
	std::cout << f[w] << "\n";
	return 0;
}
