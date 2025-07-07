/*
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
======
4

*/

#include <iostream>
#define N 210 * 210
int a[N];

inline void init(int n)
{
	for(int i = 1; i <= n * n; i++) { a[i] = i; }
}

int find(int node)
{
	int finded = node;
	if(a[node] != node) { finded = find(a[node]); }
	a[node] = finded;
	return finded;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	init(n);
	bool finded = false;
	int count = 0;
	while(m--)
	{
		int x, y;
		char op;
		std::cin >> x >> y >> op;
		if(!finded)
		{
			count++;
			int idx2 = op == 'D' ? x * n + y : (x - 1) * n + y + 1;
			int idx1 = (x - 1) * n + y;
			int class1 = find(idx1);
			int class2 = find(idx2);
			if(class1 != class2) { a[class1] = a[class2]; }
			else { finded = true; }
		}
	}
	if(finded) { std::cout << count << "\n"; }
	else { std::cout << "draw\n"; }
	return 0;
}