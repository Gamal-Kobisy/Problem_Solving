// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/808/problem/G
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

vector<int> kmp(const string &s) {
  const int n = (int) s.length();
  vector<int> fail(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && s[i] != s[j]) j = fail[j - 1];
    j += (s[j] == s[i]);
    fail[i] = j;
  }
  return fail;
}

void compute_automaton(string s, vector<vector<int>> &aut) {
  s += '#';
  int n = s.size();
  vector<int> pi = kmp(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i]) {
        aut[i][c] = aut[pi[i - 1]][c];
      } else {
        aut[i][c] = i + ('a' + c == s[i]);
      }
    }
  }
}

void TC() {
    string s , pat;
    cin >> s >> pat;
    vector<vector<int>>aut;
    compute_automaton(pat , aut);
    vector memo(s.size() + 1 , vector<int>(pat.size() + 1 , -1));
    function<int(int , int)> solve = [&](int idx1 , int idx2){
        if(idx1 == s.size()) return 0;
        int &res = memo[idx1][idx2];
        if(~res) return res;
        if(s[idx1] == '?'){
            res = 0;
            for (int i = 0; i < 26; ++i) {
                int nxt = aut[idx2][i];
                int is_match = (nxt == pat.size() ? 1 : 0);
                res = max(res , is_match + solve(idx1 + 1 , nxt));
            }
        } else {
            int nxt = aut[idx2][s[idx1] - 'a'];
            int is_match = (nxt == pat.size() ? 1 : 0);
            res = is_match + solve(idx1 + 1 , nxt);
        }
        return res;
    };
    cout << solve(0 , 0) << nl;
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