// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/UVA-10099/origin
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
const int N = 100 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n, r, s, d, p;
vector<pair<int, int>>adj[N];
vector<int>cap(N , 0);

void dijkstra()
{
    priority_queue<pair<int , int>>pq;
    pq.emplace(inf , s);
    cap[s] = inf;
    while(not pq.empty())
    {
        auto [curCap , curNode] = pq.top();
        pq.pop();
        if(curCap != cap[curNode])
            continue;
        for(auto [v ,w] : adj[curNode])
        {
            if(min(curCap , w) >cap[v])
            {
                cap[v] = min(curCap , w);
                pq.emplace(cap[v] , v);
            }
        }
    }
}

void solve(int t) {
    for (int i = 1 ; i <= n ; i++) adj[i].clear();
    fill(cap.begin(), cap.end(), 0);  // reset capacities

    for (int i = 0 , a , b, w ; i < r ; i++) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    cin >> s >> d >> p;

    dijkstra();

    ll effective = cap[d] - 1;
    ll trips = (p + effective - 1) / effective;

    cout << "Scenario #" << t << '\n';
    cout << "Minimum Number of Trips = " << trips << "\n\n";
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
    ENG_GAMAL
    int scenario = 1;
    while (cin >> n >> r) {
        if (n == 0 && r == 0) break;
        solve(scenario++);
    }
    return 0;
}
