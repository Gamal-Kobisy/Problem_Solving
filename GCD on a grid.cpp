// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1955/G
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll gcd_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

void TC() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int g = gcd(grid[0][0] , grid[n - 1][m - 1]);
    set<int>divs;
    for (int i = 1; i * i <= g; ++i) {
        if(g % i) continue;
        divs.insert(-i);
        divs.insert(-g / i);
    }
    auto can = [&](int d) -> bool{
        bool memo[n + 1][m + 1];
        mem(memo , 0);
//        vector<vector<bool>>memo(n + 1 , vector<bool>(m + 1 , false));
        int cum = 0;
        for (int i = m - 1; i >= 0; --i) {
            cum = gcd(cum , grid[n - 1][i]);
            memo[n][i] = (cum % d == 0);
        }
        cum = 0;
        for (int i = n - 1; i >= 0; --i) {
            cum = gcd(cum , grid[i][m - 1]);
            memo[i][m] = (cum % d == 0);
        }
        // memo[i][j] = max(gcd(grid[i][j] , memo[i + 1][j]) , gcd(grid[i][j] , memo[i][j + 1]))
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
//                ll down  = gcd(grid[i][j] , memo[i + 1][j]);
//                ll right = gcd(grid[i][j] , memo[i][j + 1]);
//                if(down % d == 0) memo[i][j] = max(memo[i][j] , down);
//                if(right % d == 0) memo[i][j] = max(memo[i][j] , right);
                if(grid[i][j] % d)
                    continue;
                else{
                    memo[i][j] = memo[i + 1][j] || memo[i][j + 1];
                }
            }
        }
        return memo[0][0];
    };
    for(int d : divs){
        if(can(-d)){
            cout << -d << nl;
            break;
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}