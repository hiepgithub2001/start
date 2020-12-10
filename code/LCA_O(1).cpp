///--------------------------
void    DFS(int u,int v){
    in[u] = ++m;
    nod[m] = u;
    deep[u] = deep[v] + 1;
    fore(it,adj[u]) if ((*it).fi != v){
        d[(*it).fi] = d[u] + (*it).se;
        DFS((*it).fi,u);
        nod[++m] = u;
    }
}
///--------------------------
void    RMQ(){
    fo(i,1,m) {
        Rmin[0][i] = deep[nod[i]];
        Rnod[0][i] = nod[i];
    }
    for(int k = 1; (1<<k) <= m; ++k)
    for(int i = 1; i + (1<<k) - 1 <= m; ++i){
        if (Rmin[k-1][i] < Rmin[k-1][i + (1<<(k-1))]){
                Rmin[k][i] = Rmin[k-1][i];
                Rnod[k][i] = Rnod[k-1][i];
        }else{
                Rmin[k][i] = Rmin[k-1][i + (1<<(k-1))];
                Rnod[k][i] = Rnod[k-1][i + (1<<(k-1))];
        }
    }
}
///--------------------------
int    LCA(int u,int v){
    u = in[u]; v = in[v];
    if (u > v) swap(u,v);
    int k = __lg(v - u + 1);
    if (Rmin[k][u] < Rmin[k][v - (1<<k) + 1])
        return Rnod[k][u];
    return Rnod[k][v - (1<<k) + 1];
}
///--------------------------
inline LL dist(int u,int v){
    return d[u] + d[v] - 2 * d[LCA(u,v)];
}