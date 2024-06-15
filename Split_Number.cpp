//
// DATE : Created by Gamal on 6/8/2024.
// LINK : https://vjudge.net/contest/586365#problem/F

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define f1(n) for(int i=1;i<n;i++)
#define f0(n) for(int i=0;i<n;++i)
#define fe(v) for(auto & it:v)
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T>
using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
string add_strings(string num1, string num2) {
    if (num1.size() < num2.size()) {
        swap(num1, num2);
    }

    int n1 = num1.size(), n2 = num2.size();
    string result = "";
    int carry = 0;
    for (int i = 0; i < n1; ++i) {
        int digit1 = num1[n1 - 1 - i] - '0';
        int digit2 = i < n2 ? num2[n2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        result += carry + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}

void solve() {
    ll l;
    cin >> l;
    string s , sum1 , sum2;
    cin >> s;
    ll index = l / 2;
    if( l % 2 == 0)
    {
        if(s[index] != '0')
        {
            sum1 = add_strings(s.substr(0 , index ) , s.substr(index  , l));
            cout << sum1 << nl;

        }
        else
        {
            while(s[index] == '0')
            {
                index++;
            }
            sum1 = add_strings(s.substr(0 , index ) , s.substr(index  , l));
            index = l / 2;
            while (s[index] == '0')
            {
                index--;
            }
            sum2 = add_strings(s.substr(0 , index) , s.substr(index , l));
            string result = (sum1.size() < sum2.size()) ? sum1 : ((sum1.size() == sum2.size()) ? min(sum1, sum2) : sum2);
            cout << result << nl;
        }
    }
    else
    {
        if(s[index] != '0')
        {
            sum1 = add_strings(s.substr(0 , index ) , s.substr(index  , l));
            sum2 = add_strings(s.substr(0, l / 2 + 1), s.substr(l / 2 + 1, l));
            string result = (sum1.size() < sum2.size()) ? sum1 : ((sum1.size() == sum2.size()) ? min(sum1, sum2) : sum2);
            cout << result << nl;

        }
        else
        {
            while(s[index] == '0')
            {
                index++;
            }
            sum1 = add_strings(s.substr(0 , index ) , s.substr(index  , l));
            index = l / 2;
            while (s[index] == '0')
            {
                index--;
            }
            sum2 = add_strings(s.substr(0 , index) , s.substr(index , l));
            string result = (sum1.size() < sum2.size()) ? sum1 : ((sum1.size() == sum2.size()) ? min(sum1, sum2) : sum2);
            cout << result << nl;
        }
    }

}
void solve_2() {
    int l;
    cin >> l;
    string n;
    cin >> n;

    int index1 = 0, index2 = 0;
    string result;

    if (l % 2 == 0) {
        if (n[l / 2] != '0') {
            result = add_strings(n.substr(0, l / 2), n.substr(l / 2, l));
        } else {
            for (int i = l / 2; i < l; ++i) {
                if (n[i] != '0') {
                    index1 = i;
                    break;
                }
            }
            for (int i = l / 2; i >= 0; --i) {
                if (n[i] != '0') {
                    index2 = i;
                    break;
                }
            }
            string m1 = add_strings(n.substr(0, index1), n.substr(index1, l));
            string m2 = add_strings(n.substr(0, index2), n.substr(index2, l));
            result = (m1.size() < m2.size()) ? m1 : ((m1.size() == m2.size()) ? min(m1, m2) : m2);
        }
    } else {
        if (n[l / 2] != '0') {
            string m1 = add_strings(n.substr(0, l / 2), n.substr(l / 2, l));
            string m2 = add_strings(n.substr(0, l / 2 + 1), n.substr(l / 2 + 1, l));
            result = (m1.size() < m2.size()) ? m1 : ((m1.size() == m2.size()) ? min(m1, m2) : m2);
        } else {
            for (int i = l / 2; i < l; ++i) {
                if (n[i] != '0') {
                    index1 = i;
                    break;
                }
            }
            for (int i = l / 2; i >= 0; --i) {
                if (n[i] != '0') {
                    index2 = i;
                    break;
                }
            }
            string m1 = add_strings(n.substr(0, index1), n.substr(index1, l));
            string m2 = add_strings(n.substr(0, index2), n.substr(index2, l));
            result = (m1.size() < m2.size()) ? m1 : ((m1.size() == m2.size()) ? min(m1, m2) : m2);
        }
    }

    cout << result << endl;
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
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}