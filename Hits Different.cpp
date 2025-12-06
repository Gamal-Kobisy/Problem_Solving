// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1829/G
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
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
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll memo[N];

int nearst_sum(int x){
    int lo = 1 , hi = 2000 , ans = 1;
    while (lo <= hi){
        int mid = (lo + hi) >> 1;
        ll sum = mid * (mid + 1) / 2;
        if(x <= sum){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

ll calc(int i){
    if (i <= 0) return 0;
    if(i == 1) return 1;
    ll &ret = memo[i];
    if(ret != -1) return ret;

    int r = nearst_sum(i);
    int left = i - r;
    int right = i - (r - 1);

    long long sum = 1LL * i * i;
    if (nearst_sum(i + 1) != r) {
        sum += calc(left);
    } else if (nearst_sum(i - 1) != r) {
        sum += calc(right);
    } else {
        sum += calc(left) + calc(right);
        int common = i - 2 * (r - 1);
        if (common > 0) sum -= calc(common);
    }

    ret = sum;
    return ret;
}

void TC() {
    int n;
    cin >> n;
    cout << calc(n) << nl;
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