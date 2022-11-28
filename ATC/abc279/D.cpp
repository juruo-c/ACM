#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    double x = pow(2 * b / a, -2.0 / 3) - 1;
    long long xx = x;
    printf("%.10f\n", min(a / sqrt(xx + 1) + b * xx, a / sqrt(xx + 2) + b * (xx + 1)));
    return 0;
}