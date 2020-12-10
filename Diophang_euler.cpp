#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i-1))&1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<LL,LL>
#define iii pair<int,ii>
#define TASK "diophantos"
using   namespace   std;
LL a,b,c;
///--------------------------
ii    euclid(LL A,LL B){
    LL R0 = A, R1 = B;
    LL X0 = 1, Y0 = 0;
    LL X1 = 0, Y1 = 1;
    while (R0 % R1){
        LL R2 = R0 % R1;
        LL q = R0 / R1;
        LL X2 = (X0 - q * X1);
        LL Y2 = (Y0 - q * Y1);
        X0 = X1 ; X1 = X2;
        Y0 = Y1 ; Y1 = Y2;
        R0 = R1 ; R1 = R2;
    }
    return ii(X1,Y1);
}
///--------------------------
void    solve(){
    cin >> a >> b >> c;
    if (c % __gcd(a,b)){
        cout << "NO SOLUTION";
        exit(0);
    }
    ii rs = euclid(a,b);
    rs.fi = (rs.fi * c / __gcd(a,b));
    rs.se = (rs.se * c / __gcd(a,b));
    cout << rs.fi << ' ' << rs.se << '\n';
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




