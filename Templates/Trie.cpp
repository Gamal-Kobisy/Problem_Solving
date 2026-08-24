// ==============================================================================
// TRIE (PREFIX TREE / DICTIONARY)
// ==============================================================================
// A tree that stores a set of strings so that every prefix of every string is a
// single shared node. Enables fast prefix queries, lexicographic order queries
// and counting strings under a prefix.
//
// -------------------------------------------------------------------------------
// NOTATION USED FOR COMPLEXITY:
//   L = length of the queried string / prefix
//   A = alphabet size (max 26 for lowercase) = branching factor per node
//   N = total number of characters over all inserted strings
// -------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char, int> nxt;   // child per character (only existing chars)
    int isEnd = 0;                  // # of strings that END exactly here (>1 = duplicates)
    int sz = 0;                     // subtree size: # of strings passing through (or ending at) this node

    int &operator[](char x) {
        return nxt[x];
    }
};

struct Trie {
    vector<Node> tr;

    // Allocates a fresh node and returns its index. Root is node 0.
    // COMPLEXITY: O(1) amortized
    int newNode() {
        tr.emplace_back();
        return tr.size() - 1;
    }

    // Constructs the root node.
    Trie() { tr.clear(), newNode(); }

    /*
     * HOW TO USE: insert(string)
     * WHEN TO USE: Adding a string to the dictionary (duplicates allowed).
     * WHAT IT DOES: walks/creates the path, then increments isEnd of the last node.
     * COMPLEXITY: O(L)
     */
    void insert(const string &s) {
        int u = 0;
        for (char c: s) {
            if (!tr[u][c])
                tr[u][c] = newNode();
            tr[u].sz++;                 // one more string passes through this node
            u = tr[u][c];
        }
        tr[u].sz++;                     // the string also passes through its end node
        tr[u].isEnd++;                  // a string ends exactly here
    }

    /*
     * HOW TO USE: search(string)
     * WHEN TO USE: Checking if a string is fully present in the dictionary.
     * WHAT IT RETURNS: bool - true iff 's' was inserted (isEnd counts duplicates).
     * COMPLEXITY: O(L)
     *
     * EXAMPLE:
     *   insert("car");  search("car") == true,  search("ca") == false
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   t.insert("car");
     *   cout << t.search("car") << "\n";   // 1
     */
    bool search(const string &s) {
        int u = 0;
        for (char c : s) {
            if (!tr[u].nxt.count(c)) return false;
            u = tr[u][c];
        }
        return tr[u].isEnd > 0;
    }

    /*
     * HOW TO USE: count_prefix(string)
     * WHEN TO USE: Counting how many dictionary strings have 'prefix' as a prefix.
     * WHAT IT RETURNS: int - number of strings starting with 'prefix' (0 if none).
     * COMPLEXITY: O(L)
     *
     * EXAMPLE:
     *   insert {"a", "ab", "abc", "b"}
     *   count_prefix("a") == 3,  count_prefix("ab") == 2,  count_prefix("z") == 0
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   for (auto s : {"a","ab","abc","b"}) t.insert(s);
     *   cout << t.count_prefix("a") << "\n";   // 3
     */
    int count_prefix(const string &prefix) {
        int u = 0;
        for (char c : prefix) {
            if (!tr[u].nxt.count(c)) return 0;
            u = tr[u][c];
        }
        return tr[u].sz;                // every string that reaches node u has this prefix
    }

    /*
     * HOW TO USE: longest_common_prefix()
     * WHEN TO USE: The longest string that is a prefix of EVERY inserted string.
     * WHAT IT RETURNS: string - the LCP of all dictionary strings.
     * COMPLEXITY: O(LCP) — walks down while there is exactly one child and no end.
     *
     * EXAMPLE:
     *   {"ab", "abc", "abd"} -> "ab" ;  {"x", "y"} -> ""
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   for (auto s : {"ab","abc","abd"}) t.insert(s);
     *   cout << t.longest_common_prefix() << "\n";   // "ab"
     */
    string longest_common_prefix() {
        string res;
        int u = 0;
        while (tr[u].nxt.size() == 1 && tr[u].isEnd == 0) {
            char c = tr[u].nxt.begin()->first;
            res += c;
            u = tr[u][c];
        }
        return res;
    }

    /*
     * HOW TO USE: all_with_prefix(string)
     * WHEN TO USE: Enumerating every dictionary string that starts with 'prefix'
     *              (e.g. auto-complete suggestions).
     * WHAT IT RETURNS: vector<string> - all such strings.
     * COMPLEXITY: O(size of subtree) = O(output + nodes visited)
     *
     * EXAMPLE:
     *   {"he", "hell", "hello"} + prefix "hel" -> {"hell", "hello"}
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   for (auto s : {"he","hell","hello"}) t.insert(s);
     *   auto v = t.all_with_prefix("hel");   // {"hell","hello"}
     */
    vector<string> all_with_prefix(const string &prefix) {
        int u = 0;
        for (char c : prefix) {
            if (!tr[u].nxt.count(c)) return {};
            u = tr[u][c];
        }
        vector<string> res;
        string cur = prefix;
        function<void(int)> dfs = [&](int v) {
            for (int t = 0; t < tr[v].isEnd; t++) res.push_back(cur);
            for (auto &p : tr[v].nxt) {
                cur += p.first;
                dfs(p.second);
                cur.pop_back();
            }
        };
        dfs(u);
        return res;
    }

    /*
     * HOW TO USE: kth_string(k)
     * WHEN TO USE: The k-th (1-indexed) dictionary string in lexicographic order.
     * WHAT IT RETURNS: string - the k-th smallest string, or "" if k is out of range.
     *   NOTE: strings are ordered by char ASCII; for a-z lowercase this is normal order.
     * COMPLEXITY: O(L * A log A) — sorts the children at each level (A <= 26).
     *
     * EXAMPLE:
     *   {"a", "ab", "b"}  ->  kth(1)="a", kth(2)="ab", kth(3)="b"
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   for (auto s : {"a","ab","b"}) t.insert(s);
     *   cout << t.kth_string(2) << "\n";   // "ab"
     */
    string kth_string(int k) {
        string res;
        int u = 0;
        while (k > 0) {
            if (tr[u].isEnd) {          // strings ending exactly here come first
                k--;
                if (k == 0) break;
            }
            vector<pair<char, int>> ch(tr[u].nxt.begin(), tr[u].nxt.end());
            sort(ch.begin(), ch.end());
            bool moved = false;
            for (auto &p : ch) {
                if (k <= tr[p.second].sz) {     // the k-th string lives in this subtree
                    res += p.first;
                    u = p.second;
                    moved = true;
                    break;
                }
                k -= tr[p.second].sz;
            }
            if (!moved) return "";              // k exceeds total number of strings
        }
        return res;
    }

    /*
     * HOW TO USE: rank_string(string)
     * WHEN TO USE: How many dictionary strings are strictly lexicographically
     *              smaller than 's' (its 0-based rank among all strings).
     * WHAT IT RETURNS: int - number of strings < s.
     * COMPLEXITY: O(L * A) — scan smaller children at each level (A <= 26).
     *
     * EXAMPLE:
     *   {"a", "ab", "b"}  ->  rank("ab") == 1,  rank("c") == 3
     *
     * HOW TO USE IN MAIN:
     *   Trie t;
     *   for (auto s : {"a","ab","b"}) t.insert(s);
     *   cout << t.rank_string("ab") << "\n";   // 1
     */
    int rank_string(const string &s) {
        int u = 0, rank = 0;
        for (char c : s) {
            rank += tr[u].isEnd;                // strings ending here are smaller
            for (auto &p : tr[u].nxt)           // every subtree with a smaller char
                if (p.first < c) rank += tr[p.second].sz;
            if (!tr[u].nxt.count(c)) return rank;
            u = tr[u][c];
        }
        return rank;                            // 's' itself (and longer extensions) not counted
    }
};
