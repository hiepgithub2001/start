#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using   namespace   std;
string a,b;
int La,Lb,NEXT[1000005];
//-------------------------
void    read()
{
    getline(cin,a);
    getline(cin,b);
    La=a.length();
    Lb=b.length();
    a=" "+a;
    b=" "+b;
}
//-------------------------
void    Next()
{
    int j=0;
    NEXT[1]=0;
    for(int i=2;i<=Lb;++i)
    {
        while ((j>0)&&(b[j+1]!=b[i])) j=NEXT[j];
        if (b[j+1]==b[i]) j++;
        NEXT[i]=j;
    }
}
//-------------------------
void    solve()
{
    read();
    Next();
    int j=0;
    for(int i=1;i<=La;++i)
    {
        while ((j>0)&&(b[j+1]!=a[i])) j=NEXT[j];
        if (b[j+1]==a[i]) j++;
        if (j==Lb)
        {
            printf("%d ",i-j+1);
            j=NEXT[j];
        }
    }
}
//-------------------------
int     main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    solve();
}