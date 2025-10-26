// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/245/problem/H
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
int q , memo[5001][5001];
char pal[5001][5001];
string s;

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

int solve(int l , int r) {
    if(l > r) return 0;
    int &ret = memo[l][r];
    if(~ret)
        return ret;
    ret = solve(l + 1 , r) +
            solve(l , r - 1) -
            solve(l + 1 , r - 1) +
            is_palindrome(l , r);
    return ret;
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
    cin >> s >> q;
    memset(memo , -1 , sizeof memo);
    memset(pal , - 1 , sizeof pal);
    while(q--){
        int l , r;
        cin >> l >> r;
        --l, --r;
        cout << solve(l , r) << nl;
    }

    return 0;
}