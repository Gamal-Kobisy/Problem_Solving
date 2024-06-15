//
// DATE : Created by Gamal on 6/9/2024.
// LINK : https://vjudge.net/contest/586365#problem/U

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
    int n, a, b;
    cin >> n >> a >> b;
    if(b > a)
    {
        swap(a,b);
    }
        int plates_a = ceil(((float)a / (a+b)) * n) ;
        int plates_b = floor(((float)b / (a+b)) * n) ;
        if(plates_b == 0)
        {
            plates_b++;
            plates_a--;
        }
        int ans =  min(floor(a / plates_a),floor(b / plates_b));
        plates_a = floor(((float)a / (a+b)) * n) ;
        plates_b = ceil(((float)b / (a+b)) * n) ;
        if(plates_a == 0)
        {
            plates_a++;
            plates_b--;
        }
        ans =  max(ans,(int)min(floor(a / plates_a),floor(b / plates_b)));
        cout << ans << nl;
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
