// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2004/E
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
const int N = 1e7 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int spf[N], grundy[N];
vector<int>primes;

void sieveSPF() {
    mem(spf , 0);
    grundy[1] = 1;
    int idx = 0;
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.pb(i);
            idx++;
            if (i & 1) grundy[i] = idx;
        }

        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            if (1ll * i * p >= N) break;
            spf[i * p] = p;
            if (p == spf[i]) break;
        }
    }
    for (int i = 3; i < N; i += 2) {
        if (spf[i] != i) {
            grundy[i] = grundy[spf[i]];
        }
    }
}

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    int XOR = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        XOR ^= grundy[a[i]];
    }
    cout << (XOR ? "Alice" : "Bob") << nl;
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
    sieveSPF();
// ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}