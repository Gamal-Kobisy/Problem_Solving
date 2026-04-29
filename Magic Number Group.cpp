// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/103366/problem/G
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
const int N = 1e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

vector<int> primes, spf;
vector<bool> is_prime;

void sieve(int n) {
    is_prime.assign(n + 1, true);
    spf.assign(n + 1, 0);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            spf[i] = i;
            for (ll j = 1LL * i * i; j <= n; j += i) {
                is_prime[j] = false;
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}
vector<vector<int>> facts;
struct Query{
    int lq , rq , id;
};
vector<ll>a;
ll ans = 0;
int freq[N] , freq_freq[N];
void add(int idx){
    for(int s : facts[idx]) {
        if(freq[s]) freq_freq[freq[s]]--;
        freq[s]++;
        freq_freq[freq[s]]++;
        ans = max(ans , (ll)freq[s]);
    }
}

void rem(int idx){
    for(int s : facts[idx]) {
        freq_freq[freq[s]]--;
        freq[s]--;
        if(freq[s]) freq_freq[freq[s]]++;
        if(freq_freq[ans] == 0){
            ans -= 1;
        }
    }
}

vector<ll> MO(vector<Query>&queries){
    const int SQ = 317;
    sort(all(queries), [&](Query a , Query b){
        return make_pair(a.lq / SQ , a.rq) < make_pair(b.lq / SQ , b.rq);
    });
    vector<ll>res(queries.size());
    int l = queries[0].lq , r = queries[0].lq;
    add(l);
    for(const auto [lq , rq , id] : queries){
        while (l > lq) add(--l);
        while (r < rq) add(++r);
        while (l < lq) rem(l++);
        while (r > rq) rem(r--);
        res[id] = ans;
    }
    while(l <= r){
        rem(l++);
    }
    return res;
}

void TC() {
    int n , q;
    cin >> n >> q;
    a.assign(n , 0);
    facts.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int val = a[i];
        while(val != 1){
            int s = spf[val];
            facts[i].pb(s);
            while(val % s == 0) val /= s;
        }
    }
    vector<Query>queries(q);
    for (int i = 0; i < q; ++i) {
        auto &[lq , rq , id] = queries[i];
        cin >> lq >> rq;
        --lq , --rq , id = i;
    }
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
    sieve(N);
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}