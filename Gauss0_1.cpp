#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORR(i,a,b) for (int i=(a); i>=(b); --i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define endl '\n'
#define sz(x) (int) x.size()
#define mod %
#define fillchar(x,y,z) memset(x,z,y)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define sqr(x) ((x)*(x))
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}
void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int n,T;
bitset<3505> f[3505];
int cnt[3505],x[3505],pos[3505];
void Input()
{
    n=ReadInt(); T=ReadInt();
    FOR(i,1,n-1) {
        int u=ReadInt(),v=ReadInt();
        f[u].set(v);
        f[v].set(u);
        f[i].set(i);
    }
    f[n].set(n);
    FOR(i,1,T)
        FOR(j,1,n)
            if (!ReadInt()) f[j].set(n+i);
}
void Solve()
{
    //Gauss
    FOR(i,1,n)
        FOR(j,1,n) if (f[i].test(j)) {
            pos[j]=i; //for trace
            FOR(k,1,n)
                if (k!=i&&f[k].test(j)) f[k]^=f[i];
            break;
        }
    FOR(i,1,n) {
        FOR(j,1,n)cnt[i]+=f[i].test(j);//,cout << f[i].test(j) << ' ';
        //cout << endl;
    }
    FOR(i,1,T) {
        fillchar(x,sizeof(x),0);
        bool mark=false;
        FOR(j,1,n)
            if (f[j].test(n+i)&&cnt[j]==0) {
                //vo nghiem
                mark=true;
                break;
            }
        if (mark) {
            puts("-1");
            continue;
        }
        FOR(j,1,n) x[j]=f[pos[j]].test(n+i);
        WriteInt(count(x+1,x+1+n,1)); putchar(' ');
        FOR(j,1,n) if (x[j]) {WriteInt(j); putchar(' ');}
        putchar(endl);
    }
}
int main()
{
    freopen("LAMPS.inp","r",stdin);
    #ifndef meomeomeooooo
        freopen("LAMPS.out","w",stdout);
    #endif // meomeomeooooo
    iostream::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Solve();
    return 0;
}
