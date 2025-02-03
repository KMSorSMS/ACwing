#include <iostream>

#define N 100010
int a[N], b[N];

int main()
{
	int n = 0, m = 0;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) { std::cin >> a[i]; }
	for(int j = 1; j <= m; j++) { std::cin >> b[j]; }
	int index_a = 1, index_b = 1;
	bool is_sub = false;
	while(index_a <= n && index_b <= m)
	{
		if(a[index_a] == b[index_b])
		{
			index_a++;
			if(index_a > n)
			{
				is_sub = true;
				break;
			}
		}
		index_b++;
	}
	if(is_sub)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	return 0;
}