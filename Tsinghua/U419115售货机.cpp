/*
2 2
8 2 0.90
7 1 0.40

3 2
8 3 0.90
7 3 0.40
100 3 0.8
*/

#include <cstdio>
using namespace std;
const int N=2010;
double price[N],logits[N];
int bi[N];
int n,x;
bool st[N];
double res;

void dfs(int i,double money, double prob){
    money += price[i];
    // printf("search:%d,money:%.3lf\n",i,money);
    if(i == x){
        if(st[bi[i]]) res += money * prob;
        else {
            res += money * logits[i] * prob;
            if(!st[bi[i]]){
                st[bi[i]] = true;
                dfs(bi[i],money,prob*(1-logits[i]));
                st[bi[i]] = false;
            }
        }
    }else{
        if(st[i]){
            if(!st[bi[i]]) {
                if(bi[i] == x) res += money * prob;
                else {
                    st[bi[i]] = true;
                    dfs(bi[i],money,prob);
                    st[bi[i]] = false;
                }
            }
            else{
                res += money * prob;
            }
        }else{
            if(!st[i]){
                st[i] = true;
                dfs(i,money,prob*logits[i]);
                st[i] = false;
            }
            if(!st[bi[i]]){
                if(bi[i] == x) res += money * prob * (1-logits[i]);
                else {
                    st[bi[i]]=true;
                    dfs(bi[i],money,prob*(1-logits[i]));
                    st[bi[i]] = false;
                }
            }
        }
    }

}


int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        double a,p;
        int b;
        scanf("%lf%d%lf",&a,&b,&p);
        price[i] = a,bi[i] = b,logits[i] = p;
    }
    for(int i=1;i<=n;i++){
        // printf("term:%d\n",i);
        dfs(i,0,1/(double)n);
    }
    printf("%.8lf\n",res);
    return 0;
}


/*
怎么读取 double
*/