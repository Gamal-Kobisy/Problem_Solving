// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1462/F
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

void TC() {
    int n;
    cin >> n;
    vector<pii> seg(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        seg[i] = {l, r};
        s.insert(l);
        s.insert(r);
    }

    map<int,int> replace;
    int start = 1;
    for (int x : s) replace[x] = start++;

    for (int i = 0; i < n; ++i) {
        seg[i].fr = replace[seg[i].fr];
        seg[i].sc = replace[seg[i].sc];
    }

    vector<int> preL(start + 2, 0);
    vector<int> preR(start + 2, 0);

    for (auto [l, r] : seg) {
        preL[l]++;
        preR[r]++;
    }

    for (int i = 1; i < preL.size(); ++i) {
        preL[i] += preL[i - 1];
        preR[i] += preR[i - 1];
    }

    int mx = 0;

    for (auto [l, r] : seg) {
        int left_of = preR[l - 1];
        int right_of = n - preL[r];

        int cnt = n - left_of - right_of;
        mx = max(mx, cnt);
    }
    cout << n - mx << nl;
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