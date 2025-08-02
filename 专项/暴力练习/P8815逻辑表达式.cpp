/*
# P8815 [CSP-J 2022] 逻辑表达式
## 题目描述
逻辑表达式是计算机科学中的重要概念和工具，包含逻辑值、逻辑运算、逻辑运算优先级等内容。

在一个逻辑表达式中，元素的值只有两种可能：$0$（表示假）和 $1$（表示真）。元素之间有多种可能的逻辑运算，本题中只需考虑如下两种：“与”（符号为 `&`）和“或”（符号为 `|`）。其运算规则如下：

$0 \mathbin{\&} 0 = 0 \mathbin{\&} 1 = 1 \mathbin{\&} 0 = 0$，$1 \mathbin{\&} 1 = 1$；  
$0 \mathbin{|} 0 = 0$，$0 \mathbin{|} 1 = 1 \mathbin{|} 0 = 1 \mathbin{|} 1 = 1$。

在一个逻辑表达式中还可能有括号。规定在运算时，括号内的部分先运算；两种运算并列时，`&` 运算优先于 `|` 运算；同种运算并列时，从左向右运算。

比如，表达式 `0|1&0` 的运算顺序等同于 `0|(1&0)`；表达式 `0&1&0|1` 的运算顺序等同于 `((0&1)&0)|1`。

此外，在 C++ 等语言的有些编译器中，对逻辑表达式的计算会采用一种“短路”的策略：在形如 `a&b` 的逻辑表达式中，会先计算 `a` 部分的值，如果 $a = 0$，那么整个逻辑表达式的值就一定为 $0$，故无需再计算 `b` 部分的值；同理，在形如 `a|b` 的逻辑表达式中，会先计算 `a` 部分的值，如果 $a = 1$，那么整个逻辑表达式的值就一定为 $1$，无需再计算 `b` 部分的值。

现在给你一个逻辑表达式，你需要计算出它的值，并且统计出在计算过程中，两种类型的“短路”各出现了多少次。需要注意的是，如果某处“短路”包含在更外层被“短路”的部分内则不被统计，如表达式 `1|(0&1)` 中，尽管 `0&1` 是一处“短路”，但由于外层的 `1|(0&1)` 本身就是一处“短路”，无需再计算 `0&1` 部分的值，因此不应当把这里的 `0&1` 计入一处“短路”。

## 输入格式

输入共一行，一个非空字符串 $s$ 表示待计算的逻辑表达式。

## 输出格式

输出共两行，第一行输出一个字符 `0` 或 `1`，表示这个逻辑表达式的值；第二行输出两个非负整数，分别表示计算上述逻辑表达式的过程中，形如 `a&b` 和 `a|b` 的“短路”各出现了多少次。

## 输入输出样例 #1

### 输入 #1

```
0&(1|0)|(1|1|1&0)
```

### 输出 #1

```
1
1 2
```

## 输入输出样例 #2

### 输入 #2

```
(0|1&0|1|1|(1|1))&(0&1&(1|0)|0|1|0)&0
```

### 输出 #2

```
0
2 3
```

## 说明/提示

**【样例解释 \#1】**

该逻辑表达式的计算过程如下，每一行的注释表示上一行计算的过程：

```plain
0&(1|0)|(1|1|1&0)
=(0&(1|0))|((1|1)|(1&0)) //用括号标明计算顺序
=0|((1|1)|(1&0))   //先计算最左侧的 &，是一次形如 a&b 的“短路”
=0|(1|(1&0))       //再计算中间的 |，是一次形如 a|b 的“短路”
=0|1               //再计算中间的 |，是一次形如 a|b 的“短路”
=1
```

**【样例 \#3】**

见附件中的 `expr/expr3.in` 与 `expr/expr3.ans`。

**【样例 \#4】**

见附件中的 `expr/expr4.in` 与 `expr/expr4.ans`。

**【数据范围】**

设 $\lvert s \rvert$ 为字符串 $s$ 的长度。

对于所有数据，$1 \le \lvert s \rvert \le {10}^6$。保证 $s$ 中仅含有字符 `0`、`1`、`&`、`|`、`(`、`)` 且是一个符合规范的逻辑表达式。保证输入字符串的开头、中间和结尾均无额外的空格。保证 $s$ 中没有重复的括号嵌套（即没有形如 `((a))` 形式的子串，其中 `a` 是符合规范的逻辑表达式）。

| 测试点编号 | $\lvert s \rvert \le$ | 特殊条件 |
|:-:|:-:|:-:|
| $1 \sim 2$ | $3$ | 无 |
| $3 \sim 4$ | $5$ | 无 |
| $5$ | $2000$ | 1 |
| $6$ | $2000$ | 2 |
| $7$ | $2000$ | 3 |
| $8 \sim 10$ | $2000$ | 无 |
| $11 \sim 12$ | ${10}^6$ | 1 |
| $13 \sim 14$ | ${10}^6$ | 2 |
| $15 \sim 17$ | ${10}^6$ | 3 |
| $18 \sim 20$ | ${10}^6$ | 无 |

其中：  
特殊性质 1 为：保证 $s$ 中没有字符 `&`。  
特殊性质 2 为：保证 $s$ 中没有字符 `|`。  
特殊性质 3 为：保证 $s$ 中没有字符 `(` 和 `)`。

**【提示】**

以下给出一个“符合规范的逻辑表达式”的形式化定义：

- 字符串 `0` 和 `1` 是符合规范的；
- 如果字符串 `s` 是符合规范的，且 `s` 不是形如 `(t)` 的字符串（其中 `t` 是符合规范的），那么字符串 `(s)` 也是符合规范的；
- 如果字符串 `a` 和 `b` 均是符合规范的，那么字符串 `a&b`、`a|b` 均是符合规范的；
- 所有符合规范的逻辑表达式均可由以上方法生成。
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
string input_str;
stack<char> ops;
stack<int> nums;

int process_str(int start)
{
	int i = start;
	for(;; i++)
	{
		char input = input_str[i];
		if(input == '&' || input == '|' || input == '(' || input == ')')
		{
			// 如果不存在短路，逻辑运算可以直接算只要前面的运算符优先级更高，这里就只可能是|，算到栈空或者到左扩号
			if(input == '|')
			{
				while(!ops.empty() && ops.top() != '(' && ops.top() == '&')
				{
					// printf("in while\n");
					char op = ops.top();
					ops.pop();
					int num1 = nums.top();
					nums.pop();
					int num2 = nums.top();
					nums.pop();
					printf("perform cal in | process:%d,%d\n", num1, num2);
					nums.push(num1 & num2);
				}
				// printf("need to push op\n");
				ops.push(input);
			}
			// 如果是右括号的情况就计算到左括号
			else if(input == ')')
			{
				while(ops.top() != '(')
				{
					char op = ops.top();
					ops.pop();
					int num1 = nums.top();
					nums.pop();
					int num2 = nums.top();
					nums.pop();
					if(op == '&') { nums.push(num1 & num2); }
					else { nums.push(num1 | num2); }
				}
				ops.pop();
				break;
			}
			else if(input == '(')
			{
				// 如果是左括号，就把递归去计算
				ops.push(input);
				i = process_str(i);
			}
			// 与运算的情况
			else { ops.push(input); }
		}
		else { nums.push(input - '0'); }
	}

	while(!ops.empty() && ops.top() != '(')
	{
		char op = ops.top();
		ops.pop();
		int num1 = nums.top();
		nums.pop();
		int num2 = nums.top();
		nums.pop();
		if(op == '&') { nums.push(num1 & num2); }
		else { nums.push(num1 | num2); }
	}

	return i;
}

int main()
{
	cin >> input_str;
	int result = 0, count_and_ = 0, count_or_ = 0, step;
	for(int i = 0; i < input_str.size(); i += step)
	{
		step = 1;
		char input = input_str[i];
		printf("add %c,i:%d\n", input, i);
		if(input == '&' || input == '|' || input == '(' || input == ')')
		{
			// printf("in op\n");
			// 检查是否有0& 或者 1｜
			if(input == '&' && nums.top() == 0)
			{
				int j = i;
				count_and_++, j++;
				//判断剩下的，主要是分成括号和单个数
				int count_cycle = 0;
				char input_tmp = input_str[j];
				if(input_tmp == '(')
				{
					ops.push(input_tmp);
					step = process_str(j + 1) + 1 - i;
					printf("process %c,i:%d\n", input, i);
					count_cycle = 1;
					while(count_cycle != 0)
					{
						input_tmp = input_str[++j];
						if(input_tmp == ')')
							count_cycle--;
						else if(input_tmp == '(')
							count_cycle++;
					}
				}
				printf("fin check &\n");
			}
			else if(input == '|' && nums.top() == 1)
			{
				int j = i;
				count_or_++, j++;
				int count_cycle = 0;
				char input_tmp = input_str[j];
				if(input_tmp == '(')
				{
					ops.push(input_tmp);
					step = process_str(j + 1) + 1 - i;
					count_cycle = 1;
					while(count_cycle != 0)
					{
						input_tmp = input_str[++j];
						if(input_tmp == ')')
							count_cycle--;
						else if(input_tmp == '(')
							count_cycle++;
					}
				}
			}
			// 如果不存在短路，逻辑运算可以直接算只要前面的运算符优先级更高，这里就只可能是|，算到栈空或者到左扩号
			if(input == '|')
			{
				// cout << ops.empty() << "\n";
				printf("no shortcut\n");
				while(!ops.empty() && ops.top() != '(' && ops.top() == '&')
				{
					// printf("in while\n");
					char op = ops.top();
					ops.pop();
					int num1 = nums.top();
					nums.pop();
					int num2 = nums.top();
					nums.pop();
					printf("perform cal in |:%d,%d\n", num1, num2);
					nums.push(num1 & num2);
				}
				printf("need to push op\n");
				ops.push(input);
			}
			// 如果是右括号的情况就计算到左括号
			else if(input == ')')
			{
				while(ops.top() != '(')
				{
					char op = ops.top();
					ops.pop();
					int num1 = nums.top();
					nums.pop();
					int num2 = nums.top();
					nums.pop();
					if(op == '&') { nums.push(num1 & num2); }
					else { nums.push(num1 | num2); }
				}
				ops.pop();
			}
			// 左括号以及与运算的情况
			else
			{
				ops.push(input);
				printf("add op\n");
			}
		}
		else { nums.push(input - '0'); }
	}
	while(!ops.empty() && ops.top() != '(')
	{
		char op = ops.top();
		ops.pop();
		int num1 = nums.top();
		nums.pop();
		int num2 = nums.top();
		nums.pop();
		printf("perform cal outter:%d,%d\n", num1, num2);
		if(op == '&') { nums.push(num1 & num2); }
		else { nums.push(num1 | num2); }
	}
	cout << nums.top() << "\n";
	cout << count_and_ << " " << count_or_ << "\n";
	return 0;
}