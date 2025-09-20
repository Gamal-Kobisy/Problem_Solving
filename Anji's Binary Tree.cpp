// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1900/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n;
vector<int>Right , Left;
string dir;

int dfs(int v)
{
    int mini = inf;
    if(Right[v])
        mini = min(mini , dfs(Right[v]) + (dir[v - 1] != 'R'));
    if(Left[v])
        mini = min(mini , dfs(Left[v]) + (dir[v - 1] != 'L'));
    if(not Right[v] and not Left[v])
        return 0;
    return mini;
}

void solve() {
    cin >> n;
    Right = Left = vector<int>(n + 1);
    cin >> dir;
    for(int i = 1 ; i <= n ; i++)
    {
        int l , r;
        cin >> l >> r;
        Left[i] = l;
        Right[i] = r;
    }

    cout << dfs(1) << nl;
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
    ll t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}