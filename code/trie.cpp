#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
using   namespace   std;
struct  trie
{
    int dem;
    trie *node[26];
	trie(){
		memset(node,NULL,sizeof(node));
	}
};
trie *p,*root;
//-------------------------
void    add(string s)
{
    p=root;
    int tmp;
    for(int i=0;i<s.size();++i)
    {
        tmp = s[i] - 'a';
        if (p->node[tmp]==NULL) p->node[tmp]=new(trie);
        p=p->node[tmp];
    }
    p->dem++;
}
//-------------------------
void    solve()
{
    root=new(trie);
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
