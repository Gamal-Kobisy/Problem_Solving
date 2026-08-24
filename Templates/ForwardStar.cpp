int head[N], to[M], nxt[M], wt[M], ne;

void init(int n)
{
    ne = 0;
    memset(head, -1, n * sizeof(head[0]));
}

void addEdge(int u, int v, int w = 0)
{
    to[ne] = v;
    wt[ne] = w;
    nxt[ne] = head[u];
    head[u] = ne++;
}

void addBiEdge(int u, int v, int w = 0)
{
    addEdge(u, v, w);
    addEdge(v, u, w);
}

// Traverse neighbors of u:
// for(int e = head[u]; ~e;){
//     int v = to[e];
//     int w = wt[e];
//     // process edge u -> v with weight w
//     e = nxt[e];
// }