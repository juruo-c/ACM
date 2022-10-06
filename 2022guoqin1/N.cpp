#include <iostream>

using namespace std;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    string a, b;
    cin >> a >> b;
    if (a > b) cout << a << ">" << b << endl;
    else if (a < b) cout << a << "<" << b << endl;
    else cout << a << "=" << b << endl;
    return 0;
}