#include    <bits/stdc++.h>
#define     fo(i,a,b)   for(int i=a;i<=b;++i)
using   namespace   std;
string S;
int Z[1000005],n,s;
//--------------------------
void    read()
{
    cin>>S;
    n=S.size();
}
//--------------------------
void    solve()
{
    read();
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
    if (i > R)
    {
        L = R = i;
        while (R < n && S[R] == S[R - L]) R++;
        Z[i] = R - L; R--;
    }
   else
   {
      int k = i - L;
      if (Z[k] < R - i + 1) Z[i] = Z[k];
      else
      {
          L = i;
          while (R < n && S[R] == S[R - L]) R++;
          Z[i] = R - L; R--;
      }
   }
   for(int i=0;i<n;++i) cout<<Z[i]<<' ';
}
//--------------------------
int     main()
{
    //ios::sync_with_stdio();
    //cin.tie();cout.tie();
    //freopen("Zfunction.inp","r",stdin);
    //freopen("Zfunction.out","w",stdout);
    solve();
}

