// ==============================================================================
// 1. MODULAR ARITHMETIC HELPERS
// ==============================================================================
const int mod = 1e9 + 7;
/*
 * HOW TO USE: fast_pow(base, exponent)
 * WHEN TO USE: Calculating (base^exponent) % mod.
 * COMPLEXITY: O(log b)
 */
ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
/*
 * NOTE: Helper function. Used internally by modInverse(). Do not call directly in main.
 *
 * EXAMPLE:
 *   fast_pow(2, 10) = 1024 % mod = 1024
 *   fast_pow(2, mod - 2)  -> modular inverse of 2
 *
 * EXPLANATION: Binary exponentiation folds the exponent into its binary bits;
 *   squaring the base each step while multiplying into the answer only when a bit is set.
 */

/*
 * HOW TO USE: modInverse(n)
 * WHEN TO USE: When you need to divide by 'n' under a prime modulo (Fermat's Little Theorem).
 * COMPLEXITY: O(log mod)
 */
int modInverse(int n)
{
    return fast_pow(n, mod - 2);
}
/*
 * NOTE: Helper function. Used internally for modular division.
 *
 * EXAMPLE:
 *   modInverse(2) = 500000004   (since 2 * 500000004 % mod == 1)
 *
 * EXPLANATION: By Fermat's Little Theorem, a^(mod-1) == 1 (mod p), so the inverse
 *   of 'n' is n^(mod-2) under this prime modulo.
 */

int add(int a, int b)
{
    int ret = a + b;
    if (ret >= mod) ret -= mod;
    if (ret < 0) ret += mod;
    return ret;
}

int mul(int a, int b)
{
    return 1ll * a * b % mod;
}
/*
 * NOTE: Helper functions for modular arithmetic. add(a, b) computes (a + b) % mod
 *   (handles negative results), mul(a, b) computes (a * b) % mod.
 *
 * EXAMPLE:
 *   add(7, mod - 3) = 4
 *   mul(100000, 100000) = 999300007   (no overflow thanks to the 1ll cast)
 *
 * EXPLANATION: 'add' normalizes the sum back into [0, mod) after a possible negative,
 *   'mul' uses a long-long intermediate so the product fits before taking modulo.
 */

// ==============================================================================
// 2. STANDARD FFT & APPLICATIONS (Complex Double - Updated to Long Long)
// ==============================================================================

using cd = complex<double>;
/*
 * HOW TO USE: fft(array, invert_flag)
 * WHEN TO USE: Base function for standard convolution over complex numbers (No modulo).
 * COMPLEXITY: O(N log N)
 */
void fft(vector<cd>& a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
    {
        for (cd& x : a) x /= n;
    }
}
/*
 * NOTE: Helper function. Performs the core DFT, used internally by multiply().
 *   Do NOT call in main; use multiply() instead.
 *
 * EXAMPLE:
 *   vector<cd> a = {1, 2};  fft(a, false);   // forward transform
 *   fft(a, true);                            // inverse transform, a == {1, 2} again
 *
 * EXPLANATION: Iterative Cooley-Tukey FFT. First reorders inputs via bit-reversal,
 *   then combines butterflies of increasing length. invert=false does a forward
 *   transform, invert=true undoes it and divides by N.
 */

/*
 * HOW TO USE: multiply(polyA, polyB)
 * WHEN TO USE: Multiplying two polynomials where exact values don't exceed floating-point precision (~10^15). No modulo applied.
 * COMPLEXITY: O(N log N)
 */
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++) result[i] = llround(fa[i].real());
    return result;
}
/*
 * EXAMPLE:
 *   multiply({1, 2, 3}, {1, 1})
 *     = polynomial (1 + 2x + 3x^2) * (1 + x)  ->  1 + 3x + 5x^2 + 3x^3
 *     = {1, 3, 5, 3}
 *
 * EXPLANATION: Turns each coefficient vector into complex polynomials, pads to a
 *   power of two >= (lenA+lenB), forward-transforms both, multiplies pointwise,
 *   then inverse-transforms. result[k] holds the coefficient of x^k (i.e. the
 *   convolution value at index k).
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       vector<ll> A = {1, 2, 3}, B = {1, 1};
 *       vector<ll> C = multiply(A, B);   // C = {1, 3, 5, 3}
 *       // C[k] = number of (i, j) pairs with A[i]+B[j] == k
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: poly_pow(poly, p)
 * WHEN TO USE: Raising a polynomial to the power of 'p'.
 * COMPLEXITY: O(N log N * log P)
 */
vector<ll> poly_pow(vector<ll> poly, int p)
{
    vector<ll> result = {1};
    while (p > 0)
    {
        if (p & 1) result = multiply(result, poly);
        poly = multiply(poly, poly);
        p >>= 1;
    }
    return result;
}
/*
 * EXAMPLE:
 *   poly_pow({1, 1}, 3)
 *     = (1 + x)^3 = 1 + 3x + 3x^2 + x^3  ->  {1, 3, 3, 1}
 *
 * EXPLANATION: Binary exponentiation on polynomials, identical in spirit to integer
 *   fast exponentiation: square the base polynomial and multiply into the answer
 *   when the current bit of 'p' is set. Each multiply() is O(N log N).
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       vector<ll> poly = {1, 1};
 *       vector<ll> res = poly_pow(poly, 3);   // (1+x)^3 = {1, 3, 3, 1}
 *       // great for counting ways to reach exactly k sums from p independent draws
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: big_multiply("123456...", "987654...")
 * WHEN TO USE: Multiplying two extremely large numbers represented as strings.
 * COMPLEXITY: O(N log N)
 */
string big_multiply(string s1, string s2)
{
    if (s1 == "0" || s2 == "0") return "0";
    vector<ll> a(s1.size()), b(s2.size());
    for (int i = 0; i < s1.size(); i++) a[i] = s1[s1.size() - 1 - i] - '0';
    for (int i = 0; i < s2.size(); i++) b[i] = s2[s2.size() - 1 - i] - '0';

    vector<ll> res = multiply(a, b);
    ll carry = 0;
    for (int i = 0; i < res.size(); i++)
    {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();

    string ans = "";
    for (int i = res.size() - 1; i >= 0; i--) ans += to_string(res[i]);
    return ans;
}
/*
 * EXAMPLE:
 *   big_multiply("123", "456") = "56088"
 *
 * EXPLANATION: Digit arrays are stored least-significant-first, then multiply() gives
 *   raw digit products. A single carry pass normalizes each position back to a digit,
 *   and leading zeros are trimmed before building the result string.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       string s1 = "123456789987654321", s2 = "987654321123456789";
 *       string prod = big_multiply(s1, s2);   // exact product as a string
 *       cout << prod << "\n";
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: count_distinct_triplets_sum(array_of_integers)
 * WHEN TO USE: Finding the number of ways to pick 3 distinct elements from an array that sum to exactly X.
 * COMPLEXITY: O(MAX_VAL * log(MAX_VAL))
 */
vector<ll> count_distinct_triplets_sum(const vector<ll>& A)
{
    if (A.empty()) return {};
    ll max_val = 0;
    for (ll x : A) max_val = max(max_val, x);
    int size = 1;
    while (size <= 3 * max_val) size <<= 1;

    vector<ll> p1(size, 0), p2(size, 0), p3(size, 0);
    for (ll x : A)
    {
        p1[x]++;
        if (2 * x < size) p2[2 * x]++;
        if (3 * x < size) p3[3 * x]++;
    }

    vector<ll> p1_sq = multiply(p1, p1);
    vector<ll> p_cube = multiply(p1_sq, p1);
    vector<ll> p1_p2 = multiply(p1, p2);

    vector<ll> res(size);
    for (int i = 0; i < size; i++)
    {
        ll term1 = p_cube[i];
        ll term2 = 3 * (i < p1_p2.size() ? p1_p2[i] : 0);
        ll term3 = 2 * p3[i];
        res[i] = (term1 - term2 + term3) / 6;
    }
    return res;
}
/*
 * EXAMPLE:
 *   A = {1, 1, 2, 3}
 *   count_distinct_triplets_sum(A)[6] counts triples of *distinct indices* summing to 6:
 *     (0,1,2): 1+1+2=4, (0,1,3): 1+1+3=5, (0,2,3): 1+2+3=6, (1,2,3): 1+2+3=6
 *     -> ways[6] == 2
 *
 * EXPLANATION: Convolutions count unordered choices. p_cube counts ordered triples,
 *   p1_p2 counts ordered (x,x,y) types, p3 counts (x,x,x). The classic
 *   "3 distinct elements" inclusion-exclusion is (cube - 3*pairType + 2*triples) / 6,
 *   leaving per-sum counts of triples with distinct indices.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       vector<ll> A = {1, 1, 2, 3};
 *       vector<ll> ways = count_distinct_triplets_sum(A);
 *       cout << ways[6] << "\n";   // 2 : triples of distinct indices summing to 6
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: get_hamming_distances(Text_array, Pattern_array)
 * WHEN TO USE: String matching allowing mismatches. Returns an array where ans[i] is the number of mismatches if Pattern is placed at index i of Text.
 * COMPLEXITY: O(|Sigma| * N log N) where Sigma is the unique characters in Pattern.
 */
vector<int> get_hamming_distances(const vector<int>& T, const vector<int>& P)
{
    int n = T.size(), m = P.size();
    if (n < m) return {};
    vector<int> unique_chars = P;
    sort(unique_chars.begin(), unique_chars.end());
    unique_chars.erase(unique(unique_chars.begin(), unique_chars.end()), unique_chars.end());

    vector<int> total_matches(n - m + 1, 0);
    for (int c : unique_chars)
    {
        vector<ll> t_bin(n), p_bin(m);
        for (int i = 0; i < n; i++) t_bin[i] = (T[i] == c ? 1 : 0);
        for (int i = 0; i < m; i++) p_bin[i] = (P[i] == c ? 1 : 0);

        reverse(p_bin.begin(), p_bin.end());
        vector<ll> matches_c = multiply(t_bin, p_bin);

        for (int i = 0; i <= n - m; i++) total_matches[i] += matches_c[i + m - 1];
    }

    vector<int> ham(n - m + 1);
    for (int i = 0; i <= n - m; i++) ham[i] = m - total_matches[i];
    return ham;
}
/*
 * EXAMPLE:
 *   T = "abcab", P = "ab"
 *   get_hamming_distances({0,1,2,0,1}, {0,1})
 *     -> i=0: "ab" matches both  -> 0 mismatches
 *        i=1: "bc" matches none  -> 2 mismatches
 *        i=2: "ca" matches none  -> 2 mismatches
 *        i=3: "ab" matches both  -> 0 mismatches
 *     => {0, 2, 2, 0}
 *
 * EXPLANATION: For each unique character c, text and pattern are converted to
 *   {0,1} indicators, the pattern is reversed, and the convolution counts matching
 *   positions per alignment. Summing over characters gives total matches; hamming
 *   distance = pattern length - matches.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       vector<int> T = {0,1,2,0,1}, P = {0,1};
 *       vector<int> ham = get_hamming_distances(T, P);   // {0, 2, 2, 0}
 *       cout << ham[0] << "\n";   // mismatches if pattern starts at index 0
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: wildcard_string_matching(Text, Pattern)
 * WHEN TO USE: Finding all starting indices where Pattern matches Text, allowing '?'
 *              as a wildcard character that can match any letter ('a'-'z').
 * COMPLEXITY: O(N log N) where N is the length of the Text.
 */
vector<int> wildcard_string_matching(string T, string P)
{
    int n = T.size(), m = P.size();
    if (n < m) return {};

    vector<ll> t1(n), t2(n), t3(n);
    for (int i = 0; i < n; i++)
    {
        ll val = (T[i] == '?' ? 0 : T[i] - 'a' + 1);
        t1[i] = val;
        t2[i] = val * val;
        t3[i] = val * val * val;
    }

    vector<ll> p1(m), p2(m), p3(m);
    for (int i = 0; i < m; i++)
    {
        ll val = (P[i] == '?' ? 0 : P[i] - 'a' + 1);
        p1[m - 1 - i] = val;
        p2[m - 1 - i] = val * val;
        p3[m - 1 - i] = val * val * val;
    }

    vector<ll> res1 = multiply(t3, p1);
    vector<ll> res2 = multiply(t2, p2);
    vector<ll> res3 = multiply(t1, p3);

    vector<int> match_indices;
    for (int i = m - 1; i < n; i++)
    {
        ll sum = res1[i] - 2LL * res2[i] + res3[i];
        if (sum == 0)
        {
            match_indices.push_back(i - m + 1);
        }
    }

    return match_indices;
}
/*
 * EXAMPLE:
 *   T = "a?c", P = "abc"
 *   wildcard_string_matching("a?c", "abc")
 *     -> the '?' in text can match 'b', so pattern matches at index 0
 *     => {0}
 *
 * EXPLANATION: Values are encoded as (ch - 'a' + 1), with '?' = 0. The convolution
 *   sum res1 - 2*res2 + res3 equals sum of (t - p)^2 over aligned positions, which
 *   is 0 exactly when every aligned pair is equal (including wildcard-equal cases).
 *   Positions whose aligned sum is 0 are reported.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       string T = "a?c", P = "abc";
 *       vector<int> pos = wildcard_string_matching(T, P);   // {0}
 *       for (int idx : pos) cout << idx << " ";             // 0
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: get_pairwise_differences(arrayA, arrayB)
 * WHEN TO USE: For every pair (a in A, b in B), counts how many pairs have difference X.
 *   Returned result: res[X + max_B] == number of pairs with a - b == X.
 * COMPLEXITY: O(N log N)
 */
vector<ll> get_pairwise_differences(const vector<ll>& A, const vector<ll>& B)
{
    if (A.empty() || B.empty()) return {};

    // Find maximum values to determine the size of the frequency arrays
    int max_A = 0, max_B = 0;
    for (int x : A) max_A = max(max_A, x);
    for (int x : B) max_B = max(max_B, x);

    // Create frequency arrays
    vector<ll> freq_A(max_A + 1, 0);
    for (int x : A) freq_A[x]++;

    vector<ll> freq_B(max_B + 1, 0);
    for (int x : B) freq_B[x]++;

    // Reverse the second frequency array to calculate differences
    vector<ll> rev_freq_B(max_B + 1, 0);
    for (int i = 0; i <= max_B; i++)
    {
        rev_freq_B[max_B - i] = freq_B[i];
    }

    // Multiply A and the reversed B
    vector<ll> res = multiply(freq_A, rev_freq_B);

    // The result for difference X (where X = A[i] - B[j]) is stored at index (X + max_B)
    return res;
}
/*
 * EXAMPLE:
 *   A = {1, 2}, B = {1}
 *   get_pairwise_differences({1,2}, {1})
 *     -> pairs (1-1)=0, (2-1)=1, so counts {1 for X=0, 1 for X=1}
 *     => result[1] = 1 (X=0), result[2] = 1 (X=1)  since index = X + max_B(=1)
 *
 * EXPLANATION: Frequency arrays are convolved with B reversed; the shift of max_B
 *   turns every difference into a non-negative index. res[idx] = count of pairs
 *   (a, b) with a - b = idx - max_B.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       vector<ll> A = {1, 2}, B = {1};
 *       vector<ll> cnt = get_pairwise_differences(A, B);
 *       int X = 1;                                  // want a - b == 1
 *       cout << cnt[X + 1] << "\n";                 // 1   (pair (2,1))
 *       return 0;
 *   }
 */

/*
 * HOW TO USE: get_matches_per_lag(S)
 * WHEN TO USE: Helper. matches[lag] = number of positions i with S[i] == S[i+lag]
 *              (0 <= lag < n). Used internally by smallest_period().
 * COMPLEXITY: O(n log n) per distinct character.
 */
vector<int> get_matches_per_lag(string S)
{
    int n = S.size();
    if (n <= 1) return vector<int>(n, 0);

    int sz = 1;
    while (sz < 2 * n - 1) sz <<= 1;
    vector<ll> corr(sz, 0);

    string uniq = S;
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

    for (char c : uniq)
    {
        vector<ll> f(n, 0), rf(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (S[i] == c) f[i] = 1;
            if (S[n - 1 - i] == c) rf[i] = 1;
        }
        vector<ll> conv = multiply(f, rf);          // conv[k] counts pairs at lag n-1-k
        for (int k = 0; k < 2 * n - 1; k++) corr[k] += conv[k];
    }

    vector<int> matches(n, 0);
    for (int lag = 0; lag < n; lag++) matches[lag] = corr[n - 1 - lag];
    return matches;
}

/*
 * EXAMPLE:
 *   smallest_period("abcabcabc") = 3     (string repeats every 3 chars)
 *   smallest_period("aaaaaa")     = 1     (any single char is a period)
 *   smallest_period("ababa")      = 2     (a[2i]==a, pattern "ab"-ish)
 *
 * EXPLANATION: A period 'p' (1..n) satisfies S[i] == S[i+p] for every valid i.
 *   Via self-correlation, matches[p-?] counts matching positions at each shift;
 *   the shift p is a period exactly when every position matches (n-p matches).
 *   We scan for the smallest such p.
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       string S = "abcabcabc";
 *       int p = smallest_period(S);          // 17 == n means "no smaller period"
 *       cout << p << "\n";
 *       return 0;
 *   }
 */
int smallest_period(string S)
{
    int n = S.size();
    vector<int> matches = get_matches_per_lag(S);
    for (int p = 1; p < n; p++)
        if (matches[p] == n - p) return p;
    return n;                                   // no genuine period, whole string is
}

/*
 * HOW TO USE: best_alignment(Text, Pattern)
 * WHEN TO USE: ans[i] = number of characters that match when Pattern is placed at
 *              index i of Text (i ranges 0..n-m). Best alignment = the max value.
 * COMPLEXITY: O(|Sigma| * n log n)
 *
 * EXAMPLE:
 *   best_alignment("abcabc", "abc")
 *     -> alignments: i=0 "abc"->3, i=1 "bca"->0, i=2 "cab"->0, i=3 "abc"->3
 *     => {3, 0, 0, 3}
 *
 * EXPLANATION: For each unique Pattern character, Text and Pattern are turned into
 *   {0,1} indicators (Pattern reversed), convolved, and summed. The value at each
 *   alignment equals the number of aligned positions that share the same character,
 *   i.e. the exact-match count. (Best fit = argmax over the returned array.)
 *
 * HOW TO USE IN MAIN:
 *   int main() {
 *       string T = "abcabc", P = "abc";
 *       vector<int> m = best_alignment(T, P);   // {3, 0, 0, 3}
 *       int best = *max_element(m.begin(), m.end());
 *       cout << best << "\n";                   // 3
 *       return 0;
 *   }
 */
vector<int> best_alignment(string T, string P)
{
    int n = T.size(), m = P.size();
    if (n < m) return {};

    string uniq = P;
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

    vector<int> matches(n - m + 1, 0);
    for (char c : uniq)
    {
        vector<ll> t_bin(n), p_bin(m);
        for (int i = 0; i < n; i++) t_bin[i] = (T[i] == c ? 1 : 0);
        for (int i = 0; i < m; i++) p_bin[i] = (P[i] == c ? 1 : 0);
        reverse(p_bin.begin(), p_bin.end());

        vector<ll> matches_c = multiply(t_bin, p_bin);
        for (int i = 0; i <= n - m; i++) matches[i] += matches_c[i + m - 1];
    }
    return matches;
}


/*
 * HOW TO USE: count_subset_sums(A)
 * WHEN TO USE: Finding the exact number of subsets that sum to X, for all possible sums.
 * COMPLEXITY: O(S log S log N), where S is the total sum of all elements in A.
 */
vector<ll> count_subset_sums_helper(int l, int r, const vector<vector<ll>>& polys)
{
    if (l == r) return polys[l];
    int mid = l + (r - l) / 2;
    vector<ll> left_poly = count_subset_sums_helper(l, mid, polys);
    vector<ll> right_poly = count_subset_sums_helper(mid + 1, r, polys);
    return multiply(left_poly, right_poly);
}

vector<ll> count_subset_sums(const vector<int>& A)
{
    if (A.empty()) return {1};

    // Convert each element x into a polynomial (1 + z^x)
    vector<vector<ll>> polys(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        polys[i].assign(A[i] + 1, 0);
        polys[i][0] = 1;      // exclude A[i] (sum contributes 0)
        polys[i][A[i]] = 1;   // include A[i] (sum contributes A[i])
    }

    // Multiply them all using divide and conquer
    return count_subset_sums_helper(0, polys.size() - 1, polys);
}
/*
 * EXAMPLE:
 *   A = {1, 2, 2}
 *   count_subset_sums(A)
 *     -> Polynomials: (1 + x^1) * (1 + x^2) * (1 + x^2)
 *     -> Result: {1, 1, 2, 2, 1, 1}
 *   Result[2] == 2, meaning 2 distinct subsets sum to 2: {2} and {2}.
 *   Result[5] == 1, meaning 1 subset sums to 5: {1, 2, 2}.
 *
 * EXPLANATION: Multiplying all (1 + z^x) binomials gives a polynomial where
 *   the coefficient of z^S is the number of subsets summing to S. A divide-and-conquer
 *   approach keeps polynomial sizes balanced, keeping it much faster than sequential multiplication.
 *
 * CAUTION: Because your FFT uses complex<double>, coefficients > 10^15
 *   will suffer from floating-point precision loss. If you expect a massive
 *   number of ways, you need a Number Theoretic Transform (NTT) instead of standard FFT.
 */