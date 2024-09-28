#include <stdio.h>
#define N 100000

int p[N], k[10000], result_left, result_right, _index = 0;

void number_range_left(int left, int right)
{
    int mid = 0;
	while(left < right)
	{
		mid = (left + right) >> 1;
        // printf("left is: %d right is: %d _index is %d mid is %d\n",left,right,_index,mid);
		if(p[mid] >= k[_index]) { right = mid; }
		else { left = mid + 1; }
        // printf("left is: %d right is: %d _index is %d \n",left,right,_index);
	}
	if(p[left] == k[_index]) { printf("%d ", left); }
	else { printf("-1 "); }
}

void number_range_right(int left, int right)
{
	while(left < right)
	{
		int mid = (left + right + 1) >> 1;
		if(p[mid] <= k[_index]) { left = mid; }
		else { right = mid - 1; }
	}
	if(p[left] == k[_index]) { printf("%d\n", right); }
	else { printf("-1\n"); }
}

int main()
{
	int n = 0, q = 0;
	scanf("%d %d", &n, &q);
	// printf("the n,q is %d %d\n", n, q);
	for(int i = 0; i < n; i++) { scanf("%d", &p[i]); }
    // printf("read the vector\n");
	for(int i = 0; i < q; i++) { scanf("%d", &k[i]); }
    // printf("read the number\n");
	for(; _index < q; _index++)
	{
		number_range_left(0, n - 1);
		number_range_right(0, n - 1);
	}
    // printf("\n");
}