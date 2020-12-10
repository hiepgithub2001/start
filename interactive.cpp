#include <bits/stdc++.h>
#define TASK "interactive"
#define fo(i,a,b) for(int i = (a); i <= (b); ++i)
using   namespace   std;
int n,x;
///--------------------------
bool    ask(int k){
    #ifndef TLH2203
        cout << "Q " <<k <<'\n';
        fflush(stdout);
        int rep;
        cin >> rep;
        return rep;
    #endif // TLH2203
    return (x > k);
}
///--------------------------
void    guess(int k){
    #ifndef TLH2203
        cout << "A " << k << '\n';
        fflush(stdout);
        return;
    #endif // TLH2203
    if (k == x) cout << "OK\n";
    else cout << "WA\n";
}
///--------------------------
void    solve(){
    cin >> n;
    #ifdef  TLH2203
        cin >> x;
    #endif // TLH2203
    int dau = 1, cuoi = n, ans;
    while (dau <= cuoi){
        int mid = dau + cuoi >> 1;
        if (!ask(mid)){
            ans = mid;
            cuoi = mid - 1;
        }else dau = mid + 1;
    }
    guess(ans);
}
///--------------------------
int main(){
    #ifdef  TLH2203
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // TLH2203
    solve();
}