#include    <bits/stdc++.h>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define	time	jsfdasd
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
#define TASK "stock"
using   namespace   std;
const int maxn = 100005;
int n,q,U,V,left,right,cnt,st[maxn],ed[maxn],val[maxn],x[maxn];
int freq[maxn],suf[maxn],sq,ans[maxn];
vector <int> a[maxn];
struct data{
    int L,R,tr,ph,id;
    data(){}
    data(int L,int R,int tr,int ph,int id) : L(L),R(R),tr(tr),ph(ph),id(id){};
    bool operator < (const data &A)const{
        if (L/sq == A.L/sq) return L < A.L;
        return R < A.R;
    }
}que[maxn];
///--------------------------
void    readf(){
    cin >> n >> q;
    fo(i,1,n - 1){
        cin >> U >> V;
        a[U].push_back(V);
        a[V].push_back(U);
    }
    fo(i,1,n) cin >> x[i];
}
///--------------------------
void    DFS(int u,int par){
    st[u] = ++cnt;
    val[cnt] = x[u];
    fore(it,a[u]) if ((*it) != par) DFS(*it,u);
    ed[u] = cnt;
}
///--------------------------
inline void    inc(int X){
    suf[++freq[X]]++;
}
///--------------------------
inline void    dec(int X){
    suf[freq[X]--]--;
}
///--------------------------
void    solve(){
    DFS(1,0);
    fo(i,1,q){
        cin >> U >> left >> right;
        que[i] = data(st[U],ed[U],left,right,i);
    }
    sq = sqrt(n);
    sort(que + 1,que + q + 1);
    left = 1;right = 0;
    fo(i,1,q){
        int l = que[i].L, r = que[i].R;
        while (left < l) dec(val[left++]);
        while (left > l) inc(val[--left]);
        while (right < r) inc(val[++right]);
        while (right > r) dec(val[right--]);
        ans[que[i].id] = suf[que[i].tr] - suf[que[i].ph + 1];
    }
    fo(i,1,q) cout << ans[i] << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif //ONLINE_JUDGE
    readf();
    solve();
}
 