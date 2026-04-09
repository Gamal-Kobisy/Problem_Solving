// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2218/problem/F
#include <bits/stdc++.h>
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
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int x , y;
    cin >> x >> y;
    int n = x + y;
    if(x == 0 and y % 2 == 0) return void(no);
    vector<int>odd(x + y) , even;
    vector<int>adj[x + y + 1];
    iota(all(odd) , 1);
    reverse(all(odd));
    if(n&1) swap(odd.front() , odd.back());
    while(x + y){
        if(x){
            if(odd.size() < 2 ) return void(no);
            int u = odd.back();
            odd.pop_back();
            int v = odd.back();
            odd.pop_back();
            adj[u].pb(v);
            even.pb(u);
            x--;
        }else{
            int cnt = odd.size();
            while(even.size() + cnt < y){
                if(odd.size() < 3) break;
                int a = odd.back();
                odd.pop_back();
                int b = odd.back();
                odd.pop_back();
                int c = odd.back();
                odd.pop_back();
                adj[b].pb(a);
                adj[b].pb(c);
                odd.pb(b);
                cnt++;
            }
            if(even.size() + cnt != y) return void(no);
            else break;
        }
    }
    for (int i = 0; i < even.size(); ++i) {
        if(even[i] == 1) continue;
        adj[1].pb(even[i]);
    }
    for (int i = 0; i < odd.size(); ++i) {
        if(odd[i] == 1) continue;
        adj[1].pb(odd[i]);
    }
    yes;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << i << sp << adj[i][j] << nl;
        }
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}