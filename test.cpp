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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int grundy[N];


struct MEX{
    multiset<int>vis;
    set<int>unvis;

    void insert(int val){
        vis.insert(val);
        unvis.erase(val);
    }

    void erase(int val){
        auto it = vis.find(val);
        if(it == vis.end()) return;
        vis.erase(it);
        if(vis.find(val) == vis.end())
            unvis.insert(val);
    }

    int getMex(){
        return *unvis.begin();
    }
}mex;

void pre() {
    for (int i = 0; i < N; i++)
        mex.unvis.insert(i);
    grundy[0] = 0;
    for (int x = 1; x < N; x++) {
        for (int y = 1; y * y <= x; y++) {
            if(x % y) continue;
            mex.erase(grundy[x - y]);
            if(y != x / y)
                mex.erase(grundy[x - x / y]);
        }
        grundy[x] = mex.getMex();
        for (int d = 1; d * d <= x; d++) {
            if(x % d) continue;
            mex.insert(grundy[x - d]);
            if(d != x / d)
                mex.insert(grundy[x - x / d]);
        }

        mex.insert(grundy[x]);
    }
}

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    int XOR = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        XOR ^= grundy[a[i]];
    }
    cout << (XOR ? "Alice" : "Bob") << nl;
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
    pre();
// ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}