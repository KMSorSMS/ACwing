/*
Windy 定义了一种 Windy 数：不含前导零且相邻两个数字之差至少为 2 的正整数被称为 Windy 数。

Windy 想知道，在 A 和 B 之间，包括 A 和 B，总共有多少个 Windy 数？

输入格式
共一行，包含两个整数 A 和 B。

输出格式
输出一个整数，表示答案。

数据范围
1≤A≤B≤2×10^9

输入样例1：
1 10
输出样例1：
9
输入样例2：
25 50
输出样例2：
20
*/

// #include <cstdio>
#include <iostream>
#include <vector>
#define N 13
int A, B;
// 表示，首位是 i, 长度是 j 的数中，windy 数的个数
int f[10][N];

inline void init()
{
	for(int i = 0; i <= 9; i++) f[i][1] = 1;
	for(int j = 2; j <= N - 1; j++)
	{
		for(int i = 0; i <= 9; i++)
		{
			for(int k = i - 2; k >= 0; k--) { f[i][j] += f[k][j - 1]; }
			for(int k = i + 2; k <= 9; k++) { f[i][j] += f[k][j - 1]; }
		}
	}
	// // 对前导 0 的情况进行剔除
	// for(int j=1;j<=N-1;j++){
	//     f[0][j] = 0;
	// }
}

inline int DP(int x)
{
	// 拆分数字
	std::vector<int> nums_reverse;
	if(x == 0) return 0;
	while(x != 0)
	{
		nums_reverse.push_back(x % 10);
		x /= 10;
	}
	int i = nums_reverse.size() - 1, result = 0, has_leading = 0, former = -5;
	for(; i >= 0; i--)
	{
		int digit = nums_reverse[i];
		if(digit > 0)
		{
			// 对前导 0 单独处理
			if(has_leading != 1)
			{
				for(int j = i; j >= 1; j--)
				{
					for(int k = 1; k <= 9; k++) { result += f[k][j]; }
				}
			}
			// 非前导 0 统一处理分类
			for(int head = digit - 1; head + has_leading >= 1; head--)
			{
				if(head - former >= 2 || head - former <= -2)
				{
					// printf(
					// "f[%d][%d]:%d, has_leading:%d\n", head, i + 1, f[head][i + 1], has_leading);
					result += f[head][i + 1];
				}
			}
		}
		has_leading = 1;
		if(digit - former < 2 && digit - former > -2)
		{
			// printf("in break\n");
			break;
		}
		former = digit;
	}
	if(i < 0)
	{
		// printf("in added\n");
		result++;
	}
	// printf("result is:%d\n", result);
	return result;
}

int main()
{
	std::cin >> A >> B;
	init();
	std::cout << DP(B) - DP(A - 1) << "\n";
	return 0;
}