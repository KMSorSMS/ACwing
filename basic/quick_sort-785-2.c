
#include <stdio.h>
void quick_sort(int l, int r, int *p);
int main() {
  int n = 0;
  scanf("%d", &n);
  int p[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  quick_sort(0, n - 1, p);
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
// l,r start with 0
void quick_sort(int left, int right, int *p) {
  if (left == right)
    return;
  int left_cp = left, righ_cp = right;
  //   change to upper can set division to left
  int mid = p[(left + right) >> 1];
  while (1) {
    // the left is smaller
    while (p[left] < mid)
      left++;
    // the right is bigger
    while (p[right] > mid)
      right--;
    if (left >= right) {
      quick_sort(left_cp, right, p);
      quick_sort(right + 1, righ_cp, p);
      return;
    }
    // swap them
    int tmp = p[right];
    p[right--] = p[left];
    p[left++] = tmp;
  }
}