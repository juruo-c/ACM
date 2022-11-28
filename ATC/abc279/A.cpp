#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (auto c : s)
        if (c == 'v') ans += 1;
        else if (c == 'w') ans += 2;
    cout << ans << endl;
    return 0;
}