// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1768/D
#include <bits/stdc++.h>
#define ll long long
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
int n;
vector<int>a , cycle , cycle_idx;
vector<bool>vis;

void flood_fill(int v , int c_idx)
{
    cycle.emplace_back(v);
    if(vis[v])
        return;
    cycle_idx[v] = c_idx;
    vis[v] = true;
    flood_fill(a[v] , c_idx);
}

void solve() {
    cin >> n;
    a = cycle_idx = vector<int>(n + 1);
    vis = vector<bool>(n + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int cycles = 0 , num = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(not vis[a[i]])
        {
            flood_fill(i , num++);
            cycles++;
            cycle.clear();
        }
    }
    bool found = false;
    for(int i = 1 ; i < n ; i++)
    {
        if(cycle_idx[i] == cycle_idx[i + 1])
        {
            found = true;
            break;
        }
    }
    if(found)
        cycles++;
    else
        cycles--;
    cout << n - cycles << nl;
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