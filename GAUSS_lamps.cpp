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
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "lamps"
using   namespace   std;
int n,T,U,V,c,ans[3005],m,pos[3005];
bitset <3505> p[3005],one;
///---------------------------
void    readf(){
    scanf("%d%d",&n,&T);
    fo(i,1,n) p[i].reset();
    fo(i,1,n) p[i][i] = 1,one[i] = 1;
    rep(i,1,n){
        scanf("%d%d",&U,&V);
        p[U][V] = 1; p[V][U] = 1;
    }
    fo(t,n+1,n+T) fo(i,1,n) scanf("%d",&c),p[i][t] = (c ^ 1);
}
///--------------------------
void    solve(){
    fo(i,1,n){
        pos[i] = -1;
        fo(j,1,n) if (p[i][j]) {pos[i] = j;break;}
        if (pos[i] == -1) continue;
        fo(j,1,n) if (p[j][pos[i]] && j!=i) p[j]^=p[i];
    }
    fo(t,n+1,n+T){
        m = 0;
        fo(i,1,n) {
            if (p[i][t]){
                if (pos[i] == -1){
                    printf("-1\n");
                    goto nxt;
                }else ans[++m] = pos[i];
            }
        }
        printf("%d ",m);
        fo(i,1,m) printf("%d ",ans[i]);
        printf("\n");
        nxt : ;
    }
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




