/*
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。
输入格式共一行，包含一个整数 n。
输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7

输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

#include <iostream>
#define N 10
int n, path[N];
bool used[N];

void dfs(int u) {
  if (u > n ) {
    for (int i = 1; i <= n; i++) {
      std::cout << path[i] << " ";
    }
    std::cout << std::endl;
    return;
  }
  //   go on depth further
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      path[u] = i;
      used[i] = true;
      dfs(u + 1);
      used[i] = false;
    }
  }
}

int main() {
  std::cin >> n;
  dfs(1);
}