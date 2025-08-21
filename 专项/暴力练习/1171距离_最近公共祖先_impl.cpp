#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=10005,M=N*2;
int n,m,h[N],ne[M],e[M],w[M],idx=1;
int dist[N],depth[N],fa[N][16];

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
void bfs()
{
    memset(depth,0x3f,sizeof(depth));
    queue<int> que;
    que.push(1);
    depth[1]=1,depth[0]=0;
    while(que.size())
    {
        int t=que.front();
        que.pop();

        for(int i=h[t];i!=0;i=ne[i])
        {
            int j=e[i];
            if(depth[j]>depth[t]+1)
            {
                depth[j]=depth[t]+1;
                dist[j]=dist[t]+w[i];
                que.push(j);
                fa[j][0]=t;
                for(int k=1;k<=14;k++)
                    fa[j][k]=fa[fa[j][k-1]][k-1];
            }
        }
    }
}

int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    for(int k=14;k>=0;k--)
        if(depth[fa[a][k]]>=depth[b])
            a=fa[a][k];
    if(a==b)
        return a;

    for(int k=14;k>=0;k--)
        if(fa[a][k]!=fa[b][k])
        {
            a=fa[a][k];
            b=fa[b][k];
        }
    return fa[a][0];
}
int main()
{
    int a,b,c;
    cin>>n>>m;
    // memset(h,-1,sizeof  h);
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    bfs();

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        int pa=lca(a,b);
        cout<<(dist[a]+dist[b]-dist[pa]*2)<<endl;
    }


    return 0;
}