#include    <bits/stdc++.h>
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
#define x   first
#define y   second
using   namespace   std;
typedef pair<double,double>   ii;
const double  E=1e-5;
double ans;
ii  p[100005],P1,P2;
int n;
vector <ii> up,down,res;
//--------------------------
void    read()
{
    scanf("%d",&n);
    fo(i,1,n)
        scanf("%lf%lf",&p[i].x,&p[i].y);
}
//--------------------------
int CCW(ii p1,ii p2,ii p3)
{
    //(1)->L , (0)-> up, (-1)-> R
    double a1,a2,b1,b2,t;
    a1=p2.x-p1.x;b1=p2.y-p1.y;
    a2=p3.x-p2.x;b2=p3.y-p2.y;
    t=a1*b2-a2*b1;
    if (abs(t)<E) return 0;
    if (t>0) return 1;
    return -1;
}
//--------------------------
double  D(ii A,ii B)
{
    return (sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
}
//--------------------------
void    solve()
{
    read();
    sort(p+1,p+n+1);
    P1=p[1];P2=p[n];
    up.push_back(P1);
    down.push_back(P1);
    fo(i,2,n)
    {
        if ((i==n)||(CCW(P1,p[i],P2)<=0))
        {
            while (up.size()>1 &&
                (CCW(up[up.size()-2],up[up.size()-1],p[i])>=0))
                up.pop_back();up.push_back(p[i]);
        }
        if ((i==n)||(CCW(P1,p[i],P2)))
        {
            while (down.size()>1 &&
                   (CCW(down[down.size()-2],down[down.size()-1],p[i])<=0))
                down.pop_back();down.push_back(p[i]);
        }
    }
    for(int i=0;i<up.size();++i)
        res.push_back(up[i]);
    for(int i=down.size()-2;i>0;--i)
        res.push_back(down[i]);
    ans=0;
    for(int i=0;i<res.size();++i)
        for(int j=i+1;j<res.size();++j)
            ans=max(ans,D(res[i],res[j]));
    printf("%.4lf\n",ans);
}
//--------------------------
int     main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("archery.inp","r",stdin);
    freopen("archery.out","w",stdout);
    solve();
}


