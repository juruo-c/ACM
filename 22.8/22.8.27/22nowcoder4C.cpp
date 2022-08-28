#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int p = 998244353;
const int N = 50005, M = 10000005;

int jc[M], jc_inv[M];

int norm(int x)
{
    if (x < 0)
        x += p;
    if (x >= p) 
        x -= p;
    return x;
}

template<class T>
T power(T a, int b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2) res *= a;
    return res;
}

struct Z
{
    int x;
    Z(int x = 0): x(norm(x)){}
    int val() const{
        return x;
    }
    Z operator-() const{
        return Z(norm(p - x));
    }
    Z inv() const{
        assert(x != 0);
        return power(*this, p - 2);
    }
    Z &operator *= (const Z &rhs)
    {
        x = LL(x) * rhs.x % p;
        return *this;
    }
    Z &operator += (const Z& rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator -= (const Z& rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator /= (const Z& rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator * (const Z& lhs, const Z& rhs)
    {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator + (const Z& lhs, const Z& rhs)
    {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator - (const Z& lhs, const Z& rhs)
    {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator / (const Z& lhs, const Z& rhs)
    {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

vector<int> rev;
vector<Z> roots{0, 1};
void dft(vector<Z> &a)
{
    int n = a.size();

    if (int(rev.size()) != n)
    {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i ++ )
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }

    for (int i = 0; i < n; i ++ )
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);

    if (int(roots.size()) < n)
    {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while((1 << k) < n)
        {
            Z e = power(Z(3), (p - 1) >> (k + 1));
            for (int i = 1 << (k - 1) ; i < (1 << k); i ++ )
            {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k ++;
        }
    }

    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; j ++ )
            {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
}

void idft(vector<Z>& a)
{
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = (1 - p) / n;
    for (int i = 0; i < n; i ++ )
        a[i] *= inv;
}

struct Poly
{
    vector<Z> a;
    Poly(){}
    Poly(const vector<Z> &a):a(a){}
    Poly(const initializer_list<Z> &a) : a(a){}
    int size() const
    {
        return a.size();
    }
    void resize(int n)
    {
        a.resize(n);
    }
    Z operator[](int idx) const 
    {
        if (idx < 0 || idx >= size())
            return 0;
        return a[idx];
    }
    Z& operator[](int idx)
    {
        return a[idx];
    }

    Poly mulxk(int k) const 
    {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const 
    {
        k = min(k, size());
        return Poly(vector<Z>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const 
    {
        if (size() <= k) return Poly();
        return Poly(vector<Z>(a.begin() + k, a.end()));
    }

    friend Poly operator + (const Poly& a, const Poly& b)
    {
        vector<Z> res(max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i ++ )
            res[i] = a[i] + b[i];
        return Poly(res);
    }
    friend Poly operator - (const Poly& a, const Poly& b)
    {
        vector<Z> res(max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i ++ )
            res[i] = a[i] - b[i];
        return Poly(res);
    }
    friend Poly operator * (Poly a, Poly b)
    {
        if (a.size() == 0 || b.size() == 0)
        {
            return Poly();
        }
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) sz *= 2;
        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);
        for (int i = 0; i < sz; i ++ )
            a.a[i] = a[i] * b[i];
        idft(a.a);
        a.resize(tot);
        return a;
    }   
    friend Poly operator * (Z a, Poly b)
    {
        for (int i = 0; i < int(b.size()); i ++ )
            b[i] *= a;
        return b;
    }
    friend Poly operator * (Poly a, Z b)
    {
        for (int i = 0; i < int(a.size()); i ++ )
            a[i] *= b;
        return a;
    }
    Poly & operator += (Poly b)
    {
        return (*this) = (*this) + b;
    }
    Poly & operator -= (Poly b)
    {
        return (*this) = (*this) - b;
    }
    Poly & operator *= (Poly b)
    {
        return (*this) = (*this) * b;
    }
};

int w;
Poly f[15];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i < M; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % p;
    jc_inv[M - 1] = power(jc[M - 1], p - 2);
    for (int i = M - 2; i >= 1; i -- )
        jc_inv[i] = 1LL * jc_inv[i + 1] * (i + 1) % p;

    scanf("%d", &w);
    vector<int> c(w);
    for (int i = 0; i < w; i ++ ) scanf("%d", &c[i]);
    sort(c.begin(), c.end());

    for (int i = 0; i < w; i ++ )
    {
        Poly g;
        g.resize(c[i]);
        for (int j = 0; j < c[i]; j ++ )
            g[j] = (p - jc_inv[j]) % p;
        for (int j = i; j >= 0; j -- )
            if (j == i) f[j + 1] = f[j];
            else f[j + 1] = f[j + 1] * g + f[j];
        f[0] = f[0] * g;
    }

    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;scanf("%d", &n);
        Z ans = 0;
        if (n < f[0].size()) ans += f[0][n];
        for (int i = 1; i <= w; i ++ )
        {
            int inv = power(i, p - 2);
            int cur = power(i, n);
            for (int j = 0; j < f[i].size(); j ++ )
            {
                if (j > n) break;
                ans += f[i][j] * jc_inv[n - j] * cur;
                cur = 1LL * cur * inv % p;
            }
            ans *= jc[n];
            printf("%d\n", ans.val());
        }
    }
    return 0;
}
