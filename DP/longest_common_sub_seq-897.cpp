/*
定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。
输入格式
第一行包含两个整数 N 和 M。
第二行包含一个长度为 N 的字符串，表示字符串 A。
第三行包含一个长度为 M 的字符串，表示字符串 B。

字符串均由小写字母构成。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N,M≤1000

输入样例：
4 5
acbd
abedc
输出样例：
3
*/
#include <algorithm>
#include <iostream>
#define N 1010
#define M 1010

char a[N], b[M];
int f[N][M];

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::cin >> &a[1] >> &b[1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j]) f[i][j] = std::max(f[i - 1][j - 1] + 1, f[i][j]);
		}
	}
	std::cout << f[n][m] << "\n";
	return 0;
}

/*
思路：
同样，定义f[i][j] 为 集合 a[1~i] b[1~j]里面公共子序列集合 中的最大值，
那么更新 f[i][j]的方法是：
f[i][j] = max(f[i-1][j],f[i][j-1],f[i-1][j-1]+1(前提是a[i]=b[j]))
注意这个原因是取最大值的时候可以重叠
*/