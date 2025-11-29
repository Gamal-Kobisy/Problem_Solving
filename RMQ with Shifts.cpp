// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct segTree{
#define LF 2*x+1
#define RT 2*x+2
#define mid (lx+rx)/2

    int sz;
    vector<int>seg;

    segTree(int n){
        sz = n;
        seg = vector<int>(4 * sz + 1 , inf);
    }

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = val;
            return;
        }

        if(i <= mid){
            update(i , val , LF , lx , mid);
        }else{
            update(i , val , RT , mid + 1 , rx);
        }
        seg[x] = min(seg[LF] , seg[RT]);
    }

    int query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(rx < l or lx > r) return inf;
        if(lx >= l and rx <= r) return seg[x];
        return min(query(l , r , LF , lx , mid) ,
                   query(l , r , RT , mid +1 , rx));
    }
};

vector<int> extractInts(const string &s) {
    vector<int> v;
    int cur = 0;
    bool inNum = false;
    for (char c : s) {
        if (isdigit(c)) {
            cur = cur * 10 + (c - '0');
            inNum = true;
        } else {
            if (inNum) {
                v.push_back(cur);
                cur = 0;
                inNum = false;
            }
        }
    }
    if (inNum) v.push_back(cur);
    return v;
}

void TC() {
    int n, q;
    cin >> n >> q;
    segTree seg(n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        int val; cin >> val;
        a[i] = val;
        seg.update(i, val);
    }

    string op;
    while(q--){
        cin >> op;

        if (op[0] == 'q') {
            vector<int> v = extractInts(op);
            int L = v[0], R = v[1];
            cout << seg.query(L - 1, R - 1) << '\n';
        } else {
            vector<int> v = extractInts(op);
            for (int &x : v) x--;

            if (v.size() > 1) {
                int first = a[v[0]];
                for (int i = 0; i + 1 < (int)v.size(); i++) {
                    a[v[i]] = a[v[i+1]];
                    seg.update(v[i], a[v[i]]);
                }
                a[v.back()] = first;
                seg.update(v.back(), a[v.back()]);
            }
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