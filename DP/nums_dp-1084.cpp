/*
由于科协里最近真的很流行数字游戏。
某人又命名了一种取模数，这种数字必须满足各位数字之和 mod N 为 0。

现在大家又要玩游戏了，指定一个整数闭区间 [a.b]，问这个区间内有多少个取模数。

输入格式
输入包含多组测试数据，每组数据占一行。

每组数据包含三个整数 a,b,N。

输出格式
对于每个测试数据输出一行结果，表示区间内各位数字和 mod N 为 0 的数的个数。

数据范围
1≤a,b≤2^31−1,
1≤N<100

输入样例：
1 19 9
输出样例：
2
*/
// #include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define N 110
#define R 12
int f[10][R][N];

inline void init(int n)
{
	// 清空 f[i][j][k]
	memset(f, 0, sizeof(f));
	for(int i = 0; i <= 9; i++) { f[i][1][i % n] = 1; }
	for(int j = 2; j < R; j++)
	{
		for(int i = 0; i <= 9; i++)
		{
			for(int k = 0; k < n; k++)
			{
				for(int range = 0; range <= 9; range++)
				{
					f[i][j][k] += f[range][j - 1][(k + n - i % n) % n];
				}
			}
		}
	}
	// f[0][1][0] = 0;
}

inline int DP(int x, int n)
{
	std::vector<int> nums_reverse;
	if(x == 0) return 0;
	while(x != 0)
	{
		nums_reverse.push_back(x % 10);
		x /= 10;
	}
	int i = nums_reverse.size() - 1, result = 0, leading = 0, sum_mod_n = 0;
	for(; i >= 0; i--)
	{
		int digit = nums_reverse[i];
		// printf("digit is: %d\n", digit);
		if(digit > 0)
		{ //需要分左右分支
			// 需要处理前导 0
			if(leading != 1)
			{
				for(int j = i; j >= 1; j--)
				{
					for(int i_in = 1; i_in <= 9; i_in++)
					{
						result += f[i_in][j][0];
						// printf("no_leading f[%d][%d]:%d\n", i_in, j, f[i_in][j][0]);
					}
				}
			}
			for(int i_in = digit - 1; i_in + leading >= 1; i_in--)
			{
				result += f[i_in][i + 1][(n - sum_mod_n) % n];
				// printf("leading f[%d][%d]:%d\n", i_in, i + 1, f[i_in][i + 1][0]);
			}
			sum_mod_n = (sum_mod_n + digit) % n;
		}
		leading = 1;
	}
	if(sum_mod_n == 0)
	{
		result++;
		// printf("result added\n");
	}
	return result;
}

int main()
{
	int a, b, n;
	while(std::cin >> a >> b >> n)
	{
		init(n);
		std::cout << DP(b, n) - DP(a - 1, n) << "\n";
	}
	return 0;
}

/*
思路：
我们需要找到以 i 开头，总共长度为 j 的所有数字中满足 mod N 为 k 的个数
我们用 DP 方法解决，找f[i][j][k]

f[i][j][k] = sum(f[0][j-1][(k+N-0%N)%N],f[1][j-1][(k+N-1%N)%N],...,f[9][j-1][(k+N-9%N)%N])
先遍历 j 然后遍历 i or k

*/
