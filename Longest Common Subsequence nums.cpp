// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/3403
#include <bits/stdc++.h>
#define ll long long
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
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m , a[N] , b[N] , memo[N][N];
vector<int>ans;

int calc(int idx1 , int idx2){
    if(idx1 == n or idx2 == m)
        return 0;
    int &ret = memo[idx1][idx2];
    if(~ret)
        return ret;
    ret = 0;
    if(a[idx1] == b[idx2])
        ret = max(ret , calc(idx1 + 1 , idx2 + 1) + 1);
    ret = max(ret , calc(idx1 + 1 , idx2));
    ret = max(ret , calc(idx1 , idx2 + 1));
    return ret;
}

void build(int idx1 , int idx2){
    if(idx1 == n or idx2 == m)
        return;
    if(a[idx1] == b[idx2]){
        ans.emplace_back(a[idx1]);
        build(idx1 + 1 , idx2 + 1);
    }
    else{
        if(calc(idx1 + 1 , idx2) > calc(idx1 , idx2 + 1)){
            build(idx1 + 1 , idx2);
        }
        else{
            build(idx1 , idx2 + 1);
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    memset(memo , -1 , sizeof memo);
    calc(0 , 0);
    build(0 , 0);
    cout << ans.size() << nl;
    for(int i : ans){
        cout << i << sp;
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