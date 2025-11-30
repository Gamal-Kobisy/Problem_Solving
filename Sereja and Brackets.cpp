// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/380/problem/C
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

    struct Node{
        int ans , close , open;
        Node(): ans(0), open(0), close(0) {}
        Node(char c){
            if(c == '('){
                ans = 0;
                open = 1;
                close = 0;
            } else {
                ans = 0;
                open = 0;
                close = 1;
            }
        }
    };
    int sz;
    vector<Node>seg;


    Node merge(Node a , Node b){
        Node ret;
        int match = min(a.open , b.close);
        ret.ans = a.ans + b.ans + 2 * match;
        ret.open = a.open + b.open - match;
        ret.close = a.close + b.close - match;
        return ret;
    }

    segTree(int n){
        sz = n;
        seg = vector<Node>(4 * sz + 1);
    }

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = Node(val);
            return;
        }

        if(i <= mid){
            update(i , val , LF , lx , mid);
        }else{
            update(i , val , RT , mid + 1 , rx);
        }
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    Node query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(rx < l or lx > r) return Node();
        if(lx >= l and rx <= r)
            return seg[x];
        Node left = query(l , r , LF , lx , mid);
        Node right = query(l , r , RT , mid + 1 , rx);
        return merge(left , right);
    }


};


void TC() {
    string s;
    cin >> s;
    segTree seg(s.size());
    for (int i = 0; i < s.size(); ++i) {
        seg.update(i , s[i]);
    }
    int q;
    cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        cout << seg.query(--l , --r).ans << nl;
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