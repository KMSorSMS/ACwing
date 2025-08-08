/*
给定两个非负整数（不含前导 0）A和 B，请你计算 A×B 的值。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共一行，包含 A×B 的值。

数据范围
1≤A的长度≤100000,
0≤B≤10000

输入样例：
2
3
输出样例：
6
*/



#include <iostream>
#include <vector>

using namespace std;


vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    if(b==0){ 
        C.push_back(0);
        return;
    }

    int t = 0;
    // 或 t的条件用于处理干净进位
    for (int i = 0; i < A.size() || t; i ++ )
    {
        // 从低位到高位做乘法（保证范围在 A 位数以内），需要累加进位
        if (i < A.size()) t += A[i] * b;
        // 需要取模作为当前位的结果，同时进位取/10 的部分
        C.push_back(t % 10);
        t /= 10;
    }
    // 去除前导 0，但是最终值为 0 的不要去除
    // while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}


int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    // 因为输入的 a 是先高位后低位，但是我们需要先低位后高位，所以需要转一下存储
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    auto C = mul(A, b);
    // 输出需要先高位后低位，但是存的 C 是先低位后高位，所以同样也需要转一下
    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}
