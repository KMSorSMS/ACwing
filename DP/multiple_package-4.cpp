/*
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 s_i 件，每件体积是 v_i，价值是 w_i。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 v_i,w_i,s_i，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<v_i,w_i,s_i≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/
#include <algorithm>
#include <iostream>
#define N 110
#define V 110
int f[N][V];
int v_[N], w_[N], s_[N];

int main()
{
	int n, v;
	std::cin >> n >> v;
	for(int i = 1; i <= n; i++) std::cin >> v_[i] >> w_[i] >> s_[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			f[i][j] = f[i - 1][j];
			for(int k = 1; k <= s_[i] && k * v_[i] <= j; k++)
			{
				f[i][j] = std::max(f[i][j], f[i - 1][j - k * v_[i]] + k * w_[i]);
			}
		}
	}
	std::cout << f[n][v] << "\n";
	return 0;
}

/*
思路：
加一重遍历，遍历选择从 0～s_i 件物品 i
其他的和 01 背包一样，但是注意，这个就无法压缩了，只能用公式:
f[i][j] = max(f[i-1][j], f[i-1][j - v[i]] + w[i], f[i-1][j - 2*v[i]] + 2*w[i] ..., f[i-1][j - s_i * v[i]] + s_i * w[i])
对比一下还能不能优化呢？
f[i][j - v[i]] = max(f[i-1][j - v[i]], f[i-1][j - 2*v[i]] + w[i], ... ,f[i-1][j-(s_i+1)*v[i]] + s_i * w[i])
看到最后一项, f[i-1][j-(s_i+1)*v[i]] + s_i * w[i]这个是上一个不存在的项，就无法递推下去，这也是为什么要多一重循环
*/