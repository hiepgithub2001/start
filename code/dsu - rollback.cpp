#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
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
#define TASK "dsuroll"
using namespace std;
const int maxn = 1e5 + 5;
struct data{
    int uu,vv,lef,rig;
    data(){
        uu = vv = lef = rig = 0;
    }
    data(int A,int B,int C,int D){
        uu = A; vv = B; lef = C; rig = D;
    }
};
vector <ii> node[maxn << 2];
vector <data> E;
int n,q,u[maxn],v[maxn],t[maxn];
int sz[maxn],par[maxn],ans[maxn];
map <int,int> start[maxn];
///--------------------------
void    readf(){
    stack <ii> sav;
    cin >> n >> q;
    for(int i = 1; i <= q; ++i){
        cin >> t[i] >> u[i] >> v[i];
        if (t[i] == 1){
            start[u[i]][v[i]] = start[v[i]][u[i]] = i;
            sav.push(ii(u[i],v[i]));
        }
        else if (t[i] == 2){
            E.eb(u[i],v[i],start[u[i]][v[i]],i - 1);
            start[u[i]][v[i]] = start[v[i]][u[i]] = 0;
        }
    }
    while (!sav.empty()){
        ii tmp = sav.top();
        sav.pop();
        if (start[tmp.fi][tmp.se] == 0) continue;
        E.eb(tmp.fi,tmp.se,start[tmp.fi][tmp.se],q);
        start[tmp.fi][tmp.se] = 0;
    }
}
///--------------------------
void     build(int k,int i,int j,int l,int r,int x,int y){
    if (j < l || r < i) return;
    if (l <= i && j <= r){
        node[k].eb(x,y);
        return;
    }
    int mid = i + j >> 1;
    build(k << 1,i,mid,l,r,x,y);
    build(k << 1|1,mid + 1,j,l,r,x,y);
}
///--------------------------
inline int root(int x){
    int r = x;
    while (r != par[r]) r = par[r];
    return r;
}
///--------------------------
void    join(stack <iii> &st,int x,int y){
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    x = rx; y = ry;
    if (sz[x] > sz[y]) swap(x,y);
    st.push(iii(0,ii(y,sz[y])));
    st.push(iii(1,ii(x,par[x])));
    sz[y] += sz[x];
    par[x] = y;

}
///--------------------------
void    DAC(int k,int i,int j){
    stack <iii> st;
    for(auto it : node[k]) join(st,it.fi,it.se);
    if (i == j && t[i] == 3){
        int ru = root(u[i]);
        int rv = root(v[i]);
        if (ru == rv) ans[i] = 1;
        else ans[i] = 2;
    }
    int mid = i + j >> 1;
    if (i != j){
        DAC(k << 1,i,mid);
        DAC(k << 1|1,mid + 1,j);
    }
    while (!st.empty()){
        iii tmp = st.top();
        st.pop();
        par[tmp.se.fi] = tmp.se.se;
        tmp = st.top();
        st.pop();
        sz[tmp.se.fi] = tmp.se.se;
    }
}
///--------------------------
void    solve(){
    for(auto it : E)
        build(1,1,q,it.lef,it.rig,it.uu,it.vv);
    for(int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    DAC(1,1,q);
    for(int i = 1; i <= q; ++i)
        if (ans[i] == 1) cout << "YES\n";
    else if (ans[i] == 2) cout << "NO\n";
}
///--------------------------
int     main(){
	srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    readf();
    solve();
}




