#include <stdio.h>
void quick_sort(int left, int right, int* p, int k);
int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	int p[n];
	for(int i = 0; i < n; i++) { scanf("%d", &(p[i])); }
	quick_sort(0, n - 1, p, k);
	//   print result
	printf("%d \n", p[k - 1]);
}

void quick_sort(int left, int right, int* p, int k)
{
	if(left == right) return;
	int left_cp = left, right_cp = right;
	int standard = p[(left + right) >> 1];
	while(1)
	{
		while(p[left] < standard) left++;
		while(p[right] > standard) right--;
		if(left >= right)
		{
			if(right >= k - 1)
				quick_sort(left_cp, right, p, k);
			else
				quick_sort(right + 1, right_cp, p, k);
			return;
		}
		int tmp = p[right];
		p[right--] = p[left];
		p[left++] = tmp;
	}
}