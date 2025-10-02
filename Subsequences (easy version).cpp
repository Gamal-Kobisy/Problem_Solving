// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1183/E
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
int n , k;
string s;
map<string , int>dist;

void bfs(int k)
{
    queue<string>q;
    q.emplace(s);
    dist[s] = 0;
    k--;
    while(not q.empty() and k > 0)
    {
        string cur = q.front();
        q.pop();
        k--;
        for(int i = 0 ; i < cur.size() ; i++)
        {
            string adj = cur.substr(0 , i) + cur.substr(i + 1);
            if(dist.find(adj) == dist.end())
                q.emplace(adj) , dist[adj] = dist[cur] + 1;

        }
    }
}

void solve() {
    cin >> n >> k >> s;
    bfs(k);
    if(dist.size() < k)
        return void(cout << -1 << nl);
    vector<int>costs;
    for(auto [s , d] : dist)
    {
        costs.emplace_back(d);
    }
    ll ans = 0;
    sort(all(costs));
    for(int i = 0 ; i < k ; i++)
    {
        ans += costs[i];
    }
    cout << ans << nl;
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