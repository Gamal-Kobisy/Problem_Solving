// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1525/D
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
int n , a[5001] , memo[5001][5001];
vector<int> occupied , space;
int solve(int occupied_idx , int space_idx) {
    if(occupied_idx >= occupied.size()) return 0;
    if(space_idx >= space.size()) return infLL;
    int &ret = memo[occupied_idx][space_idx];
    if(~ret) return ret;
    ret = min(solve(occupied_idx , space_idx + 1) ,
              solve(occupied_idx + 1 , space_idx + 1) + abs(occupied[occupied_idx] - space[space_idx]));
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
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i])
            occupied.emplace_back(i);
        else
            space.emplace_back(i);
    }
    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0) << nl;
    return 0;
}