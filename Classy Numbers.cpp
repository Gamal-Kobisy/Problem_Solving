// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1036/problem/C
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

string s , l , r;
int memo[20][2][2][5];

int solve(int i , bool sm , bool lr , int nonZeros){
    if(nonZeros == 4) return 0;
    if(i == r.size()) return 1;
    int &res = memo[i][sm][lr][nonZeros];
    if(~res) return res;
    res = 0;
    int lower = lr ? 0 : l[i];
    int upper = sm ? 9 : r[i];
    for (int d = lower; d <= upper; ++d) {
        res += solve(
                i + 1,
                sm or d < r[i],
                lr or d > l[i],
                nonZeros + (d != 0)
                );
    }
    return res;
}

void TC() {
    cin >> l >> r;
    mem(memo , -1);
    while(l.size() < r.size()) l = '0' + l;
    for(char&x:l) x -= '0';
    for(char&x:r) x -= '0';
    cout << solve(0 , 0 , 0 , 0) << nl;
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