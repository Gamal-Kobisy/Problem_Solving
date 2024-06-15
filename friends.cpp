//
// DATE : Created by Gamal on 6/8/2024.
// LINK : https://vjudge.net/contest/586365#problem/Z

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

bool has_triangle(vector<vector<int>> relation)
{
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5 ; ++j) {
            for (int k = 1; k <= 5 ; ++k) {
                if(relation[i][j] && relation[j][k] && relation[i][k])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    int n;
    vector<vector<int>> relation(6,vector<int>(6 , 0));
    cin >> n;
    f0(n)
    {
        int x , y;
        cin >> x >> y;
        relation[x][y]++;
        relation[y][x]++;
    }
    if(has_triangle(relation))
    {
        cout << "WIN\n";
    }
    else
    {
        vector<vector<int>> copm_relation(6,vector<int>(6 , 0));
        for (int i = 1; i < 6; ++i) {
            for (int j = 1; j < 6; ++j) {
                if(i != j)
                {
                    copm_relation[i][j] = 1 - relation[i][j];
                }
            }
        }
        if(has_triangle(copm_relation))
        {
            cout << "WIN\n";
        }
        else
        {
            cout << "FAIL\n";
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
