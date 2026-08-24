// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
const int MOD = 1e9 + 7;

int modPow(long long a, int e, int mod) {
    long long res = 1;
    a = (a % mod + mod) % mod; // handle negatives
    while (e) {
        if (e & 1) res = res * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return res;
}

int modInv(int x, int mod) { return modPow(x, mod - 2, mod); }
void fwht(vector<int>& a, bool invert) {
    int n = a.size();
    for (int len=2; len<=n; len<<=1) for (int i=0; i<n; i+=len) for (int j=0; j<len/2; j++) {
        int u=a[i+j], v=a[i+j+len/2];
        a[i+j]=u+v; a[i+j+len/2]=u-v;
    }
    if (invert) for (int& x:a) x/=n;
}

vector<int> poly_pow(vector<int> a, int p, int M) {
    int n = 1;
    while (n < a.size()) n <<= 1; // Pad to nearest power of 2
    a.resize(n, 0);

    auto fwht_mod = [&](vector<int>& v, bool inv) {
        for (int len = 2; len <= n; len <<= 1) {
            for (int i = 0; i < n; i += len) {
                for (int j = 0; j < len / 2; ++j) {
                    long long u = v[i + j];
                    long long v2 = v[i + j + len / 2];
                    v[i + j] = (u + v2) % M;
                    v[i + j + len / 2] = (u - v2 + M) % M;
                }
            }
        }
        if (inv) {
            int inv_n = modInv(n, M);
            for (int &x : v) x = (int)(1LL * x * inv_n % M);
        }
    };

    // 1. Forward transform
    fwht_mod(a, false);

    // 2. Pointwise exponentiation
    for (int i = 0; i < n; ++i) {
        a[i] = modPow(a[i], p, M);
    }

    // 3. Inverse transform
    fwht_mod(a, true);

    return a;
}
void TC() {
    int n , m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i=0; i<m; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        A[i] = w;
    }
    int maxV = *max_element(all(A));
    vector<int> freq(maxV+1, 0);
    for (int x:A) ++freq[x];
    fwht(freq, false);
    for (int i=0; i<int(freq.size()); ++i)
        freq[i] = 1 << freq[i];
    fwht(freq, true);
    int target;
    for (int i=0; i< freq.size(); ++i)
    {
        if (freq[i])
        {
            target = i;
            break;
        }
    }
    int lo = 1 , hi = m , ans = m;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        auto res = poly_pow(A , mid , LOG);
        bool ok = (res.size() > target and res[target]);
        if (ok)
        {
            ans = mid;
            lo = mid + 1;
        }else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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
