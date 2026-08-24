const int N = 1e5 + 5; // Maximum number of elements in the DSU
struct WeightedDSU
{
    int par[N];
    long long w[N]; // w[u] = value[u] - value[root]

    void init(int n)
    {
        memset(par, -1, n * sizeof(par[0]));
        memset(w, 0, n * sizeof(w[0]));
    }

    pair<int, long long> find(int u)
    {
        if (par[u] < 0)
            return {u, 0}; // par[u]<0 means u is root
        auto [root, wr] = find(par[u]);
        par[u] = root;
        w[u] += wr; // path compression: accumulate weight
        return {root, w[u]};
    }

    // Constraint: value[v] - value[u] = d
    // Returns false if contradiction
    bool join(int u, int v, long long d)
    {
        auto [ru, wu] = find(u); // wu = value[u] - value[ru]
        auto [rv, wv] = find(v); // wv = value[v] - value[rv]
        if (ru == rv)
        {
            return (wv - wu) == d; // check: value[v]-value[u] = wv-wu
        }
        par[rv] = ru;
        w[rv] = wu - wv + d; // so that value[v]-value[u] = d holds
        return true;
    }

    // Query: value[v] - value[u] (must be in same component)
    long long query(int u, int v)
    {
        auto [ru, wu] = find(u);
        auto [rv, wv] = find(v);
        if (ru != rv)
            return -infLL; // not connected
        return wv - wu;
    }
};