/*
4 4 12 1
1 2 1
1 3 2
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1
2 2 4
2 3 4
3 2 4
3 3 3
2 2
*/


#include <iostream>
// #include <unordered_map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2010,M=2010;
const int C = 750010;
struct Drop{
    int pos,count;
    // int u_d,l_d,d_d,r_d;
    Drop* next[4];
};
struct Position{
    int x,y;
};
int n,m,c,t;
int count_split;
Drop drops[C];
// int pos -> int idx_d
// unordered_map<int,int> pos_drop;
int pos_drop[N*M];
bool st[C];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

inline Position get_pos(int pos){
    int row = (pos-1) / m + 1;
    int col = (pos-1) % m + 1;
    return {row,col};
}
inline int get_from_pos(Position pos){
    return (pos.x-1)*m + pos.y;
}


void dfs(Drop* node){
    if(node == nullptr || node->pos > n*m || node->pos == 0 || node->count == 0) return;
    if(node->count<4){
        node->count++;
        return;
    }else{
        count_split++;
        node->count = 0;
        st[pos_drop[node->pos]] = true;
        for(int i=0;i<4;i++){
            Drop* next = node->next[i];
            while(next!=nullptr && (st[pos_drop[next->pos]] || next->count == 0)) next = next->next[i];
            // printf("st pos:%d,x:%d,y:%d\n",next->pos,get_pos(next->pos).x,get_pos(next->pos).y);
            dfs(next);
        }
    }
}

// 查找上下左右的附近水滴
void update_near(Drop& d,int pos,int x,int y){
    // 向上找
    if(d.next[0]==nullptr){
        for(int i=x-1;i>=1;i--){
            int pos_u = get_from_pos({i,y});
            if(pos_drop[pos_u]>=0){
                d.next[0] = &drops[pos_drop[pos_u]];
                drops[pos_drop[pos_u]].next[2] = &d;
                break;
            }
        }
    }
    // 向左找
    if(d.next[1]==nullptr){
        for(int j=y-1;j>=1;j--){
            int pos_l = get_from_pos({x,j});
            if(pos_drop[pos_l]>=0){
                d.next[1] = &drops[pos_drop[pos_l]];
                drops[pos_drop[pos_l]].next[3] = &d;
                break;
            }
        }
    }
    // 向下找
    if(d.next[2]==nullptr){
        for(int i=x+1;i<=n;i++){
            int pos_d = get_from_pos({i,y});
            if(pos_drop[pos_d]>=0){
                d.next[2] = &drops[pos_drop[pos_d]];
                drops[pos_drop[pos_d]].next[0] = &d;
                break;
            }
        }
    }
    // 向右找
    if(d.next[3]==nullptr){
        for(int j=y+1;j<=m;j++){
            int pos_r = get_from_pos({x,j});
            if(pos_drop[pos_r]>=0){
                d.next[3] = &drops[pos_drop[pos_r]];
                drops[pos_drop[pos_r]].next[1] = &d;
                break;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m >> c >> t;
    memset(pos_drop,-1,sizeof(pos_drop));
    for(int i=0;i<c;i++){
        int x,y,a;
        cin >> x >> y >> a;
        int pos = get_from_pos({x,y});
        drops[i].pos = pos;
        drops[i].count = a;
        pos_drop[pos] = i;
    }
    for(int i=0;i<c;i++){
        int pos = drops[i].pos;
        Position pos_xy = get_pos(pos);
        int x = pos_xy.x,y = pos_xy.y;
        update_near(drops[i],pos,x,y);
    }
    // printf("\nfin construct\n");
    // for(int i=0;i<c;i++){
    //     if(drops[i].count==0) continue;
    //     Position pos = get_pos(drops[i].pos);
    //     // printf("x:%d,y:%d,pos:%d,drop:%d,count:%d\n",pos.x,pos.y,drops[i].pos,i,drops[i].count);
    //     cout << pos.x << " " << pos.y << " " << drops[i].count << "\n";
    // }
    while(t--){
        count_split = 0;
        memset(st,0,sizeof(st));
        int u,v;
        cin >> u >> v;
        int pos_uv = get_from_pos({u,v});
        // printf("added u:%d,v:%d,pos_uv:%d,pos_drop:%d\n",u,v,pos_uv,pos_drop[pos_uv]);
        Drop* drop_start = &drops[pos_drop[pos_uv]];
        dfs(drop_start);
        cout << count_split << "\n";
    }
    // sort(drops,drops+c,[](const Drop &d1,const Drop &d2){return d1.pos < d2.pos;});
    // for(int i=0;i<c;i++){
    //     if(drops[i].count==0) continue;
    //     Position pos = get_pos(drops[i].pos);
    //     // printf("x:%d,y:%d,pos:%d,drop:%d,count:%d\n",pos.x,pos.y,drops[i].pos,i,drops[i].count);
    //     cout << pos.x << " " << pos.y << " " << drops[i].count << "\n";
    // }
    for(int ps=1;ps<n*m;ps++){
        int i = pos_drop[ps];
        if(i < 0) continue;
        if(drops[i].count==0) continue;
        Position pos = get_pos(ps);
        // printf("x:%d,y:%d,pos:%d,drop:%d,count:%d\n",pos.x,pos.y,drops[i].pos,i,drops[i].count);
        cout << pos.x << " " << pos.y << " " << drops[i].count << "\n";
    }
    return 0;
}
/*
结构体的初始化?
unordered_map 要 include 什么?
*/