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
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    string s = "abcaabd";
    cin >> s;
    vector<vector<int>> pre(26 , vector<int>(s.length() + 1));
    for (int i = 0; i < s.length(); ++i)
    {
        pre[s[i] - 'a'][i + 1] = 1;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= s.length() ; ++j) {
            pre[i][j] += pre[i][j-1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int l , r;
        cin >> l >> r >> c;
        cout << pre[c - 'a'][r] - pre[c - 'a'][l - 1] << nl;
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
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}