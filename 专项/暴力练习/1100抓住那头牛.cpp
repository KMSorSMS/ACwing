/*
农夫知道一头牛的位置，想要抓住它。
农夫和牛都位于数轴上，农夫起始位于点 N，牛位于点 K。
农夫有两种移动方式：
从 X 移动到 X−1 或 X+1，每次移动花费一分钟
从 X 移动到 2∗X，每次移动花费一分钟
假设牛没有意识到农夫的行动，站在原地不动。
农夫最少要花多少时间才能抓住牛？

输入格式
共一行，包含两个整数N和K。
输出格式
输出一个整数，表示抓到牛所花费的最少时间。
数据范围
0≤N,K≤105
输入样例：
5 17
输出样例：
4
*/
#include <iostream>
#include <queue>
using namespace std;

const int N = 2e5+10;
int st[N];
int n,k,up,down;
struct Item{
    int x,dep;
};

int bfs(){
    queue<Item> que;
    que.push({n,0});
    while(que.size()){
        Item item = que.front();
        que.pop();
        int x = item.x,dep = item.dep;
        if(x==k) return dep;
        if(x+1<=up && !st[x+1]){
            que.push({x+1,dep+1});
            st[x+1] = true;
        }
        if(x*2 <= up && !st[2*x]){
            que.push({x*2,dep+1});
            st[2*x] = true;
        }
        if(x-1 >= 0 && !st[x-1]){
            que.push({x-1,dep+1});
            st[x-1] = true;
        }
    }
    return -1;
}

int main(){
    cin >> n >> k;
    up = n > k ? n : k;
    down = n < k ? n : k;
    up *= 2;
    // down -= 10;
    int res=  bfs();
    cout << res << "\n";
    return 0;
}

