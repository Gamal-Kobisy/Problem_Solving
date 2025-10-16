// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc281/tasks/abc281_e?lang=en
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll gcd_vector(const vector<int>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n , m , k;
    cin >> n >> m >> k;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    ordered_set<int>os;
    ll sum = 0;
    for(int i = 0 ; i < m ; i++)
        os.insert(a[i]);
    int cnt = 0;
    for(int i : os){
        sum += i;
        cnt++;
        if(cnt == k)
            break;
    }
    cout << sum << sp;
    for(int i = m ; i < n ; i++){
        os.insert(a[i]);
        int old = os.order_of_key(a[i - m]);
        int neww = os.order_of_key(a[i]);
        if(old < k)
            sum -= *os.find_by_order(old) , sum += *os.find_by_order(k);
        if(neww < k)
            sum -= *os.find_by_order(k) , sum += *os.find_by_order(neww);
        os.erase(os.find_by_order(old));
        cout << sum << sp;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}