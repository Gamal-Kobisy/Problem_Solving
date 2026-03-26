// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/NAJPF/
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

vector<int> KMP(string &s) {
    int n = (int) s.length();
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pos[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pos[j - 1];
        if (s[i] == s[j])
            pos[i] = j + 1;
        else
            pos[i] = 0;
    }
    return pos;
}

void TC() {
    string s , pat;
    cin >> s >> pat;
    vector<int> pos = KMP(pat) , idx;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        while(j > 0 and s[i] != pat[j]) j = pos[j - 1];
        if(s[i] == pat[j]) j++;
        if(j == pat.size()){
            idx.pb(i - j + 1);
            j = pos[j - 1];
        }
    }
    if(idx.empty()){
        cout << "Not Found" << nl << nl;
    }else{
        cout << idx.size() << nl;
        for(int i : idx) cout << i + 1 << sp;
        cout << nl << nl;
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