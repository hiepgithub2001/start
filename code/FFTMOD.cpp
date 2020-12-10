#include    <bits/stdc++.h>
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
#define MOD 998244353
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "absthird"
using   namespace   std;
const int mod = MOD,maxn = 1<<18;
string a,b,c;
int n,rs[maxn + 5],N,slbit;
LL A[maxn + 5],B[maxn + 5];
///--------------------------
int revbit(int nbit,int mask){
    for(int i = 0, j = nbit - 1; i <= j; ++i,--j)
    if (bit(mask,i) != bit(mask,j)){
        mask ^= (1<<i);
        mask ^= (1<<j);
    }
    return mask;
}
///--------------------------
LL pw(LL X,LL Y){
    LL tmp = 1;
    while (Y){
        if (Y & 1) tmp = (tmp * X) % mod;
        X = (X * X) % mod;
        Y >>= 1;
    }
    return tmp;
}
///--------------------------
void    FFT(int sz,LL *x,bool inverse){
    if (sz == 1) return;
    for(int i = 0; i < sz; ++i){
        int j = revbit(slbit,i);
        if (i < j) swap(x[i],x[j]);
    }
    for(int step = 2; step <= sz; step <<= 1){
        LL wn = (inverse) ? pw(3,mod - 2) : 3;
        wn = pw(wn,(mod - 1)/__gcd(mod - 1,step));
        for(int i = 0; i < sz; i += step){
            LL w = 1;
            for(int j = 0; j < step/2; ++j){
                LL u = x[i + j], v = (x[i + j + step/2] * w) % mod;
                x[i + j] = (u + v) % mod;
                x[i + j + step/2] = ((u - v) % mod + mod) % mod;
                w = (w * wn) % mod;
            }
        }
    }
    if (inverse){
        LL tmp = pw(sz,mod - 2);
        fo(i,1,sz) x[i] = (x[i] * tmp) % mod;
    }
}
///--------------------------
void    solve(){
    cin >> n >> a >> b >> c;
    N = 1; slbit = 0;
    while (N < 2 * n) N *= 2,slbit++;
    fo(ch,0,25){
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        rep(i,0,n) if (a[i] - 'a' == ch) A[i] = 1;
        rep(i,0,n) B[n - i] = abs(b[i] - ch - 'a') + abs(c[i] - ch - 'a');
        FFT(N,A,0);
        FFT(N,B,0);
        rep(i,0,N) A[i] = (A[i] * B[i]) % mod;
        FFT(N,A,1);
        fo(i,1,n) rs[i] += (A[i] + A[i + n]);
    }
    sort(rs + 1,rs + n + 1);
    cout << rs[n] <<' ' << rs[1] << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif //ONLINE_JUDGE
    solve();
}




