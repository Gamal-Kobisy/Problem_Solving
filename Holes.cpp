// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/13/E
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
const int SQ = 500;
vector<int>C, W, a;

void build(){
    int n = a.size();
    for (int i = n - 1; i >= 0; --i) {
        int nxt = i + a[i];
        if(i / SQ != nxt / SQ or nxt >= n){
            C[i] = 1;
            W[i] = i;
        }else{
            C[i] = C[nxt] + 1;
            W[i] = W[nxt];
        }
    }
}

void update(int idx , int val){
    a[idx] = val;
    int blkIdx = idx / SQ;
    int n = a.size();
    for (int i = idx; i >= blkIdx * SQ; --i) {
        int nxt = i + a[i];
        if(i / SQ != nxt / SQ or nxt >= n){
            C[i] = 1;
            W[i] = i;
        }else{
            C[i] = C[nxt] + 1;
            W[i] = W[nxt];
        }
    }
}

void query(int idx){
    int cnt = 0, who = idx, last = idx;
    while (who < a.size()) {
        cnt += C[who];
        last = W[who];
        who = W[who] + a[W[who]];
    }
    cout << last + 1 << sp << cnt << nl;
}

void TC() {
    int n , q;
    cin >> n >> q;
    a.assign(n , 0);
    W.assign(n , 0);
    C.assign(n , 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    while(q--){
        int ty , idx , val;
        cin >> ty >> idx;
        if(ty&1){
            query(--idx);
        }else{
            cin >> val;
            update(--idx , val);
        }
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