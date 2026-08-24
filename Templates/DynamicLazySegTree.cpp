/*
 * Dynamic Lazy Segment Tree for Range Updates & Queries
 * 
 * How to Use:
 * -----------
 * 1. Create instance with domain range: DynamicLazySegTree seg(L, R);
 *    where L = min index, R = max index
 * 2. Apply range update: seg.update(l, r, val) - adds 'val' to all indices [l,r]
 * 3. Query range sum: seg.query(l, r) - returns sum of all values in [l,r]
 * 
 * Time Complexity:
 * - Update: O(log(R-L))
 * - Query:  O(log(R-L))
 * - Space:   Sparse - only creates nodes when needed (dynamic allocation)
 * 
 * Famous Applications:
 * ------------------
 * 1. Codeforces 339D - Xenia and Bit Operations (XOR queries with lazy propagation)
 * 2. POJ 3468 - A Simple Problem with Integers (range add, range sum)
 * 3. Dynamic programming optimizations on ranges (e.g., convex hull trick variants)
 * 4. Problems requiring O(n) space instead of O(4n) static trees
 * 5. Competitive programming with huge coordinate ranges (coordinates up to 1e9)
 * 
 * Tricks & Tips:
 * 1. Pre-reserve nodes if number of updates is known (faster than dynamic allocation)
 * 2. Node 0 is unused/dummy - root is always node 1
 * 3. Works well with coordinate compression for sparse data
 */
struct DynamicLazySegTree {
    struct Node {
        ll sum = 0;
        ll lazy = 0;
        int left = 0;
        int right = 0;
    };

    vector<Node> tree;
    ll L, R;

    DynamicLazySegTree(ll l, ll r, int reserve_nodes = 1e6) : L(l), R(r) {
        tree.reserve(reserve_nodes);
        tree.push_back({}); // Index 0: Dummy null node
        tree.push_back({}); // Index 1: Root node
    }

    // Safely gets the actual sum of a node including its pending lazy value
    ll get_sum(int node, ll lx, ll rx) {
        if (!node) return 0;
        return tree[node].sum + tree[node].lazy * (rx - lx + 1);
    }

    void push(int node, ll lx, ll rx) {
        if (tree[node].lazy == 0) return;

        tree[node].sum = tree[node].sum + tree[node].lazy * (rx - lx + 1);
        if (lx != rx) {
            if (!tree[node].left) {
                tree.push_back({});
                tree[node].left = tree.size() - 1;
            }
            if (!tree[node].right) {
                tree.push_back({});
                tree[node].right = tree.size() - 1;
            }
            tree[tree[node].left].lazy = tree[tree[node].left].lazy + tree[node].lazy;
            tree[tree[node].right].lazy = tree[tree[node].right].lazy + tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    void update(int node, ll lx, ll rx, ll ql, ll qr, ll val) {
        if (ql > rx || qr < lx) return;

        push(node, lx, rx);

        if (ql <= lx && rx <= qr) {
            tree[node].lazy = tree[node].lazy + val;
            return;
        }

        ll mid = lx + (rx - lx) / 2;
        if (!tree[node].left) {
            tree.push_back({});
            tree[node].left = tree.size() - 1;
        }
        if (!tree[node].right) {
            tree.push_back({});
            tree[node].right = tree.size() - 1;
        }

        update(tree[node].left, lx, mid, ql, qr, val);
        update(tree[node].right, mid + 1, rx, ql, qr, val);

        tree[node].sum = get_sum(tree[node].left, lx, mid) + get_sum(tree[node].right, mid + 1, rx);
    }

    ll query(int node, ll lx, ll rx, ll ql, ll qr) {
        if (!node || ql > rx || qr < lx) return 0;
        if (ql <= lx && rx <= qr) return get_sum(node, lx, rx);
        push(node, lx, rx);

        ll mid = lx + (rx - lx) / 2;
        return query(tree[node].left, lx, mid, ql, qr) + query(tree[node].right, mid + 1, rx, ql, qr);
    }

    void update(ll ql, ll qr, ll val) {
        update(1, L, R, ql, qr, val);
    }

    ll query(ll ql, ll qr) {
        return query(1, L, R, ql, qr);
    }
};