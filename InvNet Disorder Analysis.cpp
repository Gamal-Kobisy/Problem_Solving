// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/627262/problem/C
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _n){
        n = _n;
        tree.assign(n + 1 , 0);
    }
    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    int query_range(int l , int r){
        return query(r) - query(l - 1);
    }
};

Fenwick bit(N);

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
ll power(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans , b);
        b = mul(b , b);
        p /= 2;
    }
    return ans;
}

struct Query{
    int lq , rq , id;
};
vector<int>a;
long long current_inversions = 0;

void addR(int val){
    current_inversions += bit.query_range(val + 1, N);
    bit.update(val , 1);
}

void addL(int val){
    current_inversions += bit.query_range(1, val - 1);
    bit.update(val , 1);
}

void remR(int val){
    bit.update(val , -1);
    current_inversions -= bit.query_range(val + 1, N);
}

void remL(int val){
    bit.update(val , -1);
    current_inversions -= bit.query_range(1, val - 1);
}
vector<int> MO(vector<Query>&queries){
    const int SQ = ceil(sqrt(N)) + 1;
    sort(all(queries), [&](Query a , Query b){
        if (a.lq / SQ != b.lq / SQ) return a.lq / SQ < b.lq / SQ;
        return ((a.lq / SQ) & 1) ? a.rq < b.rq : a.rq > b.rq; // Snake optimization
    });
    vector<int>res(queries.size());
    int l = queries[0].lq , r = queries[0].lq;
    addL(a[l]);
    for(const auto [lq , rq , id] : queries){
        while (l > lq) addL(a[--l]);
        while (r < rq) addR(a[++r]);
        while (l < lq) remL(a[l++]);
        while (r > rq) remR(a[r--]);
        int len = rq - lq + 1;
        if (len < 2) {
            res[id] = 0;
        } else {
            res[id] = mul(current_inversions % MOD, power(2, len - 2));
        }
    }
    while (l <= r) remL(a[l++]);
    return res;
}

void TC() {
    int n , q;
    cin >> n;
    a = vector<int>(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    cin >> q;
    vector<Query>queries(q);
    for (int i = 0 ; i < q ; i++)
    {
        auto &[l , r , id] = queries[i];
        cin >> l >> r;
        id = i;
    }
    vector<int> res = MO(queries);
    for (int i = 0 ; i < q ; i++) cout << res[i] << nl;
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
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
