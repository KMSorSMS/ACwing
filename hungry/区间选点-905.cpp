/*
给定 N 个闭区间 [a_i,b_i]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
输出选择的点的最小数量。
位于区间端点上的点也算作区间内。
输入格式
第一行包含整数 N，表示区间数。
接下来 N 行，每行包含两个整数 a_i,b_i，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需的点的最小数量。
数据范围
1≤N≤10^5,
−10^9≤a_i≤b_i≤10^9
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
int main()
{
	std::vector<std::pair<int, int>> ranges;
	int n;
	std::cin >> n;
	while(n--)
	{
		int a, b;
		std::cin >> a >> b;
		ranges.push_back({a, b});
	}
	std::sort(ranges.begin(), ranges.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.first > b.first;
	});
	int overlap = ranges.begin()->first, count = 1;
	for(std::pair<int, int> range : ranges)
	{
		if(range.second < overlap)
		{
			overlap = range.first;
			count++;
		}
	}
	std::cout << count << "\n";
	return 0;
}
