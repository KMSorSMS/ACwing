#include <iostream>
#define N 100010
int nums[N], ptr_nums[N];

int main()
{
	int n = 0;
	std::cin >> n;
	for(int i = 1; i <= n; i++) { std::cin >> nums[i]; }
	int count = 0;
	int left = 1, right = 1;
	while(right <= n)
	{
		// check if duplicated
		if(ptr_nums[nums[right]] != 0 && left <= ptr_nums[nums[right]])
		{
			// we move the left to make it no repeat
			left = ptr_nums[nums[right]] + 1;
		}
		// here we register the new number
		ptr_nums[nums[right]] = right;
		right++;
		// update the count if larger
		if(right - left > count) { count = right - left; }
	}
	std::cout << count << std::endl;
	return 0;
}