// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1272/F
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
string s , t , ans;
int dp[205][205][405];
char par_ch[205][205][405];

int solve(int i , int j , int balance) {
    if (balance < 0 or balance > 400) return infLL;
    if (i == n and j == m) {
        return balance;
    }
    if (~dp[i][j][balance]) return dp[i][j][balance];
    int ret = infLL;
    char choose = 0;
    if (balance + 1 <= 400) {
        int ni = i + (i < n && s[i] == '(');
        int nj = j + (j < m && t[j] == '(');
        int cand = 1 + solve(ni, nj, balance + 1);
        if (cand < ret) {
            ret = cand;
            choose = '(';
        }
    }
    if (balance > 0) {
        int ni = i + (i < n && s[i] == ')');
        int nj = j + (j < m && t[j] == ')');
        int cand = 1 + solve(ni, nj, balance - 1);
        if (cand < ret) {
            ret = cand;
            choose = ')';
        }
    }
    dp[i][j][balance] = ret;
    par_ch[i][j][balance] = choose;
    return ret;
}

void build(int i, int j, int balance) {
    if (i == n && j == m) {
        for (int k = 0; k < balance; ++k) ans.push_back(')');
        return;
    }
    char c = par_ch[i][j][balance];
    if (c == '(') {
        ans.push_back('(');
        int ni = i + (i < n && s[i] == '(');
        int nj = j + (j < m && t[j] == '(');
        build(ni, nj, balance + 1);
        return;
    } else if (c == ')') {
        ans.push_back(')');
        int ni = i + (i < n && s[i] == ')');
        int nj = j + (j < m && t[j] == ')');
        build(ni, nj, balance - 1);
        return;
    } else {
        for (int k = 0; k < balance; ++k) ans.push_back(')');
        return;
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
    cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof dp);
    memset(par_ch, 0, sizeof par_ch);
    solve(0,0,0);
    build(0,0,0);
    cout << ans << nl;
    return 0;
    return 0;
}