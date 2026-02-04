// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << setprecision(6);

    while (t--) {
        string s;
        cin >> s;

        string x = s;
        for (char &c : x) c = tolower(c);

        if (x == "nan") {
            cout << "NaN\n";
            continue;
        }

        if (x == "inf" || x == "+inf") {
            cout << "0\n";
            continue;
        }

        if (x == "-inf") {
            cout << "-0\n";
            continue;
        }

        double val = stod(s);
        double res = 1.0 / val;

        if (isnan(res)) {
            cout << "NaN\n";
        } else if (isinf(res)) {
            if (res > 0) cout << "inf\n";
            else cout << "-inf\n";
        } else {
            cout << res << '\n';
        }
    }
}