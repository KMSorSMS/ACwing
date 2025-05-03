/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 v_i，价值是 w_i。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 v_i,w_i，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<v_i,w_i≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
8
*/

#include <algorithm>
#include <iostream>
#define N 1010
#define V 1010

int f[N][V];
int w_[N], v_[N];

int main()
{
	int n, v;
	std::cin >> n >> v;
	for(int i = 1; i <= n; i++) { std::cin >> v_[i] >> w_[i]; }
	// 进行动态规划
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v_[i]) { f[i][j] = std::max(f[i - 1][j - v_[i]] + w_[i], f[i][j]); }
		}
	}
	// 查找最大值，就是 f[n][v]
	// int res = 0;
	// for(int i = 0; i <= n; i++) { res = std::max(f[i][v], res); }
	// std::cout << res << "\n";
	std::cout << f[n][v] << "\n";
}

/*
思路：
先用两维的动态规划，然后再改进
二维数组 f[i][j]表示前 i 个物件里面，容量小于 j 的最大价值
在已知 f[i-1][...]的情况下，我们可以这样算 f[i][j]
1. f[i][j] = f[i-1][j] (相当于是不选择 i 的情况)
2. f[i][j] = f[i-1][j-v[i]] + w[i] (这是选择了 i 的情况)
然后对 1 和 2 两种情况取最大值就能得到结果
*/