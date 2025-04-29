// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2094/problem/G
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
    ll q;
    cin >> q;
    deque<ll>d;
    ll reg , rev , sum , n;
    reg = rev = sum = n = 0;
    bool rev_flag = false;
    while (q--)
    {
        short s;
        cin >> s;
        if(s == 1)
        {
            if(!rev_flag)
            {
                reg -= d.back() * n;
                reg += sum;
                rev -= sum;
                rev += d.back() * n;
                d.emplace_front(d.back());
                d.pop_back();
            }
            else
            {
                reg -= d.front() * n;
                reg += sum;
                rev -= sum;
                rev += d.front() * n;
                d.emplace_back(d.front());
                d.pop_front();
            }
        }
        else if(s == 2)
        {
            swap(reg , rev);
            rev_flag = !rev_flag;
        }
        else
        {
            ll x;
            cin >> x;
            if(!rev_flag)
            {
                sum += x;
                d.emplace_back(x);
                n++;
                reg += d.back() * n;
                rev += sum;
            }
            else
            {
                sum += x;
                d.emplace_front(x);
                n++;
                reg += d.front() * n;
                rev += sum;
            }
        }
        cout << reg << nl;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}