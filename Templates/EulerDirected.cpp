const int N = 200000 + 5;
const int M = 400000 + 5;
int head[N], to[M], nxt[M], inDeg[N], outDeg[N], ne, n;

int ans[M], sz;

void init()
{
    memset(head, -1, (n+1) * sizeof(head[0]));
    memset(inDeg, 0, (n+1) * sizeof(inDeg[0]));
    memset(outDeg, 0, (n+1) * sizeof(outDeg[0]));
    ne = 0;
}

void addEdge(int u, int v)
{
    to[ne] = v;
    nxt[ne] = head[u];
    head[u] = ne++;
    outDeg[u]++;
    inDeg[v]++;
}

void euler(int u)
{
    for (int &e = head[u]; ~e;)
    {
        int ee = e;
        e = nxt[e]; // Move head pointer to the next edge
        euler(to[ee]);
        ans[sz++] = ee;
    }
}

// Returns true if Euler path/circuit exists.
// Sets 'st' = valid start node.
// 'm' is the total number of DIRECTED edges.
bool buildEulerDirected(int &st, int m)
{
    int startNodes = 0, endNodes = 0;
    st = -1;

    for (int i = 1; i <= n; i++)
    {
        if (outDeg[i] - inDeg[i] == 1)
        {
            startNodes++;
            st = i;
        }
        else if (inDeg[i] - outDeg[i] == 1)
        {
            endNodes++;
        }
        else if (inDeg[i] != outDeg[i])
        {
            return false;
        }

        if (outDeg[i] > 0 && st == -1)
        {
            st = i;
        }
    }

    if (!((startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1)))
        return false;

    if (st == -1)
    {
        sz = 0;
        return true;
    }
    sz = 0;
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
        addEdge(u, v);
    }

    int st;
    bool ok = buildEulerDirected(st, m);

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
        // int edge_id = ans[i] + 1; // Assuming 1-based edge input
    }
}
*/