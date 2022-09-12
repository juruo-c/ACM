#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ )
        cin >> a[i];
    cout << (n - 1 + k - 2) / (k - 1) << endl;
    return 0;
}