#include    <bits/stdc++.h>
#define fo(i,a,b)   for(int i=a;i<=b;++i)
#define fd(i,a,b)   for(int i=a;i>=b;--i)
#define rep(i,a,b)  for(int i=a;i<b;++i)
#define fore(i,a)   for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define TASK "Fmatch"
using   namespace   std;
int n,m,p,U,V,cnt;
int vis[50005],match[50005],matchL[50005],ans;
vector <int> a[50005];
//----------------------------
bool    DFS(int u){
    if (vis[u]==cnt) return false;
    vis[u]=cnt;
    fore(it,a[u]){
        int v=(*it);
        if (match[v]==0 || DFS(match[v])){
            match[v]=u;
            matchL[u]=v;
            return true;
        }
    }
    return false;
}
//----------------------------
void    solve(){
    cin>>n>>m>>p;
    while (cin>>U>>V) a[U].push_back(V);
    cnt=0;
    while (1){
        bool ok=false;
        cnt++;
        fo(i,1,n){
            if (matchL[i] || vis[i]==cnt) continue;
            if (DFS(i)) ok=true,ans++;
        }
        if (!ok) break;
    }
    cout<<ans<<"\n";
}
//----------------------------
int main(){
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}