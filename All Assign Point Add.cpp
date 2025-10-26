// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc278/tasks/abc278_d?lang=en
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n ,q;
    cin >> n;
    vector<pair<int , int>>add(n);
    pair<int , int>assign = {0 , -1};
    for (int i = 0; i < n; ++i) {
        cin >> add[i].first;
        add[i].second = -1;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            assign = {x , i};
        }else if(op == 2){
            int idx ,  x;
            cin >> idx >> x;
            idx--;
            if(assign.second > add[idx].second){
                add[idx].first = assign.first + x;
            }else{
                add[idx].first += x;
            }
            add[idx].second = i;
        }else{
            int idx;
            cin >> idx;
            idx--;
            if(assign.second > add[idx].second){
                cout << assign.first << nl;
            } else {
                cout << add[idx].first << nl;
            }
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

signed main() {
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