/*
给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

string input_str;
stack<char> ops;
stack<int> nums;
unordered_map<char, int> prio = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(',0}};
/*
9-5*7+6
注意这个例子，左结合规则很重要
*/
void eval()
{
	int num2 = nums.top();
	nums.pop();
	int num1 = nums.top();
	nums.pop();
	char op = ops.top();
	ops.pop();
	if(op == '+') { nums.push(num1 + num2); }
	else if(op == '-') { nums.push(num1 - num2); }
	else if(op == '*') { nums.push(num1 * num2); }
	else if(op == '/') { nums.push(num1 / num2); }
}

int main()
{
	cin >> input_str;
	for(int i = 0; i < input_str.size(); i++)
	{
		char in = input_str[i];
		if(in >= '0' && in <= '9')
		{
			int num = 0;
			while(in >= '0' && in <= '9')
			{
				num = num * 10 + in - '0';
				in = input_str[++i];
			}
			nums.push(num);
			// printf("push num :%d\n", num);
			// if(i >= input_str.size()) break;
            i--;
		}
		// printf("check op:%c\n", in);
		else if(in == ')')
		{
			while(ops.top() != '(') { eval(); }
			ops.pop();
		}
		else if(in == '(') { ops.push(in); }
		else if(in < '0' || in > '9')
		{
			char op = in;
			// printf("perform add op %c\n", op);
			while(!ops.empty() && prio[op] <= prio[ops.top()]) { eval(); }
			ops.push(op);
		}
	}
	// printf("out for\n");
	while(!ops.empty()) eval();
	cout << nums.top() << "\n";
}

/*
这里的含义是：

（1）如果栈顶是+，即将入栈的是+，栈顶优先级高，需要先计算，再入栈；

（2）如果栈顶是+，即将入栈的是*，栈顶优先级低，直接入栈；

（3）如果栈顶是*，即将入栈的是+，栈顶优先级高，需要先计算，再入栈；

（4）如果栈顶是*，即将入栈的是*，栈顶优先级高，需要先计算，再入栈；
*/