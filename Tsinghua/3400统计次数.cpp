/*
给定两个正整数 n 和 k，求从 1 到 n 这 n 个正整数的十进制表示中 k 出现的次数。

输入格式
共一行，包含两个整数 n 和 k。

输出格式
输出一个整数，表示答案。

数据范围
1≤n≤10^6,1≤k≤9
输入样例：
12 1
输出样例：
5
样例解释
从 1 到 12 这些整数中包含 1 的数字有 1,10,11,12，一共出现了 5 次 1。
*/
#include <iostream>
using namespace std;

inline int count_x_k(int x, int k)
{
	int res = 0;
	while(x != 0)
	{
		if(x % 10 == k) { res++; }
		x /= 10;
	}
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int count = 0;
	for(int i = 1; i <= n; i++) { count += count_x_k(i, k); }
	cout << count << "\n";
	return 0;
}