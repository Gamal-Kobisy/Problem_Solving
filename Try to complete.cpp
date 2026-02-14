// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/TRYCOMP/
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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
#define fi first
#define se second
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

struct Node{
    unordered_map<char , int>adj;
    int mxFreq = -inf , isEnd = 0;
    char mnChar = '$';
    int &operator[](char x){
        return adj[x];
    }
};

struct Trie {
    vector<Node>trie;

    int newNode(){
        trie.emplace_back();
        return trie.size() - 1;
    }

    void init(){
        trie.clear();
        newNode();
    }

    Trie(){
        init();
    }


    void insert(string &s){
        int u = 0;
        for(char x : s){
            if(!trie[u][x]){
                trie[u][x] = newNode();
            }
            u = trie[u][x];
        }
        trie[u].isEnd++;
    }

    void update(int u , int newFreq , char newChar){
        if(newFreq > trie[u].mxFreq){
            trie[u].mxFreq = newFreq;
            trie[u].mnChar = newChar;
        }else if(newFreq == trie[u].mxFreq){
            trie[u].mnChar = min(trie[u].mnChar , newChar);
        }
    }

    int insert(string &s , int idx , int u){
        if(idx == s.size()){
            trie[u].isEnd++;
            update(u , trie[u].isEnd , '$');
            return trie[u].isEnd;
        }
        char ch = s[idx];
        if(!trie[u][ch]){
            trie[u][ch] = newNode();
        }
        int curFreq = insert(s , idx + 1 , trie[u][ch]);
        update(u , curFreq , ch);
        return curFreq;
    }

    void query(string &s){
        int u = 0;
        for(char x : s){
            if(!trie[u][x]){
                cout << -1;
                return;
            }
            u = trie[u][x];
        }
        cout << s;
        char x;
        while((x = trie[u].mnChar) != '$'){
            cout << x;
            u = trie[u][x];
        }
        cout << sp << trie[u].mxFreq;
    }

};

void TC() {
    int n , q;
    cin >> n;
    Trie trie;
    while(n--){
        string s;
        cin >> s;
        trie.insert(s , 0 , 0);
    }
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        trie.query(s);
        cout << nl;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}