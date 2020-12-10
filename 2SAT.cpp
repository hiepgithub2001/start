#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a,b)  for(int i=a;i<b;++i)
#define fore(i,a)  for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define __unique(V) V.resize(unique(V.begin(),V.end())-V.begin())
#define cntbit(X)   __builtin_popcount(X)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "twosat"
using   namespace   std;
const int maxn=4e4+5;
const int oo=1e9;
int n,m,U,V,num[maxn],low[maxn];
int cnt=0,team[maxn],tplt=0,topo=0;
int dd[maxn],deg[maxn];
bool ok[maxn];
vector <int> a[maxn],pp[maxn],b[maxn],ans;
vector <ii> E;
stack <int> st;
queue <int> q;
///--------------------------
inline int hate(int X){return (X>n) ? (X-n) : (n+X);}
inline int change(int X) {return (X<0) ? (n-X) : X;}
bool   cmp(int A,int B){return (dd[A]<dd[B]);}
///--------------------------
void    readf(){
    cin>>m>>n;
    fo(i,1,m){
        cin>>U>>V;
        U=change(U);V=change(V);
        a[hate(U)].push_back(V);
        a[hate(V)].push_back(U);
        E.push_back(ii(hate(U),V));
        E.push_back(ii(hate(V),U));
    }
}
///--------------------------
void    DFS(int u){
    num[u]=++cnt;low[u]=oo;
    st.push(u);
    fore(it,a[u]){
        int v=(*it);
        if (ok[v]){
            if (num[v]==0){
                DFS(v);
                low[u]=min(low[u],low[v]);
            }else low[u]=min(low[u],num[v]);
        }
    }
    if (low[u]>=num[u]){
        tplt++;
        int v;
        do{
            v=st.top();
            st.pop();
            ok[v]=false;
            team[v]=tplt;
            pp[tplt].push_back(v);
        }while (v!=u);
    }
}
///--------------------------
void    toposort(){
    fo(i,1,tplt) fore(it,b[i]) deg[*it]++;
    fo(i,1,tplt) if (!deg[i]) {
        q.push(i);
        dd[i]=++topo;
    }
    while (q.size()){
        int u=q.front();
        q.pop();
        fore(it,b[u]) {
            int v=(*it);
            deg[v]--;
            if (deg[v]==0){
                dd[v]=++topo;
                q.push(v);
            }
        }
    }
}
///--------------------------
void    solve(){
    memset(num,0,sizeof(num));
    memset(ok,true,sizeof(ok));
    fo(i,1,2*n) if (ok[i]) DFS(i);
    fo(i,1,n) if (team[i]==team[n+i]){
        cout<<"NO\n";
        exit(0);
    }
    fore(it,E){
        U=(*it).fi;V=(*it).se;
        if (team[U]!=team[V]) b[team[U]].push_back(team[V]);
    }
    fo(i,1,tplt) sort(b[i].begin(),b[i].end());
    fo(i,1,tplt) __unique(b[i]);
    toposort();
    fo(i,1,n) if (dd[team[i]]>dd[team[hate(i)]])
        ans.push_back(i);
    cout<<"YES\n"<<ans.size()<<'\n';
    fore(it,ans) cout<<(*it)<<' ';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    readf();
    solve();
}
 