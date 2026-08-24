const int N = 200000 + 5;
const int M = 400000 + 5;
int head[N], to[M * 2], nxt[M * 2], deg[N], ne, n;

int vis[M * 2];
int vid = 1;
int ans[M * 2], sz;

void init()
{
    memset(head, -1, (n + 1) * sizeof(head[0]));
    memset(deg, 0, (n + 1) * sizeof(deg[0]));
    ne = 0;
}

void addEdge(int u, int v)
{
    to[ne] = v;
    nxt[ne] = head[u];
    head[u] = ne++;
    deg[u]++;
}

void addBiEdge(int u, int v)
{
    addEdge(u, v);
    addEdge(v, u);
}

void euler(int u)
{
    for (int v, &e = head[u]; ~e;)
    {
        int ee = e;
        e = nxt[e]; // Move head pointer to the next edge
        if (vis[ee] == vid)
            continue;
        vis[ee] = vis[ee ^ 1] = vid;
        v = to[ee];
        euler(v);
        ans[sz++] = ee;
    }
}

// Returns true if Euler path/circuit exists.
// Sets 'st' = valid start node.
// 'm' is the total number of UNDIRECTED edges.
bool buildEulerUndirected(int &st, int m)
{
    int odd = 0;
    st = -1;

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            odd++;
            st = i;
        }
        if (deg[i] > 0 && st == -1)
        {
            st = i;
        }
    }

    if (!(odd == 0 || odd == 2))
        return false;

    if (st == -1)
    {
        sz = 0;
        return true;
    }

    sz = 0;
    ++vid; // O(1) visited array reset
    euler(st);
    if (sz != m)
        return false;
    reverse(ans, ans + sz);

    return true;
}

/*
// Usage Example:
int main() {
    // ... read n (nodes) and m (edges) ...
    init();

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addBiEdge(u, v);
    }

    int st;
    bool ok = buildEulerUndirected(st, m);

    if(!ok) {
        cout << "No Euler Path/Circuit" << endl;
    } else {
        // Print the vertex sequence:
        cout << st << " "; // Print starting node
        for(int i = 0; i < sz; i++) {
            cout << to[ans[i]] << " "; // Print destination node of each edge in the path
        }
        cout << endl;

        // To get the ID of the original edge used:
        // int edge_id = (ans[i] / 2) + 1; // Assuming 1-based edge input
    }
}
*/