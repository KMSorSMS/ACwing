#include <iostream>
#include <ostream>
#include <string>
#define N 100010
int l[N], r[N], e[N], idx;

inline void init()
{
	r[0] = 1, l[1] = 0, idx = 2;
}

inline void insert_k_r(int k, int x)
{
	e[idx] = x, l[idx] = k, r[idx] = r[k], l[r[k]] = idx;
	r[k] = idx++;
}

inline void remove_k(int k)
{
	r[l[k]] = r[k], l[r[k]] = l[k];
}
inline void print_link()
{
	for(int i = r[e[0]]; i != 1; i = r[i]) { std::cout << e[i] << ' '; }
}
int main()
{
	int M, k, x;
	init();
	std::string op;
	std::cin >> M;
	while(M--)
	{
		std::cin >> op;
		if(op == "L")
		{
			std::cin >> x;
			insert_k_r(0, x);
		}
		else if(op == "R")
		{
			std::cin >> x;
			insert_k_r(l[1], x);
		}
		else if(op == "D")
		{
			std::cin >> k;
			remove_k(k + 1);
		}
		else if(op == "IL")
		{
			std::cin >> k >> x;
			insert_k_r(l[k + 1], x);
		}
		else if(op == "IR")
		{
			std::cin >> k >> x;
			insert_k_r(k + 1, x);
		}
	}
	print_link();
	std::cout << std::endl;
	return 0;
}