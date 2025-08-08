/*
乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过 50 个长度单位。
然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。
请你设计一个程序，帮助乔治计算木棒的可能最小长度。
每一节木棍的长度都用大于零的整数表示。
输入格式
输入包含多组数据，每组数据包括两行。
第一行是一个不超过 64 的整数，表示砍断之后共有多少节木棍。
第二行是截断以后，所得到的各节木棍的长度。
在最后一组数据之后，是一个零。
输出格式
为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。
数据范围
数据保证每一节木棍的长度均不大于 50。

输入样例：
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0
输出样例：
6
5
*/
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 65;
int n;
int w_pitch[N], len,sum;
bool st[N];

bool dfs(int start,int cur,int num_pitch){
    if(num_pitch * len == sum) return true;
    if(cur == len) return dfs(1,0,num_pitch+1);
    for(int i=start;i<=n;i++){
        if(w_pitch[i] + cur > len || st[i]) continue;
        st[i] = true;
        if(dfs(i+1,cur+w_pitch[i],num_pitch)) {
            st[i] = false;
            return true;
        }
        st[i] = false;
        if(cur==0 || cur+w_pitch[i]==len) return false;
        int j;
        for(j=i;w_pitch[i]==w_pitch[j];j++){}
        i = j-1;
    }
    return false;
}

int main()
{
	while(true) { 
        cin >> n; 
        if(n==0) break;
        sum = 0;
        for(int i=1;i<=n;i++){
            cin >> w_pitch[i];
            sum += w_pitch[i];
        }
        sort(w_pitch+1,w_pitch+n+1,[](int a,int b){return a>b;});
        for(len=w_pitch[1];len <= sum;len++){
            if(sum%len==0){
                if(dfs(1,0,0)){
                    cout << len << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

/*
优化搜索顺序：尽可能选深度短的分支
排除冗余方案：每一根长木棍内部的小木棍编号从小到大，因为方案的时候不考虑顺序，不考虑排列
可行性剪枝：
当前匹配失败后，跳过与当前木棍长度相等的其他木棍
第i 个未被使用的木棍，若作为新木棍的第一根无解，则回溯
若当前小木棍加上后，刚好是一根，但是后面无解了，则回溯
*/
