#include <iostream>
#include <ostream>
#define N 100010

int NUM[N], stack[N], top = 0;

int main()
{
	stack[0] = -1;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) { std::cin >> NUM[i]; }
	for(int i = 0; i < n; i++)
	{
		while(stack[top] >= NUM[i]) { top--; }
		std::cout << stack[top] << ' ';
		stack[++top] = NUM[i];
	}
	std::cout << std::endl;
}