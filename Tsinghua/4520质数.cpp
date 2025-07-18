/*
给定一个正整数 X，请你在 X 后面添加若干位数字（至少添加一位数字；添加的数不能有前导0），使得结果为质数，在这个前提下所得的结果应尽量小。

输入格式
第一行包含一个整数 T，表示共有 T 组测试数据。
每组数据占一行，包含一个整数 X。

输出格式
每组数据输出一行结果，一个整数，表示所得的满足条件的最小质数。

数据范围
1≤T≤100,
1≤X≤100。

输入样例：
1
1
输出样例：
11
*/
#include <iostream>

#define N 10010
using namespace std;
int primes[N], cnt = 0;
bool st[N];
void get_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) primes[cnt++] = i; // 循环到 i 时, 算法暗含 1 ~ i-1 的所有合数都被筛掉, 只剩素数
		for(int j = 0; primes[j] <= n / i; j++) // 算法不会闲的没事干筛去 primes[j] * i > n 的数
		{
			st[primes[j] * i] = true; // 筛掉以最小质因子左乘 i 的方式得到的合数
			if(i % primes[j] == 0) break;
			// 出现 i 是 primes[j] 的倍数情况时,
			// primes[j] 后一个质数左乘 i 就不是 "最小质因子左乘的方式" 了,
			// 如 i = 4, primes[j] = 2, primes[j] 后一个质数是 3,
			// 3 * 4 显然不是 "最小质因子左乘的方式", 而应该是 2 * 6
		}
	}
}
int main()
{
	get_primes(N - 1);
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		// 检查加一位的
		x *= 10;
		bool finded = false;
		for(int i = 0; i < 10; i++)
		{
			int test = x + i;
			if(!st[test])
			{
				finded = true;
				cout << test << "\n";
				break;
			}
		}
		if(!finded)
		{
			// 找加 2 位数的情况
			x *= 10;
			for(int i = 10; i < 100; i++)
			{
				int test = x + i;
				if(!st[test])
				{
					finded = true;
					cout << test << "\n";
					break;
				}
			}
		}
		if(!finded) { cout << "not found with 2\n"; }
	}
	return 0;
}