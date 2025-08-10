#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=4e5+10,M=8e5+10;
int h[N],e[M],ne[M];
int idx=1;
ll w[N],search_seq[N];
int n;

void add_edge(int a,int b){
	e[idx] = b,ne[idx] = h[a];
	h[a] = idx++;
}

int dfs(int node,int fa){
	int l_child=0,r_child=0,l_last_child=0,r_last_child=0;
	for(int edge = h[node];edge!=0;edge = ne[edge]){
		int next_node = e[edge];
		if(next_node==fa) continue;
		if(r_child == 0) {
			r_child = next_node;
		}
		else {
			l_child = next_node;
		}
	}
	ll l_search = 0, r_search = 0,c_l_search=0,c_r_search=0;
	if(l_child != 0){
		//均衡的，先左
		l_last_child = dfs(l_child,node);
		r_last_child = dfs(r_child,node);
		l_search = w[l_child] - w[node],c_l_search = w[r_child] - w[node];
		r_search = w[l_last_child] - w[r_child];c_r_search = w[r_last_child] - w[l_child];
		l_search = l_search <0 ? -l_search:l_search,r_search = r_search <0 ? -r_search:r_search;
		c_l_search = c_l_search <0 ? -c_l_search:c_l_search,c_r_search = c_r_search <0 ? -c_r_search:c_r_search;
		ll best;
		int r_last_node;
		// printf("l_search:%lld,r_search:%lld,cl:%lld,rl:%lld,l_last_child:%d,r_last_child:%d\n",l_search,r_search,c_l_search,c_r_search,l_last_child,r_last_child);
		if(l_search+r_search <= c_l_search+c_r_search){
			best = l_search+r_search;
			r_last_node = r_last_child;
		}else{
			// printf("swap:node:%d,left:%d,right:%d\n",node,l_child,r_child);
			best = c_l_search+c_r_search;
			r_last_node = l_last_child;
		}
		// printf("debug:best:%lld,l_child:%d,r_child:%d,node:%d\n",best,l_child,r_child,node);
		search_seq[node] = best + search_seq[l_child] + search_seq[r_child];
		return r_last_node;
	}else if(r_child !=0){
		//只有左子树
		l_child = r_child;
		l_last_child = dfs(l_child,node);
		l_search = w[node] - w[l_child];
		l_search = l_search <0 ? -l_search:l_search;
		search_seq[node] = l_search + search_seq[l_child];
		// printf("single left best:%d,l_child:%d,r_child:%d,node:%d\n",l_search,l_child,r_child,node);
		return l_last_child;
	}else{
		return node;
	}
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	for(int i=2;i<=n;i++){
		int fa;
		cin >> fa;
		add_edge(i,fa);
		add_edge(fa,i);
	}
	dfs(1,0);
	cout << search_seq[1] << "\n";
	return 0;
}




/*
5
1 2 3 4 5
1 1 2 2

6



3
1 2 3
1 1

4
1 2 3 4
1 1 2

4
1 2 3 4
1 1 3

6
1 2 3 4 5 6
1 1 2 4 4

7
1 2 3 4 5 6 7
1 1 2 3 5 5

7
1 3 2 5 4 7 6
1 1 2 3 4 4

7
1 2 3 4 5 6 7
1 2 2 3 4 5

6

*/