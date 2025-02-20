/*
给定一个字符串 S，以及一个模式串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
模式串 P 在字符串 S 中多次作为子串出现。
求出模式串 P 在字符串 S 中所有出现的位置的起始下标。
输入格式
第一行输入整数 N，表示字符串 P的长度。
第二行输入字符串 P。
第三行输入整数 M，表示字符串 S的长度。
第四行输入字符串 S。
输出格式
共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。
数据范围
1≤N≤105
1≤M≤106
输入样例：
3
aba
5
ababa
输出样例：
0 2
*/

// #include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#define N 100010
int Next[N];
// SSS77SSS77
int main()
{
	int n, m, ne;
	std::string P, S;
	std::cin >> n >> P >> m >> S;
	// 处理模版串p得next串
	for(int i = 1; i < n; i++)
	{
		ne = Next[i - 1];
		// printf("next is: %d, i is: %d\n", ne, i);
		while(ne && P[i] != P[ne])
		{
			ne = Next[ne - 1];
			// printf("ne is %d\n", ne);
		}
		// printf("char is %c,%c\n", P[i], P[ne]);
		if(P[i] == P[ne]) Next[i] = ne + 1;
	}
	// 打印next数组
	// for(int i = 0; i < n; i++) { printf("%d ", Next[i]); }
	// std::cout << std::endl;
	// 根据next串我们能够进行匹配
	for(int i = 0, j = 0; i < m; i++)
	{
		// printf("\ni is:%d, j is:%d\n", i, j);
		while(j < n && i < m && S[i] != P[j])
		{
			if(j == 0)
			{
				i++;
				continue;
			}
			// 回退模版
			j = Next[j - 1];
		}
		j++;
		if(j == n && i < m)
		{
			// 输出下标
			std::cout << i - n + 1 << ' ';
			j = Next[n - 1];
		}
	}
	std::cout << std::endl;
	return 0;
}