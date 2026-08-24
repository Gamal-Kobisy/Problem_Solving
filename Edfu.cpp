// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/530046/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int B1, B2, MOD1, MOD2;
int pw1[N], pw2[N];
int inv_pw1[N], inv_pw2[N];

long long power(long long b, long long e, long long m) {
    long long res = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) res = (res * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return res;
}

long long modInverse(long long n, long long m) {
    return power(n, m - 2, m);
}

void build() {
    if (B1) return;
    random_device rd;
    mt19937 mt(rd());
    auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l, r)(mt); };
    auto check = [](int x) {
        for (int i = 2; i <= x / i; ++i) if (!(x % i)) return false;
        return true;
    };
    B1 = rnd(100, 500);
    B2 = rnd(100, 500);
    MOD1 = rnd(2e8, 2e9);
    MOD2 = rnd(2e8, 2e9);
    while (!check(MOD1)) MOD1--;
    while (MOD1 == MOD2 || !check(MOD2)) MOD2--;

    pw1[0] = pw2[0] = inv_pw1[0] = inv_pw2[0] = 1;
    int invB1 = modInverse(B1, MOD1);
    int invB2 = modInverse(B2, MOD2);

    for (int i = 1; i < N; ++i) {
        pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
        pw2[i] = 1LL * pw2[i - 1] * B2 % MOD2;
        inv_pw1[i] = 1LL * inv_pw1[i - 1] * invB1 % MOD1;
        inv_pw2[i] = 1LL * inv_pw2[i - 1] * invB2 % MOD2;
    }
}

// ---------------------------------------------------------
// COMPOSABLE HASH NODE
// ---------------------------------------------------------
struct Hash {
    int h1, h2, len;

    // 1. Empty string
    Hash() : h1(0), h2(0), len(0) {}

    // 2. Single character string
    Hash(char c) : h1(c), h2(c), len(1) {}

    // 3. Known hash states
    Hash(int h1, int h2, int len) : h1(h1), h2(h2), len(len) {}

    // Concatenate two hashes (A + B)
    Hash operator+(const Hash& o) const {
        if (len == 0) return o;
        if (o.len == 0) return *this;

        int nh1 = (1LL * h1 * pw1[o.len] % MOD1 + o.h1) % MOD1;
        int nh2 = (1LL * h2 * pw2[o.len] % MOD2 + o.h2) % MOD2;

        return Hash(nh1, nh2, len + o.len);
    }

    // Push character to the end
    void push_back(char c) {
        *this = *this + Hash(c);
    }

    // Push character to the beginning
    void push_front(char c) {
        *this = Hash(c) + *this;
    }

    // Pop character from the end (Requires knowing the character removed)
    void pop_back(char c) {
        if (len == 0) return;
        h1 = (1LL * h1 - c % MOD1 + MOD1) % MOD1;
        h1 = 1LL * h1 * inv_pw1[1] % MOD1;
        h2 = (1LL * h2 - c % MOD2 + MOD2) % MOD2;
        h2 = 1LL * h2 * inv_pw2[1] % MOD2;
        len--;
    }

    // Pop character from the front (Requires knowing the character removed)
    void pop_front(char c) {
        if (len == 0) return;
        len--;
        h1 = (h1 - 1LL * c * pw1[len] % MOD1 + MOD1) % MOD1;
        h2 = (h2 - 1LL * c * pw2[len] % MOD2 + MOD2) % MOD2;
    }

    // Equality check
    bool operator==(const Hash& o) const {
        return len == o.len && h1 == o.h1 && h2 == o.h2;
    }

    // If THIS = A + B, and we know A, we want B
    Hash remove_prefix(const Hash& A) const {
        // assert(len >= A.len);
        int rem_len = len - A.len;
        int nh1 = (h1 - 1LL * A.h1 * pw1[rem_len] % MOD1 + MOD1) % MOD1;
        int nh2 = (h2 - 1LL * A.h2 * pw2[rem_len] % MOD2 + MOD2) % MOD2;
        return Hash(nh1, nh2, rem_len);
    }

    // If THIS = A + B, and we know B, we want A
    // If THIS = A + B, and we know B, we want A
    Hash remove_suffix(const Hash& B) const {
        int rem_len = len - B.len;
        int nh1 = (1LL * h1 - B.h1 + MOD1) % MOD1;
        nh1 = 1LL * nh1 * inv_pw1[B.len] % MOD1;
        int nh2 = (1LL * h2 - B.h2 + MOD2) % MOD2;
        nh2 = 1LL * nh2 * inv_pw2[B.len] % MOD2;
        return Hash(nh1, nh2, rem_len);
    }
};

vector<int> adj[N];
int n, q, depth[N], up[N][LOG], timer, tin[N], tout[N] , par[N];
char c[N];
Hash norHash[N] , revHash[N];
void dfs(int u, int p , Hash h , Hash rh) {
    par[u] = p;
    h.push_back(c[u]);
    rh.push_front(c[u]);
    norHash[u] = h;
    revHash[u] = rh;
    tin[u] = timer++;
    for (auto v: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        dfs(v, u , h , rh);
    }
    tout[u] = timer - 1;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int Kthancestor(int u,int k){
    if(k > depth[u]) return -1;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            u = up[u][j];
        }
    }
    return u;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    u = Kthancestor(u , k);
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void buildLCA() {
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        depth[i] = 0;
        tin[i] = tout[i] = 0;
    }
    depth[1] = 0;
    dfs(1, 0 , Hash() , Hash() );
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

void TC() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    buildLCA();
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        Hash h1 = revHash[u].remove_suffix(revHash[par[lca]]);
        Hash h2 = norHash[v].remove_prefix(norHash[lca]);
        Hash h = h1 + h2;
        Hash rh1 = revHash[v].remove_suffix(revHash[par[lca]]);
        Hash rh2 = norHash[u].remove_prefix(norHash[lca]);
        Hash rh = rh1 + rh2;
        cout << (h == rh) << nl;
    }
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
    // test-independent code ——————————————————————
    build();
    // ————————————————————————————————————————————
    ll tc = 1;
    //     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
