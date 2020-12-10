#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define oo 1000000
using   namespace   std;
int n,m,U,V,khop,cau,dem,low[10005],num[10005];
int okkhop[10005],cha[10005],con[10005];
vector <int> a[10005];
//-------------------------
void    read()
{
    scanf("%d%d",&n,&m);
    fo(i,1,m)
    {
        scanf("%d%d",&U,&V);
        a[U].push_back(V);
        a[V].push_back(U);
    }
}
//-------------------------
void    DFS(int u)
{
    int v;
    dem++;
    num[u]=dem;
    low[u]=oo;
    for (int i=0;i<a[u].size();++i)
    {
        v=a[u][i];
        if (cha[u]!=v)
        {
        	if (cha[v]==0)
        	{
            	cha[v]=u;
            	DFS(v);
            	low[u]=min(low[u],low[v]);
        	}
        	else low[u]=min(low[u],num[v]);
        }

    }
}
//-------------------------
void       printres()
{
    int u;
    fo(v,1,n)
    {
        u=cha[v];
        if ((u!=-1)&&(low[v]>=num[v])) cau++;
    }
    fo(v,1,n)
    {
        u=cha[v];
        if (u!=-1) con[u]++;
    }
    fo(v,1,n)
        okkhop[v]=((cha[v]==-1)&&(con[v]>=2));
    fo(v,1,n)
    {
        u=cha[v];
        if ((u!=-1)&&(cha[u]!=-1)&&(low[v]>=num[u])) okkhop[u]=true;
    }
    fo(v,1,n)
        if (okkhop[v]) khop++;
    printf("%d %d\n",khop,cau);
}
//-------------------------
void    solve()
{
    read();
    dem=cau=khop=0;
    memset(cha,0,sizeof(cha));
    memset(okkhop,false,sizeof(okkhop));
    fo(i,1,n)
    if (cha[i]==0)
    {
        cha[i]=-1;
        DFS(i);
    }
    printres();
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
