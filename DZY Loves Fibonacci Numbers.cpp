// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/446/C
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
const int SQ = 317;
int fib[N], pre_fib[N];
vector<ll>B(SQ), lazy(SQ), a;
void build(){
    fib[0] = fib[1] = 1;
    pre_fib[0] = 1;
    pre_fib[1] = 2;
    for (int i = 2; i < N; ++i) {
        fib[i] = add(fib[i - 1] , fib[i - 2]);
        pre_fib[i] = add(fib[i] , pre_fib[i - 1]);
    }
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        B[i / SQ] += a[i];
    }
}
void update(int l , int r){
    int idx = l;
    while(idx % SQ and idx <= r){
        a[idx] = add(a[idx] , fib[idx - l]);
        idx++;
    }
    while(idx + SQ - 1 <= r){
        int extra = sub(pre_fib[idx + SQ - 1], pre_fib[idx - 1]);
        lazy[idx / SQ] = add(lazy[idx / SQ] , extra);
        idx += SQ;
    }
    while(idx <= r){
        a[idx] += add(a[idx] , fib[idx - l]);
        idx++;
    }
}

int query(int l , int r){
    int idx = l;
    int res = 0;
    while(idx % SQ and idx <= r){
        res = add(a[idx] , res);
        idx++;
    }
    while(idx + SQ - 1 <= r){
        int extra = sub(pre_fib[idx + SQ - 1], pre_fib[idx - 1]);
        lazy[idx / SQ] = add(lazy[idx / SQ] , extra);
        idx += SQ;
    }
    while(idx <= r){
        a[idx] += add(a[idx] , fib[idx - l]);
        idx++;
    }
}

void TC() {
    int n, q;
    cin >> n >> q;
    a.assign(n , 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    while(q--){
        int ty , l , r;
        cin >> l >> r;
        --l , --r;
        if(ty&1){
            update(l , r);
        }else{
            cout << query(l , r) << nl;
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