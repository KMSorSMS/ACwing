/*
给定 N 个闭区间 [a_i,b_i]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。
输入格式
第一行包含整数 N，表示区间数。
接下来 N 行，每行包含两个整数 a_i,b_i，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

数据范围
1≤N≤10^5,−10^9≤a_i≤b_i≤10^9

输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/
#include <algorithm>
// #include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
typedef std::pair<int, int> pii;

int main()
{
	int n;
	std::vector<pii> ranges;
	std::cin >> n;
	while(n--)
	{
		int a, b;
		std::cin >> a >> b;
		ranges.push_back({a, b});
	}
	std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.second > b.second; });
	std::priority_queue<int, std::vector<int>> left_max;
	left_max.push(ranges.begin()->second + 1);

	// printf("the new begin is: %d\n", ranges.begin()->first);
	for(auto range = ranges.begin(); range != ranges.end(); range++)
	{
		if(range->second < left_max.top())
		{
			left_max.pop();
			left_max.push(range->first);
		}
		else { left_max.push(range->first); }
	}
	std::cout << left_max.size() << "\n";
	return 0;
}