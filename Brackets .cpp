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

    struct Node {
        bool valid;
        int balance , minPref;
        Node(): balance(0), minPref(infLL) , valid(false) {}
        Node(int v): balance(v), minPref(v) , valid(false) {}
    };
    int sz;
    vector<Node>seg;


    Node merge(Node a , Node b){
        Node ret;
        ret.minPref = min(a.minPref , a.balance + b.minPref);
        ret.balance = a.balance + b.balance;
        ret.valid = (ret.minPref >= 0) and (ret.balance == 0);
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
        if(rx < l or lx > r) return Node(0);
        if(lx >= l and rx <= r) return seg[x];
        return merge(query(l , r , LF , lx , mid) ,
                     query(l , r , RT , mid + 1 , rx));
    }


};

void TC() {
    int n , q;
    string s;
    cin >> n >> s;
    segTree seg(n);
    for (int i = 0; i < n; ++i) {
        if(s[i] == ')')
            seg.update(i , -1);
        else
            seg.update(i , 1);
    }
    cin >> q;
    while (q--){
        int t , l , r , i , val;
        cin >> t;
        if(t != 0){
            t--;
            if(s[t] == ')'){
                seg.update(t , 1);
                s[t] = '(';
            }else{
                seg.update(t , -1);
                s[t] = ')';
            }
        }else{
            (seg.query(0 , n - 1).valid ? yes : no);
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

    for (int i = 1; i <= 10; ++i)
    {
        cout << "Test " << i << ":" << nl;
        TC();
    }

    return 0;
}