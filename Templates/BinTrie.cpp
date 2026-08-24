// ==============================================================================
// BINARY TRIE (BINARY PREFIX TREE / XOR TRIE)
// ==============================================================================
// Stores a multiset of integers as a binary tree on their bits. Enables fast
// XOR queries (max/min XOR with a number), counting XOR values above/below a
// bound, and k-th smallest queries.
//
// -------------------------------------------------------------------------------
// CHANGEABLE PART #1 : NUMBER OF BITS 'M'
//   M = 30 -> supports 0 <= val < 2^30 (default, enough for int up to ~1e9)
//   M = 63 -> full long long range (use with non-negative values, or watch the
//             sign bit behaviour of negative numbers)
// -------------------------------------------------------------------------------
// NOTATION USED FOR COMPLEXITY (M is the bit length, n = #inserted numbers):
//   update   : O(M)
//   queries  : O(M)
//   memory   : O(M * n) nodes
// -------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int ch[2]{};    // child[0] = bit 0, child[1] = bit 1 (0 means "none")
    int sz = 0;     // # of numbers stored in this subtree

    int &operator[](int x) {
        return ch[x];
    }
};

template<int M = 30>
struct BT {
    vector<node> nodes;
    ll total = 0;               // number of stored numbers (root.sz stays 0 on purpose)

    int newNode() { return nodes.emplace_back(), nodes.size() - 1; }

    void init() { nodes.clear(), newNode(); total = 0; }

    BT() { init(); }

    /*
     * HOW TO USE: update(val, op)
     * WHEN TO USE: op = +1 inserts 'val', op = -1 removes it (must be present).
     * WHAT IT DOES: walks the bit path from the most significant bit, creating
     *   nodes as needed and adding 'op' to every subtree size along the way.
     * COMPLEXITY: O(M)
     *
     * EXAMPLE:
     *   BT<30> b;
     *   b.update(5, +1);   // insert 5
     *   b.update(5, -1);   // delete 5
     */
    /// +1 to add, -1 to delete
    void update(ll val, int op) {
        total += op;
        int u = 0;
        for (int i = M - 1; i >= 0; --i) {
            int v = val >> i & 1;
            if (!nodes[u][v]) {
                nodes[u][v] = newNode();
            }
            u = nodes[u][v];
            nodes[u].sz += op;
        }
    }

    /*
     * HOW TO USE: query(num, l)
     * WHEN TO USE: Count stored numbers 'a' with (a XOR num) >= l.
     * WHAT IT RETURNS: ll - the count. O(M)
     *
     * EXAMPLE:
     *   insert {1, 3, 5}
     *   query(0, 4) == 1   (a XOR 0 = a >= 4  ->  only 5)
     *   query(0, 0) == 3   (every number is >= 0)
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   for (int x : {1, 3, 5}) b.update(x, +1);
     *   cout << b.query(0, 4) << "\n";   // numbers >= 4 among {1,3,5} -> 1
     */
    /// Count the number of integers such that a[i] XOR num >= l
    ll query(ll num, ll l) {
        int u = 0;
        ll ans = 0;
        for (int i = M - 1; i >= 0; i--) {
            int btP = num >> i & 1, btL = l >> i & 1;
            if (btL) {
                u = nodes[u][!btP];
            } else {
                ans += nodes[nodes[u][!btP]].sz;
                u = nodes[u][btP];
            }
            if (!u)return ans;
        }
        return ans + nodes[u].sz;
    }

    /*
     * HOW TO USE: query(x)  (overloaded)
     * WHEN TO USE: The maximum value of (a XOR x) over all stored 'a'.
     * WHAT IT RETURNS: ll - the maximum XOR value. O(M)
     *
     * EXAMPLE:
     *   insert {3, 10};  query(5) == max(3^5, 10^5) == max(6, 15) == 15
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   b.update(3, +1); b.update(10, +1);
     *   cout << b.query(5) << "\n";   // 15
     */
    /// maximum value of a[i] XOR x
    ll query(int x) {
        ll ans = 0;
        int u = 0;
        for (int i = M - 1; i >= 0; --i) {
            int bt = x >> i & 1;
            if (nodes[nodes[u][!bt]].sz) {
                ans |= (1ll << i);
                u = nodes[u][!bt];
            } else {
                u = nodes[u][bt];
            }
        }
        return ans;
    }

    /*
     * HOW TO USE: min_xor(x)
     * WHEN TO USE: The minimum value of (a XOR x) over all stored 'a'.
     * WHAT IT RETURNS: ll - the minimum XOR value. O(M)
     *
     * EXAMPLE:
     *   insert {3, 10};  min_xor(5) == min(3^5, 10^5) == min(6, 15) == 6
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   b.update(3, +1); b.update(10, +1);
     *   cout << b.min_xor(5) << "\n";   // 6
     */
    ll min_xor(ll x) {
        ll ans = 0;
        int u = 0;
        for (int i = M - 1; i >= 0; --i) {
            int bt = x >> i & 1;
            if (nodes[nodes[u][bt]].sz) {       // prefer the bit equal to x's bit
                u = nodes[u][bt];
            } else {                            // forced to the opposite bit
                ans |= (1ll << i);
                u = nodes[u][!bt];
            }
        }
        return ans;
    }

    /*
     * HOW TO USE: count_xor_less(num, bound)
     * WHEN TO USE: Count stored numbers 'a' with (a XOR num) < bound.
     *   (The strict-less twin of query(num, l).)
     * WHAT IT RETURNS: ll - the count. O(M)
     *
     * EXAMPLE:
     *   insert {1, 3, 5};  count_xor_less(0, 4) == 2   (1 and 3 are < 4)
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   for (int x : {1, 3, 5}) b.update(x, +1);
     *   cout << b.count_xor_less(0, 4) << "\n";   // 2
     */
    ll count_xor_less(ll num, ll bound) {
        if (bound <= 0) return 0;
        int u = 0;
        ll ans = 0;
        for (int i = M - 1; i >= 0; i--) {
            int btN = num >> i & 1, btB = bound >> i & 1;
            if (btB) {
                // choosing (a bit = num bit) makes XOR bit 0 < bound bit 1: all count
                ans += nodes[nodes[u][btN]].sz;
                // continue with XOR bit 1 (equal to bound), i.e. a bit != num bit
                u = nodes[u][!btN];
            } else {
                // bound bit 0 => XOR bit must be 0 => a bit == num bit
                u = nodes[u][btN];
            }
            if (!u) break;                      // no number extends this prefix
        }
        return ans;                             // strictly less; equality is NOT counted
    }

    /*
     * HOW TO USE: kth(k)
     * WHEN TO USE: The k-th (1-indexed) smallest stored number.
     * WHAT IT RETURNS: ll - the value, or -1 if k is out of range. O(M)
     *
     * EXAMPLE:
     *   insert {3, 1, 2}  ->  kth(1)==1, kth(2)==2, kth(3)==3
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   for (int x : {3, 1, 2}) b.update(x, +1);
     *   cout << b.kth(2) << "\n";   // 2
     */
    ll kth(ll k) {
        if (k > total) return -1;            // k-th value is out of range
        int u = 0;
        ll ans = 0;
        for (int i = M - 1; i >= 0; i--) {
            int left = nodes[nodes[u][0]].sz;   // how many numbers with bit 0 here
            if (k <= left) {
                u = nodes[u][0];
            } else {
                ans |= (1ll << i);
                k -= left;
                u = nodes[u][1];
            }
        }
        return ans;
    }

    /*
     * HOW TO USE: count_le(val)
     * WHEN TO USE: Number of stored numbers <= val (their rank by value).
     * WHAT IT RETURNS: ll - the count. O(M)
     *
     * EXAMPLE:
     *   insert {1, 3, 5};  count_le(3) == 2,  count_le(4) == 2,  count_le(6) == 3
     *
     * HOW TO USE IN MAIN:
     *   BT<30> b;
     *   for (int x : {1, 3, 5}) b.update(x, +1);
     *   cout << b.count_le(3) << "\n";   // 2
     */
    ll count_le(ll val) {
        int u = 0;
        ll ans = 0;
        for (int i = M - 1; i >= 0; i--) {
            if (!u) break;
            int bt = val >> i & 1;
            if (bt) {
                ans += nodes[nodes[u][0]].sz;   // all numbers with bit 0 are < val here
                u = nodes[u][1];
            } else {
                u = nodes[u][0];
            }
        }
        return ans + nodes[u].sz;               // numbers exactly equal to val
    }
};
