// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2033/problem/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<long long, int> prefixSumMap;
    long long prefixSum = 0;
    int beautifulSegments = 0;
    prefixSumMap[0] = -1;  // Mark the prefix sum 0 as "before the start"

    int lastBeautifulEnd = -1;  // Tracks the last index of a beautiful segment

    for (int i = 0; i < n; ++i) {
        prefixSum += a[i];

        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            // Ensure the new beautiful segment doesn't overlap with the previous one
            if (prefixSumMap[prefixSum] >= lastBeautifulEnd) {
                beautifulSegments++;
                lastBeautifulEnd = i;
            }
            // Clear the prefix sum map after counting this segment
            prefixSumMap.clear();
            prefixSumMap[0] = i;  // Reset to start fresh after a beautiful segment
            prefixSum = 0;
        } else {
            prefixSumMap[prefixSum] = i;
        }
    }

    cout << beautifulSegments << endl;
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}