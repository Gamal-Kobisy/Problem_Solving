// LINK : https://vjudge.net/contest/583461#problem/E
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
vector<string>words;
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
    last.push_back(v + 'A');
}

void solve() {
    while (true)
    {
        string s;
        cin >> s;
        if(s == "#")
        {
            break;
        }
        else
        {
            words.push_back(s);
        }
    }
    ll n = words.size();
    for (ll i = 0; i < n - 1; ++i) {
        ll mini = min(words[i].size() , words[i + 1].size());
        bool valid = false;
        for (ll j = 0; j < mini; ++j) {
            if(words[i][j] != words[i + 1][j])
            {
                adj[words[i][j] - 'A'].push_back(words[i + 1][j] - 'A');
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}