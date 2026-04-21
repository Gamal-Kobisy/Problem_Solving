// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1335/E2
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

struct SEG {
    int freq[201];
    pii mx;
    SEG() {
        mem(freq,0);
        mx = {-inf , 1};
    }

    SEG(ll x){
        mem(freq,0);
        mx = {1 , x};
        freq[x]++;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        for(int i = 1 ; i <= 200 ; i++){
            ret.freq[i] = lf.freq[i] + rt.freq[i];
            ret.mx = max(ret.mx , {ret.freq[i] , i});
        }
        return ret;
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int i , ll val , int x , int lx , int rx){

        if(lx == rx){
            seg[x] = SEG(val);
            return;
        }

        if(i <= md)
            update(i , val , LF , lx , md);
        else
            update(i , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int i , ll val){
        update(i , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){

        if(l <= lx && rx <= r)
            return seg[x];

        if(rx < l || lx > r)
            return SEG();

        return merge(
                query(l , r , LF , lx , md),
                query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int> pos[201];
    vector<vector<int>>pre(n + 1 , vector<int>(200));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].pb(i);
        if(i){
            for (int c = 1; c <= 200; ++c) {
                pre[i][c] = pre[i - 1][c];
            }
        }
        pre[i][a[i]]++;
    }
    int ans = 0;
    for (int num = 1; num <= 200; ++num) {
        ans = max(ans, (int)pos[num].size());
    }
    for (int num = 1; num <= 200; ++num) {
        if(pos[num].empty()) continue;
        int sz = pos[num].size();
        for (int x = 1; x <= sz / 2; ++x) {
            int l = pos[num][x - 1] + 1;
            int r = pos[num][sz - x] - 1;
            if(l <= r){
                int y = 0;
                for (int c = 1; c <= 200; ++c) {
                    y = max(y, pre[r][c] - pre[l - 1][c]);
                }
                ans = max(ans , 2 * x + y);
            }
        }
    }
    cout << ans << nl;
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