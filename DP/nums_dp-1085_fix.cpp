/*
杭州人称那些傻乎乎粘嗒嗒的人为 62（音：laoer）。

杭州交通管理局经常会扩充一些的士车牌照，新近出来一个好消息，以后上牌照，不再含有不吉利的数字了，这样一来，就可以消除个别的士司机和乘客的心理障碍，更安全地服务大众。

不吉利的数字为所有含有 4 或 62 的号码。例如：62315,73418,88914 都属于不吉利号码。但是，61152 虽然含有 6 和 2，但不是 连号，所以不属于不吉利数字之列。

你的任务是，对于每次给出的一个牌照号区间 [n,m]，推断出交管局今后又要实际上给多少辆新的士车上牌照了。

输入格式
输入包含多组测试数据，每组数据占一行。

每组数据包含一个整数对 n 和 m。

当输入一行为“0 0”时，表示输入结束。

输出格式
对于每个整数对，输出一个不含有不吉利数字的统计个数，该数值占一行位置。

数据范围
1≤n≤m≤10^9

输入样例：
1 100
0 0
输出样例：
80
*/

// #include <cstdio>
#include <iostream>
#include <vector>
#define N 10
// f[i][j] 代表，以 i 开头，长度为 j 的数字中，吉利数字的个数
int f[10][N];

inline void init()
{
	for(int i = 0; i <= 9; i++) f[i][1] = 1;
	f[4][1] = 0;
	for(int j = 2; j < N; j++)
	{
		for(int i = 0; i <= 9; i++)
		{
			if(i == 4) continue;
			for(int k = 0; k <= 9; k++)
			{
				if((i == 6 && k == 2)) continue;
				f[i][j] += f[k][j - 1];
			}
		}
	}
}

inline int DP(int x)
{
	std::vector<int> nums_reverse;
	if(x == 0) return 1;
	while(x != 0)
	{
		nums_reverse.push_back(x % 10);
		x /= 10;
	}
	int j = nums_reverse.size() - 1, result = 0, former = 0;
	for(; j >= 0; j--)
	{
		int digit = nums_reverse[j];
		if(digit > 0)
		{
			for(int i = 0; i < digit; i++)
			{
				if((former == 6 && i == 2)) continue;
				result += f[i][j + 1];
			}
			if(digit == 4 || (digit == 2 && former == 6)) break;
		}
		former = digit;
		if(j == 0) result++;
	}
	// printf("results:%d\n", result);
	return result;
}

int main()
{
	int n, m;
	init();
	while(true)
	{
		std::cin >> n >> m;
		if(m == 0 && n == 0) { break; }
		std::cout << DP(m) - DP(n - 1) << "\n";
	}

	return 0;
}