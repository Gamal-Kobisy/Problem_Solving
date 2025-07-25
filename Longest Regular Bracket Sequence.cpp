// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/5/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
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
    string s , temp;
    cin >> s;
    vector<string>a;
    vector<ll>ans(s.size() + 1);
    ll balance = 0 , len;
    for (int i = 0; i < s.size(); ++i) {
        s[i] == ')' ? balance-- : balance++;
        if(balance < 0)
        {
            balance = 0;
            if(!temp.empty())
            {
                a.emplace_back(temp);
                temp.clear();
            }
            continue;
        }
        temp += s[i];
    }
    if(!temp.empty())
        a.emplace_back(temp);

    for (int idx = 0; idx < a.size(); ++idx) {
//        cout << a[idx] << nl;
        balance = 0 , len = 0;
        for (int i = a[idx].size() - 1; i >= 0; --i) {
            len++;
            if(a[idx][i] == '(')
                balance--;
            else
                balance++;
            if(balance == 0)
                ans[len]++ ;
            if(balance < 0)
                len = 0 , balance = 0;
        }
    }
    ans[0] = 1;
    for (int i = s.size(); i >= 0; --i) {
        if(ans[i])
        {
            cout << i << sp << ans[i] << nl;
            return;
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}