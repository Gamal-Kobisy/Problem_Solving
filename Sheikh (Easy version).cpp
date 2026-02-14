// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1732/C1
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
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct range{
    ll val;
    int l , r;
};

void TC() {
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll>preSum(n + 1) , preXor(n + 1);
    for (int i = 1; i <= n; ++i) {
        preSum[i] = preSum[i - 1] + a[i - 1];
        preXor[i] = preXor[i - 1] ^ a[i - 1];
    }
    auto calc = [&](int l , int r){
        return (preSum[r + 1] - preSum[l]) - (preXor[r + 1] ^ preXor[l]);
    };

    while(q--){
        int lq , rq;
        cin >> lq >> rq;
        range ans(-infLL , 0 , 0);
        auto check = [](range cand , range cur){
            if(cand.val > cur.val){
                return true;
            }else if(cand.val == cur.val){
                int len1 = cand.r - cand.l;
                int len2 = cur.r - cur.l;
                if(len1 < len2){
                    return true;
                }
            }
            return false;
        };
        for (int l = lq - 1; l < rq; ++l) {
            range cur(calc(l , rq - 1) , l , rq - 1);
            int lo = l , hi = rq - 1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                range cand(calc(l , mid) , l , mid);
                if(check(cur  , cand)){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                    cur = cand;
                }
            }
            if(check(cur , ans)) ans = cur;
        }
        cout << ans.l + 1 << sp << ans.r + 1 << nl;
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