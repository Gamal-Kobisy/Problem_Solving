// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/ELIS/en/
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
vector<int>ans;

void back(vector<int>curr , vector<int>rem)
{
    if(curr.size() > ans.size())
        ans = curr;
    if(!rem.size())
    {
        return;
    }
    bool found = false;
    for (ll i = 0; i < rem.size(); ++i) {
        vector<int> new_curr = curr , new_rem = rem;
        new_curr.emplace_back(rem[i]);
        new_rem.erase(new_rem.begin() , new_rem.begin() + i);
        if(curr.empty() || rem[i] > curr.back())
        {
            back(new_curr , new_rem);
            found = true;
        }
    }
    if(!found)
    {

    }
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    back(vector<int>(0) , a);
    cout << ans.size() << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}