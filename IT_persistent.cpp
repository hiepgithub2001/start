///task: you have a array consist N element a(1) -> a(N).
///For Q query [L,R]: calculate the product of all diffirent in {a(L),a(L + 1),...,a(R)}
///--------------------------
persis build(int i,int j){
    persis cur = new(ITper);
    cur -> cost = 1;
    if (i == j){
        return cur;
    }
    int mid = i + j >> 1;
    cur -> node[0] = build(i,mid);
    cur -> node[1] = build(mid + 1,j);
    return cur;
}
///--------------------------
persis update(persis R,int i,int j,int pos,int val){
    persis cur = new(ITper);
    if (i == j){
        cur -> cost = val;
        return cur;
    }
    int mid = i + j >> 1;
    if (pos <= mid) {
        cur -> node[0] = update(R -> node[0],i,mid,pos,val);
        cur -> node[1] = R -> node[1];
    }else{
        cur -> node[0] = R -> node[0];
        cur -> node[1] = update(R -> node[1],mid + 1,j,pos,val);
    }
    cur -> cost = 1ll * (cur -> node[0] -> cost) *
                        (cur -> node[1] -> cost) % mod;
    return cur;
}
///--------------------------
int getIT(persis R,int i,int j,int l,int r){
    if (j < l || r < i) return 1;
    if (l <= i && j <= r) return R -> cost;
    int mid = i + j >> 1;
    return 1ll * getIT(R -> node[0],i,mid,l,r) *
               getIT(R -> node[1],mid + 1,j,l,r) % mod;
}
///--------------------------
void    build_big_prime(){
    root[0] = build(1,n);
    for(int i = 1; i <= n; ++i){
        if (pos[a[i]] == 0)
            root[i] = update(root[i - 1],1,n,i,a[i]);
        else {
            root[i] = update(root[i - 1],1,n,i,a[i]);
            root[i] = update(root[i],1,n,pos[a[i]],1);
        }
        pos[a[i]] = i;
    }
}