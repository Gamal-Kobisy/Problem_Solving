// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/HIST2/
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
const int N = 15, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , a[N + 1] , memo[N + 1][1<<N] , memo2[N + 1][1<<N];

int solve(int i , int mask){
    if(not mask) return a[i];
    int &ret = memo[i][mask];
    if(~ret) return ret;
    ret = 0;
    int val = mask , j;
    while(val > 0){
        j = __lg(val);
        val ^= (1 << j);
        int nMask = mask ^ (1 << j);
        ret = max(ret , abs(a[j + 1] - a[i]) + solve(j + 1 , nMask));
    }
    return ret;
}


int solveCnt(int i , int mask){
    if(not mask) return 1;
    int &ret = memo2[i][mask];
    if(~ret) return ret;
    ret = 0;
    int val = mask , j;
    while(val > 0){
        j = __lg(val);
        val ^= (1 << j);
        int nMask = mask ^ (1 << j);
        if(abs(a[j + 1] - a[i]) + solve(j + 1 , nMask) == solve(i , mask)){
            ret += solveCnt(j + 1 , nMask);
        }
    }
    return ret;
}

void TC() {
    cin >> n;
    if(n <= 0) exit(0);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    mem(memo , -1);
    cout << solve(0 , (1 << n) - 1) + 2 * n << sp;
    mem(memo2 , -1);
    cout << solveCnt(0 , (1 << n) - 1) << nl;
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
    while(true) TC();

    return 0;
}