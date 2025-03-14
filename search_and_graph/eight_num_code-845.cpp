/*
在一个 3×3 的网格中，1∼8这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3的网格中。
例如：
1 2 3
x 4 6
7 5 8
在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。
我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：
1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让 x
先后与右、下、右三个方向的数字交换成功得到正确排列。 交换过程如下：

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。
输入格式
输入占一行，将 3×3 的初始网格描绘出来。

例如，如果初始网格如下所示：
1 2 3
x 4 6
7 5 8
则输入为：1 2 3 x 4 6 7 5 8
输出格式
输出占一行，包含一个整数，表示最少交换次数。
如果不存在解决方案，则输出 −1。
输入样例：
2 3 4 1 5 x 7 6 8
输出样例
19
*/

#include <cstdio>
#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
std::string start;
std::string end = "12345678x";
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs() {
  std::queue<std::string> que;
  std::string tmp;
  std::unordered_map<std::string, int> d;
  int tmp_index, x, y, tmp_d, x_old, y_old;
  d[start] = 0;
  que.push(start);
  while (!que.empty()) {
    tmp = que.front();
    que.pop();
    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     printf("%c ", start[i * 3 + j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");
    if (tmp == end)
      return d[tmp];
    tmp_index = tmp.find('x');
    x_old = x = tmp_index / 3, y_old = y = tmp_index % 3, tmp_d = d[tmp];
    for (int i = 0; i < 4; i++) {
      x += dir[i][0], y += dir[i][1];
      if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        std::swap(tmp[tmp_index], tmp[x * 3 + y]);
        if (d.find(tmp) == d.end()) {
          que.push(tmp), d[tmp] = tmp_d + 1;
        }
        std::swap(tmp[tmp_index], tmp[x * 3 + y]);
      }
      x = x_old, y = y_old;
    }
  }
  return -1;
}

int main() {
  char c;
  for (int i = 0; i < 9; i++) {
    std::cin >> c;
    start += c;
  }
  //   printf("after input\n");
  //   printf("str is: %s\n", start.c_str());
  std::cout << bfs() << std::endl;
}