//To query the maximum value of the function for all x in [l, r], query only two points: l, r because the functions are convex.
struct Line {
    ll m, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &other) const {
        return m < other.m;
    }

    bool operator<(const ll &x) const {
        const Line *s = succ();
        if (!s)
            return 0;
        return b - s->b < (s->m - m) * x;
    }
};

// will maintain upper hull for maximum
struct HullDynamic : public multiset<Line, less<>> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end())
                return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->m == x->m && y->b <= x->b;
        return (ld) (x->b - y->b) * (z->m - y->m) >= (ld) (y->b - z->b) * (y->m - x->m);
    }

    void insert_line(ll m, ll b) {
        // for minimum
        //        m *= -1;
        //        b *= -1;
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y)))
            erase(next(y));
        while (y != begin() && bad(prev(y)))
            erase(prev(y));
    }

    ll query(ll x) {

        auto l = *lower_bound(x);
        //        return -(l.m * x + l.b) for minimum;
        return l.m * x + l.b;
    }
};


struct Line {
    ll m, b;

    ll value(ll x) {
        return m * x + b;
    }
};

// minimum query
// slopes must be added in monotonic order
// queries must also be monotonic
struct CHT {

    deque<Line> dq;

    // remove middle line if useless
    bool bad(Line l1, Line l2, Line l3) {

        return (__int128)(l3.b - l1.b) * (l1.m - l2.m)
            <= (__int128)(l2.b - l1.b) * (l1.m - l3.m);
    }

    void add(ll m, ll b) {

        // for maximum query:
        // m *= -1;
        // b *= -1;

        Line cur = {m, b};

        while (dq.size() >= 2 &&
            bad(dq[dq.size() - 2], dq.back(), cur))
            dq.pop_back();

        dq.push_back(cur);
    }

    ll query(ll x) {

        while (dq.size() >= 2 &&
            dq[0].value(x) >= dq[1].value(x))
            dq.pop_front();

        // for maximum query:
        // return -dq[0].value(x);

        return dq[0].value(x);
    }
};

string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};