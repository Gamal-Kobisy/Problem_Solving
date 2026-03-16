// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :  https://atcoder.jp/contests/abc367/tasks/abc367_f?lang=en
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
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

random_device rd;
mt19937  mt(rd());
ll rnd(ll l , ll r){
    return uniform_int_distribution<ll>(l, r)(mt);
}

void TC() {
    int n , q;
    cin >> n >> q;
    vector<int>replace(N);
    vector<int>a(n) , b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        replace[a[i]] = rnd(1 , 1e12);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        replace[b[i]] = rnd(1 , 1e12);
    }
    vector<ll>preA(n + 1) , preB(n + 1);
    for (int i = 1; i <= n; ++i) {
        preA[i] = preA[i - 1] + replace[a[i - 1]];
        preB[i] = preB[i - 1] + replace[b[i - 1]];
    }
    while(q--){
        int l1 , r1 , l2 , r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ((preA[r1] - preA[l1 - 1]) == (preB[r2] - preB[l2 - 1])) ? yes : no;
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