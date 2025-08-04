#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 10, M = 1e5 + 10;
int h[N], e[M], ne[M];
int idx = 1, n;
int tasks[N];
int w[N];
int idx_task = 1;

void add_edge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		int fa;
		cin >> fa;
		add_edge(fa, i);
	}
	for(int i = 1; i <= n; i++) { cin >> tasks[i]; }
	for(int i = 1; i <= n; i++) { cin >> w[i]; }
	sort(w + 2, w + n + 1), sort(tasks + 1, tasks + n + 1);
	int max_ = max(tasks[n] - w[1], 0);
	// printf("max: %d,task:%d,w:%d\n", max_, tasks[n], w[1]);
	if(max_ == 0)
	{
		int best1_w = 0, task1_ = 0;
		for(int i = 1; i <= n - 1; i++)
		{
			if(tasks[i] - w[i + 1] > 0)
			{
				best1_w = best1_w == 0 ? w[i + 1] : best1_w;
				task1_ = tasks[i];
			}
		}
		// printf("best1_w:%d,task1_:%d\n", best1_w, task1_);
		max_ = task1_ - best1_w;
	}
	// printf("max1:%d,max2:%d\n", max1_, max2_);
	cout << max_ << "\n";
}
/*
6
1 1 1 1 1
1 2 3 4 5 6
4 1 3 3 5 1

5 
1 1 1 1
100 1 4 5 10
100 2 3 6 8

5 
1 1 1 1
100 1 4 5 8
100 2 3 6 8

5 
1 1 1 1
100 1 4 7 8
100 2 3 6 8

*/