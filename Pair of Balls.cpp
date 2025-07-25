// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc216/tasks/abc216_d?lang=en
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;



void solve() {
    ll n , m;
    cin >> n >> m;
    vector<queue<ll>>a;
    vector<vector<ll>>idx(n + 1);
    vector<ll>top_cnt(n + 1);
    queue<ll>q;
    for (int i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        queue<ll>temp;
        for (int j = 0; j < k; ++j) {
            ll x;
            cin >> x;
            idx[x].emplace_back(i);
            temp.push(x);
        }
        top_cnt[temp.front()]++;
        if(top_cnt[temp.front()] == 2)
            q.push(temp.front());
        temp.pop();
        a.emplace_back(temp);
    }
    for (int x = 1; x <= n; ++x)
        if (idx[x].size() == 2 && idx[x][0] == idx[x][1])
            return void(no);

    ll op = 0;
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        ll idx1 = idx[cur][0];
        ll idx2 = idx[cur][1];
        if(!a[idx1].empty())
        {
        top_cnt[a[idx1].front()]++;
        if(top_cnt[a[idx1].front()] == 2)
            q.push(a[idx1].front());
        a[idx1].pop();
        }
        if(!a[idx2].empty())
        {
        top_cnt[a[idx2].front()]++;
        if(top_cnt[a[idx2].front()] == 2)
            q.push(a[idx2].front());
        a[idx2].pop();
        }
        op++;
    }
    op == n ? yes : no;
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