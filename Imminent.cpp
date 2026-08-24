// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/467645/problem/I
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
const int N = 1e4 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
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
int pow2[N];
int n;
int memo[N][M][3] , vid[N][M][3] , id = 0;
vector<string>a;
string s;
int solve(int idx , int len , int rel)
{
    if (idx == n)
        return len == s.size() and rel >= 1;
    int &res = memo[idx][len][rel];
    if (vid[idx][len][rel] == id) return res;
    res = solve(idx + 1 , len , rel);
    int newLen = len + a[idx].size();
    if (newLen > s.size())
    {
        res = add(res , pow2[n - 1 - idx]);
    }else
    {
            int newRel = rel;
            if (rel == 1) {
                string sub = s.substr(len, a[idx].size());
                if (a[idx] < sub) newRel = 0;
                else if (a[idx] > sub) newRel = 2;
                else newRel = 1;
            }
        res = add(res , solve(idx+1 , newLen , newRel));
    }
    vid[idx][len][rel] = id;
    return res;
}
void TC() {
    cin >> n;
    a = vector<string>(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    // while (s.size() < sum) s.push_back('0');
    cout << solve(0 , 0 , 1) << nl;
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
    pow2[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        pow2[i] = mul(pow2[i-1] , 2);
    }
    mem(vid , -1);
    // ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
        id++;
    }

    return 0;
}
