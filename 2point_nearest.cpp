#include    <bits/stdc++.h>
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define f   first
#define s   second
using   namespace   std;
typedef pair<double,double>   ii;
ii  a[100005],p[100005];
double ans;
int n;
//--------------------------
void    read()
{
    scanf("%d",&n);
    fo(i,1,n)
        scanf("%lf%lf",&p[i].f,&p[i].s);
}
//--------------------------
double  sqr(double X)
{
    return X*X;
}
//--------------------------
bool    cmp(ii A,ii B)
{
    return (A.s<B.s);
}
//--------------------------
double  D(ii A,ii B)
{
    return (sqr(A.f-B.f)+sqr(A.s-B.s));
}
//--------------------------
void    solve(int L,int R)
{
    if (L==R) return;
    int M=(L+R)>>1,T=0;
    solve(L,M);
    solve(M+1,R);
    fo(i,L,R)
        if (sqr(p[i].f-p[M].f)<ans) a[++T]=p[i];
    sort(a+1,a+T+1,cmp);
    for(int i=1;i<=T-1;++i)
        for(int j=i+1;j<=T && D(a[i],a[j])<ans;++j)
            ans=D(a[i],a[j]);
}
//--------------------------
void    solve()
{
    read();
    ans=1e18;
    sort(p+1,p+n+1);
    solve(1,n);
    printf("%.3lf",sqrt(ans));
}
//--------------------------
int     main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("nearest.inp","r",stdin);
    //freopen("nearest.out","w",stdout);
    solve();
}
 