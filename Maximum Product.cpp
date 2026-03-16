// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/100886/problem/G
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
int target;
ll memo[20][2][2][2];
string L , R;

ll calc(int i , bool sm , bool lr , bool st){
    if(i == R.size()) return st;
    ll &ret = memo[i][sm][lr][st];
    if(~ret) return ret;
    int lower = lr ? 0 : L[i];
    int upper = sm ? 9 : R[i];
    for (int d = lower; d <= upper; ++d) {
        ll mult = (!st && d == 0) ? 1 : d;
        ret = max(ret , mult * calc(
                i + 1,
                sm or d < R[i],
                lr or d > L[i],
                st or d > 0
        ));
    }
    return ret;
}

void build(int i , bool sm , bool lr , bool st , ll prod){
    if(i == R.size()) return;
    int lower = lr ? 0 : L[i];
    int upper = sm ? 9 : R[i];
    for (int d = lower; d <= upper; ++d) {
        ll mult = (!st && d == 0) ? 1 : d;
        ll val =  calc(
                i + 1,
                sm or d < R[i],
                lr or d > L[i],
                st or d > 0
        );
        if(mult * val == prod){
            if(st or d > 0) cout << d;
            build(i + 1,
                    sm or d < R[i],
                    lr or d > L[i],
                    st or d > 0,
                    val
                    );
            return;
        }
    }
}

ll solve(int i){
    target = i;
    mem(memo , -1);
    ll mx = calc(0 , 0 , 0 , 0);
    return  mx;
}

void TC() {
    cin >> L >> R;
    while(L.size() < R.size()) L = '0' + L;
    for(char&x : L) x -= '0';
    for(char&x : R) x -= '0';
    ll ans = -1;
    int best_sum = 0;
    for (int i = 1; i < 165; ++i) {
        ll current_prod = solve(i);
        if(current_prod > ans) {
            ans = current_prod;
            best_sum = i;
        }
    }
    mem(memo , -1);
    target = best_sum;
    build(0 , 0 , 0 , 0 , ans);
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