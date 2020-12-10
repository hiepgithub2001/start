#include    <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "161D"
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
    tree_order_statistics_node_update> OST;
const int maxn = 50005;
int n,KC,sz[maxn],par[maxn],P[20][maxn],dep[maxn];
int total,root,sl[505];
LL  ans;
vector <int> AD[maxn],nod[maxn];
set <int> adj[maxn];
///--------------------------
void    readf(){
    cin >> n >> KC;
    fo(i,1,n - 1){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}
///--------------------------
int     find_centroid(int u,int p){
    for(auto v : adj[u])
        if (v != p && sz[v] > total/2)
            return find_centroid(v,u);
    return u;
}
///--------------------------
void    dfs_subtree(int u,int p){
    sz[u] = 1; total++;
    for(auto v : adj[u]) if (v != p){
        dfs_subtree(v,u);
        sz[u] += sz[v];
    }
}
///--------------------------
void    Centroid_decompose(int u,int p){
    total = 0;
    dfs_subtree(u,u);
    int centroid = find_centroid(u,u);
    if (p == 0) p = centroid, root = p;
    par[centroid] = p;
    for(auto v : adj[centroid]){
        adj[v].erase(centroid);
        Centroid_decompose(v,centroid);
    }
    adj[centroid].clear();
}
///--------------------------
void    dfs(int u,int p){
    P[0][u] = p; dep[u] = dep[p] + 1;
    for(int k = 1; (1 << k) <= n; ++k)
        P[k][u] = P[k - 1][P[k - 1][u]];
    for(auto v : adj[u]) if (v != p) dfs(v,u);
}
///--------------------------
int LCA(int u,int v){
    if (dep[v] < dep[u]) swap(u,v);
    for(int k = 16; k >= 0; --k) if (dep[P[k][v]] >= dep[u])
        v = P[k][v];
    if (u == v) return u;
    for(int k = 16; k >= 0; --k) if (P[k][v] != P[k][u])
        v = P[k][v], u = P[k][u];
    return P[0][u];
}
///--------------------------
inline  int dist(int u,int v){
    return dep[u] + dep[v] - 2 * dep[LCA(u,v)];
}
///--------------------------
LL  res(vector <int> A,int k){
    LL rs = 0;
    for(auto it : A) {
        if (it <= k) sl[it] = 0;
        if (it <= k) sl[k - it] = 0;
    }
    for(auto it : A){
        if (it <= k) rs += sl[k - it];
        if (it <= k) sl[it]++;
    }
    return rs;
}
///--------------------------
void    DFS_again(int u){
    vector <int> A;
    nod[u].eb(u);
    A.eb(0);
    int dem = 0;
    for(auto v : AD[u]){
        DFS_again(v);
        vector <int> B;
        for(auto v2 : nod[v]){
            nod[u].eb(v2);
            int tmp = dist(v2,u);
            A.eb(tmp);
            B.eb(tmp);
            dem += (tmp == KC);
        }
        ans -= res(B,KC);
    }
    ans += res(A,KC);
}
///--------------------------
void    solve(){
    dfs(1,0);
    Centroid_decompose(1,0);
    fo(i,1,n) if (par[i] != i)
        AD[par[i]].eb(i);
    ans = 0;
    DFS_again(root);
    cout << ans << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    readf();
    solve();
}





