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
	int count = 0;
	while(!ranges.empty())
	{
		std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.first > b.first; });
		count++;
		int left = ranges.begin()->first;
		// printf("left is: %d\n", left);
		ranges.erase(ranges.begin());
		std::sort(ranges.begin(), ranges.end(), [](pii a, pii b) { return a.first > b.first; });

		// printf("the new begin is: %d\n", ranges.begin()->first);
		for(auto range = ranges.begin(); range != ranges.end();)
		{

			if(range->second < left)
			{
				left = range->first;
				// printf("the new left is %d\n", left);
				range = ranges.erase(range);
			}
			else { range++; }
		}
	}
	std::cout << count << "\n";
	return 0;
}