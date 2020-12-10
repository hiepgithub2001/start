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
#define TASK "164C"
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
    tree_order_statistics_node_update> OST;
struct  data{
    int fr,to,capa,cost,flow,id;
    data(){
        fr = to = capa = cost = flow = id= 0;
    }
    data(int u,int v,int ca,int co,int adv){
        fr = u; to = v; flow = 0;
        capa = ca; cost = co; id = adv;
    }
    int isdelta(void) const{
        return capa - flow;
    }
};
const int maxn = 2005;
struct  tup{
    int L,R,C;
}a[maxn];
int source,sink,n,k,pre[maxn],dist[maxn];
int MaxFlow,MinCost,rs[maxn];
bool    inQ[maxn];
vector <data> Edge;
vector <int> RR,adj[maxn];
///--------------------------
void    readf(){
    cin >> n >> k;
    fo(i,1,n){
        cin >> a[i].L >> a[i].R >> a[i].C;
        a[i].R += a[i].L;
        RR.eb(a[i].R);RR.eb(a[i].L);
    }
    sort(RR.begin(),RR.end());
    __unique(RR);
}
///--------------------------
inline int index(int K){
    return upper_bound(RR.begin(),RR.end(),K) - RR.begin();
}
///--------------------------
void    addEdge(int u,int v,int ca,int co,int adv){
    adj[u].eb(Edge.size()); Edge.eb(u,v,ca,co,adv);
    adj[v].eb(Edge.size()); Edge.eb(v,u,0,-co,adv);
}
///--------------------------
bool    FindPath(){
    memset(pre,0,sizeof(pre));
    memset(dist,0x3f,sizeof(dist));
    memset(inQ,0,sizeof(inQ));
    queue <int> Q;
    Q.push(source);inQ[source] = 1; dist[source] = 0;
    while(Q.size()){
        int u = Q.front(); Q.pop(); inQ[u] = 0;
        for(auto it : adj[u]) if (Edge[it].isdelta() > 0){
            int v = Edge[it].to;
            int uv = Edge[it].cost;
            if (dist[v] > dist[u] + uv){
                dist[v] = dist[u] + uv;
                pre[v] = it;
                if (inQ[v]) continue;
                inQ[v] = 1;
                Q.push(v);
            }
        }
    }
    return pre[sink];
}
///--------------------------
void    incFlow(){
    int delta = INT_MAX;
    for(int v = sink; v != source; v = Edge[pre[v]].fr)
        delta = min(delta,Edge[pre[v]].isdelta());
    for(int v = sink; v != source; v = Edge[pre[v]].fr){
        Edge[pre[v]].flow += delta;
        Edge[pre[v] ^ 1].flow -= delta;
    }
    MaxFlow += delta;
    MinCost += delta * dist[sink];
}
///--------------------------
void    solve(){
    fo(i,1,n){
        a[i].L = index(a[i].L);
        a[i].R = index(a[i].R);
    }
    for(int i = 1; i < RR.size(); ++i) addEdge(i,i + 1,k,0,0);
    source = RR.size() + 1;
    sink = RR.size() + 2;
    addEdge(source,1,k,0,0);
    addEdge(RR.size(),sink,k,0,0);
    fo(i,1,n) addEdge(a[i].L,a[i].R,1,-a[i].C,i);
    while (FindPath()) incFlow();
    fo(u,1,RR.size()) for(auto it : adj[u])
        if (Edge[it].flow > 0 && Edge[it].id > 0) rs[Edge[it].id] = 1;
    fo(i,1,n) cout << rs[i] <<' ';
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



