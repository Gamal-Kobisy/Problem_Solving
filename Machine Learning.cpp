// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/940/problem/F
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

struct query {
    int idx, l, r, t;
};

struct update {
    int i, prevx, x;
};

const int SQ = 3153; // (2 * n) ^ 0.666
int freq[N] , freq_freq[N];
vector<query> queries;
vector<update> updates;
vector<int> arr;

bool cmp(const query &x, const query &y) {
    if (x.l / SQ != y.l / SQ)
        return x.l / SQ < y.l / SQ;
    if (x.r / SQ != y.r / SQ)
        return x.r / SQ < y.r / SQ;
    return x.t < y.t;
}

vector<ll> run(const vector<int> &initial_arr) {
    sort(queries.begin(), queries.end(), cmp);
    vector<ll> ans(queries.size());
    arr = initial_arr;
    int l = 0, r = 0, t = 0;
    auto add = [&](int x) {
        if(freq[x]) freq_freq[freq[x]]--;
        freq[x]++;
        freq_freq[freq[x]]++;
    };
    auto rem = [&](int x) {
        freq_freq[freq[x]]--;
        freq[x]--;
        if (freq[x] > 0) freq_freq[freq[x]]++;
    };
    auto get_mex = [&](){
        int mex = 1;
        while (freq_freq[mex] > 0) {
            mex++;
        }
        return mex;
    };
    add(arr[0]);
    for (const auto &q: queries) {
        while (r < q.r) add(arr[++r]);
        while (l > q.l) add(arr[--l]);
        while (r > q.r) rem(arr[r--]);
        while (l < q.l) rem(arr[l++]);

        while (t > q.t) {
            t--;
            if (q.l <= updates[t].i && q.r >= updates[t].i) {
                rem(updates[t].x);
                add(updates[t].prevx);
            }
            arr[updates[t].i] = updates[t].prevx;
        }

        while (t < q.t) {
            if (q.l <= updates[t].i && q.r >= updates[t].i) {
                rem(updates[t].prevx);
                add(updates[t].x);
            }
            arr[updates[t].i] = updates[t].x;
            t++;
        }

        ans[q.idx] = get_mex();
    }

    return ans;
}

void init(const vector<int> &initial_arr) {
    arr = initial_arr;
}

void add_query(int l, int r) {
    query cur{};
    cur.l = l;
    cur.r = r;
    cur.idx = queries.size();
    cur.t = updates.size();
    queries.emplace_back(cur);
}

void add_update(int idx, int val) {
    update cur{};
    cur.i = idx;
    cur.x = val;
    cur.prevx = arr[idx];
    arr[idx] = val;
    updates.emplace_back(cur);
}


void TC() {
    map<int, int> comp;
    int curr = 1;
    auto get_id = [&](int x) {
        if (comp.find(x) == comp.end()) {
            comp[x] = curr++;
        }
        return comp[x];
    };
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = get_id(a[i]);
    }
    mem(freq , 0);
    mem(freq_freq , 0);
    init(a);
    for (int i = 0; i < q; ++i) {
        int ty , l , r , idx , val;
        cin >> ty;
        if(ty&1){
            cin >>  l >> r;
            --l , --r;
            add_query(l , r);
        }else{
            cin >> idx >> val;
            --idx;
            add_update(idx, get_id(val));
        }
    }
    vector<ll> ans = run(a);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << nl;
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