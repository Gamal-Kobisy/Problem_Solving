// LINK : https://codeforces.com/contest/1980/problem/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll gcd_Vector(const std::vector<ll>& nums) {
    ll result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = gcd(result, nums[i]);
        if (result == 1) {
            return 1; // GCD is 1, no need to continue
        }
    }
    return result;
}
bool is_non_decreasing(const vector<int>& b) {
    for (int i = 1; i < b.size(); i++) {
        if (b[i] < b[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to compute the GCD sequence after removing the element at index 'idx'
bool check_after_removal(const vector<int>& a, int idx) {
    vector<int> temp_a;
    for (int i = 0; i < a.size(); i++) {
        if (i != idx) {
            temp_a.push_back(a[i]);
        }
    }

    vector<int> temp_b(temp_a.size() - 1);
    for (int i = 0; i < temp_a.size() - 1; i++) {
        temp_b[i] = gcd(temp_a[i], temp_a[i + 1]);
    }

    return is_non_decreasing(temp_b);
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Calculate the GCD sequence
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; i++) {
            b[i] = gcd(a[i], a[i + 1]);
        }

        // Identify the violation
        int violation = -1;
        for (int i = 0; i < n - 2; i++) {
            if (b[i] > b[i + 1]) {
                violation = i;
                break;
            }
        }

        // If no violation, return YES
        if (violation == -1) {
            cout << "YES" << endl;
            continue;
        }

        // Try removing either a[violation], a[violation + 1], or a[violation + 2] (if it exists)
        bool possible = false;

        // Case 1: Remove the element a[violation]
        possible = check_after_removal(a, violation);

        // Case 2: Remove the element a[violation + 1]
        if (!possible && violation + 1 < n) {
            possible = check_after_removal(a, violation + 1);
        }

        // Case 3: Remove the element a[violation + 2] (if it exists)
        if (!possible && violation + 2 < n) {
            possible = check_after_removal(a, violation + 2);
        }

        // Output result
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}