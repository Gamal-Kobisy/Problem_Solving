// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.hackerrank.com/challenges/digits-square-board-1/problem
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
int memo[30][30][30][30], board[30][30];

int MEX(vector<int>a){
    int n = a.size();
    bool seen[n];
    mem(seen , false);
    for(int i : a) if(i < n) seen[i] = true;
    for(int i = 0 ; i < n ; i++) if(not seen[i]) return i;
    return n;
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2 or num == 3) return true;
    if (num % 2 == 0 or num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 or num % (i + 2) == 0)
            return false;
    }
    return true;
}

bool valid(int l, int r, int u, int d)
{
    for (int i = u; i <= d; i++)
    {
        for (int j = l; j <= r; j++)
        {
            if (!isPrime(board[i][j]))
                return true;
        }
    }
    return false;
}

int getGrundy(int l, int r, int u, int d)
{
    if (!valid(l,r,u,d)) return 0;
    int &res = memo[l][r][u][d];
    if (~res) return res;

    vector<int> childs;
    for (int row = u; row < d; row++)
    {
        childs.pb(
                getGrundy(l,r,u,row)
                ^
                getGrundy(l,r,row+1,d)
        );
    }

    for (int col = l; col < r; col++)
    {
        childs.pb(
                getGrundy(l,col,u,d)
                ^
                getGrundy(col+1,r,u,d)
        );
    }

    return res = MEX(childs);
}

void TC() {
    mem(memo , -1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int g = getGrundy(0, n - 1, 0, n - 1);
    cout << (g ? "First" : "Second") << nl;
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