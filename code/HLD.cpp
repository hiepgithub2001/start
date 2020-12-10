#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define TASK "qtree3"
using   namespace   std;
int n,Q,U,V,sz[100005],cnt;
int heavy[100005],head[100005],ind[100005];
int par[100005],m,pos[100005],last[100005];
int L[100005],R[100005],val[100005],w[100005];
vector <int> a[100005];
vector <int> IT[100005];
//--------------------------
inline void    read(){
    cin>>n>>Q;
    fo(i,1,n-1){
        cin>>U>>V;
        a[U].push_back(V);
        a[V].push_back(U);
    }
}
//--------------------------
inline void DFS(int u){
    int v,tmp=0;
    sz[u]=1;
    for(int i=0;i<a[u].size();++i){
        v=a[u][i];
        if (sz[v]==0){
            DFS(v);
            sz[u]+=sz[v];
            par[v]=u;
            if (sz[v]>sz[tmp]) tmp=v;
        }
    }
    heavy[u]=tmp;
}
//--------------------------
inline void HLD(int u){
    int v;
    if (head[cnt]==0) head[cnt]=u;
    ind[u]=cnt;
    fo(i,1,4) IT[cnt].push_back(0);
    pos[u]=++m;
    w[m]=u;
    if (L[cnt]==0) L[cnt]=m;
    R[cnt]=m;
    if (heavy[u]==0) return;
    HLD(heavy[u]);
    for(int i=0;i<a[u].size();++i){
        v=a[u][i];
        if (par[v]==u && v!=heavy[u]){
            ++cnt;
            HLD(v);
        }
    }
}
//--------------------------
inline void update(int id,int k,int l,int r,int p,int gt){
    if (l==r){
        IT[id][k]=gt*w[p];
        return;
    }
    int mid=(l+r)>>1;
    if (p<=mid) update(id,2*k,l,mid,p,gt);
    else update(id,2*k+1,mid+1,r,p,gt);
    if (IT[id][2*k]>0)  IT[id][k]=IT[id][2*k];
    else    IT[id][k]=IT[id][2*k+1];
}
//--------------------------
inline int get(int id,int k,int i,int j,int l,int r){
    if (j<l || r<i) return 0;
    if (l<=i && j<=r) return IT[id][k];
    int mid=(i+j)>>1;
    int tmp1=get(id,2*k,i,mid,l,r);
    int tmp2=get(id,2*k+1,mid+1,j,l,r);
    if (tmp1>0) return tmp1;
    else return tmp2;
}
//--------------------------
inline int query(int u){
    int idu=ind[u],id1=ind[1],tmp,rs=-1;
    while (1){
        if (idu==id1){
            tmp=get(idu,1,L[idu],R[idu],L[idu],pos[u]);
            if (tmp>0) rs=tmp;
            return rs;
        }
        tmp=get(idu,1,L[idu],R[idu],L[idu],pos[u]);
        u=par[head[idu]];
        idu=ind[u];
        if (tmp>0) rs=tmp;
    }
}
//--------------------------
inline void    solve(){
    DFS(1);
    cnt=1;
    HLD(1);
    while (Q--){
        cin>>V>>U;
        if (V==0){
            val[U]^=1;
            update(ind[U],1,L[ind[U]],R[ind[U]],pos[U],val[U]);
        }
        else  cout<<query(U)<<"\n";
    }
}
//--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    read();
    solve();
}
 