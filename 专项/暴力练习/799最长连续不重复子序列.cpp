/*
给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数 n。

第二行包含 n 个整数（均在 0∼10^5 范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

数据范围
1≤n≤10^5

输入样例：
5
1 2 2 3 5
输出样例：
3
*/

#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int idexs[N];
int nums[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) { cin >> nums[i]; }
	int left = 1, right = 1, max_ = 1;
	for(int i = 1; i <= n; i++)
	{
		int num = nums[i];
		if(idexs[num] != 0 && idexs[num] >= left) { left = idexs[num] + 1; }
		idexs[num] = i;
		right++;
		max_ = max(max_, right - left);
	}
	cout << max_ << "\n";
	return 0;
}
