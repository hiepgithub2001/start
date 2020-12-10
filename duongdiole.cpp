#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <sstream>
 
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
const int nm=102;
 
int n,m,a[nm][nm];
int ns,st[nm*nm];
int bac[nm];
 
void nhap()
{
    scanf("%d%d",&n,&m);
    int i,u,v;
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        a[u][v]=a[v][u]=1;
        bac[u]++;bac[v]++;
    }
}
 
void xuli()
{
    int i,j;
    for(i=1;i<=n;++i) if (bac[i]%2) break;
    ns=1;
    if (i<=n) st[1]=i;else st[1]=1;
    while (ns)
    {
        i=st[ns];
        for(j=1;j<=n;++j)
        {
            if (a[i][j])
            {
                st[++ns]=j;a[i][j]--;a[j][i]--;
                break;
            }
        }
        if (i==st[ns])
        {
            printf("%d ",i);ns--;
        }
    }
}
 
int main()
{
    //freopen("5.in","r",stdin);
    //freopen("vd.out","w",stdout);
    nhap();xuli();
}