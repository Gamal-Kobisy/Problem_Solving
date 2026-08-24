struct SEG {
    ll sum = 0;

    SEG() {}

    SEG(ll x){
        sum = x;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.sum = lf.sum + rt.sum;
        return ret;
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int i , ll val , int x , int lx , int rx){

        if(lx == rx){
            seg[x] = SEG(val);
            return;
        }

        if(i <= md)
            update(i , val , LF , lx , md);
        else
            update(i , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int i , ll val){
        update(i , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){

        if(l <= lx && rx <= r)
            return seg[x];

        if(rx < l || lx > r)
            return SEG();

        return merge(
            query(l , r , LF , lx , md),
            query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

struct SEG {
    ll sum = 0;
    ll pref = -1e16;
    ll suff = -1e16;
    ll ans = -1e16;

    SEG() {}

    SEG(ll x){
        sum = x;
        pref = x;
        suff = x;
        ans = x;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.sum = lf.sum + rt.sum;
        ret.pref = max(lf.pref, lf.sum + rt.pref);
        ret.suff = max(rt.suff, rt.sum + lf.suff);
        ret.ans = max({lf.ans, rt.ans, lf.suff + rt.pref});
        return ret;
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int i , ll val , int x , int lx , int rx){

        if(lx == rx){
            seg[x] = SEG(val);
            return;
        }

        if(i <= md)
            update(i , val , LF , lx , md);
        else
            update(i , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int i , ll val){
        update(i , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){

        if(l <= lx && rx <= r)
            return seg[x];

        if(rx < l || lx > r)
            return SEG();

        return merge(
            query(l , r , LF , lx , md),
            query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

struct Query{
    int lq , rq , id;
};
vector<int>a;
int ans = 0;
int freq[N];
void add(int val){
    if(val >= N) return;
    if(freq[val] == val) ans--;
    freq[val]++;
    if(freq[val] == val) ans++;
}

void rem(int val){
    if(val >= N) return;
    if(freq[val] == val) ans--;
    freq[val]--;
    if(freq[val] == val) ans++;
}

vector<int> MO(vector<Query>&queries){
    const int SQ = ceil(sqrt(N)) + 1;
    sort(all(queries), [&](Query a , Query b){
        return make_pair(a.lq / SQ , a.rq) < make_pair(b.lq / SQ , b.rq);
    });
    vector<int>res(queries.size());
    int l = queries[0].lq , r = queries[0].lq;
    add(a[l]);
    for(const auto [lq , rq , id] : queries){
        while (l > lq) add(a[--l]);
        while (r < rq) add(a[++r]);
        while (l < lq) rem(a[l++]);
        while (r > rq) rem(a[r--]);
        res[id] = ans;
    }
    return res;
}

ll fact[N] , modinv[N];

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll power(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans , b);
        b = mul(b , b);
        p /= 2;
    }
    return ans;
}

void pre(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1] , i);
    }
    modinv[N - 1] = power(fact[N - 1] , MOD - 2);
    for (int i = N - 2; i >= 0 ; --i) {
        modinv[i] = mul(i + 1  , modinv[i + 1]);
    }
}

ll nCr(int n, int r) {
    return mul(mul(fact[n], modinv[n - r]), modinv[r]);
}

ll nPr(int n, int r) {
    return mul(fact[n], modinv[n - r]);
}

// double n to use this
ll starsBars(int n , int k){
    return nCr(n + k - 1 , k - 1);
}

struct BIT {
private:
    int n;
    vector<int> B1, B2;

    void add(vector<int> &b, int idx, int x) {
        ++idx;
        while (idx <= n) {
            b[idx] += x;
            idx += idx & -idx;
        }
    }

    int sum(vector<int> &b, int idx) {
        idx++;
        int total = 0;
        while (idx > 0) {
            total += b[idx];
            idx -= idx & -idx;
        }
        return total;
    }

    int prefix(int idx) {
        return sum(B1, idx) * idx - sum(B2, idx);
    }

public:

    BIT(int n) : n(n) {
        B1.assign(n + 1, {});
        B2.assign(n + 1, {});
    }

    void update(int l, int r, int x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }

    int query(int i) {
        return prefix(i) - prefix(i - 1);
    }

    int query(int l, int r) {
        return prefix(r) - prefix(l - 1);
    }

};
