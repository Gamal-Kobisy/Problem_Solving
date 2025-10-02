// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/796/D
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

void solve() {
    int n , k , d;
    cin >> n >> k >> d;
    vector<int>adj[n + 1] , dist(n + 1 , inf) , keep(n) , par(n + 1) , stations(k);
    map<pair<int , int> , int>idx;
    for(int i = 0 ; i < k ; i++)
        cin >> stations[i];
    for(int i = 0 , a , b ; i < n - 1 ; i++)
    {
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        idx[{a , b}] = idx[{b , a}] = i + 1;
    }
    set<int>roads_to_del;
    queue<int>q;
    for(int i = 0 ; i < k ; i++)
    {
        q.emplace(stations[i]);
        dist[stations[i]] = 0;
    }
    while(not q.empty())
    {
        int cur = q.front();
        q.pop();
        if(dist[cur] == d)
            continue;
        for(int u : adj[cur])
        {
            if (u == par[cur])
                continue;
            if(dist[u] == inf)
            {
                par[u] = cur;
                dist[u] = dist[cur] + 1;
                keep[idx[{cur, u}]] = true;
                q.emplace(u);
            }
        }
    }
    for(int i = 1 ; i <= n - 1 ; i++)
        if(not keep[i])
            roads_to_del.insert(i);
    cout << roads_to_del.size() << nl;
    for(int i : roads_to_del)
        cout << i << sp;
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