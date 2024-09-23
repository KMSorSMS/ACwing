#include <stdio.h>

void quick_sort(int* p, int n);
int main()
{
	int n = 0;
	scanf("%d\n", &n);
	// get input numbers
	if(n == 0) { return 0; }
	int p[n];
	// loop to assign value
	for(int i = 0; i < n; i++) { scanf("%d", &p[i]); }
	// start to quick sort
	// set leftmost as standard, the smaller or equal on left, bigger on right
	quick_sort(p, n);
	// print the result
	for(int i = 0; i < n; i++) { printf("%d ", p[i]); }
	printf("\n");
}

void quick_sort(int* p, int n)
{
	// the recursive return condition
	if(n <= 1) return;
	int left = 0, right = n - 1, standard_point = (left + right) / 2, standard = p[standard_point];
	while(1)
	{
		while(left < right && p[left] < standard) left++;
		// then the left is the left most that larger than standard
		while(right >= left && p[right] > standard) right--;
		// then the right is the right most that less than or equal to standard
		// judge if already sort
		if(left >= right)
		{
			// this means one process finish
			// change the standard to the mid
			quick_sort(&(p[0]), right + 1);
			quick_sort(&(p[right + 1]), n - right - 1);
			return;
		}
		//   swap value
		int tmp = p[right];
		p[right--] = p[left];
		p[left++] = tmp;
	}
}