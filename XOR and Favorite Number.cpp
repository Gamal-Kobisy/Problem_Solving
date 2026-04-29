// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/617/problem/E
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
struct Query {
    int lq, rq, id;
};

int n, q, k;
vector<int> pre;
ll freq[(1<<20) + 5];
ll ans = 0;

void add(int val) {
    ans += freq[val ^ k];
    freq[val]++;
}

void rem(int val) {
    freq[val]--;
    ans -= freq[val ^ k];
}

vector<ll> MO(vector<Query>& queries) {
    const int SQ = ceil(sqrt(N)) + 1;
    sort(all(queries), [&](Query a , Query b){
        return make_pair(a.lq / SQ , a.rq) < make_pair(b.lq / SQ , b.rq);
    });
    vector<ll>res(queries.size());
    int l = queries[0].lq, r = queries[0].lq;
    add(pre[l]);
    for (const auto& [lq, rq, id] : queries) {
        while (l > lq) add(pre[--l]);
        while (r < rq) add(pre[++r]);
        while (l < lq) rem(pre[l++]);
        while (r > rq) rem(pre[r--]);
        res[id] = ans;
    }
    return res;
}

void TC() {
    cin >> n >> q >> k;
    pre.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] ^ x;
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        auto &[lq, rq, id] = queries[i];
        cin >> lq >> rq;
        --lq;
        id = i;
    }

    mem(freq, 0);
    ans = 0;

    vector<ll> res = MO(queries);
    for (int i = 0; i < q; ++i) {
        cout << res[i] << nl;
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