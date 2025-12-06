// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
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

bool is_palindrome(int l , int r){
    if(l >= r) return true;
    char &ret = pal[l][r];
    if(~ret) return ret;
    if(s[l] == s[r])
        ret = is_palindrome(l + 1 , r - 1);
    else
        ret = false;
    return ret;
}

void TC() {
    int n;
    cin >> n;
    string s , t;
    cin >> s >> t;
    for (int i = 0; i < n; ++i) {
    }
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]){
            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if(is_palindrome(i , j).valid){
                    found = true;
                    for (int k = i; k <= j; ++k) {
                        if(s[k] == '1'){
                            s[k] = '0';
                            seg.update(k , 0);
                        }else{
                            s[k] = '1';
                            seg.update(k , 1);
                        }
                    }
                }
            }
            if(not found){
                return void(cout << -1 << nl);
            }
        }
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        valid &= s[i] == t[i];
    }
    cout << valid << nl;
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