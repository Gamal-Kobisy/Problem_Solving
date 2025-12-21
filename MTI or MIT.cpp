// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/640620/problem/C
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;cin >> n;
    string s;cin >> s;
    string mit1,mit2,mit3;
    string mti1,mti2,mti3;
    vector<char> mit = {'m','i','t'};
    vector<char> mti = {'m','t','i'};
    for (int i = 0; i < n; ++i) {
        mit1 += mit[i%3];
    }
    for (int i = 1; i < n+1; ++i) {
        mit2 += mit[i%3];
    }
    for (int i = 2; i < n+2; ++i) {
        mit3 += mit[i%3];
    }
    for (int i = 0; i < n; ++i) {
        mti1 += mti[i%3];
    }
    for (int i = 1; i < n+1; ++i) {
        mti2 += mti[i%3];
    }
    for (int i = 2; i < n+2; ++i) {
        mti3 += mti[i%3];
    }
    int mitcost[3] = {0};
    int mticost[3] = {0};
    for (int i = 0; i < n; ++i) {
        if (s[i] != mit1[i]) {
            mitcost[0]++;
        }
        if (s[i] != mit2[i]) {
            mitcost[1]++;
        }
        if (s[i] != mit3[i]) {
            mitcost[2]++;
        }
        if (s[i] != mti1[i]) {
            mticost[0]++;
        }
        if (s[i] != mti2[i]) {
            mticost[1]++;
        }
        if (s[i] != mti3[i]) {
            mticost[2]++;
        }
    }
    int minimit = INT_MAX,minimti = INT_MAX;
    for (int i = 0; i < 3; ++i) {
        minimit = min(mitcost[i],minimit);
    }
    for (int i = 0; i < 3; ++i) {
        minimti = min(mticost[i],minimti);
    }
    if (minimti == minimit) {
        cout << "FAKE" << endl;
        return;
    }
    if (minimit < minimti) {
        cout << "mit" << ' ' << minimit << endl;
    }else {
        cout << "mti" << ' ' << minimti << endl;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}