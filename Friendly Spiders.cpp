// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1775/D
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 6e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<int>adj[N];
vector<int>dist(N , -1) , par(N , -1);

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x = a[i];
        for (int j = 2; j * j <= x; ++j) {
            if(x % j) continue;
            adj[i].push_back(n + j);
            adj[n + j].push_back(i);
            while(x % j == 0) x /= j;
        }
        if(x > 1) {
            adj[i].push_back(n + x);
            adj[n + x].push_back(i);
        }
    }
    int s , t;
    cin >> s >> t;
    s-- , t--;
    dist[s] = 0;
    queue<int>q;
    q.push(s);
    while(not q.empty()){
        int curNode = q.front();
        q.pop();
        if(curNode == t) break;
        for(int v : adj[curNode]){
            if(~dist[v]) continue;
            dist[v] = dist[curNode] + 1;
            par[v] = curNode;
            q.push(v);
        }
    }
    if(~dist[t]){
        vector<int>path;
        int curNode = t;
        while(~curNode){
            if(curNode < n) path.push_back(curNode + 1);
            curNode = par[curNode];
        }
        cout << path.size() << nl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << sp;
        }
    } else {
        cout << -1 << nl;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}