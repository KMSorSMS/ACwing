/*
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。
若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y
之前，则称 A 是该图的一个拓扑序列。 输入格式 第一行包含两个整数 n 和 m。 接下来
m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。
输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
否则输出 −1。
数据范围
1≤n,m≤10^5
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

#include <iostream>
#include <queue>
#define N 100010
#define M 100010

int h[N], e[M], ne[M], eidx = 1, d[N], n, m;
std::queue<int> result;

// add edge x->y
inline void add(int x, int y) {
  e[eidx] = y, ne[eidx] = h[x], d[y]++;
  h[x] = eidx++;
}

inline void bfs() {
  std::queue<int> que_no_in_;
  // first find all the node with no input edge
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      que_no_in_.push(i), result.push(i);
    }
  }
  while (!que_no_in_.empty()) {
    int tmp_node = que_no_in_.front();
    que_no_in_.pop();
    // range its edges to update d to get new zero input node
    for (int tmp_edge = h[tmp_node]; tmp_edge != 0; tmp_edge = ne[tmp_edge]) {
      tmp_node = e[tmp_edge];
      if ((--d[tmp_node]) == 0) {
        que_no_in_.push(tmp_node), result.push(tmp_node);
      }
    }
    if (result.size() == n) {
      while (!result.empty()) {
        std::cout << result.front() << " ";
        result.pop();
      }
      std::cout << "\n";
      return;
    }
  }
  std::cout << "-1\n";
}

int main() {
  int x, y;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> x >> y;
    add(x, y);
  }
  bfs();
  return 0;
}

/*
思路：
一个有向图，如果图中有入度为 0 的点，就把这个点删掉，同时也删掉这个点所连的边。
一直进行上面出处理，如果所有点都能被删掉，则这个图可以进行拓扑排序。
*/