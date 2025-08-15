/*
Rubik 先生在发明了风靡全球的魔方之后，又发明了它的二维版本——魔板。

这是一张有 8 个大小相同的格子的魔板：

1 2 3 4
8 7 6 5
我们知道魔板的每一个方格都有一种颜色。

这 8 种颜色用前 8 个正整数来表示。
可以用颜色的序列来表示一种魔板状态，规定从魔板的左上角开始，沿顺时针方向依次取出整数，构成一个颜色序列。
对于上图的魔板状态，我们用序列 (1,2,3,4,5,6,7,8) 来表示，这是基本状态。
这里提供三种基本操作，分别用大写字母 A，B，C 来表示（可以通过这些操作改变魔板的状态）：

A：交换上下两行；
B：将最右边的一列插入到最左边；
C：魔板中央对的4个数作顺时针旋转。

下面是对基本状态进行操作的示范：
A：

8 7 6 5
1 2 3 4

B：

4 1 2 3
5 8 7 6

C：

1 7 2 4
8 6 3 5
对于每种可能的状态，这三种基本操作都可以使用。
你要编程计算用最少的基本操作完成基本状态到特殊状态的转换，输出基本操作序列。
注意：数据保证一定有解。
输入格式
输入仅一行，包括 8 个整数，用空格分开，表示目标状态。

输出格式
输出文件的第一行包括一个整数，表示最短操作序列的长度。
如果操作序列的长度大于0，则在第二行输出字典序最小的操作序列。

数据范围
输入数据中的所有数字均为 1 到 8 之间的整数。

输入样例：
2 6 8 4 5 7 3 1
输出样例：
7
BCABCCB
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_OP = 1e5; //8!

unordered_map<string,char> st_pre;
unordered_map<string,string> st_pre_str;
char pre[MAX_OP];
string str_begin = "",str_end_tmp = "12348765",str_next,str_end;


string A_op(string src,string dst){
    for(int i = 0;i<8;i++){
        dst[(i+4)%8] = src[i];
    }
    return dst;
}

string C_op(string src,string dst){
    for(int i=0;i<8;i++){
        dst[i] = src[i];
    }
    dst[1] = src[2];
    dst[6] = src[5];
    dst[2] = src[6];
    dst[5] = src[1];
    return dst;
}

string B_op(string src,string dst){
    for(int i=0;i<3;i++){
        dst[i] = src[i+1];
    }
    dst[3] = src[0];
    for(int i=4;i<7;i++){
        dst[i] = src[i+1];
    }
    dst[7] = src[4];
    return dst;
}

bool judge_equal(char *a,char *b){
    for(int i=0;i<8;i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int bfs(){
    int now_idx = 0;
    queue<pair<string,int>> que;
    que.push({str_begin,0});
    while(que.size()){
        string state = que.front().first;
        int dep = que.front().second;
        que.pop();
        // printf("search: %s\n",state.c_str());
        if(strcmp(state.c_str(),str_end.c_str())==0) return dep;
        string m[3] = {A_op(state,str_next),B_op(state,str_next),C_op(state,str_next)};
        for(int i=0;i<3;i++){
            if(st_pre.count(m[i])==0){
                // printf("the origin_state:%s m[%d]: %s\n",state.c_str(),i,m[i].c_str());
                que.push({m[i],dep+1});
                st_pre[m[i]] = i+'A';
                // printf("the pre op:%c:added %c,i:%d\n",st_pre[m[i]],i+'A',i);
                st_pre_str[m[i]] = state;
                // printf("the %s prev state:%s,dep is %d\n",m[i].c_str(),st_pre_str[m[i]].c_str(),dep+1);
            }
        }
    }
    return -1;
}

int main(){
    str_begin.resize(9),str_next.resize(9),str_end.resize(9);
    for(int i=0;i<4;i++){
        char num;
        cin >> num;
        str_begin[i] = num;
        // cout << "states: " << states[idx][i] << "\n";
    }
    for(int i=4;i<8;i++){
        char num;
        cin >> num;
        str_begin[11-i] = num;
    }
    for(int i=0;i<8;i++){
        str_end[i] = str_end_tmp[i];
    }
    // printf("begin %s\n",str_begin.c_str());
    int res = bfs();
    cout << res << "\n";
    for(int i=1;i<=res;i++){
        // printf("\nstr_begin:%s,count %zu\n",str_end.c_str(),st_pre.count(str_end));
        cout << st_pre[str_end];
        if(st_pre_str.count(str_end) == 0) break;
        str_end = st_pre_str[str_end];
    }
    return 0;
}
