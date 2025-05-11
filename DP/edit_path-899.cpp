/*
给定 n 个长度不超过 10 的字符串以及 m 次询问，每次询问给出一个字符串和一个操作次数上限。

对于每次询问，请你求出给定的 n 个字符串中有多少个字符串可以在上限操作次数内经过操作变成询问给出的字符串。

每个对字符串进行的单个字符的插入、删除或替换算作一次操作。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含一个字符串，表示给定的字符串。

再接下来 m 行，每行包含一个字符串和一个整数，表示一次询问。

字符串中只包含小写字母，且长度均不超过 10。

输出格式
输出共 m 行，每行输出一个整数作为结果，表示一次询问中满足条件的字符串个数。

数据范围
1≤n,m≤1000,

输入样例：
3 2
abc
acd
bcd
ab 1
acbd 2
输出样例：
1
3
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#define N 1010
#define M 1010
#define LEN 15

char str[N][LEN];
char query[LEN];
int f[LEN][LEN];

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) { std::cin >> &str[i][1]; }
	for(int i = 1; i < LEN; i++)
	{
		f[i][0] = i;
		f[0][i] = i;
	}
	for(int q_ = 1; q_ <= m; q_++)
	{
		int limit, count = 0;
		std::cin >> &query[1] >> limit;
		int len_b = strlen(query + 1);
		// 遍历所有 A
		for(int s_ = 1; s_ <= n; s_++)
		{
			int len_a = strlen(str[s_] + 1);
			for(int i = 1; i <= len_a; i++)
			{
				for(int j = 1; j <= len_b; j++)
				{
					f[i][j] = std::min(f[i - 1][j], f[i][j - 1]) + 1;
					if(str[s_][i] == query[j]) { f[i][j] = std::min(f[i][j], f[i - 1][j - 1]); }
					else { f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + 1); }
				}
			}
			if(f[len_a][len_b] <= limit) { count++; }
		}
		std::cout << count << "\n";
	}
	return 0;
}

/*
思路：
对 902题目稍加变形，遍历（n）每个字符串和询问的最小操作即可
对每个字符和询问的时候，就是一组 A[1~i] B[1~j]对应的 f[i][j]的更新找最小值
*/