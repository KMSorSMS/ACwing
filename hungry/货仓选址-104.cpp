/*
在一条数轴上有 N 家商店，它们的坐标分别为 A_1∼A_N。
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入格式
第一行输入整数 N。

第二行 N 个整数 A_1∼A_N。

输出格式
输出一个整数，表示距离之和的最小值。

数据范围
1≤N≤100000,
0≤Ai≤40000

输入样例：
4
6 2 9 1
输出样例：
12
*/

#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
	std::vector<int> stores;
	int n;
	std::cin >> n;
	int index = n / 2;
	stores.resize(n);
	for(int i=0;i<n;i++)
	{
		int a;
		std::cin >> a;
		stores[i] = a;
	}
	std::sort(stores.begin(), stores.end(), [](int a, int b) { return a < b; });
    int count = 0;
    for(int i=0;i<index;i++){
        count += stores[index] - stores[i];
    }
    for(int i=index+1;i<n;i++){
        count += stores[i] - stores[index];
    }
    std::cout << count << "\n";

}
