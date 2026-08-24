const int N = 1e5 + 5; // Maximum number of elements in the DSU

struct ModuloDSU
{
    int par[N], dist[N];
    int k; // The modulo / number of groups

    void init(int n, int mod)
    {
        k = mod;
        memset(par, -1, n * sizeof(par[0]));
        memset(dist, 0, n * sizeof(dist[0]));
    }

    // Returns {root, distance_to_root}
    pair<int, int> find(int u)
    {
        if (par[u] < 0)
            return {u, 0};
        auto [root, d] = find(par[u]);

        // Path compression + modular addition
        dist[u] = (dist[u] + dist[par[u]]) % k;
        par[u] = root;

        return {root, dist[u]};
    }

    // Adds relationship: (val(u) - val(v)) % k == p
    // Returns: -1=conflict, 0=new edge ok, 1=redundant ok
    int addEdge(int u, int v, int p)
    {
        p = (p % k + k) % k; // Ensure p is positive
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru == rv)
        {
            // Check consistency safely handling negative modulo
            return (((du - dv - p) % k + k) % k == 0) ? 1 : -1;
        }

        // Union by size: par holds negative sizes.
        if (par[rv] < par[ru])
        {
            swap(ru, rv);
            swap(du, dv);
            p = (k - p) % k; // CRITICAL: Reverse relationship direction for modulo
        }

        par[ru] += par[rv]; // Update size of the larger root's tree
        par[rv] = ru;       // Attach smaller tree to larger tree

        // Set new distance for rv relative to ru
        dist[rv] = ((du - dv - p) % k + k) % k;

        return 0;
    }

    // Query relationship between u and v
    // Returns: -1 if not connected, otherwise (val(u) - val(v)) % k
    int query(int u, int v)
    {
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru != rv)
            return -1; // Not connected

        return ((du - dv) % k + k) % k;
    }
};