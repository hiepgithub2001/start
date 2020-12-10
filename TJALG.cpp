#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define oo 100000
using   namespace   std;
int n,m,X,Y,res=0,low[10005],num[10005],dem;
bool    ok[10005];
vector <int> a[10005];
stack <int> st;
//-------------------------
void    read()
{
    scanf("%d%d",&n,&m);
    fo(i,1,m)
    {
        scanf("%d%d",&X,&Y);
        a[X].push_back(Y);
    }
}
//-------------------------
void    DFS(int u)
{
    int v;
    num[u]=++dem;
    low[u]=oo;
    st.push(u);
    for (int i=0;i<a[u].size();++i)
    {
        v=a[u][i];
        if (ok[v])
        {
            if (num[v]==0)
            {
                DFS(v);
                low[u]=min(low[u],low[v]);
            }
            else low[u]=min(low[u],num[v]);
        }

    }
    if (low[u]>=num[u])
    {
        res++;
        v=u+1;
        while (v!=u)
        {
            v=st.top();
            st.pop();
            ok[v]=false;
        }
    }
}
//-------------------------
void    solve()
{
    read();
    memset(num,0,sizeof(num));
    memset(ok,true,sizeof(ok));
    fo(i,1,n)
    if (ok[i]) DFS(i);
    printf("%d",res);
}
//-------------------------
int     main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    solve();
}
