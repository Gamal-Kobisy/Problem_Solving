// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/UVA-348
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
int n , memo[11][11] , split_idx[11][11];
vector<pair<int , int>>mat;
int solve(int idx1 , int idx2) {
    if(idx1 == idx2) return 0;
    int &ret = memo[idx1][idx2];
    if(~ret) return ret;
    ret = infLL;
    for (int i = idx1 ; i < idx2; ++i) {
        int l = solve(idx1 , i);
        int r = solve(i + 1 , idx2);
        int cost = l + r + (mat[idx1].first * mat[i].second * mat[idx2].second);
        if(cost < ret){
            ret = cost;
            split_idx[idx1][idx2] = i;
        }
    }
    return ret;
}

string build(int idx1 , int idx2) {
    if(idx1 == idx2) {
        return "A" + to_string(idx1 + 1);
    }
    int k = split_idx[idx1][idx2];
    string left = build(idx1 , k);
    string right = build(k + 1 , idx2);
    return "(" + left + " x " + right + ")";
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
    int cs = 1;
    while (cin >> n && n) {
        memset(memo , -1 , sizeof memo);
        memset(split_idx , -1 , sizeof split_idx);
        mat = vector<pair<int , int>>(n);
        for (int i = 0; i < n; ++i) {
            cin >> mat[i].first >> mat[i].second;
        }
        solve(0 , n - 1);
        cout << "Case " << cs++ << ": " << build(0 , n - 1) << nl;
    }
}