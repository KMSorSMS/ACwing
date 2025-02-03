#include <iostream>

#define N 100010
int nums[N];

int main()
{
	int n = 0, count = 0;
	std::cin >> n;
	for(int i = 0; i < n; i++) { std::cin >> nums[i]; }
	for(int i = 0; i < n; i++)
	{
		count = 0;
		while(nums[i] != 0) nums[i] = nums[i] - (nums[i] & (-nums[i])), count++;
		std::cout << count << ' ';
	}
	std::cout << std::endl;
	return 0;
}