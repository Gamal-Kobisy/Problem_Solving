// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/204/problem/B
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

void solve() {
    long long n;
    cin >> n;
    map<long long, long long> front, back;
    for (long long i = 0; i < n; i++)
    {
        long long frst, scnd;
        cin >> frst >> scnd;
        front[frst]++;
        if (frst != scnd)
        {
            back[scnd]++;
        }
    }
    auto it = front.begin();
    auto it_2 = back.begin();
    long long min_moves = LLONG_MAX;
    for (; it != front.end(); it++, it_2++)
    {
        if (it->second >= ceil(double(n) / 2))
        {
            min_moves = 0;
            break;
        }
        else if (it->second + back[it->first] >= ceil(double(n) / 2))
        {
            min_moves = min(min_moves, (long long)(ceil(double(n) / 2) - it->second));
        }
        if (it_2->second >= ceil(double(n) / 2))
        {
            min_moves = min(min_moves, (long long)ceil(double(n) / 2));
        }
    }
    if (min_moves == LLONG_MAX)
    {
        min_moves = -1;
    }
    cout << min_moves << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}