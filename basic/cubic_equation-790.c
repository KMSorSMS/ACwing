#include <stdio.h>

int main()
{
	double n = 0;
	scanf("%lf", &n);
	double abs_n = n < 0 ? -n : n;
	abs_n = abs_n < 1 ? 1 : abs_n;
	double left = -abs_n, right = abs_n, mid = (left + right) / 2;
	while(right - left >= 0.0000001)
	{
		if(mid * mid * mid <= n) { left = mid; }
		else { right = mid; }
		mid = (left + right) / 2;
		// printf("left is: %lf, right is: %lf\n", left, right);
	}
	printf("%.6lf\n", mid);
}