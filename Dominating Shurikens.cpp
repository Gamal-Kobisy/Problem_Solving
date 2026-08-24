// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/zZYq310uLQ/contest/699485/problem/K
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

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

struct DynamicLazySegTree {
    struct Node {
        ll sum = 0;
        ll lazy = 0;
        int left = 0;
        int right = 0;
    };

    vector<Node> tree;
    ll L, R;

    DynamicLazySegTree(ll l, ll r, int reserve_nodes = 1e6) : L(l), R(r) {
        tree.reserve(reserve_nodes);
        tree.push_back({}); // Index 0: Dummy null node
        tree.push_back({}); // Index 1: Root node
    }

    // Safely gets the actual sum of a node including its pending lazy value
    ll get_sum(int node, ll lx, ll rx) {
        if (!node) return 0;
        return add(tree[node].sum , mul(tree[node].lazy , (rx - lx + 1)));
    }

    void push(int node, ll lx, ll rx) {
        if (tree[node].lazy == 0) return;

        tree[node].sum = add(tree[node].sum , mul(tree[node].lazy , (rx - lx + 1)));
        if (lx != rx) {
            if (!tree[node].left) {
                tree.push_back({});
                tree[node].left = tree.size() - 1;
            }
            if (!tree[node].right) {
                tree.push_back({});
                tree[node].right = tree.size() - 1;
            }
            tree[tree[node].left].lazy = add(tree[tree[node].left].lazy , tree[node].lazy);
            tree[tree[node].right].lazy = add(tree[tree[node].right].lazy , tree[node].lazy);
        }
        tree[node].lazy = 0;
    }

    void update(int node, ll lx, ll rx, ll ql, ll qr, ll val) {
        if (ql > rx || qr < lx) return;

        push(node, lx, rx);

        if (ql <= lx && rx <= qr) {
            tree[node].lazy = add(tree[node].lazy , val);
            // push(node, lx, rx);
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        if (!tree[node].left) {
            tree.push_back({});
            tree[node].left = tree.size() - 1;
        }
        if (!tree[node].right) {
            tree.push_back({});
            tree[node].right = tree.size() - 1;
        }

        update(tree[node].left, lx, mid, ql, qr, val);
        update(tree[node].right, mid + 1, rx, ql, qr, val);

        // Pull updated sum using get_sum to avoid stale child values
        tree[node].sum = add(get_sum(tree[node].left, lx, mid) ,
                         get_sum(tree[node].right, mid + 1, rx));
    }

    ll query(int node, ll lx, ll rx, ll ql, ll qr) {
        if (!node || ql > rx || qr < lx) return 0;
        if (ql <= lx && rx <= qr) return get_sum(node, lx, rx);
        push(node, lx, rx);

        ll mid = lx + (rx - lx) / 2;
        return add(query(tree[node].left, lx, mid, ql, qr) ,
               query(tree[node].right, mid + 1, rx, ql, qr));
    }

    void update(ll ql, ll qr, ll val) {
        update(1, L, R, ql, qr, val);
    }

    ll query(ll ql, ll qr) {
        return query(1, L, R, ql, qr);
    }
};

void TC() {
    ll n , q;
    cin >> n >> q;
    DynamicLazySegTree seg(1 , n);
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1) {
            ll l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << nl;
        } else {
            ll l, r, k, x;
            cin >> l >> r >> k >> x;
            ll L = -1;
            ll lo = 1, hi = n;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                if (n / mid <= k) {
                    if (n / mid == k) L = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            ll R = -1;
            lo = 1, hi = n;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                if (n / mid >= k) {
                    if (n / mid == k) R = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ll ql = max(l, L);
            ll qr = min(r, R);
            if (ql <= qr) {
                seg.update(ql, qr, x);
            }
        }
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
    // ————————————————————————————————————————————
    ll tc = 1;
    //     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
