const int N = 1e5 + 5; // maximum number of elements in DSU
struct DSU
{
    // par[u] < 0  ->  root, component size = -par[u]
    // par[u] >= 0 ->  non-root, parent = par[u]
    int par[N], ncmp, sets[N], pos[N];
    int tail[N], nxt[N];

    void init(int n)
    {
        memset(par, -1, n * sizeof par[0]); // -1 = root of size 1 (-(-1)=1)
        iota(sets, sets + n, 0);            // active root list: sets[0..ncmp-1]
        iota(pos, pos + n, 0);              // pos[u] = index of u in sets[]
        iota(tail, tail + n, 0);            // tail[u] = last node in u's linked list
        ncmp = n;
        memset(nxt, -1, n * sizeof nxt[0]);
    }

    int find(int u)
    {
        return par[u] < 0 ? u : par[u] = find(par[u]); // path compression
    }

    // s = small, b = big (by convention - swap if inconsistent).
    // Returns false if s and b are already in the same component.
    bool join(int s, int b)
    {
        s = find(s);
        b = find(b);
        if (s == b) return false;
        if (par[b] > par[s])
            swap(s, b);   // par more negative = bigger; ensure b is bigger
        par[b] += par[s]; // merge sizes: both negative, sum = larger size
        par[s] = b;       // s becomes child of b
        int &t = tail[b];
        nxt[t] = s;
        t = tail[s];
        int p = pos[s];
        sets[p] = sets[--ncmp];
        pos[sets[p]] = p;
        return true;
    }

    // Returns all nodes in the component containing u.
    vector<int> getCmp(int u)
    {
        u = find(u);
        vector<int> ret;
        ret.reserve(-par[u]); // preallocate with component size
        for (int v = u; v != -1; v = nxt[v])
            ret.push_back(v);
        return ret;
    }

    // Returns all components as a list of node lists.
    vector<vector<int>> getCmps()
    {
        vector<vector<int>> ret;
        ret.reserve(ncmp); // preallocate with number of components
        for (int i = 0; i < ncmp; i++)
            ret.push_back(getCmp(sets[i]));
        return ret;
    }
};