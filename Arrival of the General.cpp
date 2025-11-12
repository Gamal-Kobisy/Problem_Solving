// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/144/A
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mx = -inf, mn = inf;
    int pos_max = -1, pos_min = -1;
    // find leftmost max
    for (int i = 1; i <= n; ++i) {
        if (a[i] > mx) {
            mx = a[i];
            pos_max = i;
        }
    }
    // find rightmost min
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= mn) {
            mn = a[i];
            pos_min = i;
        }
    }
    int moves = 0;
    // moves to bring max to front (position 1)
    moves += (pos_max - 1);
    // moves to bring min to end (position n)
    moves += (n - pos_min);
    // if max is to the right of min, after moving max to front the min shifts one to the right,
    // so we can save one move
    if (pos_max > pos_min) --moves;
    cout << moves << nl;
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
