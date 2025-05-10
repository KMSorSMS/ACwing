/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤100000，−10^9≤数列中的数≤10^9

输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/

#include <algorithm>
// #include <cstdio>
#include <iostream>

const int N = 2e5;

int f[N];

int main()
{
	int n, num;
	std::cin >> n;
	int len = 0;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> num;
		// 二分查找最大的小于 num 的数，在 1～len 的范围内
		// l是大于 num 的最小的数
		int l = 1, r = len;
		// printf("l is %d, r is %d,f[mid] is: %d\n", l, r, f[1]);
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			// printf("mid is %d,f[%d]: %d\n", mid, mid, f[mid]);
			if(f[mid] < num)
			{
				// std::cout << "in l++\n";
				l = mid + 1;
			}
			else
			{
				// std::cout << "in r++\n";
				r = mid - 1;
			}
		}
		f[l] = num;
		len = std::max(len, l);
		// std::cout << "len: " << len << " l: " << l << "  i: " << i << "\n";
	}
	std::cout << len << "\n";
	return 0;
}

/*
思路：
f[i] 保存长度为 i 的单调序列的最小数字。
遍历第 j 个数，找到一个最大的小于第 j 个数的数，这个数字对应的 i，我们可以更新 f[i+1] = 第 j 个数
*/
