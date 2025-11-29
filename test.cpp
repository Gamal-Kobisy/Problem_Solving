#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'


struct matrix
{
    vector<vector<ll>> mat;
    int n, m;
    matrix(int _n, int _m)
    {
        n = _n;
        m = _m;
        mat.assign(n, vector<ll>(m, 0));
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << nl;
        }
    }
};

// ----------------- helpers -----------------
int nextPowerOfTwo(int x)
{
    int p = 1;
    while (p < x)
        p <<= 1;
    return p;
}

matrix padMatrix(const matrix &A, int sz)
{
    matrix R(sz, sz);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
            R.mat[i][j] = A.mat[i][j];
    return R;
}

matrix unpadMatrix(const matrix &A, int n, int m)
{
    matrix R(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            R.mat[i][j] = A.mat[i][j];
    return R;
}

matrix addMatrix(const matrix &A, const matrix &B)
{
    int n = A.n;
    matrix C(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C.mat[i][j] = A.mat[i][j] + B.mat[i][j];
    return C;
}

matrix subMatrix(const matrix &A, const matrix &B)
{
    int n = A.n;
    matrix C(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C.mat[i][j] = A.mat[i][j] - B.mat[i][j];
    return C;
}

// naive multiply used for small sizes
matrix naiveMultiply(const matrix &A, const matrix &B)
{
    int n = A.n;
    matrix C(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    return C;
}

// split A into 4 blocks (assume square and even n)
void split(const matrix &A, matrix &A11, matrix &A12, matrix &A21, matrix &A22)
{
    int s = A.n / 2;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            A11.mat[i][j] = A.mat[i][j];
            A12.mat[i][j] = A.mat[i][j + s];
            A21.mat[i][j] = A.mat[i + s][j];
            A22.mat[i][j] = A.mat[i + s][j + s];
        }
    }
}

// join 4 blocks into one
matrix join(const matrix &C11, const matrix &C12, const matrix &C21, const matrix &C22)
{
    int s = C11.n;
    matrix C(2 * s, 2 * s);
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            C.mat[i][j] = C11.mat[i][j];
            C.mat[i][j + s] = C12.mat[i][j];
            C.mat[i + s][j] = C21.mat[i][j];
            C.mat[i + s][j + s] = C22.mat[i][j];
        }
    }
    return C;
}

// ----------------- Strassen -----------------
matrix strassenMultiply(const matrix &A, const matrix &B, int threshold = 64)
{
    int n = A.n;
    // base
    if (n <= threshold)
        return naiveMultiply(A, B);
    if (n == 1)
    {
        matrix C(1, 1);
        C.mat[0][0] = A.mat[0][0] * B.mat[0][0];
        return C;
    }

    int s = n / 2;
    // allocate sub-blocks
    matrix A11(s, s), A12(s, s), A21(s, s), A22(s, s);
    matrix B11(s, s), B12(s, s), B21(s, s), B22(s, s);

    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // Strassen's 7 products
    matrix S1 = addMatrix(A11, A22);
    matrix S2 = addMatrix(B11, B22);
    matrix P1 = strassenMultiply(S1, S2, threshold);

    matrix S3 = addMatrix(A21, A22);
    matrix P2 = strassenMultiply(S3, B11, threshold);

    matrix S4 = subMatrix(B12, B22);
    matrix P3 = strassenMultiply(A11, S4, threshold);

    matrix S5 = subMatrix(B21, B11);
    matrix P4 = strassenMultiply(A22, S5, threshold);

    matrix S6 = addMatrix(A11, A12);
    matrix P5 = strassenMultiply(S6, B22, threshold);

    matrix S7 = subMatrix(A21, A11);
    matrix S8 = addMatrix(B11, B12);
    matrix P6 = strassenMultiply(S7, S8, threshold);

    matrix S9 = subMatrix(A12, A22);
    matrix S10 = addMatrix(B21, B22);
    matrix P7 = strassenMultiply(S9, S10, threshold);

    // compute result sub-blocks
    // C11 = P1 + P4 - P5 + P7
    matrix temp1 = addMatrix(P1, P4);
    matrix temp2 = subMatrix(temp1, P5);
    matrix C11 = addMatrix(temp2, P7);

    // C12 = P3 + P5
    matrix C12 = addMatrix(P3, P5);

    // C21 = P2 + P4
    matrix C21 = addMatrix(P2, P4);

    // C22 = P1 + P3 - P2 + P6
    matrix temp3 = addMatrix(P1, P3);
    matrix temp4 = subMatrix(temp3, P2);
    matrix C22 = addMatrix(temp4, P6);

    return join(C11, C12, C21, C22);
}

matrix multiplyStrassen(const matrix &Aorig, const matrix &Borig, int threshold = 64)
{
    int n = Aorig.n, m = Borig.m;
    int maxn = max({Aorig.n, Aorig.m, Borig.n, Borig.m});
    int sz = nextPowerOfTwo(maxn);
    matrix A = padMatrix(Aorig, sz);
    matrix B = padMatrix(Borig, sz);
    matrix Cpad = strassenMultiply(A, B, threshold);
    matrix C = unpadMatrix(Cpad, Aorig.n, Borig.m);
    return C;
}

// ----------------- demo main -----------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0; // read n (assume square matrices n x n)
    matrix A(n, n), B(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A.mat[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B.mat[i][j];

    int threshold = 64; // tune if needed
    matrix C = multiplyStrassen(A, B, threshold);

    cout << "Product:\n";
    C.print();

    return 0;
}
