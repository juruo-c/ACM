#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = (b + c) * 2 + 1;
    if (a == 1 && b == 0 && c == 0)
    {
        cout << "YES\n0\n";
        return 0;
    }
    if (a + b + c < d) cout << "NO" << endl;
    else cout << "YES\n" << d << endl;
    return 0;
}