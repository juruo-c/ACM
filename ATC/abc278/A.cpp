#include <iostream>

using namespace std;

const int N = 105;

int n ,k;
int a[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = k + 1; i <= n; i ++ )
        cout << a[i] << " ";
    for (int i = 1; i <= min(k, n); i ++ )
        cout << 0 << " ";
    return 0;
}