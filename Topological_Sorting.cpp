// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/TOPOSORT/en/
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
const int N = 1e4 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<int>adj[N] , inDeg(N) , ans;
void bfs()
{
    priority_queue<int , vector<int> , greater<>>pq;
    for (int i = 1; i <= n; ++i) {
        if(inDeg[i] == 0)
            pq.emplace(i);
    }
    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        for(int u : adj[cur])
        {
            inDeg[u]--;
            if(inDeg[u] == 0)
            {
                pq.emplace(u);
            }
        }
        ans.emplace_back(cur);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        inDeg[b]++;
    }
    bfs();
    if(ans.size() != n)
        cout << "IMPOSSIBLE" << nl;
    else
    {
        for (int i = 0; i < n; ++i) {
            cout <<  ans[i] << sp;
        }
        cout << nl;
    }
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