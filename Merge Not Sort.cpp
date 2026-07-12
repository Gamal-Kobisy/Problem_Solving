// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1906/problem/E
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
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;


void TC() {
    int n;
    cin >> n;
    vector<int>a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    stack<int>st;
    st.push(2 * n);
    vector<int>nxtG(2 * n , 2 * n);
    for (int i = 2 * n - 1; i >= 0; --i) {
        while(st.top() != 2 * n and a[st.top()] <= a[i]) st.pop();
        nxtG[i] = st.top();
        st.push(i);
    }
    vector<pii>blocks;
    int idx = 0;
    while(idx < 2 * n){
        blocks.pb({idx , nxtG[idx] - 1});
        idx = nxtG[idx];
    }
    int k = blocks.size();
    vector<int> sz(k);
    for (int i = 0; i < k; ++i)
        sz[i] = blocks[i].sc - blocks[i].fr + 1;
    vector<vector<int>> memo(k + 1, vector<int>(n + 1, 0));
    memo[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int sum = 0; sum <= n; ++sum) {
            if (!memo[i][sum]) continue;
            memo[i + 1][sum] = 1;
            if (sum + sz[i] <= n)
                memo[i + 1][sum + sz[i]] = 1;
        }
    }
    if (not memo[k][n]) return void(cout << -1 << nl);
    vector<int> arr1, arr2;
    idx = k;
    int sum = n;
    while(idx > 0){
        if(memo[idx - 1][sum]){
            for(int i = blocks[idx - 1].sc ; i >= blocks[idx - 1].fr ; i--){
                arr1.pb(a[i]);
            }
        }else{
            for(int i = blocks[idx - 1].sc ; i >= blocks[idx - 1].fr ; i--){
                arr2.pb(a[i]);
            }
            sum -= sz[idx - 1];
        }
        idx--;
    }
    reverse(all(arr1)) , reverse(all(arr2));
    for(int i : arr1) cout << i << sp; cout << nl;
    for(int i : arr2) cout << i << sp; cout << nl;
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