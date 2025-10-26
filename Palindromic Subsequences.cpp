// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2399
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int memo[1001][1001];
string s , ans;
int solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    int &ret = memo[l][r];
    if (ret != -1) return ret;
    if (s[l] == s[r]) {
        ret = solve(l + 1, r - 1) + 2;
    } else {
        ret = max(solve(l + 1, r), solve(l, r - 1));
    }
    return ret;
}

void build(int l, int r) {
    if (l > r) return;
    if (l == r) {
        ans.push_back(s[l]);
        return;
    }
    int target = solve(l, r);
    if (target == 0) return;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        bool found = false;
        for (int i = l; i <= r && !found; ++i) {
            if (s[i] != ch) continue;
            for (int j = r; j >= i && !found; --j) {
                if (s[j] != ch) continue;
                int val;
                if (i == j) val = 1;
                else {
                    if (i + 1 <= j - 1) val = solve(i + 1, j - 1) + 2;
                    else val = 2;
                }
                if (val == target) {
                    ans.push_back(ch);
                    build(i + 1, j - 1);
                    return;
                }
            }
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

signed main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    while(cin >> s){
        ans = "";
        memset(memo , -1 , sizeof memo);
        build(0 , s.size() - 1);
        string rev;
        for (int i = 0; i < solve(0 , s.size() - 1) / 2; ++i) {
            rev += ans[i];
        }
        reverse(all(rev));
        ans += rev;
        cout << ans << nl;
    }

    return 0;
}