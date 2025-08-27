/*
有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。
给出每个人的孩子的信息。
输出一个序列，使得每个人的孩子都比那个人后列出。
输入格式
第 1 行一个整数 n，表示家族的人数；
接下来 n 行，第 i 行描述第 i 个人的孩子；
每行最后是 0 表示描述完毕。
每个人的编号从 1 到 n。

输出格式
输出一个序列，使得每个人的孩子都比那个人后列出；
数据保证一定有解，如果有多解输出任意一解。

数据范围
1≤n≤100

输入样例：
5
0
4 5 1 0
1 0
5 3 0
3 0
输出样例：
2 4 5 3 1
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int M = 10010,N = 110;
int h[N],e[M],ne[M];
int idx=1;
int node_single[N],count_single[N];
int idx_s,n;

void add_edge(int a,int b){
    e[idx] = b,ne[idx] = h[a];
    h[a] = idx++;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        while(true){
            cin >> x;
            if(x==0) break;
            add_edge(i,x);
            count_single[x]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(count_single[i]==0){
            node_single[idx_s++] = i;
        }
    }
    // printf("idx_s:%d\n",idx_s);
    for(int i=0;i<idx_s;i++){
        int node = node_single[i];
        // printf("node:%d\n",node);
        for(int edge=h[node];edge!=0;edge=ne[edge]){
            int node_next = e[edge];
            // printf("node_next:%d,count:%d\n",node_next,count_single[node_next]);
            if(--count_single[node_next]==0) {
                node_single[idx_s++] = node_next;
            }
        }
    }
    if(idx_s<n) cout << "No solution\n";
    else{
        for(int i=0;i<idx_s;i++){
            cout << node_single[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

