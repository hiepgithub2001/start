void    build(){
    queue <int> qu;
    link[0] = 0;
    qu.push(0);
    while (qu.size() > 0){
        int u = qu.front();
        qu.pop();
		if (terminal[link[u]]) terminal[u] = 1;
        for(int i = 0; i < 10; ++i){
            go[u][i] = go[link[u]][i];
            if (trie[u][i] != -1){
                link[trie[u][i]] = go[u][i];
                go[u][i] = trie[u][i];
                qu.push(trie[u][i]);
            }
        }
    }
}