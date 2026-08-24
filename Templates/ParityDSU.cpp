const int N = 1e5 + 5; // maximum number of elements in DSU
struct ParityDSU
{
    int par[N], dist[N]; // dist[u] = XOR parity to root

    void init(int n)
    {
        memset(par, -1, n * sizeof(par[0]));
        memset(dist, 0, n * sizeof(dist[0]));
    }

    // Returns {root, distance_to_root}
    pair<int, int> find(int u)
    {
        if (par[u] < 0)
            return {u, 0}; // par[u]<0 means u is root
        auto [root, d] = find(par[u]);
        dist[u] ^= dist[par[u]]; // path compression + parity
        par[u] = root;
        return {root, dist[u]};
    }

    // p=0: u and v same group, p=1: different group
    // Returns: -1=conflict, 0=new edge ok, 1=redundant ok
    int addEdge(int u, int v, int p)
    {
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru == rv)
        {
            return (du ^ dv) == p ? 1 : -1; // check consistency
        }

        // Union by size: par holds negative sizes.
        // More negative means a larger tree.
        if (par[rv] < par[ru])
        {
            swap(ru, rv);
            swap(du, dv); // Must swap distances to match the swapped roots
        }

        par[ru] += par[rv];     // Update the size of the larger root's tree
        par[rv] = ru;           // Attach the smaller tree's root to the larger one
        dist[rv] = du ^ dv ^ p; // Set parity so dist[v] is correct

        return 0;
    }

    // Query relationship between u and v
    // Returns: -1 if not connected, 0 if same group, 1 if different group
    int query(int u, int v)
    {
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru != rv)
            return -1; // Not connected

        return du ^ dv;
    }
};