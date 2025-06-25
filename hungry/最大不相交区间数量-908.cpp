/*
给定 N 个闭区间 [a_i,b_i]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。
输出可选取区间的最大数量。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 a_i,b_i，表示一个区间的两个端点。

输出格式
输出一个整数，表示可选取区间的最大数量。

数据范围
1≤N≤105,−10^9≤a_i≤b_i≤10^9

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
typedef std::pair<int, int> pii;
int main()
{
	std::vector<pii> ranges;
	int n;
	std::cin >> n;
	ranges.resize(n);
	while(n--)
	{
		int a, b;
		std::cin >> a >> b;
		ranges[n] = {a, b};
		// ranges.push_back({a, b});
	}
	std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.first > b.first; });
	int count = 1, left = ranges.begin()->first;
	for(pii range : ranges)
	{
		if(range.second < left) { left = range.first, count++; }
	}
	std::cout << count << "\n";
	return 0;
}