struct DSU{
    vector<int> par , sz , ans;
    vector<vector<pii>> queries;

    DSU(int n, int q) : par(n) , sz(n , 1), queries(n), ans(q, -1) {
        iota(all(par) , 0);
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void add_query(int u, int v, int idx) {
        if(u == v) return void(ans[idx] = 0);
        queries[u].pb({v, idx});
        queries[v].pb({u, idx});
    }

    void merge(int x , int y , int w){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x , y);

        for(auto& q : queries[x]){
            if(find(q.fr) == y){
                ans[q.sc] = w;
            }else{
                queries[y].pb(q);
            }
        }
        queries[x].clear();

        sz[y] += sz[x];
        par[x] = y;
    }
};
