/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。
所有边的长度都是 1，点的编号为 1∼n。
请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。
输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
数据范围
1≤n,m≤10^5
输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/

#include <iostream>
#include <ostream>
#include <queue>
#define N 100010
#define M 100010

int m, n, h[N], e[2 * M], ne[2 * M], eidx = 1, d[N];
bool added[N];
// insert a->b to graph
inline void add(int a, int b) {
  e[eidx] = b, ne[eidx] = h[a];
  h[a] = eidx++;
}

int bfs(int start) {
  std::queue<int> que;
  int tmp_node, d_old;
  que.push(start);
  d[start] = 0;
  added[start] = true;
  while (!que.empty()) {
    tmp_node = que.front();
    que.pop();
    d_old = d[tmp_node];
    if (tmp_node == n)
      return d_old;
    for (int edge_ = h[tmp_node]; edge_ != 0; edge_ = ne[edge_]) {
      tmp_node = e[edge_];
      if (!added[tmp_node]) {
        d[tmp_node] = d_old + 1;
        que.push(tmp_node);
        added[tmp_node] = true;
      }
    }
  }
  return -1;
}

int main() {
  int a, b;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> a >> b;
    add(a, b);
  }
  std::cout << bfs(1) << std::endl;
  return 0;
}