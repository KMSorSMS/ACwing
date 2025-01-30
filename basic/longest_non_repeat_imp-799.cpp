#include <algorithm>
#include <iostream>
#include <unordered_map>
#define N 100010
int nums[N];

int main()
{
	int n = 0;
	std::cin >> n;
	for(int i = 1; i <= n; i++) { std::cin >> nums[i]; }
	std::unordered_map<int, int> register_;
	int left = 1, right = 1, count = 0;
	while(right <= n)
	{
		// if duplicated
		auto it = register_.find(nums[right]);
		if(it != register_.end())
		{
			// update left to remove repeat
			left = std::max(it->second + 1, left);
		}
		// register right
		register_[nums[right]] = right;
		// right ptr go to the next
		right++;
		count = std::max(right - left, count);
	}
	std::cout << count << std::endl;
	return 0;
}