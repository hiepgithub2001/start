#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define TASK "group"
#define LL long long
#define f   first
#define s   second
using   namespace   std;
typedef pair<LL,LL> ii;
int n,m;
ii  p[300005],a[300005];
LL  ans;
vector <LL> B;
vector <LL> M;
//--------------------------
inline void    read(){
    cin>>m;
    fo(i,1,m) cin>>a[i].f>>a[i].s;
}
//--------------------------
inline bool cmp(int p1,int p2,int p3){
    return ((M[p1]-M[p2])*(B[p3]-B[p1])<(M[p1]-M[p3])*(B[p2]-B[p1]));
}
//--------------------------
inline void add(LL m,LL b){
    M.push_back(m);
    B.push_back(b);
    while (M.size()>2 && cmp(M.size()-3,M.size()-2,M.size()-1)){
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}
//--------------------------
inline LL query(LL X){
    if (M.size()==1) return (M[0]*X+B[0]);
    int dau=1,cuoi=M.size()-1,mid,rs=0;
    while (dau<=cuoi){
        mid=(dau+cuoi)>>1;
        if (M[mid]*X+B[mid]<M[mid-1]*X+B[mid-1]){
                rs=mid;
                dau=mid+1;
            }else cuoi=mid-1;
    }
    return (M[rs]*X+B[rs]);
}
//--------------------------
inline void    solve(){
    sort(a+1,a+m+1);
    fo(i,1,m){
        while (n>0 && p[n].s<=a[i].s) n--;
        p[++n]=a[i];
    }
    add(p[1].s,0);
    fo(i,1,n){
        ans=query(p[i].f);
        if (i<n) add(p[i+1].s,ans);
    }
    cout<<ans<<"\n";
}
//--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    read();
    solve();
}
 