/*
时间限制： 1.0 秒

空间限制： 512 MB

注：本题数据的输入输出格式与原题进行了微调，将一组输入改成多组输入。
我们有 10 个计入分数的测试点（每个测试点 10 分）以及 10 个不计入分数的测试点（每个测试点 0 分），
只通过前 10 个测试点视为 100 分 unaccepted ，通过所有测试点视为 accepted 。

题目描述
对于每个数据点你需要处理 T 组查询。每次查询输入 n ，求长度为 n 的字符串个数，要求：
每一位为 1 , 2 或 3;
不得连续出现 3 个相同的数字。
输入格式
从标准输入读入数据。
输入的第一行包含一个正整数 T ，表示共有 T 组数据。
接下来 T 行，每组数据占一行，分别包含一个正整数 n 。

输出格式
输出到标准输出。
共输出 T 行，第 i 行对应第 i 组询问所求的答案：
如果答案不超过 16 位数，则直接输出。
如果答案至少 17 位数，则先输出 ...... ，然后输出答案的最后 10 位。

输入输出样例
输入
3
4
28
51
输出
66
1970947301376
......9614132224
*/

// #include <cstdio>
#include <cstdio>
#include <cstring>
// #include <iostream>
#define N 2100000
// f[i][j][k] 代表以 j 结尾，长度为 i 的字符串中连续数字为 k 的个数。
// f[i][j][1] = f[i-1][其它][1] + f[i-1][其它][2]
// f[i][j][2] = f[i-1][j][1]
typedef unsigned long long ull;
ull f[N][4][3];
char is_out[N][4][3];
const ull mod = (ull)1e16;
const ull mod_out = (ull)1e10;
bool print_dot = false;

void dp(int n)
{
	for(int j = 1; j <= 3; j++) { f[1][j][1] = 1; }
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			for(int range = 1; range <= 3; range++)
			{
				if(range == j)
				{
					f[i][j][2] += f[i - 1][j][1];
					if(is_out[i - 1][j][1] == 1) is_out[i][j][2] = 1;
					if(f[i][j][2] >= mod) { f[i][j][2] %= mod_out, is_out[i][j][2] = 1; }
				}
				else
				{
					f[i][j][1] += f[i - 1][range][1] + f[i - 1][range][2];
					if(is_out[i - 1][range][1] == 1 || is_out[i - 1][range][2] == 1)
						is_out[i][j][1] = 1;
					if(f[i][j][1] >= mod) { f[i][j][1] %= mod_out, is_out[i][j][1] = 1; }
				}
			}
		}
	}
}

int main()
{
	int T, n;
	ull result = 0;
	scanf("%d", &T);
	dp(N);
	while(T--)
	{
		// memset(f, 0, sizeof(f));
		scanf("%d", &n);
		print_dot = false;
		result = 0;
		for(int i = 1; i <= 3; i++)
		{
			for(int k = 1; k <= 2; k++)
			{
				result += f[n][i][k];
				if(is_out[n][i][k] == 1)
				{
					print_dot = true;
					// printf("finded %d,%d,%d\n", n, i, k);
				}
			}
		}
		if(result >= mod) print_dot = true;
		if(print_dot) { printf("......%llu\n", result % mod_out); }
		else { printf("%llu\n", result); }
	}
	return 0;
}