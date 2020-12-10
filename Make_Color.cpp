#include    <bits/stdc++.h>
#define TASK "NKDEC"
#define fo(i,a,b) for(int i = (a); i <= (b); ++i)
#define eb  emplace_back
#define ii  pair<int,int>
#define fi  first
#define se  second
using   namespace   std;
const int maxn = 10005;
const int ma =105;
int n,m,kq[ma][ma],nod[ma][ma],cnt;
int color[maxn],ans,a[ma][ma];
ii  aff[maxn];
set <int> col[maxn],st,res;
vector <int> adj[maxn];
///---------------------------
void    try_hard(){
    st.clear();res.clear();
    for(int i = 1; i <= cnt; ++i){
        st.insert(i);
        col[i].clear();
        for(int j = 1; j <= max(m,n) + 1; ++j)
            col[i].insert(j);
    }
    while (st.size()){
        int cur = 200;
        vector <int> sav;
        for(auto u : st){
            if (cur > col[u].size()){
                cur = col[u].size(); sav.clear();
                sav.eb(u);
            }else if (cur == col[u].size())
                sav.eb(u);
        }
        cur = sav[rand() % sav.size()];
        int co = *col[cur].begin();
        res.insert(co);
        color[cur] = co;
        for(auto u : adj[cur]) col[u].erase(co);
        st.erase(cur);
    }
    if (ans > res.size()){
        ans = res.size();
        for(int i = 1; i <= cnt; ++i)
            kq[aff[i].fi][aff[i].se] = color[i];
    }
}
///---------------------------
void    solve(){
    cin >> m >> n;
    fo(i,1,m) fo(j,1,n){
        char ch;
        cin >> ch;
        a[i][j] = ch - '0';
    }
    cnt = 0;
    fo(i,1,m){
        fo(j,1,n) if (a[i][j]){
            nod[i][j] = ++cnt;
            aff[cnt] = ii(i,j);
        }
        fo(j1,1,n) if (a[i][j1]) fo(j2,j1 + 1,n) if (a[i][j2]){
            adj[nod[i][j1]].eb(nod[i][j2]);
            adj[nod[i][j2]].eb(nod[i][j1]);
        }
    }
    fo(j,1,n) fo(i1,1,m) fo(i2,i1 + 1,m) if (a[i1][j] && a[i2][j]){
        adj[nod[i1][j]].eb(nod[i2][j]);
        adj[nod[i2][j]].eb(nod[i1][j]);
    }
    ans = max(m,n) + 2;
    for(int i = 0; i < 2; ++i) try_hard();
    cout << ans << '\n';
    fo(i,1,m) fo(j,1,n) cout << kq[i][j] << " \n"[j == n];
}
///---------------------------
int     main(){
    #ifdef  TLH2203
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // TLH2203
    solve();
}
