// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cdn.vjudge.net.cn/81c566ac0d4de16114be3b9eced37614
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
double memo[76][76][76][2];
bool vis[76][76][76][2];
double solve(int c , int h , int x , bool who) {
    if(who and c + x == 75) return 1;
    if(who and c + x > 75) return 0;
    if(not who and h + x == 75) return 0;
    if(not who and h + x > 75) return 0;
    double &ret = memo[c][h][x][who];
    if(vis[c][h][x][who]) return ret;
    if(who){
        int op1 = 0 , op2 = 0;
        if(x)
            op1 = solve(c + x , h , 0 , false);
        for (int i = 2; i <= 6; ++i) {
            op2 += solve(c , h , x + i , true);
        }
        op2 /= 6;
        ret = max(op1 , op2);
    }else{
        int op1 = 0 , op2 = 0;
        if(x)
            op1 = solve(c , h + x , 0 , true);
        for (int i = 2; i <= 6; ++i) {
            op2 += solve(c , h , x + i , false);
        }
        op2 /= 6;
        ret = min(op1 , op2);
    }
    vis[c][h][x][who] = true;
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
    int q;
    cin >> q;
    memset(vis , false , sizeof vis);
    while(q--){
        int c , h , x;
        cin >> c >> h >> x;
        double ph = 0.0, pc = 0.0;
        if(x) ph = solve(c + x, h, 0, false);
        for (int i = 2; i <= 6; ++i) {
            pc += solve(c, h, x + i, true);
        }
        pc /= 6.0;
        cout << (ph > pc ? 'H' : 'C') << nl;
    }
    return 0;
}