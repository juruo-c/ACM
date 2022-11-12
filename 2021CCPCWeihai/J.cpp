#include <iostream>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int _;
    cin >> _;
    while (_ --)
    {
        LL a, b;
        cin >> a >> b;
        b *= 180;
        LL g = gcd(a, b);
        a /= g, b /= g;
        cout << b - 1 << endl;
    }
    return 0;
}