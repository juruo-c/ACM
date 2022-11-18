#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, N = 100005;

int n, m;
struct Seq
{
    int l, r;
    bool operator < (const Seq& b) const 
    {
        return l < b.l;
    }  
}seq[N];

struct Matrix
{
    int m[2][2];
    Matrix () {memset(m, 0, sizeof m);}
    Matrix operator * (const Matrix& b)
    {
        Matrix res;
        for (int i = 0; i < 2; i ++ )
            for (int j = 0; j < 2; j ++ )
                for (int k = 0; k < 2; k ++ )
                    res.m[i][j] = (1LL * m[i][k] * b.m[k][j] % mod + res.m[i][j]) % mod;
        return res;
    }  
};

Matrix qpow(Matrix a, int b)
{
    Matrix res;
    for (int i = 0; i < 2; i ++ )
        res.m[i][i] = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++ )
        {
            int x, y;
            scanf("%d%d", &x, &y);
            seq[i] = {min(x, y), max(x, y)};
        }
        sort(seq + 1, seq + 1 + m);

        Matrix ans, a, b;
        ans.m[0][0] = ans.m[1][1] = 1;
        a.m[0][0] = a.m[0][1] = a.m[1][0] = 1, a.m[1][1] = 2;
        b.m[1][0] = 1, b.m[1][1] = 2;
        int r = 1;
        for (int i = 1; i <= m; i ++ )
        {
            if (seq[i].l >= r)
            {
                ans = ans * qpow(a, seq[i].l - r);
                ans = ans * b;
            }
            r = max(seq[i].r + 1, r);
        }
        ans = ans * qpow(a, n + 1 - r);
        printf("%d\n", (ans.m[0][0] + ans.m[1][0]) % mod);
    }
    return 0;
}