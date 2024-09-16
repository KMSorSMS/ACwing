#include <stdio.h>
#define N 100010
int p[N], tmp[N];

void merge_sort(int left, int right) {
  if (left == right)
    return;
  int mid = (left + right) >> 1, k = 0, mid_cp = mid, left_cp = left;
  merge_sort(left, mid), merge_sort(mid + 1, right);
  mid++;
  while (left <= mid_cp && mid <= right) {
    if (p[left] < p[mid])
      tmp[k++] = p[left++];
    else
      tmp[k++] = p[mid++];
  }
  while (left <= mid_cp)
    tmp[k++] = p[left++];
  while (mid <= right)
    tmp[k++] = p[mid++];
  // copy the tmp to corresponding p
  for (int i = left_cp, j = 0; i <= right; j++, i++) {
    p[i] = tmp[j];
  }
}

int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  merge_sort(0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}