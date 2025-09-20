// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102219/problem/J
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
vector<int>adj[6] , last , in_deg(6);
vector<bool>ancs(6) , vis(6);
bool imp = false;
void dfs(int v)
{
    ancs[v] = true;
    for(int u : adj[v])
    {
        if(ancs[u])
        {
            imp = true;
            return;
        }
        if(vis[u])
        {
            continue;
        }
        if(!vis[u])
        {
            dfs(u);
        }
    }
    vis[v] = true;
    ancs[v] = false;
    last.push_back(v);
}

void solve() {
    for(int i = 0 ; i < 5 ; i++)
    {
        string s;
        cin >> s;
        if(s[1] == '>')
        {
            adj[s[2] - 'A'].emplace_back(s[0] - 'A');
        }
        else
        {
            adj[s[0] - 'A'].emplace_back(s[2] - 'A');
        }
    }
    for (int i = 0 ; i < 5 ; i++) {
        if(!vis[i] && adj[i].size())
        {
            dfs(i);
        }
    }
    if(imp)
    {
        cout << "impossible" << nl;
    }
    else
    {
        reverse(all(last));
        for(char c : last)
        {
            cout << char(c + 'A');
        }
        for (ll i = 0; i < 5; ++i) {
            if(!vis[i])
            {
                cout << char(i + 'A');
            }
        }
    }
    cout << nl;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}