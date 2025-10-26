// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
string s , t;
deque<deque<int>>pos1(26) , pos2(26);
int memo[26][1001][1001];
int solve(int idxc , int idx1 , int idx2) {
    int &ret = memo[idxc][idx1][idx2];
    if(~ret) return ret;
    ret = 0;
    for (int i = 0; i < 26; ++i) {
        auto next_idx1 = upper_bound(all(pos1[i]) , pos1[idxc][idx1]);
        auto next_idx2 = upper_bound(all(pos2[i]) , pos2[idxc][idx2]);
        if(next_idx1 != pos1[i].end() and next_idx2 != pos2[i].end())
            ret = max(ret , solve(i , next_idx1 - pos1[i].begin() , next_idx2 - pos2[i].begin()) + 1);
    }
    return ret;
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
    int tc = 1;
    cin >> tc;
    while(tc--){
        cin >> s >> t;
        memset(memo , -1 , sizeof memo);
        for (int i = 0; i < s.size(); ++i) {
            pos1[s[i] - 'a'].emplace_back(i);
        }
        for (int i = 0; i < t.size(); ++i) {
            pos2[t[i] - 'a'].emplace_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if(not pos1[i].empty() and not pos2[i].empty())
                ans = max(ans , solve(i , 0 , 0) + 1);
        }
        cout << ans << nl;
    }
    return 0;
}