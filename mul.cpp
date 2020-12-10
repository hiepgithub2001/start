#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a,b)  for(int i=a;i<b;++i)
#define fore(i,a)  for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define __unique(V) V.resize(unique(V.begin(),V.end())-V.begin())
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "mul"
using   namespace   std;
LL  A,B,C;
///--------------------------
LL  mul(LL X,LL Y,LL Z){
    X%=Z;Y%=Z;
    LL  q = (long double) X*Y/Z;
    return (((X*Y-q*Z)%Z+Z)%Z);
}
///--------------------------
void    solve(){
    cin>>A>>B>>C;
    cout<<mul(A,B,C)<<'\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
}




