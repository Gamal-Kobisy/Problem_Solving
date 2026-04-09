// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2210/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;
    string s , t;
    cin >> n >> s >> t;
    vector<int>p1(n) , p2(n);
    stack<int>st;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') st.push(i);
        else{
            p1[i] = st.top();
            p1[st.top()] = i;
            st.pop();
        }
    }
    for (int i = 0; i < n; ++i) {
        if(t[i] == '(') st.push(i);
        else{
            p2[i] = st.top();
            p2[st.top()] = i;
            st.pop();
        }
    }
    int outer1 = 0;
    for (int i = 0; i < n; ++i) {
        if(p1[i] == n - i - 1) outer1++;
        else break;
    }
    int outer2 = 0;
    for (int i = 0; i < n; ++i) {
        if(p2[i] == n - i - 1) outer2++;
        else break;
    }
    if(outer1 != outer2) return void(no);
    int leafs1 = 0 , internal1 = 0;
    for (int i = outer1; i < n; ++i) {
        if(fabs(i - p1[i]) == 1) leafs1++;
        else internal1++;
    }
    int leafs2 = 0 , internal2 = 0;
    for (int i = outer1; i < n; ++i) {
        if(fabs(i - p2[i]) == 1) leafs2++;
        else internal2++;
    }
    ((leafs1 == leafs2) and (internal1 == internal2)) ? yes : no;
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}