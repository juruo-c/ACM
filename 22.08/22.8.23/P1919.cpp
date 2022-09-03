#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4000005;
const double PI = acos(-1);

int n, m;
int res, ans[N];
int AA, BB;
int Lim = 1;
int L, R[N];
char s1[N], s2[N];
int c1, c2;

struct Complex
{
    double x, y;
    Complex (double x = 0, double y = 0): x(x), y(y){}
}A[N], B[N];

Complex operator * (Complex& a, Complex& b)
{
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

Complex operator - (Complex& a, Complex& b)
{
    return Complex(a.x - b.x, a.y - b.y);
}

Complex operator + (Complex& a, Complex& b)
{
    return Complex(a.x + b.x, a.y + b.y);
}

void FFT(Complex* J, double type)
{
    for (int i = 0; i < Lim; i ++ )
        if (i < R[i]) swap(J[i], J[R[i]]);

    for (int mid = 1; mid < Lim; mid <<= 1)
    {
        Complex wn(cos(PI / mid), type * sin(PI / mid));
        for (int len = mid << 1, pos = 0; pos < Lim; pos += len)
        {
            Complex w(1, 0);
            for (int k = 0; k < mid; k ++, w = w * wn)
            {
                Complex x = J[pos + k];
                Complex y = w * J[pos + k + mid];
                J[pos + k] = x + y;
                J[pos + mid + k] = x - y;
            }
        }
    }
}

void mul()
{
    while (Lim < c1 + c2) Lim <<= 1, L ++;

    for (int i = 0; i <= Lim; i ++ ) R[i] = (R[i >> 1] >> 1) | ((i & 1) << ( L - 1 ));

    FFT(A, 1);
    FFT(B, 1);
    for (int i = 0; i <= Lim; i ++ )
        A[i] = A[i] * B[i];
    
    FFT(A, -1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    for (int i = n - 1; i >= 0; i -- ) A[c1 ++] = s1[i] - '0';
    for (int i = m - 1; i >= 0; i -- ) B[c2 ++] = s2[i] - '0';

    mul();

    for (int i = 0; i <= Lim; i ++ )
    {
        ans[i] += (int)(A[i].x / Lim + 0.5);
        if (ans[i] >= 10)
        {
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
            Lim += (i == Lim);
        }
    }

    while (!ans[Lim] && Lim >= 1) Lim --;

    for (int i = Lim; i >= 0; i -- ) printf("%d", ans[i]);
    puts("");

    return 0;
}
