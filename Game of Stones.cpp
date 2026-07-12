// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.hackerrank.com/challenges/game-of-stones-1/problem
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
int memo[101];

int MEX(vector<int>a){
    int n = a.size();
    int seen[n];
    mem(seen , 0);
    for(int i : a) if(i < n) seen[i] = true;
    for(int i = 0 ; i < n ; i++) if(not seen[i]) return i;
    return n;
}

int getGrundyNumber(int val){
    if(val < 0) return inf;
    if(val == 0) return 0;
    int& res = memo[val];
    if(~res) return res;
    vector<int>childs;
    childs.pb(getGrundyNumber(val - 2));
    childs.pb(getGrundyNumber(val - 3));
    childs.pb(getGrundyNumber(val - 5));
    return res = MEX(childs);
}
void TC() {
    int n;
    cin >> n;
    int grundy = getGrundyNumber(n);
    cout << (grundy ? "First" : "Second") << nl;
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
    mem(memo , -1);
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}