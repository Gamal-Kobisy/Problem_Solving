// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/911/G
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int SQ = 500;
vector<vector<int>>B(SQ , vector<int>(101));
vector<int>a;

void build(){
    for (int i = 0; i < SQ; ++i) {
        iota(all(B[i]) , 0);
    }
}

inline void update(int l , int r , int x , int y){
    if (x == y) return;
    int bl = l / SQ;
    int br = r / SQ;
    if (bl == br) {
        for (int i = bl * SQ; i < min((int)a.size(), (bl + 1) * SQ); ++i) {
            a[i] = B[bl][a[i]];
        }
        iota(all(B[bl]) , 0);
        for (int i = l; i <= r; ++i) {
            if (a[i] == x) a[i] = y;
        }
    } else {
        for (int i = bl * SQ; i < (bl + 1) * SQ; ++i) {
            a[i] = B[bl][a[i]];
        }
        iota(all(B[bl]) , 0);
        for (int i = l; i < (bl + 1) * SQ; ++i) {
            if (a[i] == x) a[i] = y;
        }

        for (int b = bl + 1; b < br; ++b) {
            for (int v = 1; v <= 100; ++v) {
                if (B[b][v] == x) {
                    B[b][v] = y;
                }
            }
        }

        for (int i = br * SQ; i < min((int)a.size(), (br + 1) * SQ); ++i) {
            a[i] = B[br][a[i]];
        }
        iota(all(B[br]) , 0);
        for (int i = br * SQ; i <= r; ++i) {
            if (a[i] == x) a[i] = y;
        }
    }
}

void TC() {
    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build();

    int q;
    cin >> q;
    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--; r--;
        update(l, r, x, y);
    }
    for (int i = 0; i < n; ++i) {
        cout << B[i / SQ][a[i]] << sp;
    }
    cout << nl;
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