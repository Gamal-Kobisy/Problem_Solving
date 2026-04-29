// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2111/problem/E
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
    int n, q;
    string s;
    cin >> n >> q >> s;

    map<pair<char, char>, set<int>> cnt;
    for (int i = 0; i < q; ++i) {
        char a, b;
        cin >> a >> b;
        if (a != b) cnt[{a, b}].insert(i);
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') continue;

        if (s[i] == 'b') {
            auto &ba = cnt[{'b', 'a'}];
            if (!ba.empty()) {
                ba.erase(ba.begin());
                s[i] = 'a';
            } else {
                auto &bc = cnt[{'b', 'c'}];
                auto &ca = cnt[{'c', 'a'}];
                if (!bc.empty()) {
                    auto it1 = bc.begin();
                    auto it2 = ca.lower_bound(*it1);
                    if (it2 != ca.end()) {
                        bc.erase(it1);
                        ca.erase(it2);
                        s[i] = 'a';
                    }
                }
            }
        }
        else if (s[i] == 'c') {
            auto &ca = cnt[{'c', 'a'}];
            if (!ca.empty()) {
                ca.erase(ca.begin());
                s[i] = 'a';
            } else {
                auto &cb = cnt[{'c', 'b'}];
                auto &ba = cnt[{'b', 'a'}];
                if (!cb.empty()) {
                    auto it1 = cb.begin();
                    auto it2 = ba.lower_bound(*it1);
                    if (it2 != ba.end()) {
                        cb.erase(it1);
                        ba.erase(it2);
                        s[i] = 'a';
                    } else {
                        cb.erase(it1);
                        s[i] = 'b';
                    }
                }
            }
        }
    }

    cout << s << nl;
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