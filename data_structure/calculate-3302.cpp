#include <cstdio>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unordered_map>
/*
特例：
3/(1)*1
1-((1-3))*2-3

*/
#define N 100010
char OP[N];
int NUM[N];
int op_top = -1, num_top = -1;
char exp_;
std::unordered_map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}};
inline void eval()
{
	int result;
	int b = NUM[num_top--];
	int a = NUM[num_top--];
	// printf(
	// "exp is: %c,a is %d,b is %d,result is %d,sum is %d\n", exp_, a, b, result, result + a + b);
	switch(exp_)
	{
	case '+':
		result = a + b;
		// printf("a+b: %d,a: %d,b:%d\n", a + b, a, b);
		break;
	case '-':
		result = a - b;
		// printf("a-b: %d,a: %d,b:%d\n", a - b, a, b);
		break;
	case '*':
		result = a * b;
		// printf("in Mul a*b: %d,a=%d,b=%d\n", a * b, a, b);
		break;
	case '/':
		result = a / b;
		// printf("in div a/b:%d,a=%d,b=%d\n", a / b, a, b);
		break;
	}
	// printf("result is %d\n", result);
	NUM[++num_top] = result;
}
int main()
{
	int num;
	std::string s;
	std::cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		exp_ = s[i];
		// printf("01 exp is: %c\n", exp_);
		// printf("you input --%c--\n", exp_);
		if(exp_ >= '0' && exp_ <= '9')
		{
			num = 0;
			while(exp_ >= '0' && exp_ <= '9')
			{
				// printf("exp is: %c\n", exp_);
				num = 10 * num + exp_ - '0';
				// printf("num is:%d\n", num);
				// scanf("%c", &exp_);
				exp_ = s[++i];
				// printf("02 exp is: %c\n", exp_);
			}
			NUM[++num_top] = num;
			i = i - 1;
		}
		else if(exp_ == '(')
		{
			// 比较特殊，直接入栈
			OP[++op_top] = exp_;
		}
		else if(exp_ == ')')
		{
			// 特殊，需要一直算到左括号
			exp_ = OP[op_top];
			while(exp_ != '(')
			{
				// printf("debug op is: %c\n", exp_);
				exp_ = OP[op_top--];
				eval();
				exp_ = OP[op_top];
			}
			// 去掉左括号
			op_top--;
		}
		else if(exp_ == '\n' || exp_ == '\0')
		{

			while(op_top >= 0)
			{
				// printf("op top is %d\n", op_top);
				exp_ = OP[op_top--];
				eval();
				// printf("after eval op top is:%d\n", op_top);
			}
			// printf("in break\n");
			break;
		}
		else
		{
			char tmp = exp_;
			// printf("op top in nums is :%d and op is:%c\n", op_top, exp_);
			while(op_top >= 0 && h[exp_] <= h[OP[op_top]])
			{
				exp_ = OP[op_top--];
				// printf("in op: %c\n",exp_);
				eval();
				exp_ = tmp;
			}
			// printf("fin\n");
			OP[++op_top] = tmp;
		}
	}
	while(op_top >= 0)
	{
		// printf("op top is %d\n", op_top);
		exp_ = OP[op_top--];
		eval();
		// printf("after eval op top is:%d\n", op_top);
	}
	printf("%d\n", NUM[num_top]);
}