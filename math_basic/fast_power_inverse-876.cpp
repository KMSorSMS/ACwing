/*
给定 n 组 a_i,p_i，其中 p_i 是质数，求 a_i 模 p_i 的乘法逆元，若逆元不存在则输出 impossible。
注意：请返回在 0∼p_i−1 之间的逆元。

乘法逆元的定义
若整数 b，m 互质，并且对于任意的整数 a ，如果满足 b|a，则存在一个整数 x，
使得 a / b≡a×x(mod m) ，则称 x 为 b 的模 m 乘法逆元，记为 b^−1(mod m)。

b 存在乘法逆元的充要条件是 b 与模数 m 互质。当模数 m 为质数时，b^(m−2) 即为 b 的乘法逆元。

输入格式
第一行包含整数 n 。

接下来 n 行，每行包含一个数组 a_i,p_i，数据保证 p_i 是质数。

输出格式
输出共 n 行，每组数据输出一个结果，每个结果占一行。

若 a_i 模 p_i 的乘法逆元存在，则输出一个整数，表示逆元，否则输出 impossible。
数据范围
1≤n≤10^5,
1≤a_i,p_i≤2∗10^9
输入样例：
3
4 3
8 5
6 3
输出样例：
1
2
impossible
*/

#include <iostream>
int main()
{
	int n;
	long a_i, b_i, p_i, res,p;
	char power;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a_i >> p_i;
		res = 1;
		b_i = a_i % p_i;
        p = p_i;
		p_i = p_i - 2;
		if(b_i == 0 || p_i < 0)
		{
			std::cout << "impossible\n";
			continue;
		}
		while(p_i)
		{
			power = p_i & 0x1;
			if(power) { res = res * b_i % p; }
			b_i = b_i * b_i % p, p_i = p_i >> 1;
            // std::cout << "res is " << res << "\n";
		}
		std::cout << res << "\n";
	}
	return 0;
}