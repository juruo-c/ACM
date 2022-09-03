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

const int N = 1000005;
const double PI = acos(-1);

int n, m;
int Lim;
int L, R[N];

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
    Lim = 1, L = 0;
    while (Lim <= n + m) Lim <<= 1, L ++;

    for (int i = 0; i < Lim; i ++ ) R[i] = (R[i >> 1] >> 1) | ((i & 1) << ( L - 1 ));

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
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i ++ ) scanf("%lf", &A[i].x);
    for (int i = 0; i <= m; i ++ ) scanf("%lf", &B[i].x);
    n ++, m ++;

    mul();

    for (int i = 0; i <= n + m - 2; i ++ ) 
        printf("%d ", (int)(A[i].x / Lim + 0.5));
    puts("");

    return 0;
}
