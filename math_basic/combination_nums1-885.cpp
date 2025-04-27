/*
给定 n 组询问，每组询问给定两个整数 a，b ，请你输出 C_a^b mod (10^9+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤2000

输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/
#include <iostream>
#define N 2010
int C[N][N];
const int MOD = 1e9 + 7;

int main()
{
	int n, a, b;
	int update = 1;
	C[0][0] = 1;
	std::cin >> n;
	while(n--)
	{
		std::cin >> a >> b;
		for(int i = update; i <= a; i++)
		{
			C[i][0] = 1;
			for(int j = 1; j <= i; j++) { C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD; }
		}
		update = a > update ? a : update;
		std::cout << C[a][b] << "\n";
	}
	return 0;
}

/*
思路：
很简单，C_a^b = C_(a-1)^b + C_(a-1)^(b-1),
不使用递归，使用递推
*/