// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1111/
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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
#define fi first
#define se second
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

const ll MOD1 = 1e9 + 123;
const ll MOD2 = 2e9 + 333;
const int BASE = 313;
ll pw1[N], pw2[N];
ll invB1, invB2;
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

void initHash() {
    pw1[0] = 1; pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = (pw1[i - 1] * BASE) % MOD1;
        pw2[i] = (pw2[i - 1] * BASE) % MOD2;
    }
    invB1 = modInverse(BASE, MOD1);
    invB2 = modInverse(BASE, MOD2);
}

struct HashString {
    int len;
    ll h1, h2;

    HashString() {
        len = h1 = h2 = 0;
    }
    void push_back(char c) {
        h1 = (h1 * BASE + c) % MOD1;
        h2 = (h2 * BASE + c) % MOD2;
        len++;
    }

    void pop_back(char c) {
        h1 = (h1 - c + MOD1) % MOD1;
        h2 = (h2 - c + MOD2) % MOD2;

        h1 = (h1 * invB1) % MOD1;
        h2 = (h2 * invB2) % MOD2;
        len--;
    }

    void push_front(char c) {
        h1 = (h1 + c * pw1[len]) % MOD1;
        h2 = (h2 + c * pw2[len]) % MOD2;
        len++;
    }

    void pop_front(char c) {
        ll v1 = (c * pw1[len - 1]) % MOD1;
        ll v2 = (c * pw2[len - 1]) % MOD2;

        h1 = (h1 - v1 + MOD1) % MOD1;
        h2 = (h2 - v2 + MOD2) % MOD2;
        len--;
    }

    pll getHash() {
        return {h1, h2};
    }

    bool operator==(HashString& other) {
        return getHash() == other.getHash();
    }
};

void TC() {
    string s;
    cin >> s;
    int n = s.size();
    auto ok = [&](int sz){
        HashString h , rh;
        for (int i = 0; i < sz - 1; ++i) {
            h.push_back(s[i]);
            rh.push_front(s[i]);
        }

        for(int i = sz - 1 , j = 0 ; i < n ; i++ , j++){
            h.push_back(s[i]);
            rh.push_front(s[i]);
            if(h == rh)
                return true;
            h.pop_front(s[j]);
            rh.pop_back(s[j]);
        }
        return false;
    };

    int lo = 1 , hi = n / 2 , ansEv = 0 , ansOd = 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(ok(mid * 2)){
            ansEv = mid * 2;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    lo = 1 , hi = (n - 1) / 2;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(ok(mid * 2 + 1)){
            ansOd = mid * 2 + 1;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    int sz = max(ansOd , ansEv);

    auto calc = [&](){
        HashString h , rh;
        for (int i = 0; i < sz - 1; ++i) {
            h.push_back(s[i]);
            rh.push_front(s[i]);
        }

        for(int i = sz - 1 , j = 0 ; i < n ; i++ , j++){
            h.push_back(s[i]);
            rh.push_front(s[i]);
            if(h == rh)
                return s.substr(j , sz);
            h.pop_front(s[j]);
            rh.pop_back(s[j]);
        }
    };

    cout << calc() << nl;
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
    initHash();
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}