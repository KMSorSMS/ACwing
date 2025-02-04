#include <stdio.h>

#define N 100010

int p[N], tmp[N];
unsigned long count = 0;

void merge_sort_2(int left, int right)
{
	if(left == right) return;
	int mid = (left + right) >> 1, mid_cp = mid, left_cp = left;
	merge_sort_2(left, mid), merge_sort_2(mid + 1, right);
	// 我们需要left-mid插入到mid+1-right这个区间里面，并且记录逆序个数
	int k = 0;
	unsigned long local_count = 0;
	mid++;
	while(left <= mid_cp && mid <= right)
	{
		if(p[left] <= p[mid])
		{
			tmp[k++] = p[left++];
			count += local_count;
		}
		else
		{
			tmp[k++] = p[mid++];
			local_count++;
		}
	}
	while(left <= mid_cp)
	{
		tmp[k++] = p[left++];
		count += local_count;
	}
	while(mid <= right) tmp[k++] = p[mid++];
	// 为了排序，将tmp内容copy
	for(int l = left_cp, j = 0; l <= right; l++, j++) { p[l] = tmp[j]; }
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) { scanf("%d", &p[i]); }
	merge_sort_2(0, n - 1);
	// 打印答案
	printf("%ld\n", count);
	// for(int i = 0; i < n; i++) printf("%d ", p[i]);
	// printf("\n");
}