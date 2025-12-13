// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1660/problem/D
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

ll calc(vector<int>a){

}

void TC() {
    int n;
    cin >> n;
    vector<vector<int>> segs;
    vector<pair<int,int>> seg_ranges;

    vector<int> temp;
    int start_idx = -1;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if(a) {
            if(temp.empty()) start_idx = i;
            temp.push_back(a);
        } else {
            if(!temp.empty()) {
                segs.push_back(temp);
                seg_ranges.push_back({start_idx, i-1});
                temp.clear();
            }
        }
    }

    if(not temp.empty()) {
        segs.push_back(temp);
        seg_ranges.push_back({start_idx, n-1});
        temp.clear();
    }
    int ans = -1;
    pii range = {-1 , -1};

    for (int i = 0; i < segs.size(); ++i) {
        vector<int> a = segs[i];
        int firstNeg = -1 , lastNeg = -1;
        int cnt2 = 0 , cntNeg = 0;

        for (int j = 0; j < a.size(); ++j) {
            if(a[j] < 0){
                if(firstNeg == -1) firstNeg = j;
                lastNeg = j;
                cntNeg++;
            }
            if(abs(a[j]) == 2) cnt2++;
        }

        if(cntNeg % 2 == 0) {
            if(cnt2 > ans) {
                ans = cnt2;
                range = seg_ranges[i];
            }
        } else {
            int left_cnt2 = 0;
            for(int j = firstNeg + 1; j < a.size(); ++j)
                if(abs(a[j]) == 2) left_cnt2++;

            int right_cnt2 = 0;
            for(int j = 0; j < lastNeg; ++j)
                if(abs(a[j]) == 2) right_cnt2++;

            if(left_cnt2 >= right_cnt2) {
                if(left_cnt2 > ans) {
                    ans = left_cnt2;
                    range = {seg_ranges[i].first + firstNeg + 1, seg_ranges[i].second};
                }
            } else {
                if(right_cnt2 > ans) {
                    ans = right_cnt2;
                    range = {seg_ranges[i].first, seg_ranges[i].first + lastNeg - 1};
                }
            }
        }
    }

    if(ans == -1) {
        cout << n << sp << 0 << nl;
    } else {
        cout << range.fi << sp << n - 1 - range.se << nl;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}