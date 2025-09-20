// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/510/C
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
vector<string>words(100);
vector<vector<int>>adj(26);
vector<bool>vis(26 , false) , ancs(26 , false);
vector<char> last;
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
    last.push_back(v + 'a');
}

void solve() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<int>v;
    for (ll i = 0; i < n - 1; ++i) {
        ll mini = min(words[i].size() , words[i + 1].size());
        bool valid = false;
        for (ll j = 0; j < mini; ++j) {
            if(words[i][j] != words[i + 1][j])
            {
                v.push_back(words[i][j] - 'a');
                adj[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                valid = true;
                break;
            }
        }
        if(!valid && (words[i].size() > words[i + 1].size()))
        {
            cout << "Impossible" << nl;
            return;
        }
    }
    for (int i = 0 ; i < 26 ; i++) {
        if(!vis[i] && adj[i].size())
        {
            dfs(i);
        }
    }
    if(imp)
    {
        cout << "Impossible" << nl;
    }
    else
    {
        reverse(all(last));
        for(char c : last)
        {
            cout << c;
        }
        for (ll i = 0; i < 26; ++i) {
            if(!vis[i])
            {
                cout << char(i + 'a');
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