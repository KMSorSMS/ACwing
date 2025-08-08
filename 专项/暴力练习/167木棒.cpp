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
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=65;
int pitch[N],w_pitch[N];
int n,min_pitch=0x3f3f3f3f;

void dfs(int depth,int pack){
    if(pack >= min_pitch) return;
    if(depth > n) {
        // printf("pack:%d,depth:%d,n:%d\n",pack,depth,n);
        min_pitch = pack;return;
    }
    for(int i=1;i<=pack;i++){
        if(w_pitch[i] >= pitch[depth]){
            w_pitch[i] -= pitch[depth];
            dfs(depth+1,pack);
            w_pitch[i] += pitch[depth];
        }
    }
    w_pitch[pack+1] -= pitch[depth];
    dfs(depth+1,pack+1);
    w_pitch[pack+1] += pitch[depth];
}

int main(){
    while(true){
        cin >> n;
        if(n==0) break;
        int sum = 0;
        for(int i=1;i<=n;i++){
            cin >> pitch[i];
            sum += pitch[i];
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",pitch[i]);
        // }
        // printf("\n");
        sort(pitch+1,pitch+n+1,[](int a,int b) {
            return a>b;
        });
        // for(int i=1;i<=n;i++){
        //     printf("%d ",pitch[i]);
        // }
        // printf("\n");
        // printf("n=%d!!!\n",n);

        int start_pack = pitch[1];
        while(true){
            if(sum % start_pack == 0){
                // printf("in while n=%d!!!\n",n);
                min_pitch=0x3f3f3f3f;
                // printf("before loop n=%d!!!\n",n);
                for(int i=1;i<=n;i++){
                    // printf("in loop n=%d!!!\n",n);
                    w_pitch[i] = start_pack;
                }
                // printf("n=%d!!!\n",n);
                dfs(1,1);
                // printf("pack_size:%d,min_pitch:%d,sum:%d,n:%d\n",start_pack,min_pitch,sum,n);
                if(min_pitch == sum/start_pack){
                    cout << start_pack << "\n";
                    break;
                }
            }
            start_pack++;
        }
    }
    return 0;
}


/*
优化搜索顺序：尽可能选深度短的分支
排除冗余方案：每一根长木棍内部的小木棍编号从小到大，因为方案的时候不考虑顺序，不考虑排列
可行性剪枝：
当前匹配失败后，跳过与当前木棍长度相等的其他木棍
第i 个未被使用的木棍，若作为新木棍的第一根无解，则无解
若当前小木棍加上后，刚好是一根，但是后面无解了，则无解
*/
