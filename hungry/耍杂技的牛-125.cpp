/*
农民约翰的 N 头奶牛（编号为 1..N）计划逃跑并加入马戏团，为此它们决定练习表演杂技。

奶牛们不是非常有创意，只提出了一个杂技表演：
叠罗汉，表演时，奶牛们站在彼此的身上，形成一个高高的垂直堆叠。
奶牛们正在试图找到自己在这个堆叠中应该所处的位置顺序。

这 N 头奶牛中的每一头都有着自己的重量 W_i 以及自己的强壮程度 S_i。
一头牛支撑不住的可能性取决于它头上所有牛的总重量（不包括它自己）减去它的身体强壮程度的值，现在称该数值为风险值，风险值越大，这只牛撑不住的可能性越高。
您的任务是确定奶牛的排序，使得所有奶牛的风险值中的最大值尽可能的小。

输入格式
第一行输入整数 N，表示奶牛数量。

接下来 N 行，每行输入两个整数，表示牛的重量和强壮程度，第 i 行表示第 i 头牛的重量 W_i 以及它的强壮程度 S_i。

输出格式
输出一个整数，表示最大风险值的最小可能值。

数据范围
1≤N≤50000,
1≤Wi≤10,000,
1≤Si≤1,000,000,000
输入样例：
3
10 3
2 5
3 3
输出样例：
2
*/

#include <algorithm>
#include <iostream>
#include <utility>
#define N 50010
typedef std::pair<int, int> pii;
pii cows[N];
int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		int w, s;
		std::cin >> w >> s;
		cows[i] = {w, s};
	}
	std::sort(cows, cows + n, [](pii a, pii b) { return a.first + a.second > b.first + b.second; });
	long max = -0x3f3f3f3f3f, weight_sum = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		int weight_i = cows[i].first, s_i = cows[i].second;
		if(weight_sum > max + s_i) { max = weight_sum - s_i; }
		weight_sum += weight_i;
	}
	std::cout << max << "\n";
    return 0;
}