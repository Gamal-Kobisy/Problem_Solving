// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/432/D
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
    string s;
    cin >> s;
    vector pos = kmp(s);
    vector<int> freq(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        freq[pos[i]]++;
    }
    for (int i = s.size(); i > 0; i--) {
        if (pos[i - 1] > 0) {
            freq[pos[i - 1]] += freq[i];
        }
    }
    vector<pii>ans;
    ans.pb({s.size() , 1});
    int idx = s.size() - 1;
    while(pos[idx]){
        ans.pb({pos[idx] , freq[pos[idx]] + 1});
        idx = pos[idx] - 1;
    }
    reverse(all(ans));
    cout << ans.size() << nl;
    for(auto [p , f] : ans) cout << p << sp << f << nl;
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