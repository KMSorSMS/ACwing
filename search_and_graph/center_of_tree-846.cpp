/*
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。
接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。
输出格式
输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。
数据范围
1≤n≤10^5
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
*/

// #include <cstdio>
#include <iostream>
#include <ostream>

#define N 100010
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
// 用邻接表存储图，参考：
// https://www.acwing.com/blog/content/4663/
// h是树节点的链表头结点，e是记录对应边的终点，ne是链表，记录下一条边的索引
int h[N], e[2 * N], ne[2 * N], n, eidx = 1, result = N;
bool added[N];

// insert a->b
inline void add(int a, int b) {
  e[eidx] = b, ne[eidx] = h[a];
  h[a] = eidx++;
}

// dfs搜索，返回start所属的子连通图的节点个数
int dfs(int start) {
  added[start] = true;
  int total_sum = 1, sub_max = 0, node_, sub_sum;
  for (int edge_ = h[start]; edge_ != 0; edge_ = ne[edge_]) {
    node_ = e[edge_];
    if (!added[node_]) {
      sub_sum = dfs(node_);
      total_sum += sub_sum, sub_max = MAX(sub_sum, sub_max);
    }
  }
  sub_max = MAX(sub_max, n - total_sum);
  result = MIN(sub_max, result);
  added[start] = false;
  return total_sum;
}

int main() {
  // 接收参数，建立树
  int node1, node2;
  std::cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    std::cin >> node1 >> node2;
    add(node1, node2), add(node2, node1);
  }
//   printf("fin input\n");
  dfs(1);
  std::cout << result << std::endl;
  return 0;
}

/*
思路：
基于dfs的图遍历，在向更深处查找的时候，让dfs有返回值，返回子树的节点数量
*/