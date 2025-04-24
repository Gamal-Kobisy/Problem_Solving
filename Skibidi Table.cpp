// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2093/problem/D
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
int arr[2][2];

void Operation1(ll n)
{
    ll i, j;
    cin >> i >> j;
	i--, j--;
    ll ans = 0;
    while (n > 1)
    {
		ans += arr[i / n][j / n] * (1LL << n);
        if (i >= n)
            i -= n;
        if(j >= n)
            j -= n;
        n /= 2;
    }
	cout << ans + arr[i][j] + 1 << nl;
}
void Operation2(ll n)
{
    ll num, x = 0, y = 0;
	cin >> num;

    while (num > 4)
    {
        if(num > 3 * n)
		{
			num -= 3 * n;
            y += n / 2;
		}
		else if (num > 2 * n)
		{
			num -= 2 * n;
			x += n / 2;
		}
		else if (num > n)
		{
			num -= n;
            x += n / 2;
			y += n / 2;
		}
        n /= 4;
    }
    x++, y++;
    if (num == 4)
        y++;
    else if (num == 3)
        x++;
    else if (num == 2)
        x++, y++;
    cout << x << sp << y << nl;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    arr[0][0] = 0;
    arr[1][1] = 1;
    arr[1][0] = 2;
    arr[0][1] = 3;
    while (q--)
    {
        string op;
		cin >> op;
		(op == "->") ? Operation1(n) : Operation2((1LL << n));
    }
}

int main() {
    ENG_GAMAL
        // test-independent code ——————————————————————
        // ———————————————————————————————————————————— 
        ll t = 1;
         cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
