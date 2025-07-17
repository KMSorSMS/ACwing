/*
给定一个整数序列，其中包含 n 个非负整数，其中的每个整数都恰好有 m 位，从最低位到最高位，依次编号为 1∼m 位。
现在，请你统计该序列各个位的众数。

第 i 位的众数是指，在给定的 n 个整数的第 i 位上，出现次数最多的最小数字。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个非负整数，表示给定的整数序列。

输出格式
共 m 行，第 i 行输出第 i 位的众数。

数据范围
1≤n≤10^5,
1≤m≤6

输入样例：
3 2
31 32 30
输出样例：
0
3
*/

#define M 7
#define NUM 11
#include <iostream>
int count_num[M][NUM];
int max_[M], max_idx_[M];
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int number;
		cin >> number;
		for(int j = 1; j <= m; j++)
		{
			int bit = number % 10;
			number /= 10;
			count_num[j][bit]++;
			if(max_[j] < count_num[j][bit] || (max_[j] == count_num[j][bit] && bit < max_idx_[j]))
			{
				max_[j] = count_num[j][bit], max_idx_[j] = bit;
			}
		}
	}
	for(int j = 1; j <= m; j++) { cout << max_idx_[j] << "\n"; }
	return 0;
}