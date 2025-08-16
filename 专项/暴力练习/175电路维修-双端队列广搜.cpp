/*
达达是来自异世界的魔女，她在漫无目的地四处漂流的时候，遇到了善良的少女翰翰，从而被收留在地球上。
翰翰的家里有一辆飞行车。
有一天飞行车的电路板突然出现了故障，导致无法启动。
电路板的整体结构是一个 R 行 C 列的网格（R,C≤500）
每个格点都是电线的接点，每个格子都包含一个电子元件。
电子元件的主要部分是一个可旋转的、连接一条对角线上的两个接点的短电缆。
在旋转之后，它就可以连接另一条对角线的两个接点。
电路板左上角的接点接入直流电源，右下角的接点接入飞行车的发动装置。
达达发现因为某些元件的方向不小心发生了改变，电路板可能处于断路的状态。
她准备通过计算，旋转最少数量的元件，使电源与发动装置通过若干条短缆相连。
不过，电路的规模实在是太大了，达达并不擅长编程，希望你能够帮她解决这个问题。
注意：只能走斜向的线段，水平和竖直线段不能走。
输入格式
输入文件包含多组测试数据。
第一行包含一个整数 T，表示测试数据的数目。

对于每组测试数据，第一行包含正整数 R 和 C，表示电路板的行数和列数。
之后 R 行，每行 C 个字符，字符是"/"和"\"中的一个，表示标准件的方向。
输出格式
对于每组测试数据，在单独的一行输出一个正整数，表示所需的最小旋转次数。
如果无论怎样都不能使得电源和发动机之间连通，输出 NO SOLUTION。
数据范围
1≤R,C≤500,
1≤T≤5
输入样例：
2
3 5
\\/\\
\\///
/\\\\
3 5
\\/\\
\\///
/\\\\
输出样例：
1
1

1
4 4
\/\\
/\/\
//\\
\\\\

0
*/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int R = 510,C = 510;
typedef pair<int,int> pii;
int r,c;
struct Node{
    int x,y,dep;
};
int dist[R][C];
int dir[4][2] = {{1,1},{-1,-1},{-1,1},{1,-1}};
bool st[R][C];

bool has_edge(int x1,int y1,int x2,int y2){
    // int x_up = max(x1,x2),y_up = max(y1,y2);
    int x_down = min(x1,x2),y_down = min(y1,y2);
    if(dist[x_down][y_down]==1){
        return ((x_down ==x1 && y_down == y1) || (x_down == x2 && y_down == y2));
    }else{
        return ((x_down == x2 && y_down == y1)|| (x_down == x1 && y_down == y2));
    }

}

inline void debug_queue(deque<Node> &deq){
    for(Node q:deq){
        printf("in que:(%d,%d):%d\n",q.x,q.y,q.dep);
    }
    printf("===\n\n");
}

int bfs(){
    deque<Node> deq;
    memset(st,0,sizeof(st));
    deq.push_front({1,1,0});
    while(deq.size()){
        Node node = deq.front();
        // debug_queue(deq);
        deq.pop_front();
        int x = node.x,y = node.y,dep = node.dep;
        if(st[x][y]) continue;
        st[x][y] = true;
        if(x==r+1 && y == c+1) return dep;
        for(int i=0;i<4;i++){
            int next_x = dir[i][0] + x,next_y = dir[i][1] + y;
            // printf("(%d,%d),next:(%d,%d)\n",x,y,next_x,next_y);
            if(next_x >=1 && next_x <= r+1 && next_y >= 1 && next_y <= c+1 && !st[next_x][next_y]){
                bool if_has_edge = has_edge(x,y,next_x,next_y);
                if(if_has_edge==true){
                    // printf("has edge:%d,(%d,%d),node(%d,%d)\n",if_has_edge,next_x,next_y,x,y);
                    deq.push_front({next_x,next_y,dep});
                }else{
                    // printf("has edge:%d,(%d,%d),node(%d,%d)\n",if_has_edge,next_x,next_y,x,y);
                    deq.push_back({next_x,next_y,dep+1});
                }
            }
        }
    }
    return -1;
}


int main(){
    int t_iter;
    cin >> t_iter;
    while(t_iter--){
        cin >> r >> c;
        // memset(dist,0,sizeof(dist));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                char in; 
                cin >> in;
                if(in == '\\'){
                    dist[i][j] = 1;
                }else{
                    dist[i][j] = 2;
                }
            }
        }
        int res = bfs();
        if(res == -1){
            cout << "NO SOLUTION\n";
        }else{
            cout << res << "\n";
        }
    }
}

/*
只包含 0 和 1 的最短边权问题
*/