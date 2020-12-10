#include    <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
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
#define TASK "fflow"
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
    tree_order_statistics_node_update> OST;
struct  data{
    int fr,to,capa,flow;
    data(){
        fr = to = capa = flow = 0;
    }
    data(int u,int v,int ca){
        fr = u; to = v; flow = 0; capa = ca;
    }
    int isdelta(void) const{
        return capa - flow;
    }
};
const int maxn = 5005;
vector <data> Edge;
vector <int> adj[maxn];
int T,vis[maxn],dist[maxn],source,sink,n,m;
///--------------------------
void    addEdge(int u,int v,int ca){
    adj[u].eb(Edge.size());Edge.eb(u,v,ca);
    adj[v].eb(Edge.size());Edge.eb(v,u,0);
}
///--------------------------
void    readf(){
    scanf("%d%d%d%d",&n,&m,&source,&sink);
    fo(i,1,m){
        int u,v,ca;
        scanf("%d%d%d",&u,&v,&ca);
        addEdge(u,v,ca);
    }
}
///--------------------------
bool    BFS(){
    memset(dist,-1,sizeof(dist));
    queue <int> Q;
    Q.push(source);dist[source] = 0;
    while (Q.size()){
        int u = Q.front(); Q.pop();
        for(auto it : adj[u]){
            int v = Edge[it].to;
            if (dist[v] < 0 && Edge[it].isdelta() > 0){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[sink] >= 0;
}
///--------------------------
LL    DFS(int u,LL delta){
    if (u == sink) return delta;
    for( ; vis[u] < adj[u].size(); ++vis[u]) {
        int it = adj[u][vis[u]];
        if (Edge[it].isdelta() <= 0) continue;
        int v = Edge[it].to;
        if (dist[v] == dist[u] + 1)
        if (int x = DFS(v,min(delta, (LL)Edge[it].isdelta()))){
            Edge[it].flow += x;
            Edge[it ^ 1].flow -= x;
            return x;
        }
    }
    return 0;
}
///--------------------------
void    solve(){
    LL MaxFlow = 0;
    while (BFS()){
        while (1){
            memset(vis,0,sizeof(vis));
            int delta = DFS(source,LLONG_MAX);
            if (delta == 0) break;
            MaxFlow += delta;
        }
    }
    printf("%lld\n",MaxFlow);
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






