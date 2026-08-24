#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int mod = 1e9 + 7;
const int sz = 200;
typedef array<ll, sz> row;
typedef array<row, sz> mat;
const int S = 32;

mat operator*(const mat &a, const mat &b) {
    mat ret{};

    // The outer loops iterate over the "blocks" or "tiles"
    for (int ih = 0; ih < sz; ih += S) {
        for (int kh = 0; kh < sz; kh += S) {
            for (int jh = 0; jh < sz; jh += S) {

                // The inner loops multiply the elements within the current block
                for (int il = ih; il < min(ih + S, sz); ++il) {
                    for (int kl = kh; kl < min(kh + S, sz); ++kl) {

                        if (a[il][kl] == 0) continue; // Zero-skip optimization

                        // Because of the pragmas at the top, the compiler will
                        // automatically vectorize this innermost loop using AVX!
                        for (int jl = jh; jl < min(jh + S, sz); ++jl) {
                            ret[il][jl] = (ret[il][jl] + a[il][kl] * b[kl][jl]) % mod;
                        }
                    }
                }

            }
        }
    }
    return ret;
}

row operator*(const row &a, const mat &b) {
    row ret{};
    // Tiling isn't needed here since a 1D array easily fits in L1 cache
    for (int k = 0; k < sz; k++) {
        if (a[k] == 0) continue;
        for (int j = 0; j < sz; j++) {
            ret[j] = (ret[j] + a[k] * b[k][j]) % mod;
        }
    }
    return ret;
}

mat operator^(mat a, ll k) {
    mat ret{};
    for (int i = 0; i < sz; i++) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}
