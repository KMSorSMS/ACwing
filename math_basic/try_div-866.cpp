/*
给定 n 个正整数 a_i，判定每个数是否是质数。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个正整数 a_i。

输出格式共 n 行，其中第 i 行输出第 i 个正整数 a_i 是否为质数，是则输出 Yes，否则输出 No。
数据范围
1≤n≤100,
1≤a_i≤2^31−1

输入样例：
2
2
6
输出样例：
Yes
No
*/

#include <iostream>

inline bool judge_prime(int num)
{
	for(int i = 2; i <= num / i; i++)
	{
		if(num % i == 0) return false;
	}
	return true;
}

int main()
{
	int n, a;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> a;
		if(a == 1)
			std::cout << "No\n";
		else if(judge_prime(a)) { std::cout << "Yes\n"; }
		else { std::cout << "No\n"; }
	}
	return 0;
}

/*
思路：去挨个做除法即可，范围是2~i (i*i<n)
*/