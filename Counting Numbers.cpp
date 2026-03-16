// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

ll memo[20][2][2][2][11];
string a , b;

ll solve(int i , bool sm , bool lr , bool st , int lastDigit){
    if(i == b.size()) return 1;
    ll &ret = memo[i][sm][lr][st][lastDigit];
    if(~ret) return ret;
    ret = 0;
    int lower = lr ? 0 : a[i];
    int upper = sm ? 9 : b[i];
    for(int d = lower ; d <= upper ; d++){
        if(d == lastDigit and st) continue;
        ret += solve(i + 1 ,
                     sm or d < b[i],
                     lr or d > a[i] ,
                     st or d > 0,
                     d);
    }
    return ret;
}

void TC() {
    cin >> a >> b;
    while(a.size() < b.size()) a = '0' + a;
    for(char &x : a) x -= '0';
    for(char &x : b) x -= '0';
    mem(memo, -1);
    cout << solve(0 , 0 , 0 , 0 , 10) << nl;
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