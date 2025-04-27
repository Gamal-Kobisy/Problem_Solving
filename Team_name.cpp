 // "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :

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
    srand(time(0));
    string name[] = { "yitm tanfeedh el-backtrack 3alina" , "El dp ehna awla beh"};
    map<string, ll>names;
    names["O(Zay ma teegy teegy)"];
    names["Ehna el talata test cases"];
    names["DP wel 2alb shariyeh"];
    names["Makhowafaty code hayaty"];
    names["El dp ehna awla beh"];
    names["El-code ye7kom"];
    names["yitm tanfeedh el-backtrack 3alina"];
    for (ll i = 0; i < 1000; ++i) {
        names[name[rand() % 2]]++;
    }
    for (auto i : names) {
        cout << i.first << " : " << i.second << nl;
    }
}

void file() {
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
    while (t--) {
        solve();
    }

    return 0;
}
