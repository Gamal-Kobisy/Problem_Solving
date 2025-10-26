// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/gymProblem/102791/J
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
const int N = 4e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , memo[N][26];
vector<int> parts;
string s;
int solve(int idx , int c) {
    if(idx == n)
        return -infLL;
    if(idx == n - 1 and s[idx] == c + 'a')
        return 1;
    int &ret = memo[idx][c];
    if(~ret) return ret;
    ret = -infLL;
    if(s[idx] == c + 'a')
            ret = max(ret , solve(idx + 2 , s[idx + 1] - 'a') + 1);
    ret = max(ret , solve(idx + 1 , c));
    return ret;
}

void build(int idx, int c) {
    if (idx >= n) return;
    int start = idx - 1;
    for (int j = idx; j < n; ++j) {
        if (s[j] == char(c + 'a')) {
            int cand = (j == n - 1) ? 1 : (solve(j + 2, s[j + 1] - 'a') + 1);
            if (solve(idx , c) == cand) {
                parts.push_back(j - start + 1);
                if (j + 1 < n) build(j + 2, s[j + 1] - 'a');
                return;
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
    cin >> n >> s;
    memset(memo , -1 , sizeof memo);
    int ans = max(-1ll , solve(1 , s.front() - 'a'));
    cout << ans << nl;
    if(~ans){
        build(1 , s.front() - 'a');
        for(int i : parts)
            cout << i << sp;
    }

    return 0;
}