// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/526482/problem/D
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
vector<int> f(N, 2);
void precompute() {
    for (int i = 2; i * i < N; ++i) {
        for (int j = i * i; j < N; j += i * i) {
            f[j] = 1; // Any multiple of i^2 is NOT square-free
        }
    }
}

int getGrundy(int x) {
    if (x == 1) return 0;
    int sq = sqrt(x);
    if (1ll * sq * sq != x) return 1;
    return f[sq];
}

void TC() {
    int n;
    cin >> n;
    int Xor = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Xor ^= getGrundy(x);
    }
    cout << (Xor ? "Bolbol" : "Balabeelo") << nl;
}
void file()
{
    freopen("math.in", "r", stdin);
#ifndef ONLINE_JUDGE
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
    // test-independent code ——————————————————————
    precompute();
    // ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        // for (int i = 0 ; i < 2000 ; i++) cout << grundy(i) << nl;;
        TC();
    }

    return 0;
}
