/*

3
S 2
H 2
C A

1
S 2

3
S 2
H 2
C 2

5
S 9
S X
S J
S Q
S K

5
S 9
S X
H J
S Q
S K

8
S X
H X
C X
C 9
D 3
D 7
S 3
S A
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Type_C{
    int base,rate;
};
struct Card{
    char num,col;
};
Type_C types[10];
int n;
Card cards[10];
Card cards_s[10];
char sets[15] = "23456789XJQKA";
char in_s[15];
int count_set[16];

int map_c[512];
int jud_type;
int res_sum = 0;

void init(){
    for(int i=0;i<13;i++){
        map_c[sets[i]] = i;
    }
    types[1] = {5,1};//高牌
    types[2] = {10,2};//对子
    types[3] = {20,2};//两对
    types[4] = {30,3};//三条
    types[5] = {30,4};//顺子
    types[6] = {35,4};//同花
    types[7] = {40,4};//葫芦
    types[8] = {60,7};//四条
    types[9] = {100,8};//同花顺

}

int judge_card(int n){
    memset(in_s,0,sizeof(in_s));
    memset(count_set,0,sizeof(count_set));
    // 判断同花顺
    char col=0,start=16;
    bool is_s=true,is_s_c=true;
    int base_s_res=0;
    if(n>=5){
        // 判断顺子
        col=0,start=16;
        is_s=true;
        for(int i=1;i<=n;i++){
            // printf("num_%d:%c ",i,cards[i].num);
            if(col==0){
                col = cards[i].col;
                in_s[map_c[cards[i].num]] = cards[i].num;
                start = map_c[cards[i].num]<start?map_c[cards[i].num]:start;
            }
            else if(in_s[map_c[cards[i].num]]!=0){
                is_s=false;
                break;
            }else{
                in_s[map_c[cards[i].num]] = cards[i].num;
                // printf("num:%c,map_c:%d\n",cards[i].num,map_c[cards[i].num]);
                start = map_c[cards[i].num]<start?map_c[cards[i].num]:start;
            }
        }
        // printf("\n");

        // printf("is_s:%d,start:%d\n",is_s,start);
        if(is_s){
            for(int i=start;i<start+5;i++){
                // printf("i:%d,in_s[i]:%c\n",i,in_s[i]);
                if(in_s[i]==0) is_s=false;
            }
        }
        //判断同花
        col=0;
        is_s_c=true;
        base_s_res=0;
        for(int i=1;i<=n;i++){
            if(col==0){
                col = cards[i].col;
                int base_s = map_c[cards[i].num]+2;
                if(base_s > 13) base_s = 11;
                else if(base_s > 10) base_s = 10;
                base_s_res += base_s;
            }
            else if(cards[i].col!=col){
                is_s_c=false;
                break;
            }else{
                int base_s = map_c[cards[i].num]+2;
                if(base_s > 13) base_s = 11;
                else if(base_s > 10) base_s = 10;
                base_s_res += base_s;
            }
        }
        // printf("is_s_c:%d,is_s:%d\n",is_s_c,is_s);
        if(is_s && is_s_c){
            jud_type = 9;
            int base=0;
            for(int i=start;i<start+5;i++){
                char num = in_s[i];
                int base_t = map_c[num]+2;
                if(base_t > 13) base_t = 11;
                else if(base_t > 10) base_t = 10;
                base += base_t;
            }
            return base;
        }
    }
    // 判断是否4 条 or 3 条
    int count=0,res=0;
    char num=0,num_tmp=0,num2=0;
    for(int i=1;i<=n;i++){
        count_set[map_c[cards[i].num]]++;
    }
    for(int i=0;i<13;i++){
        if(count_set[i]>res){
            res = count_set[i];
            num = sets[i];
        }
        if(count_set[i]==2){
            num2 = sets[i];
        }
    }
    // printf("res:%d\n",res);
    // 四条
    if(res==4){
        jud_type = 8;
        int base = map_c[num]+2;
        if(base > 13) base = 11;
        else if(base > 10) base = 10;
        base *= 4;
        return base;
    }
    if(n>=5){
        // 葫芦
        if(res==3 && num2!=0){
            jud_type = 7;
            int base = map_c[num]+2;
            if(base > 13) base = 11;
            else if(base > 10) base = 10;
            base *=3;
            int base2 = map_c[num2]+2;
            if(base2 > 13) base2 = 11;
            else if(base2 > 10) base2 = 10;
            base2 *=2;
            base += base2;
            return base;
        }
        // 先判断是否同花
        if(is_s_c){
            jud_type = 6;
            return base_s_res;
        }
        // 判断是否是顺子
        if(is_s){
            jud_type = 5;
            int base=0;
            for(int i=start;i<start+5;i++){
                char num = in_s[i];
                int base_t = map_c[num]+2;
                if(base_t > 13) base_t = 11;
                else if(base_t > 10) base_t = 10;
                base += base_t;
            }
            return base;
        }
    }
    // 再看是否三条
    if(res==3){
        jud_type = 4;
        int base = map_c[num]+2;
        if(base > 13) base = 11;
        else if(base > 10) base = 10;
        base *= 3;
        return base;
    }
    // 判断 2 对 or 对子
    count=0,res=0;
    num=0,num_tmp=0;
    int group=0;
    num2=0;
    for(int i=0;i<13;i++){
        if(count_set[i]==2){
            // printf("cards[i].num:%c\n",cards[i].num);
            if(group==0) num = sets[i],group++;
            else{
                num2 = sets[i],group++;
            }
        }
    }
    // printf("group:%d,count:%d,res:%d,num:%c\n",group,count,res,num);
    if(group==2){//两对
        jud_type=3;
        int base = map_c[num]+2;
        if(base > 13) base = 11;
        else if(base > 10) base = 10;
        int base2 = map_c[num2]+2;
        if(base2 > 13) base = 11;
        else if(base2 > 10) base2 = 10;
        base += base2;
        base *= 2;
        return base;
    }else if(group==1){
        jud_type=2;
        int base = map_c[num]+2;
        if(base > 13) base = 11;
        else if(base > 10) base = 10;
        base *=2;
        return base;
    }
    // 高牌，找最大
    int card_max=0;
    for(int i=1;i<=n;i++){
        int now_card = map_c[cards[i].num]+2;
        if(now_card>13) now_card=11;
        else if(now_card>10) now_card=10;
        if(now_card > card_max){
            card_max = now_card;
        }
    }
    jud_type=1;
    return card_max;

}

void dfs(int dep,int start){
    if(dep > 5 || dep > n){
        int n_param = n > 5?5:n;
        int add_base = judge_card(n_param);
        int base = add_base + types[jud_type].base;
        int res_tmp = base * types[jud_type].rate;
        res_sum = res_tmp > res_sum ? res_tmp : res_sum;
        // printf("add_base:%d,jud_type:%d,res_sum:%d\n",add_base,jud_type,res_sum);
        return;
    }
    for(int i=start;i<=n;i++){
        cards[dep] = cards_s[i];
        dfs(dep+1,i+1);
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cards_s[i].col >> cards_s[i].num;
    }
    init();
    dfs(1,1);
    // int add_base = judge_card();
    // printf("add_base:%d,jud_type:%d\n",add_base,jud_type);
    // int base = add_base + types[jud_type].base;
    // cout << base*types[jud_type].rate << "\n";
    cout << res_sum << "\n";
}
