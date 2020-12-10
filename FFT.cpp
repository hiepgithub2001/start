#include    <bits/stdc++.h>
#include    <complex>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "post2"
using   namespace   std;
const int maxn = 5e4,maxx = 1<<18;
typedef complex<double> base;
typedef vector<base>    vb;
vb  A(maxx+5),B(maxx+5),anxt(maxx+5);
base    W[maxx+5];
LL  ans;
int m,x;
///--------------------------
void    readf(){
    cin >> m;
    fo(i,1,m) cin >> x,A[x + maxn]+=1.0;
    fo(i,1,m) cin >> x,B[x + maxn]+=1.0;
}
///--------------------------
int revBIT(int nbit,int mask){
    for(int i = 0,j = nbit - 1; i <= j; ++i,--j){
        if (bit(mask,i) != bit(mask,j)){
            mask ^= (1<<i);
            mask ^= (1<<j);
        }
    }
    return mask;
}
///--------------------------
void    FFT(int n,vb &a,bool inverse){
    if (n == 1) return;
    for(int i = 0; i < n; ++i){
        int j = revBIT(18,i);
        if (i < j) swap(a[i],a[j]);
    }
    for(int step = 1; step < n; step <<= 1){
        double  ang = PI/step;
        if (inverse) ang = -ang;
        base    w(1),wn(cos(ang),sin(ang));
        for(int i = 0; i < step; ++i){
            W[i] = w;
            w *= wn;
        }
        int even = 0;
        int odd = even + step;
        while (even < n){
            for(int i = 0; i < step; ++i){
                anxt[even + i]  =   a[even + i] + W[i] * a[odd + i];
                anxt[even + i + step]  =   a[even + i] - W[i] * a[odd + i];
            }
            even += 2 * step;
            odd   = even + step;
        }
        for(int i = 0;i < n; ++i) a[i] = anxt[i];
    }
    if (inverse) for(int i = 0; i < n; ++i) a[i]/=n;
}
///--------------------------
void    solve(){
    FFT(maxx,A,0);
    FFT(maxx,B,0);
    for(int i = 0; i < maxx ; ++i)
        A[i] *= B[i];
    FFT(maxx,A,1);
    ans = 0;
    fo(i,1,m) cin >> x, ans += round(A[x + 2 * maxn].real());
    cout << ans << '\n';
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




