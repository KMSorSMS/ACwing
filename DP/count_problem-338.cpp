/*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中 0∼9 的出现次数。
例如，a=1024，b=1032，则 a 和 b 之间共有 9 个数如下：
1024 1025 1026 1027 1028 1029 1030 1031 1032

其中 0 出现 10 次，1 出现 10 次，2 出现 7 次，3 出现 3 次等等…

输入格式
输入包含多组测试数据。

每组测试数据占一行，包含两个整数 a 和 b。

当读入一行为 0 0 时，表示输入终止，且该行不作处理。

输出格式
每组数据输出一个结果，每个结果占一行。
每个结果包含十个用空格隔开的数字，第一个数字表示 0 出现的次数，第二个数字表示 1 出现的次数，以此类推。
数据范围
0<a,b<100000000
输入样例：
1 10
44 497
346 542
1199 1748
1496 1403
1004 503
1714 190
1317 854
1976 494
1001 1960
0 0
输出样例：
1 2 1 1 1 1 1 1 1 1
85 185 185 185 190 96 96 96 95 93
40 40 40 93 136 82 40 40 40 40
115 666 215 215 214 205 205 154 105 106
16 113 19 20 114 20 20 19 19 16
107 105 100 101 101 197 200 200 200 200
413 1133 503 503 503 502 502 417 402 412
196 512 186 104 87 93 97 97 142 196
398 1375 398 398 405 499 499 495 488 471
294 1256 296 296 296 296 287 286 286 247
*/

#include <cmath>
// #include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define N 10
// f[i][j][k]代表最高位是 i，长度为 j 的数字中，k 的出现次数
int f[10][N][10];

inline void init()
{
	for(int i = 0; i <= 9; i++) { f[i][1][i] = 1; }
	for(int j = 2; j < N; j++)
	{
		for(int i = 0; i <= 9; i++)
		{
			for(int k = 0; k <= 9; k++)
			{
				for(int range = 0; range <= 9; range++) { f[i][j][k] += f[range][j - 1][k]; }
				if(i == k) { f[i][j][k] += (int)pow(10, j - 1); }
			}
		}
	}
}

inline void DP(int x, int* result)
{
	std::vector<int> nums_reverse;
	// 记录本身这个数字的各个位里面的数字有多少个
	int result_num[10];
	memset(result_num, 0, sizeof(result_num));
	if(x == 0) return;
	while(x != 0)
	{
		nums_reverse.push_back(x % 10);
		x /= 10;
	}
	int j = nums_reverse.size() - 1, is_leading = 0;
	for(; j >= 0; j--)
	{
		int digit = nums_reverse[j];
		// printf("digit is: %d,j is: %d \n", digit, j);
		// fflush(stdout);
		if(digit > 0)
		{
			if(is_leading != 1)
			{
				// printf("no leading\n");
				for(int len = j; len >= 1; len--)
				{
					for(int i = 1; i <= 9; i++)
					{
						for(int k = 0; k <= 9; k++)
						{
							// printf("f[%d][%d][%d]:%d\n", i, len, k, f[i][len][k]);
							result[k] += f[i][len][k];
						}
					}
				}
			}
			// printf("the normal\n");
			for(int i = digit - 1; i + is_leading >= 1; i--)
			{
				for(int k = 0; k <= 9; k++)
				{
					// printf("f[%d][%d][%d]:%d\n", i, j + 1, k, f[i][j + 1][k]);
					result[k] += f[i][j + 1][k] + result_num[k] * (int)pow(10, j);
				}
			}
		}
		is_leading = 1;
		result_num[digit]++;
	}
	for(int k = 0; k <= 9; k++) { result[k] += result_num[k]; }
}

int main()
{
	int a = 0, b = 0;
	init();
	// printf("after init\n");
	int result_l[10], result_r[10];
	while(true)
	{
		memset(result_l, 0, sizeof(result_l));
		memset(result_r, 0, sizeof(result_r));
		// printf("input \n");
		std::cin >> a >> b;
		// printf("a is %d , b is %d\n", a, b);
		// fflush(stdout);
		if(a == 0 && b == 0) { break; }
		if(a > b) std::swap(a, b);
		DP(a - 1, result_l);
		DP(b, result_r);
		// printf("after DP\n");
		for(int i = 0; i <= 9; i++) { std::cout << result_r[i] - result_l[i] << " "; }
		std::cout << "\n";
	}
	return 0;
}

/*
思路：
主要是预处理，这部分很关键，主要难点在已知高位的情况下，除了通过下一位的已知来更新之外，还要去通过当前位数，来更新一下高位加上之后的数量
这种处理同样在分类里面也有有，所以需要记录当前数字前面的情况，然后根据这些情况进行加法处理
*/
