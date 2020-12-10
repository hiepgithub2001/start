#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define LL long long
#define a first
#define b second
using   namespace   std;
typedef pair<LL,LL> ii;
ii IT[800005];
int n,m;
LL S,E,V,D;
const LL oo=1e18;
//--------------------------
LL get(ii d,LL x){
    return (d.a*x+d.b);
}
//--------------------------
LL  query(int k,LL i,LL j,LL p){
    if (j<p || p<i) return -oo;
    LL kq=get(IT[k],p);
    if (i==j) return kq;
    int mid=(i+j)>>1;
    kq=max(kq,query(2*k,i,mid,p));
    kq=max(kq,query(2*k+1,mid+1,j,p));
    return kq;
}
//--------------------------
void    update(int k,LL i,LL j,int L,int R,ii val){
    LL mid=(i+j)>>1;
    if (j<L || R<i) return;
    if (L<=i && j<=R){
        if (get(IT[k],i)>=get(val,i) &&  get(IT[k],j)>=get(val,j)) return;
        if (get(IT[k],i)<=get(val,i) && get(IT[k],j)<=get(val,j)){
            IT[k]=val;
            return;
        }
        if (get(IT[k],i)>=get(val,i) && get(IT[k],mid)>=get(val,mid)){
            update(2*k+1,mid+1,j,L,R,val);
            return;
        }
        if (get(IT[k],i)<=get(val,i) && get(IT[k],mid)<=get(val,mid)){
            update(2*k+1,mid+1,j,L,R,IT[k]);
            IT[k]=val;
            return;
        }
        if (get(IT[k],mid+1)>=get(val,mid+1) && get(IT[k],j)>=get(val,j)){
            update(2*k,i,mid,L,R,val);
            return;
        }
        if (get(IT[k],mid+1)<=get(val,mid+1)&& get(IT[k],j)<=get(val,j)){
            update(2*k,i,mid,L,R,IT[k]);
            IT[k]=val;
            return;
        }
    }
    update(2*k,i,mid,L,R,val);
    update(2*k+1,mid+1,j,L,R,val);
}
//--------------------------
void    solve(){
    cin>>n>>m;
    fo(i,1,m){
        cin>>S>>E>>V>>D;
        update(1,1,n,S,E,ii(D,V-S*D));
    }
    fo(i,1,n)
        cout<<query(1,1,n,i)<<"\n";
}
//--------------------------
int     main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   // freopen("jewelnb.inp","r",stdin);
    //freopen("jewelnb.out","w",stdout);
    solve();
}