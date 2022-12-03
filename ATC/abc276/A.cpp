#include <iostream>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    int ans = 0;
    for (int i = 1; i <= h; i ++ )
    {
        string s;
        cin >> s;
        for (int j = 0; s[j]; j ++ )
            if (s[j] == '#') ans ++;
    }
    cout << ans << endl;
    return 0;
}