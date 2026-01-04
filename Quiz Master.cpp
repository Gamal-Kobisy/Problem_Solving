// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1777/problem/C
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
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<int> divs[N];

void TC() {
    int n , m;
    cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    int lo = 0 , hi = 1e5 + 5 , ans = -1;
    while(lo <= hi){
        int md = (lo + hi) / 2;
        bool ok = false;

        unordered_map<int , int , custom_hash>freq;
        unordered_map<int , int , custom_hash>used;

        int l = 0;
        for (int i = 0; i < n; ++i) {

            if(used[a[i]] == 0){
                for(int d : divs[a[i]]){
                    if(d > m) continue;
                    freq[d]++;
                }
            }
            used[a[i]]++;
            while((a[i] - a[l]) > md){
                used[a[l]]--;
                if(used[a[l]] == 0){
                    for(int d : divs[a[l]]){
                        if(d > m) continue;
                        freq[d]--;
                        if(freq[d] == 0)
                            freq.erase(d);
                    }
                }
                l++;
            }
            if(freq.size() == m){
                ok = true;
                break;
            }
        }
        if(ok){
            ans = md;
            hi = md - 1;
        }else{
            lo = md + 1;
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

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
// ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}