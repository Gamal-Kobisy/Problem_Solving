//
// DATE : Created by Gamal on 7/19/2024.
// LINK : https://vjudge.net/contest/592750#problem/L

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;
ll digit_sum(string num)
{
    ll sum = 0;
    for(char c : num)
    {
        sum += c - '0';
    }
    return sum;
}

void solve()
{
    string num;
    cin >> num;
    ll even = 0;
    ll zero = 0;
    for(char c : num)
    {
        if(c == '0')
        {
            zero++;
        }
        if((c - '0') % 2 == 0)
        {
            even++;
        }
    }
    if(even >= 2 && zero >= 1)
    {
        if(digit_sum(num) % 9 == 0)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    else
    {
        cout << "NO" << nl;
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
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}
int main() {
    file();
    fast();
    ll t = 1;
     cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
