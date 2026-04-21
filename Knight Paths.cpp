// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102644/problem/E
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

string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

const ll mod = 4294967296;

const unsigned ll MOD = 4294967296;

ll add(unsigned ll a, unsigned ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(unsigned ll a, unsigned ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(unsigned ll a, unsigned ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

typedef vector<unsigned  ll> row;
typedef vector<row> mat;

mat operator*(const mat &a, const mat &b) {
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    mat ret(r1, row(c2));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < r2; k++)
                ret[i][j] = add(ret[i][j] , mul(a[i][k] , b[k][j]));;
    return ret;
}

mat operator^(const mat &a, unsigned ll k) {
    mat ret(a.size(), row(a.size()));
    for (int i = 0; i < a.size(); i++)ret[i][i] = 1;
    for (mat tmp = a; k; tmp = tmp * tmp, k /= 2)if (k & 1)ret = ret * tmp;
    return ret;
}

void TC() {
    unsigned ll n;
    cin >> n;
    mat s = {row(65 , 0)}; // index 65 will be the prefix
    s[0][0] = 1;
    mat t(65 , row(65));
    t[64][64] = 1; // add old prefix to the current prefix
    auto valid = [&](int x , int y){
        return x >= 0 and x < 8 and y >= 0 and y < 8;
    };
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int x = i , y = j;
            int a = 8 * x + y;
            t[a][64] = 1; // sum all nodes to the prefix
//            t[a][a] = 1;
            for (int k = 0; k < 8; ++k) {
                int nx = x + knightx[k] , ny = y + knighty[k];
                if(valid(nx , ny)){
                    int b = 8 * nx + ny;
                    t[a][b] = 1;
                }
            }
        }
    }
    t = t ^ (n + 1); // this is because the prefix is lated with one from the answer
    s = s * t;
    cout << s[0][64] << nl;
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}